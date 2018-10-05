import random


class PID:
    """PID

        Class used to simulate PID controller.
    """
    def __init__(self):
        """Constructor

        """
        self.outputs = []
        self.measureds = []
        self.noises = []
        self.__max_steps__ = 10000

    def start(self, KP, KI, KD, initial_value, target_value, error, noise=0, extra_plots=250):
        """start

        :param KP: proportional gain
        :type KP: float
        :param KI: integral gain
        :type KI: float
        :param KD: derivative gain
        :type KD: float
        :param initial_value: starting value
        :type initial_value: float
        :param target_value: desired value
        :type target_value: float
        :param error: target value accepted error percentage
        :type error: float
        :param noise: noise percentage level
        :type noise: float
        :param extra_plots: number of plots after error overcome
        :type extra_plots: int
        :return: simulation result
        :rtype: bool
        """
        self.outputs = []
        self.measureds = []
        self.noises = []

        try:

            plots = 0
            accepted_error_value = (error / 100) * target_value

            integral = 0
            previous_error = 0
            output = initial_value
            self.outputs.append(output)

            steps = 0
            while True:

                steps += 1
                if steps > self.__max_steps__:
                    print("Maximum steps of {} overcome!".format(self.__max_steps__))
                    return False

                error = target_value - output
                integral = integral + error
                derivative = error - previous_error

                output = KP * error + KI * integral + KD * derivative
                self.measureds.append(output)

                noise = ((random.randrange(0, 1000, 1) - 500) / 500) * ((noise / 100) * (abs(target_value - initial_value)))
                self.noises.append(noise)
                output += noise

                self.outputs.append(output)
                previous_error = error

                if error < accepted_error_value:
                    plots += 1
                    if plots > extra_plots:
                        break

            return True

        except Exception as err:
            print("Error on PID simulation! {}".format(err))
            return False
