from WonderPy.core.wwConstants import WWRobotConstants
from .wwCommandBase import WWCommandBase

_rc  = WWRobotConstants.RobotComponent
_rcv = WWRobotConstants.RobotComponentValues


class WWCommandMonoLED(WWCommandBase):

    def __init__(self, robot):
        super().__init__(robot)

    def stage_button_main(self, brightness):
        self._robot.stage_cmds(self.compose_button_main(brightness))

    def compose_button_main(self, brightness):
        return {_rc.WW_COMMAND_LIGHT_MONO_BUTTON_MAIN: self._compose_val_brightness(brightness)}

    def _compose_val_brightness(self, brightness):
        return {
            _rcv.WW_COMMAND_VALUE_COLOR_BRIGHTNESS: brightness,
        }

    def stage_3_button_brightness(self, brightness1, brightness2, brightness3):
        self._robot.stage_cmds(self.compose_3_button_brightness(self, brightness1, brightness2, brightness3))

    def compose_3_button_brightness(self, brightness1, brightness2, brightness3):
        return {
            _rc.WW_COMMAND_LIGHT_MONO_BUTTONS: {
                _rcv.WW_COMMAND_VALUE_1: brightness1,
                _rcv.WW_COMMAND_VALUE_1: brightness2,
                _rcv.WW_COMMAND_VALUE_1: brightness3,
            }
        }

