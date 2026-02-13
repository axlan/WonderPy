from WonderPy.core.wwConstants import WWRobotConstants
from .wwCommandBase import WWCommandBase

_rc  = WWRobotConstants.RobotComponent
_rcv = WWRobotConstants.RobotComponentValues


class wwCommandNew(WWCommandBase):

    def __init__(self, robot):
        super().__init__(robot)

    def stage_power(self, power_action: int):
        self._robot.stage_cmds(self.compose_power(power_action))

    def compose_power(self, power_action: int):
        ret = {
            _rc.WW_COMMAND_POWER : {
                power_action
            }
        }
        return ret
