import sys

from PyQt5.QtWidgets import QApplication, QMainWindow, QMenu, QVBoxLayout, QSizePolicy, QMessageBox, QWidget, \
    QPushButton, QDesktopWidget, QLineEdit

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
from core import PID
import matplotlib.pyplot as plt
from pid import pid

import random


class App(QMainWindow):

    def __init__(self):
        super().__init__()
        self.left = 10
        self.top = 10
        self.title = 'PID vs Fuzzy'
        self.width = 1100
        self.height = 800
        self.pid_simulator = PID()
        self.init_ui()

    def init_ui(self):

        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        self.plotter = PlotCanvas(self, width=5, height=4)
        self.plotter.move(0, 0)

        button = QPushButton('Start', self)
        button.setToolTip('Start')
        button.move(1000, 0)
        button.resize(80, 40)
        button.clicked.connect(self.plot)
        self.__load_widgets__()

        self.centre()
        self.show()

    def __load_widgets__(self):
        """__load_widgets__

            Load GUI's widgets.
        :return: None
        """
        self.__lw_kp_entry__()
        self.__lw_ki_entry__()
        self.__lw_kd_entry__()
        self.__lw_initial_value_entry__()
        self.__lw_target_value_entry__()
        self.__lw_error_entry__()
        self.__lw_noise_entry__()

    def __lw_kp_entry__(self):
        """__lw_kp_entry__

            Load line edit entry used to set kp.
        :return: None
        """
        x = 1000
        y = 90
        self.kp_entry = QLineEdit(self)
        self.kp_entry.setToolTip("Proportional gain")
        self.kp_entry.setText('0.03')
        self.kp_entry.move(x, y)
        self.kp_entry.resize(40, 20)
        self.kp_entry.show()

    def __lw_ki_entry__(self):
        """__lw_ki_entry__

            Load line edit entry used to set ki.
        :return: None
        """
        x = 1000
        y = 120
        self.ki_entry = QLineEdit(self)
        self.ki_entry.setToolTip("Integral gain")
        self.ki_entry.setText('0.03')
        self.ki_entry.move(x, y)
        self.ki_entry.resize(40, 20)
        self.ki_entry.show()

    def __lw_kd_entry__(self):
        """__lw_kd_entry__

            Load line edit entry used to set kd.
        :return: None
        """
        x = 1000
        y = 150
        self.kd_entry = QLineEdit(self)
        self.kd_entry.setToolTip("Derivative gain")
        self.kd_entry.setText('0.03')
        self.kd_entry.move(x, y)
        self.kd_entry.resize(40, 20)
        self.kd_entry.show()

    def __lw_initial_value_entry__(self):
        """__lw_initial_value_entry__

            Load line edit entry used to set initial_value.
        :return: None
        """
        x = 1000
        y = 180
        self.initial_value_entry = QLineEdit(self)
        self.initial_value_entry.setToolTip("Initial value")
        self.initial_value_entry.setText('0')
        self.initial_value_entry.move(x, y)
        self.initial_value_entry.resize(40, 20)
        self.initial_value_entry.show()

    def __lw_target_value_entry__(self):
        """__lw_target_value_entry__

            Load line edit entry used to set target_value.
        :return: None
        """
        x = 1000
        y = 210
        self.target_value_entry = QLineEdit(self)
        self.target_value_entry.setToolTip("Desired value")
        self.target_value_entry.setText('100')
        self.target_value_entry.move(x, y)
        self.target_value_entry.resize(40, 20)
        self.target_value_entry.show()

    def __lw_error_entry__(self):
        """__lw_error_entry__

            Load line edit entry used to set error.
        :return: None
        """
        x = 1000
        y = 240
        self.error_entry = QLineEdit(self)
        self.error_entry.setToolTip("Accepted error [%]")
        self.error_entry.setText('2')
        self.error_entry.move(x, y)
        self.error_entry.resize(40, 20)
        self.error_entry.show()

    def __lw_noise_entry__(self):
        """__lw_noise_entry__

            Load line edit entry used to set noise.
        :return: None
        """
        x = 1000
        y = 270
        self.noise_entry = QLineEdit(self)
        self.noise_entry.setToolTip("Noise level [%]")
        self.noise_entry.setText('5')
        self.noise_entry.move(x, y)
        self.noise_entry.resize(40, 20)
        self.noise_entry.show()

    def centre(self):
        """
        Center the window on screen. This implementation will handle the window
        being resized or the screen resolution changing.
        """
        # Get the current screens' dimensions...
        screen = QDesktopWidget().screenGeometry()
        # ... and get this windows' dimensions
        app_dimensions = self.geometry()
        # The horizontal position is calculated as screenwidth - window's width /2
        h_pos = (screen.width() - app_dimensions.width()) / 2
        # And vertical position the same, but with the height dimensions
        v_pos = (screen.height() - app_dimensions.height()) / 2
        # And the move call repositions the window
        self.move(h_pos, v_pos)

    def plot(self):
        """

        :return:
        """
        try:
            kp = float(self.kp_entry.text())
            ki = float(self.ki_entry.text())
            kd = float(self.kd_entry.text())
            iv = float(self.initial_value_entry.text())
            tv = float(self.target_value_entry.text())
            error = float(self.error_entry.text())
            noise = float(self.noise_entry.text())
            result = self.pid_simulator.start(kp, ki, kd, iv, tv, error, noise)
            if result:
                # plt.figure(1)
                # plt.plot(range(len(self.pid_simulator.outputs)), self.pid_simulator.outputs)
                # plt.figure(1)
                # plt.plot(range(len(self.pid_simulator.measureds)), self.pid_simulator.measureds)
                # plt.figure(2)
                # plt.plot(range(len(self.pid_simulator.noises)), self.pid_simulator.noises)
                # plt.show()
                self.plotter.plot(self.pid_simulator.outputs, tv)
        except Exception as err:
            print("Simulation error: {}!".format(err))


class PlotCanvas(FigureCanvas):

    def __init__(self, parent=None, width=6, height=6, dpi=200):
        fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = fig.add_subplot(111)

        FigureCanvas.__init__(self, fig)
        self.setParent(parent)

        FigureCanvas.setSizePolicy(self,
                                   QSizePolicy.Expanding,
                                   QSizePolicy.Expanding)
        FigureCanvas.updateGeometry(self)
        self.plot()

    def plot(self, data=(1, ), target=0):
        self.axes.clear()
        ax = self.figure.add_subplot(111)
        ax.plot(data, 'g-')
        ax.plot([target] * len(data), 'b-')
        # ax.plot(noise, 'r-')
        ax.set_title('PID: {} steps'.format(len(data)))
        self.draw()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())
