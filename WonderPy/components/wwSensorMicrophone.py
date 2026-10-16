from WonderPy.components.wwSensorBase import WWSensorBase
from WonderPy.core.wwConstants import WWRobotConstants

_rcv = WWRobotConstants.RobotComponentValues


class WWSensorMicrophone(WWSensorBase):
    """
    Sensor component representing Dash's 3-microphone array telemetry:
    - clap_detected: True if sudden clap/transient acoustic shock is detected
    - amplitude: Microphone audio level [0.0 - 1.0]
    - triangulation_angle: Angle in radians towards sound source
    - triangulation_confidence: Confidence score of sound source localization
    """

    def __init__(self, robot):
        super().__init__(robot)
        self._amplitude = 0.0
        self._triangulation_confidence = 0
        self._triangulation_angle = 0.0
        self._clap_detected = False

    def _important_field_names(self):
        return ('amplitude', 'clap_detected', 'triangulation_angle', 'triangulation_confidence')

    @property
    def amplitude(self):
        return self._amplitude

    @property
    def clap_detected(self):
        return self._clap_detected

    @property
    def triangulation_angle(self):
        return self._triangulation_angle

    @property
    def triangulation_confidence(self):
        return self._triangulation_confidence

    def parse(self, single_component_dictionary):
        if not single_component_dictionary:
            self._valid = False
            return

        self._amplitude = single_component_dictionary.get(_rcv.WW_SENSOR_VALUE_MIC_AMPLITUDE, 0.0)
        self._triangulation_confidence = single_component_dictionary.get(_rcv.WW_SENSOR_VALUE_MIC_TRIANGULATION_CONF, 0)
        self._triangulation_angle = single_component_dictionary.get(_rcv.WW_SENSOR_VALUE_MIC_TRIANGULATION_ANGLE, 0.0)
        self._clap_detected = single_component_dictionary.get(_rcv.WW_SENSOR_VALUE_MIC_CLAP_DETECTED, False)
        self._valid = True
