from WonderPy.core.wwConstants import WWRobotConstants
from .wwSensorBase import WWSensorBase

_rcv = WWRobotConstants.RobotComponentValues


class WWSensorFlag(WWSensorBase):
    """Generic sensor component for boolean flags (e.g. picked_up, bump_stall)"""

    def __init__(self, robot):
        super().__init__(robot)
        self._value = False

    @property
    def value(self):
        return self._value

    def _important_field_names(self):
        return ('value',)

    def parse(self, single_component_dictionary):
        if not single_component_dictionary:
            self._valid = False
            return

        self._value = bool(single_component_dictionary.get(_rcv.WW_SENSOR_VALUE_FLAG, False))
        self._valid = True
