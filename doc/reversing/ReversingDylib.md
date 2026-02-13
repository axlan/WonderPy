# Parsing JSON Commands

| json ID | WW_COMMAND | Parse Function | Storage Type | Flags Set |
|---|---|---|---|---|
| `1` | `POWER` | `parsePower` | `HALPower_t` | `0x8000` |
| `100` | `EYE_RING` | `parseEyeRing` | `HALEyeRing_t` | `0x100` or `0x80000000000` (brightness mode 0 or 1) + `0x200` or `0x400` (frame `0xffff` or not) |
| `101` | `LIGHT_RGB_EYE` | `parseLightRGB` | `HALRGB_t` | `0x8` |
| `102` | `LIGHT_RGB_LEFT_EAR` | `parseLightRGB` | `HALRGB_t` | `0x800` |
| `103` | `LIGHT_RGB_RIGHT_EAR` | `parseLightRGB` | `HALRGB_t` | `0x1000` |
| `104` | `LIGHT_RGB_CHEST` | `parseLightRGB` | `HALRGB_t` | `0x8` *(shares 101 path)* |
| `105` | `LIGHT_MONO_TAIL` | `parseLightLED` | `HALLED_t` | `0x10` |
| `106` | `LIGHT_MONO_BUTTON_MAIN` | `parseLightLED` | `HALLED_t` | `0x2000` |
| `107` | `LIGHT_RGB_BUTTON_MAIN` | `parseLightRGB` | `HALRGB_t` | `0x40000000000` |
| `108` | `LIGHT_MONO_BUTTONS` | `parseLightLED3` | `HALLED3_t` | `0x100000000000` |
| `109` | `LIGHT_MONO_BUTTON_1` | `parseLightLED` | `HALLED_t` | `0x200000000000` |
| `110` | `LIGHT_MONO_BUTTON_2` | `parseLightLED` | `HALLED_t` | `0x400000000000` |
| `111` | `LIGHT_MONO_BUTTON_3` | `parseLightLED` | `HALLED_t` | `0x800000000000` |
| `200` | *(unmapped)* | `parseMotorWheel` | `HALMotorWheel_t` | `0x1` |
| `201` | *(unmapped)* | `parseMotorWheel` | `HALMotorWheel_t` | `0x2` |
| `202` | `HEAD_POSITION_TILT` | `parseMotorHeadTiltServo` | `HALMotorServo_t` | `0x80` |
| `203` | `HEAD_POSITION_PAN` | `parseMotorHeadPanServo` | `HALMotorServo_t` | `0x40` |
| `204` | `BODY_LINEAR_ANGULAR` | `parseBodyMotionLinearAngular` |`HALBodyMotionLinearAngular_t` | `0x4` |
| `205` | `BODY_POSE` | `parseBodyPose` | `HALBodyPose_t` | `0x20000` |
| `206` | *(unmapped)* | `parseMotorHeadTiltServo` | `HALMotorServo_t` | `0x40000` |
| `207` | *(unmapped)* | `parseMotorHeadPanServo` | `HALMotorServo_t` | `0x100000` |
| `208` | *(unmapped)* | `parseMotorHeadTiltServo` | `HALMotorServo_t` | `0x80000` |
| `209` | *(unmapped)* | `parseMotorHeadPanServo` | `HALMotorServo_t` | `0x200000` |
| `210` | `MOTOR_HEAD_BANG` | `parseNoParams` | `HALNoParams_t` | `0x400000` |
| `211` | `BODY_WHEELS` | `parseBodyWheels` | `HALMotorWheel_t * (×2, IDs  `0x1` + `0x2` (both wheel flags) |200 & 201)` |
| `212` | `BODY_COAST` | `parseNoParams` | `HALNoParams_t` | `0x80000000` |
| `213` | `HEAD_PAN_VOLTAGE` | `parseScalarPercentage` | `HALComponentScalar_t` | `0x2000000000000` |
| `214` | `HEAD_TILT_VOLTAGE` | `parseScalarPercentage` | `HALComponentScalar_t` | `0x4000000000000` |
| `300` | `SPEAKER` | `parseSpeaker` | `HALSpeaker_t` | `0x800000` (if filename set) + `0x4000` (if volume < 101) |
| `301` | `ON_ROBOT_ANIM` | `parseOnRobotAnim` | `HALAnim_t` | `0x4000000000` (stop) or `0x2000000000` (play) |
| `304` | *(unmapped)* | `parseAudioSynth` | `HALAudioSynth_t` | `0x200000000` |
| `400` | `LAUNCHER_FLING` | `parseLauncher` | `HALLauncher_t` | `0x800000000` |
| `401` | `LAUNCHER_RELOAD` | `parseLauncher` | `HALLauncher_t` | `0x1000000000` |
| `410` | `LED_MESSAGE` | `parseLedMsg` | `HALLedMsg_t` | `0x8000000000000` |
| `450` | *(unmapped)* | `parsePamplemousseStart` | `HALPamplemousse_t` | `0x10000000000` |
| `451` | *(unmapped)* | `parsePamplemousseStop` | `HALPamplemousse_t` | `0x20000000000` |
| `5000` | *(unmapped)* | `parseUserSettings` | `HALUserSetting_t` | `0x2000000` (name set) or one of: `0x10000000` (color+anim), `0x4000000` (color only), `0x8000000` (anim only), `0x1000000000000` (eye color), `0x400000000` (volume), `0x100000000` (default) |
| `6001` | *(unmapped)* | *(unmapped)* | *(unmapped)* | `0x20000000` |
| `6002` | *(unmapped)* | *(unmapped)* | *(unmapped)* | `0x40000000` |
| `9000` | `SET_PING` | `parsePing` | `HALPing_t` | `0x8000000000` |

**Notes:**
- The *(unmapped)* entries have no corresponding reference in the original Python library.
- **(101) and (104)** both fall into the same branch setting `0x8` since referenced lights are mutually exclusive between dot/dash
- **(211) `BODY_WHEELS`** sets both wheel flags `0x1` and `0x2` simultaneously, consistent with commanding both wheels together.
- **`300` `SPEAKER`** flag logic: `0x800000` is conditional on a filename being present, and `0x4000` is conditional on volume being below 101 — both can be set together.
- **`5000`** has the most complex flag logic, with 6 mutually exclusive flag paths depending on which user setting fields are populated.

This table was made by combining the Python `RobotComponent` constants with the decompiled WonderPy/lib/WonderWorkshop/osx/libWWHAL.dylib .

The parse function and storage type come from the `convertCtlrMessageToPackets` function, and the flags (which map to binary packets sent to the robot) come from `setCommand`.

## Storing JSON Command Arguments

See [json_cmd_defs.h](json_cmd_defs.h) for the structures the JSON commands are stored as. These were determined from the referenced functions. These were determined from the [](parse_functions.c)

## Encoding JSON as Binary

The values in this and the definitions can then be applied to [packetizeCtlr2BotMsg.c](packetizeCtlr2BotMsg.c) to get the binary packet structure to generate from the JSON in [packet_data_converter.py](../../WonderPy/core/packet_data_converter.py)
