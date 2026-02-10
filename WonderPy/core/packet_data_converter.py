from dataclasses import dataclass
from typing import Any

from .wwConstants import WWRobotConstants

@dataclass
class DotSensorData:
    index: int = 0
    pitch: int = 0
    roll: int = 0
    acceleration: int = 0
    button0: bool = False
    button1: bool = False
    button2: bool = False
    button3: bool = False


@dataclass
class DashSensorData:
    index: int = 0
    pitch_delta: int = 0
    roll_delta: int = 0
    prox_right: int = 0
    prox_left: int = 0
    prox_rear: int = 0
    yaw: int = 0
    left_wheel: int = 0
    right_wheel: int = 0
    head_pitch: int = 0
    head_yaw: int = 0
    wheel_distance: int = 0


def _to_int(value, bits):
    if value > ((1<<(bits-1))-1):
        return  value - (1<<bits)
    else:
        return value

    

def dot_sensor_decode(value: bytes) -> dict[str, Any]:
    results = {}
    # sensor_data = DotSensorData()

    # sensor_data.index = value[0] >> 4
    # sensor_data.pitch=_to_int(
    #     (value[4] & 0xf0) << 4 | value[2],
    #     12)
    # sensor_data.pitch = _to_int(
    #     (value[4] & 0xf0) << 4 | value[2],
    #     12
    # )
    # sensor_data.roll = _to_int(
    #     (value[4] & 0xf) << 8 | value[3],
    #     12
    # )
    # sensor_data.acceleration = _to_int(
    #     (value[5] & 0xf0) << 4 | value[6],
    #     12
    # )
    # sensor_data.button0 = value[8] & 0x10 > 0
    # sensor_data.button1 = value[8] & 0x20 > 0
    # sensor_data.button2 = value[8] & 0x40 > 0
    # sensor_data.button3 = value[8] & 0x80 > 0

    results[WWRobotConstants.RobotComponent.WW_SENSOR_BUTTON_MAIN] = {
        WWRobotConstants.RobotComponentValues.WW_SENSOR_VALUE_BUTTON_STATE: value[8] & 0x10 > 0
    }
    results[WWRobotConstants.RobotComponent.WW_SENSOR_BUTTON_1] = {
        WWRobotConstants.RobotComponentValues.WW_SENSOR_VALUE_BUTTON_STATE: value[8] & 0x20 > 0
    }
    results[WWRobotConstants.RobotComponent.WW_SENSOR_BUTTON_2] = {
        WWRobotConstants.RobotComponentValues.WW_SENSOR_VALUE_BUTTON_STATE: value[8] & 0x40 > 0
    }
    results[WWRobotConstants.RobotComponent.WW_SENSOR_BUTTON_3] = {
        WWRobotConstants.RobotComponentValues.WW_SENSOR_VALUE_BUTTON_STATE: value[8] & 0x80 > 0
    }


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


def dash_sensor_decode(data: bytes) -> dict[str, Any]:
    # sensor_data = DashSensorData()

    # sensor_data.index = data[0] >> 4
    # sensor_data.pitch_delta = _to_int(
    #     (data[4] & 0x30) << 4 | data[3],
    #     10
    # )
    # sensor_data.roll_delta = _to_int(
    #     (data[4] & 0x3) << 8 | data[5],
    #     10
    # )
    # sensor_data.prox_right = data[6]
    # sensor_data.prox_left = data[7]
    # sensor_data.prox_rear = data[8]
    # sensor_data.yaw = _to_int((data[13] << 8) | data[12], 12)
    # sensor_data.left_wheel = (data[15] << 8) | data[14]
    # sensor_data.right_wheel = (data[17] << 8) | data[16]
    # sensor_data.head_pitch = data[18]
    # sensor_data.head_yaw = data[19]
    # sensor_data.wheel_distance = _to_int(
    #     (data[9] & 0xf) << 12 | data[11] << 8 | data[10],
    #     16
    # )
    return {}
