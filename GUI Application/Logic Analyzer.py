from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


from threading import Thread

from re import S
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
import serial

# declare port to be initialized later

x_values = []
y_values = []
class Ui_MainWindow(object):
    modeOperation=''
    port = None
    serialPort = None
    def load_ports(self):
        ports = QSerialPortInfo().availablePorts()
        for port in ports:
            self.comboBox.addItem(port.portName())

    # connect to selected port in combobox
    def connect(self):
        self.port = self.comboBox.currentText()
        #self.serial = QSerialPort(port)
        self.serialPort = serial.Serial(self.port, 9600, timeout=1)
        #if self.serial is open

        if self.serialPort.isOpen():
            self.connectionLabel.setText("Connected")
            self.connectionLabel.setStyleSheet("color: green")
            self.signalGroup.setEnabled(True)
            self.signalInfoGroup.setEnabled(True)
            signalReadingThread = Thread(target = self.readingSerialPortThread, daemon=True, args=(self.serialPort,))
            signalReadingThread.start()
        else:
            self.connectionLabel.setText("Not connected")
            self.connectionLabel.setStyleSheet("color: red")
            self.signalGroup.setEnabled(False)
            self.signalInfoGroup.setEnabled(False)
            self.port=None
    # disconnect from serial port
    def disconnect(self):
        self.serialPort.close()
        self.port=None
        self.connectionLabel.setText("No connection")
        self.connectionLabel.setStyleSheet("color: red")
        self.signalGroup.setEnabled(False)
        self.signalInfoGroup.setEnabled(False)

    # refreshBtn ports
    def refresh_ports(self):
        self.comboBox.clear()
        self.load_ports()

    def send_to_memory(self, data):
        self.serialPort.write(data.encode())

    def receive_data(self, serialPort):
        data = serialPort.read().decode('ascii').strip()
        return data 

    def readingSerialPortThread(self, serialPort):
        print("readingSerialPortThread")
        while True:
            if serialPort.isOpen():
                for j in range(3):
                    data = ''
                    for i in range(7):
                        data = data + self.receive_data(serialPort=serialPort)
                        # if data legnth is greater than 0
                    if len(data) > 0:
                        print(data)
                    #remove any @ or ; from data
                    # data = data.replace('@', '')
                    # data = data.replace(';', '')
                    # #append first byte to y_values list and combine values from second to fifth byte to x_values list and convert to number from ascii
                    # y_values.append(int(data[0])-0x30)
                    # x_values.append(int(data[1:5]))
                    # print (y_values)
                
                #def animate(i):
                #x = data['x_value']
                #y1 = data['total_1']
                #y2 = data['total_2']

                #plt.cla()

                #plt.plot(x, y1, label='Channel 1')
                #plt.plot(x, y2, label='Channel 2')

                #plt.legend(loc='upper left')
                #plt.tight_layout()


                #ani = FuncAnimation(plt.gcf(), animate, interval=1000)

                #plt.tight_layout()
                #plt.show()

              


    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setEnabled(True)
        MainWindow.resize(410, 756)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.connectionGroup = QtWidgets.QGroupBox(self.centralwidget)
        self.connectionGroup.setGeometry(QtCore.QRect(20, 20, 371, 181))
        self.connectionGroup.setObjectName("connectionGroup")
        self.disconnectBtn = QtWidgets.QPushButton(self.connectionGroup)
        self.disconnectBtn.setGeometry(QtCore.QRect(240, 120, 93, 28))
        self.disconnectBtn.setObjectName("disconnectBtn")
        self.connectionStatusLabel = QtWidgets.QLabel(self.connectionGroup)
        self.connectionStatusLabel.setGeometry(QtCore.QRect(40, 30, 111, 16))
        self.connectionStatusLabel.setObjectName("connectionStatusLabel")
        self.connectBtn = QtWidgets.QPushButton(self.connectionGroup)
        self.connectBtn.setGeometry(QtCore.QRect(140, 120, 93, 28))
        self.connectBtn.setObjectName("connectBtn")
        self.connectionLabel = QtWidgets.QLabel(self.connectionGroup)
        self.connectionLabel.setGeometry(QtCore.QRect(210, 30, 81, 16))
        self.connectionLabel.setObjectName("connectionLabel")
        self.comboBox = QtWidgets.QComboBox(self.connectionGroup)
        self.comboBox.setGeometry(QtCore.QRect(40, 70, 291, 31))
        self.comboBox.setObjectName("comboBox")
        self.refreshBtn = QtWidgets.QPushButton(self.connectionGroup)
        self.refreshBtn.setGeometry(QtCore.QRect(40, 120, 93, 28))
        self.refreshBtn.setObjectName("refreshBtn")
        self.signalGroup = QtWidgets.QGroupBox(self.centralwidget)
        self.signalGroup.setEnabled(False)
        self.signalGroup.setGeometry(QtCore.QRect(20, 210, 371, 421))
        self.signalGroup.setObjectName("signalGroup")
        self.signalWidget = QtWidgets.QWidget(self.signalGroup)
        self.signalWidget.setGeometry(QtCore.QRect(10, 30, 351, 381))
        self.signalWidget.setObjectName("signalWidget")
        self.signalInfoGroup = QtWidgets.QGroupBox(self.centralwidget)
        self.signalInfoGroup.setEnabled(False)
        self.signalInfoGroup.setGeometry(QtCore.QRect(20, 640, 371, 91))
        self.signalInfoGroup.setObjectName("signalInfoGroup")
        self.avgFrequencyLabel = QtWidgets.QLabel(self.signalInfoGroup)
        self.avgFrequencyLabel.setGeometry(QtCore.QRect(20, 30, 121, 16))
        self.avgFrequencyLabel.setObjectName("avgFrequencyLabel")
        self.pulseWidthLabel = QtWidgets.QLabel(self.signalInfoGroup)
        self.pulseWidthLabel.setGeometry(QtCore.QRect(20, 60, 111, 16))
        self.pulseWidthLabel.setObjectName("pulseWidthLabel")
        self.avgFrequencyValue = QtWidgets.QLabel(self.signalInfoGroup)
        self.avgFrequencyValue.setGeometry(QtCore.QRect(220, 30, 55, 16))
        self.avgFrequencyValue.setText("")
        self.avgFrequencyValue.setObjectName("avgFrequencyValue")
        self.pulseWidthValue = QtWidgets.QLabel(self.signalInfoGroup)
        self.pulseWidthValue.setGeometry(QtCore.QRect(220, 60, 55, 16))
        self.pulseWidthValue.setText("")
        self.pulseWidthValue.setObjectName("pulseWidthValue")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        self.load_ports()
        self.connectBtn.clicked.connect(self.connect)
        self.disconnectBtn.clicked.connect(self.disconnect)
        self.refreshBtn.clicked.connect(self.refresh_ports)



    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Logic Analyzer"))
        self.connectionGroup.setTitle(_translate("MainWindow", "Connection"))
        self.disconnectBtn.setText(_translate("MainWindow", "Disconnect"))
        self.connectionStatusLabel.setText(_translate("MainWindow", "Connection status:"))
        self.connectBtn.setText(_translate("MainWindow", "Connect"))
        self.connectionLabel.setText(_translate("MainWindow", "No connection"))
        self.refreshBtn.setText(_translate("MainWindow", "Refresh"))
        self.signalGroup.setTitle(_translate("MainWindow", "Signal"))
        self.signalInfoGroup.setTitle(_translate("MainWindow", "Signal information"))
        self.avgFrequencyLabel.setText(_translate("MainWindow", "Average frequency:"))
        self.pulseWidthLabel.setText(_translate("MainWindow", "Pulse width:"))

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
    