from time import sleep

import matplotlib.pyplot as plt
import random

KP = .1
KI = .15
KD = .2


def pid():
    outputs = []
    measureds = []
    noises = []
    noise_percentage = 10

    previous_error = 0
    integral = 0
    output = 0

    desired_value = 55
    dt = 0.5

    loops = 0

    accepted_error = 0.005
    error = 1000000

    counter = 0

    while True:
        loops += 1
        error = desired_value - output
        integral = integral + error
        derivative = error - previous_error
        output = KP * error + KI * integral + KD * derivative
        measureds.append(output)
        noise = (random.randrange(0, 1000, 1) / 1000) * ((noise_percentage / 100) * desired_value)
        noises.append(noise)
        output += noise
        outputs.append(output)
        previous_error = error
        if error < accepted_error:
            counter += 1
            if counter > 100:
                break


    # print(loops)
    # plt.figure(1)
    # plt.plot(range(len(outputs)), outputs)
    # plt.plot(range(len(outputs)), [desired_value] * len(outputs))
    # plt.figure(1)
    # plt.plot(range(len(outputs)), measureds)
    # plt.figure(2)
    # plt.plot(range(len(outputs)), noises)
    # plt.show()
    return outputs


if __name__ == "__main__":
    pid()
