import math
import struct
from typing import Any

from .wwConstants import WWRobotConstants
from .distance_calc import DoubleExponentialDistanceCalc

_rc  = WWRobotConstants.RobotComponent
_rcv = WWRobotConstants.RobotComponentValues

class EncoderExtender:
    ENCODER_RANGE = 2**15 - 1

    def __init__(self) -> None:
        self.prev_value = 0
        self.overflow_count = 0

    def unwrap_encoder(self, new_value):
        # Track 16-bit encoder wrap-around: large negative jump = overflow, large positive = underflow
        if (new_value - self.prev_value < -self.ENCODER_RANGE):
            self.overflow_count += 1
        elif new_value - self.prev_value > self.ENCODER_RANGE:
            self.overflow_count -= 1

        self.prev_value = new_value

        # Reconstruct full unwrapped tick count from overflow cycles and current value
        return self.overflow_count * self.ENCODER_RANGE * 2.0 + float(new_value)

_left_encoder_extender = EncoderExtender()
_right_encoder_extender = EncoderExtender()

def _bytes_to_s16(data: bytes) -> int:
    return struct.unpack('<h', data)[0]

def _clamp(value, min_val, max_val):
    return max(min_val, min(max_val, value))

def _check_range(value, min_val, max_val, name):
    if value > max_val or value < min_val:
        raise ValueError(f'Value {name} out of range [{min_val} to {max_val}]')
    return _clamp(value, min_val, max_val)

def _create_command_lookup():
    """
    Create a reverse lookup dictionary mapping command values to names.
    
    Returns:
        Dictionary with command values as keys and member names as values
    """
    lookup = {}
    for attr_name in dir(_rc):
        if attr_name.startswith('WW_COMMAND_'):
            attr_value = getattr(_rc, attr_name)
            lookup[attr_value] = attr_name
    return lookup

_CMD_NAME_DICT = _create_command_lookup()
    

def _decode_12bit_pose_int(high_byte, low_byte, nibble_is_msb: bool = False) -> int:
    high_nibble = high_byte >> 4 if nibble_is_msb else high_byte & 0xf
    if high_nibble & 0x8:
        high_nibble |= 0xF0

    return _bytes_to_s16(bytes([low_byte, high_nibble]))

# Scale brightness from 0-1 to 0-255
def _scale_brightness(val: float) -> int:
    val = _clamp(val, 0.0, 1.0)
    return int(round(val * 255.0))

def _color_byte_array(color_dict: dict[str, float]):
    """
    convert color into a 3 byte bytearray

    :param color_value: 6-digit (e.g. #fa3b2c), 3-digit (e.g. #fbb),
    fully spelled color (e.g. white)
    """
    return bytearray([
        _scale_brightness(color_dict[_rcv.WW_COMMAND_VALUE_COLOR_RED]),
        _scale_brightness(color_dict[_rcv.WW_COMMAND_VALUE_COLOR_GREEN]),
        _scale_brightness(color_dict[_rcv.WW_COMMAND_VALUE_COLOR_BLUE]),
    ])

def _mono_byte_array(bright_dict: dict[str, float]):
    """
    convert 3 brightness values into a 3 byte bytearray
    """
    return bytearray([
        _scale_brightness(bright_dict[_rcv.WW_COMMAND_VALUE_1]),
        _scale_brightness(bright_dict[_rcv.WW_COMMAND_VALUE_2]),
        _scale_brightness(bright_dict[_rcv.WW_COMMAND_VALUE_3]),
    ])

def _mono_single_byte(bright_dict: dict[str, float]):
    return bytearray([
        _scale_brightness(bright_dict[_rcv.WW_COMMAND_VALUE_COLOR_BRIGHTNESS]),
    ])

def _servo_angle_bytes(angle_dict: dict[str, float], min_deg, max_deg) -> bytes:
    angle_val = _clamp(angle_dict[_rcv.WW_COMMAND_VALUE_ANGLE_DEGREE], min_deg, max_deg)
    angle_val = int(round(angle_val * -100.0))
    return struct.pack('>h', angle_val)

def _get_mic_results(value: bytes) -> dict[str, Any]:
    ############# This is probably Dash specific ##################
    # This does not appear to work well. The angle and clap flag are
    # reasonable, but mic_count is always 0.
    # Probably, not implemented correctly
    clap_flag =  (value[0xb] & 1) != 0
    mic_amp = value[7]
    mic_dir = 0
    mic_con = 0

    if mic_amp != 0:
        # Extract direction: 13-bit angle from bits [12:8] of data[2] and bits [7:4] of data[1]
        # Scaled from [0, 512) to [0, 360) degrees, then shifted to [-180, +180)
        angle_raw = ((value[2] & 0x1F) << 4) | (value[1] >> 4)
        angle_deg = int((angle_raw * 360.0) / 512.0)
        if angle_deg > 180:
            angle_deg -= 360

        # Extract mic count (bits 3:0 of data[0]), clamped to [0, 3]
        mic_count = min(max((value[0] & 0x0F) - 3.0, 0.0), 3.0)
        confidence  = mic_count / 3.0

        # For robot type 0x3E9: scale confidence by signal strength (bits 3:0 of data[1]), clamped to [0, 15]
        signal = min((value[1] & 0x0F), 15.0)
        confidence  *= signal / 15.0

        # Scale confidence by gain (bits 7:4 of data[0]), clamped to [0, 5]
        gain       = min(value[0] >> 4, 5.0)
        confidence_byte = confidence * (gain / 5.0) * 255.0
        confidence_byte = float(int(confidence_byte) & 0xFF)

        # Only report direction if confidence is high enough and noise flag is not set
        # Bit 5 of data[1] is a noise/unreliable flag
        noisy = (value[1] & 0x20) != 0

        # For now just report the values even if low confidence
        #if confidence_byte > 10.0 and not noisy:
        mic_dir = angle_deg
        mic_con = int(confidence_byte)

    return {_rc.WW_SENSOR_MICROPHONE: {
        _rcv.WW_SENSOR_VALUE_MIC_AMPLITUDE: mic_amp / 255.0,
        _rcv.WW_SENSOR_VALUE_MIC_TRIANGULATION_CONF: mic_con,
        _rcv.WW_SENSOR_VALUE_MIC_TRIANGULATION_ANGLE: mic_dir / 180.0 * math.pi,
        _rcv.WW_SENSOR_VALUE_MIC_CLAP_DETECTED: clap_flag,
    }}


def dot_sensor_decode(value: bytes) -> dict[str, Any]:
    results = {}

    index = value[0] >> 4
    results[_rc.WW_SENSOR_TIMESTAMP] = value[1] | ((value[0] & 0xff) << 8)

    results[_rc.WW_SENSOR_ACCELEROMETER] = {
        _rcv.WW_SENSOR_VALUE_AXIS_X: _decode_12bit_pose_int(value[4], value[2], True) / 2047.0 * 2.0,
        _rcv.WW_SENSOR_VALUE_AXIS_Y: _decode_12bit_pose_int(value[4], value[3]) / 2047.0 * 2.0,
        _rcv.WW_SENSOR_VALUE_AXIS_Z: _decode_12bit_pose_int(value[5], value[6], True) / 2047.0 * 2.0
    }

    results[_rc.WW_SENSOR_BUTTON_MAIN] = {
        _rcv.WW_SENSOR_VALUE_BUTTON_STATE: value[8] & 0x10 > 0
    }
    results[_rc.WW_SENSOR_BUTTON_1] = {
        _rcv.WW_SENSOR_VALUE_BUTTON_STATE: value[8] & 0x20 > 0
    }
    results[_rc.WW_SENSOR_BUTTON_2] = {
        _rcv.WW_SENSOR_VALUE_BUTTON_STATE: value[8] & 0x40 > 0
    }
    results[_rc.WW_SENSOR_BUTTON_3] = {
        _rcv.WW_SENSOR_VALUE_BUTTON_STATE: value[8] & 0x80 > 0
    }

    results.update(_get_mic_results(value))

    results[_rc.WW_SENSOR_PICKED_UP] = {
        _rcv.WW_SENSOR_VALUE_FLAG: value[0xb] & 4 != 0
    }
    results[_rc.WW_SENSOR_BUMP_STALL] = {
        _rcv.WW_SENSOR_VALUE_FLAG: value[0xb] & 8 != 0
    }
    results[_rc.WW_SENSOR_SOUND_PLAYING] = {
        _rcv.WW_SENSOR_VALUE_FLAG: value[0xb] & 2 != 0
    }
    results[_rc.WW_SENSOR_ANIMATION_PLAYING] = {
        _rcv.WW_SENSOR_VALUE_FLAG: value[0xb] & 0x40 != 0
    }

    ########### Remaining is HW specific / more complicated
    # results[_rc.WW_SENSOR_BATTERY] = {}
    # results[_rc.WW_SENSOR_BEACON] = {}
    # results[_rc.WW_SENSOR_BEACON_V2] = {}
    # results[_rc.WW_SENSOR_PING_RESPONSE] = {}

    ########## Notes from https://github.com/IlyaSukhanov/morseapi
    # # byte 11
    # # 0x30 when nominal position
    # # 0x24 when on side
    # # 0x04 when picked up
    # # 0x00 when wheels moving
    # # 0x01 when bumped, last bit ONLY active bit of byte 11 on dot
    # # 0x25 picked up and bumped
    # self.sensor_state["moving"] = value[11] == 0
    # self.sensor_state["picked_up"] = bool(value[11] & 0x04)
    # self.sensor_state["hit"] = bool(value[11] & 0x01)
    # self.sensor_state["side"] = value[11] & 0x20 == 0x20
    # self.sensor_state["nominal"] = value[11] & 0x30 == 0x30


    # self.sensor_state["clap"] = (value[11] & 1) == 1
    # self.sensor_state["mic_level"] = value[7]
    # if value[15] == 4:
    #     self.sensor_state["sound_direction"] = value[13] << 8 | value[12]

    # # Dash sensing of dot; Dash only, there might be more states here
    # # there are false positice reading mostly on reflective surfaces
    # self.sensor_state["dot_left_of_dash"] = value[16] & 0x0f not in [0x0f, 0x0]
    # self.sensor_state["dot_right_of_dash"] = value[16] & 0xf0 not in [0xf0, 0x0]
    # # This seems to be another way of dash sensing dot, but its not
    # # very accurate either
    # # self.sensor_state["dot_left_of_dash"] = (
    # #     value[19] == 5 and value[17] == 0xAA
    # # )
    # # self.sensor_state["dot_right_of_dash"] = (
    # #     value[19] == 5 and value[18] == 0xAA
    # # )

    # # Unknown sensor fields
    # #if "unknown_dot" not in self.sensor_state:
    # #    self.sensor_state["unknown_dot"] = {}
    # #self.sensor_state["unknown_dot"]["0"] = value[0] & 0x0f
    # #self.sensor_state["unknown_dot"]["1"] = value[1]  # always 0?
    # #self.sensor_state["unknown_dot"]["8"] = value[8] & 0x0f # awlays 0?
    # #self.sensor_state["unknown_dot"]["9"] = value[9]
    # #self.sensor_state["unknown_dot"]["10"] = value[10]
    # #self.sensor_state["unknown_dot"]["14"] = value[14]
    # # partially known:
    # #self.sensor_state["unknown_dot"]["15"] = value[15]
    # #self.sensor_state["unknown_dot"]["17"] = value[17]
    # #self.sensor_state["unknown_dot"]["18"] = value[18]
    # #self.sensor_state["unknown_dot"]["19"] = value[19]
    return results


def dash_sensor_decode(packet1_data: bytes, data: bytes) -> dict[str, Any]:
    results = {}

    GYRO_SCALE = 500.0 * 0.017453292519943295 / 2047.0
    results[_rc.WW_SENSOR_GYROSCOPE] = {
        _rcv.WW_SENSOR_VALUE_AXIS_ROLL: _decode_12bit_pose_int(data[4], data[5]) * GYRO_SCALE,
        _rcv.WW_SENSOR_VALUE_AXIS_PITCH: _decode_12bit_pose_int(data[4], data[3], True) * GYRO_SCALE,
        _rcv.WW_SENSOR_VALUE_AXIS_YAW: _decode_12bit_pose_int(data[0], data[2]) * GYRO_SCALE,
    }

    # The actual distances are computed using a "PIReflectance" model class.
    # This class has a model built from previously measured data to map
    # The reflectance (0-255) to a distance in cm.
    # The code for this is very opaque and would be easier to generate a new
    # model by empirically measuring for desired wall materials.
    # Included is quick attempt at that process.
    results[_rc.WW_SENSOR_DISTANCE_FRONT_LEFT_FACING] = {
        _rcv.WW_SENSOR_VALUE_REFLECTANCE: float(data[7]),
        _rcv.WW_SENSOR_VALUE_DISTANCE: DoubleExponentialDistanceCalc.reflect_to_distance_cm(float(data[7])),
    }
    results[_rc.WW_SENSOR_DISTANCE_FRONT_RIGHT_FACING] = {
        _rcv.WW_SENSOR_VALUE_REFLECTANCE: float(data[6]),
        _rcv.WW_SENSOR_VALUE_DISTANCE: DoubleExponentialDistanceCalc.reflect_to_distance_cm(float(data[6])),
    }
    results[_rc.WW_SENSOR_DISTANCE_BACK] = {
        _rcv.WW_SENSOR_VALUE_REFLECTANCE: float(data[8]),
        _rcv.WW_SENSOR_VALUE_DISTANCE: DoubleExponentialDistanceCalc.reflect_to_distance_cm(float(data[8])),
    }

    # pi * diameter_cm
    WHEEL_CIRCUMFERENCE_CM = math.pi * 7.85
    # Convert encoder ticks to cm: (ticks / 1200 rev) * pi * diameter
    left_enc = _left_encoder_extender.unwrap_encoder(_bytes_to_s16(data[0xe:0xe+2]))
    results[_rc.WW_SENSOR_ENCODER_LEFT_WHEEL] = {
        _rcv.WW_SENSOR_VALUE_DISTANCE: float(left_enc) * WHEEL_CIRCUMFERENCE_CM / 1200.0,
    }
    right_enc = _right_encoder_extender.unwrap_encoder(_bytes_to_s16(data[0x10:0x10+2]))
    results[_rc.WW_SENSOR_ENCODER_RIGHT_WHEEL] = {
        _rcv.WW_SENSOR_VALUE_DISTANCE: float(right_enc) * WHEEL_CIRCUMFERENCE_CM / 1200.0,
    }

    HEAD_ANGLE_SCALE = 360.0 / 6.283185307179586 / 100.0
    # Use last bit of data[12] as msb 
    pan_tmp = 0xf if (data[0x12] & 1) else 0
    results[_rc.WW_SENSOR_HEAD_POSITION_PAN] = {
        _rcv.WW_SENSOR_VALUE_ANGLE_DEGREE: _decode_12bit_pose_int(pan_tmp, data[0x13]) * HEAD_ANGLE_SCALE
    }
    
    tilt_tmp = struct.unpack('<b',data[0x12:0x13])[0] >> 1 
    results[_rc.WW_SENSOR_HEAD_POSITION_TILT] = {
        _rcv.WW_SENSOR_VALUE_ANGLE_DEGREE: tilt_tmp * HEAD_ANGLE_SCALE * -1.0
    }

    # Guess at decoding watermark info?
    event1_type = packet1_data[0x13]
    event1_data = packet1_data[0x10]
    event2_type = packet1_data[0xf]
    event2_data = packet1_data[0xc]
    watermark = 0
    add_watermark = False
    if event1_type == 1:
        add_watermark = True
        watermark = event1_data
    elif event2_type == 1:
        add_watermark = True
        watermark = event2_data

    pose_x_encoded = _decode_12bit_pose_int(data[9], data[10], True)
    pose_y_encoded = _decode_12bit_pose_int(data[9], data[11])
    pose_theta_encoded = _bytes_to_s16(data[12:14])

    results[_rc.WW_SENSOR_BODY_POSE] = {
        _rcv.WW_SENSOR_VALUE_AXIS_X: pose_x_encoded / 10.0,
        _rcv.WW_SENSOR_VALUE_AXIS_Y: pose_y_encoded / 10.0,
        _rcv.WW_SENSOR_VALUE_ANGLE_DEGREE: math.degrees(pose_theta_encoded / 1000.0),
    }
    if add_watermark:
        results[_rc.WW_SENSOR_BODY_POSE][_rcv.WW_SENSOR_VALUE_POSE_WATERMARK] = watermark

    return results

def _encode_pose(args: dict[str, Any]) -> bytes:
    """
    Command robot to alter its pose

    NOTE: Original library tracks quantization error and tries to compensate on
    subsequent commands. This isn't implemented here for simplicity.

    Encoding format: - X, Y: 14-bit signed integers (scaled by 10) - Theta:
    12-bit signed integer (scaled by 100) - Time: 16-bit unsigned integer
    (milliseconds) - Mode, direction, wrap_theta, ease: packed control flags
    """

    packet_id = 0x23

    try:
        # Scale and round values
        POS_SCALE = 10.0
        x = _check_range(args[_rcv.WW_COMMAND_VALUE_AXIS_X], -8192 / POS_SCALE, 8191 / POS_SCALE,'pose_cmd_x')
        x_encoded = int(round(x * POS_SCALE))
        y = _check_range(args[_rcv.WW_COMMAND_VALUE_AXIS_Y], -8192 / POS_SCALE, 8191 / POS_SCALE,'pose_cmd_y')
        y_encoded = int(round(y * POS_SCALE))
        
        THETA_SCALE = math.pi / 180.0 * 100.0
        theta = _check_range(args[_rcv.WW_COMMAND_VALUE_ANGLE_DEGREE], -2048 / THETA_SCALE, 2047 / THETA_SCALE,'pose_cmd_degrees')
        theta_scaled = theta * THETA_SCALE
        theta_encoded = int(round(theta_scaled))
        
        TIME_SCALE = 1000.0
        time_cmd = _check_range(args[_rcv.WW_COMMAND_VALUE_TIME], 0, 65535 / TIME_SCALE, 'pose_cmd_time')
        time_ms = int(round(time_cmd * TIME_SCALE))
    except ValueError as e:
        print(e)
        return bytes()
    
    ease = args[_rcv.WW_COMMAND_VALUE_POSE_EASE]
    mode = args[_rcv.WW_COMMAND_VALUE_POSE_MODE]
    wrap_theta = args[_rcv.WW_COMMAND_VALUE_POSE_WRAP_THETA]
    direction = args[_rcv.WW_COMMAND_VALUE_POSE_DIRECTION]

    # Handle mode 5 -> 3 conversion
    mode = 3 if mode == 5 else (int(mode) & 0x03)

    if mode == WWRobotConstants.WWPoseMode.WW_POSE_MODE_SET_GLOBAL:
        raise NotImplementedError('Setting global origin position not implemented.')

    # Pack into bytes
    return struct.pack(
        'BBBBBBBBB',
        packet_id,
        x_encoded & 0xFF,                               # Byte 1: X low byte
        y_encoded & 0xFF,                               # Byte 2: Y low byte
        theta_encoded & 0xFF,                           # Byte 3: Theta low byte
        (time_ms >> 8) & 0xFF,                         # Byte 4: Time high byte
        time_ms & 0xFF,                                 # Byte 5: Time low byte
        ((x_encoded >> 8) & 0x3F) | ((theta_encoded >> 2) & 0xC0),  # Byte 6
        ((y_encoded >> 8) & 0x3F) | ((theta_encoded >> 4) & 0xC0),  # Byte 7
        (mode << 6) | ((int(ease) & 0x01) << 5) | 
        ((int(wrap_theta) & 0x01) << 4) | (int(direction) & 0x0F)  # Byte 8
    )


    # def eye(self, value):
    #     """
    #     Turn on and off the Iris LEDs. There are 12 of them. Top one is the
    #     first and they are incremeted clockwise.

    #     Light bottom LED
    #     >>> bot.eye(1<<6)

    #     Light alternate LEDs
    #     >>> bot.eye(0b1010101010101)

    #     light all LEDs
    #     >>> bot.eye(8191)

    #     :param value: bitmask to which light to light up 0-8191
    #     """
    #     self.command("eye", two_byte_array(value))

    # def eye_brightness(self, value):
    #     """
    #     Set brightness of the eye backlight.

    #     :param value: Brightness value 0-255
    #     """
    #     self.command("eye_brightness", one_byte_array(value))

def _encode_speaker(args: dict[str, Any]) -> bytes:
    file_name = args[_rcv.WW_COMMAND_VALUE_FILE]

    if len(file_name) > 15 or len(file_name) == 0:
        print('Invalid sound name.')
        file_name = _rcv.WW_COMMAND_VALUE_STOP_SOUND
    
    if file_name == _rcv.WW_COMMAND_VALUE_STOP_SOUND:
        return b'\x1a'
    else:
        return b'\x18' + file_name.encode('ascii')
    
MAX_PACKET_LEN = 20

def encode_cmd(dict_data: dict[str, Any]) -> list[bytes]:
    packets = []
    for key, val in dict_data.items():
        if key not in _CMD_NAME_DICT:
            raise ValueError(f'Invalid command key: {key}')
        
        msg_bytes:list[bytes] = []
        if key == _rc.WW_COMMAND_BODY_POSE:
            msg_bytes.append(_encode_pose(val))
        elif key == _rc.WW_COMMAND_LIGHT_RGB_EYE:
            # Haven't double checked this ID
            msg_bytes.append(b'\x0a' + _color_byte_array(val))
        elif key == _rc.WW_COMMAND_LIGHT_RGB_LEFT_EAR:
            msg_bytes.append(b'\x0b' + _color_byte_array(val))
        elif key == _rc.WW_COMMAND_LIGHT_RGB_RIGHT_EAR:
            msg_bytes.append(b'\x0c' + _color_byte_array(val))
        elif key == _rc.WW_COMMAND_LIGHT_RGB_CHEST:
            msg_bytes.append(b'\x03' + _color_byte_array(val))
        elif key == _rc.WW_COMMAND_LIGHT_RGB_BUTTON_MAIN:
            msg_bytes.append(b'\x0d' + _color_byte_array(val))
        elif key == _rc.WW_COMMAND_SPEAKER:
            # what is expected range? In dylib its multiplied by 100 then truncated to 8 bits
            volume = int(_clamp(val[_rcv.WW_COMMAND_VALUE_SOUND_VOLUME], 0, 2.5) * 100.0)
            msg_bytes.append(b'\x0e' + bytes([volume]))
            msg_bytes.append(_encode_speaker(val))
        elif key == _rc.WW_COMMAND_POWER:
            # Must be u8 value. Only known function is 4=soft_reset
            msg_bytes.append(b'\xc8' + bytes([val]))
        elif key == _rc.WW_COMMAND_LIGHT_MONO_TAIL:
            msg_bytes.append(b'\x04' + _mono_single_byte(val))
        elif key == _rc.WW_COMMAND_LIGHT_MONO_BUTTON_MAIN:
            msg_bytes.append(b'\x0d' + _mono_single_byte(val))
        elif key == _rc.WW_COMMAND_LIGHT_MONO_BUTTON_1:
            msg_bytes.append(b'3' + _mono_single_byte(val))
        elif key == _rc.WW_COMMAND_LIGHT_MONO_BUTTON_2:
            msg_bytes.append(b'4' + _mono_single_byte(val))
        elif key == _rc.WW_COMMAND_LIGHT_MONO_BUTTON_3:
            msg_bytes.append(b'5' + _mono_single_byte(val))
        elif key == _rc.WW_COMMAND_LIGHT_MONO_BUTTONS:
            msg_bytes.append(b'1' + _mono_byte_array(val))
        elif key == _rc.WW_COMMAND_HEAD_POSITION_TILT:
            # Should limit servo as follows:
            # (1003)"Dot":  −24°to+13°
            # (1001)"Dash": −24°to+7°
            msg_bytes.append(b'\x07' + _servo_angle_bytes(val, -24, 7))
        elif key == _rc.WW_COMMAND_HEAD_POSITION_PAN:
            # Should limit servo as follows:
            # (1003)"Dot":  −133°to+133°
            # (1001)"Dash": −120°to+120°
            msg_bytes.append(b'\x06' + _servo_angle_bytes(val, -120, 120))
        elif key in {_rc.WW_COMMAND_BODY_WHEELS, _rc.WW_COMMAND_BODY_COAST, _rc.WW_COMMAND_BODY_LINEAR_ANGULAR,
                     _rc.WW_COMMAND_EYE_RING, _rc.WW_COMMAND_HEAD_PAN_VOLTAGE, _rc.WW_COMMAND_HEAD_TILT_VOLTAGE,
                      _rc.WW_COMMAND_LAUNCHER_FLING, _rc.WW_COMMAND_LAUNCHER_RELOAD, _rc.WW_COMMAND_LED_MESSAGE,
                      _rc.WW_COMMAND_SET_PING,_rc.WW_COMMAND_POWER, _rc.WW_COMMAND_ON_ROBOT_ANIM, 
                      _rc.WW_COMMAND_MOTOR_HEAD_BANG}:
            raise NotImplementedError(f'Command {_CMD_NAME_DICT[key]} not yet implemented.')
        else:
            raise NotImplementedError(f'Command {_CMD_NAME_DICT[key]} not yet implemented.')
        
        for msg in msg_bytes:
            fit = False
            for i, packet in enumerate(packets):
                if len(packet) + len(msg) < MAX_PACKET_LEN:
                    packets[i] = packet + msg
                    fit = True

            if not fit:
                packets.append(msg)
        
    return packets
