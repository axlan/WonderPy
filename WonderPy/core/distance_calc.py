import math

class DoubleExponentialDistanceCalc:
    """
    This is a very rough computation of distance based on empirical observation of the Dash's rear sensor.

    For better results, measure and fit a function based on observations in the desired environment.
    See doc/distance_data.ipynb
    """
    A1=48.7536
    tau1=6.19267
    A2=16.9606
    tau2=54.453
    offset=6.05125

    # When reflectance is below this value report max distance.
    MIN_REFLECTANCE = 10.0
    # Distance reported when reflectance is low.
    MAX_DISTANCE = 100.0

    @classmethod
    def reflect_to_distance_cm(cls, reflectance: float):
        if reflectance < cls.MIN_REFLECTANCE:
            return cls.MAX_DISTANCE
        return cls.A1 * math.exp(-reflectance / cls.tau1) + cls.A2 * math.exp(-reflectance / cls.tau2) + cls.offset
