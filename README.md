# Unofficial WonderPy Port

See <https://github.com/playi/WonderPy/blob/master/README.md> for the original documentation.

This is an unofficial port that reverse engineers the JSON to binary protocol. 

See: <https://www.robopenguins.com/reverse-dash/> for a blog post of my approach 

See: [ReversingDylib.md](doc/reversing/ReversingDylib.md) for reverse engineering notes.

For the supported commands and sensors, the interface should be exactly the same as with the original library.

I'm only testing on a Dash, so it's likely that some features will not work properly for other bots without some tweaking.

# Setup
## Prerequisites
1. Python 3.9+
2. Familiarity with python and the command-line

## pip

See the original instructions for setting up a virtual environment if desired.

```sh
pip install -r requirements.txt
pip install .
```

## uv

You can use <https://docs.astral.sh/uv/> with this library

```sh
uv sync
```

# Known Issues
 - The manufacturer info reported by the BlueTooth client does not have the bytes the original library expected for a Dash robot. It's unclear if this has to do with switching the underlying BlueTooth stack, or is a change in the BlueTooth interface the bot's used after this Python library was made. **Currently the hardware type is hard coded to be a Dash bot**
 - Sometimes the initial connection after Linux restarts fails. I'm not sure if this is a timeout or what. Retrying succeeds.
 - Many of the commands and sensors haven't been implemented. Some of these are due to specific issues, but mostly these are due to a lack of time to reverse engineer them all. See the list below.

## Feature Status

Commands
 - pose ✅ Mostly working. Didn't implement some logic for resetting global origin. May have some issues with accumulating error around relative angle commands.
 - RGB Lights ✅
 - Speaker ❔ Same functionality as original library. This does not include uploading custom sounds
 - Power ❔ Implemented, but didn't experiment with values
 - Head Pan/Tilt ❔ Only implemented position commands
 - Eye Ring Lights/Animation 🛑 Didn't attempt, but should be doable
 - Launcher 🛑 Didn't attempt, but should be doable
 - Low Level Wheel Control 🛑 Didn't attempt, but should be doable
 - Robot Animation 🛑 Didn't attempt, but should be doable

Sensors
 - Buttons ✅
 - Head Pan/Tilt ✅
 - Pose ✅ This includes the "watermark" to determine how many movement commands are queued
 - Accelerometer ✅
 - Gyro ✅
 - Distance Sensors ❔ The raw values are captured, but the original library used the dylib to convert the values to distance in cm. This would be fairly complicated to extract, and would probably be better done from scratch.
 - Wheel Encoders ✅
 - Picked Up ✅
 - Bump Stall ✅
 - Sound Playing ✅
 - Animation Playing ✅
 - Microphone ❔ I made an attempt at reversing this from the dylib. The amplitude and direction sort of worked, but not the confidence. Also, this value isn't actually surfaced in the API.
 - Battery 🛑 Didn't attempt, is complicated by device specific variations
 - Beacons 🛑 Didn't attempt, is complicated by device specific variations

The original Python library had many features that were referenced, but not fully implemented. Other features were reference in the dylib, but not the Python code. The remaining functionality could probably be found by spying on the BlueTooth traffic, but I'm not planning to look into that.
