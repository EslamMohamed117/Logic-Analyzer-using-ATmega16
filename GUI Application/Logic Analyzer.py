from re import S
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
import serial

# declare port to be initialized later
port = 0
class Ui_MainWindow(object):
    modeOperation=''

    def load_ports(self):
        ports = QSerialPortInfo().availablePorts()
        for port in ports:
            self.comboBox.addItem(port.portName())

    # connect to selected port in combobox
    def connect(self):
        port = self.comboBox.currentText()
        #self.serial = QSerialPort(port)
        self.serial = serial.Serial(port, 9600, timeout=1)
        #if self.serial is open

        if self.serial.isOpen():
            self.connectionLabel.setText("Connected")
            self.connectionLabel.setStyleSheet("color: green")
        else:
            self.connectionLabel.setText("Not connected")
            self.connectionLabel.setStyleSheet("color: red")
    # disconnect from serial port
    def disconnect(self):
        self.serial.close()

        self.connectionLabel.setText("No connection")
        self.connectionLabel.setStyleSheet("color: red")

    # refreshBtn ports
    def refresh_ports(self):
        self.comboBox.clear()
        self.load_ports()

    def send_to_memory(self, data):
        self.serial.write(data.encode())

    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setEnabled(True)
        MainWindow.resize(381, 218)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.comboBox = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox.setGeometry(QtCore.QRect(50, 80, 291, 31))
        self.comboBox.setObjectName("comboBox")
        self.connectBtn = QtWidgets.QPushButton(self.centralwidget)
        self.connectBtn.setGeometry(QtCore.QRect(150, 130, 93, 28))
        self.connectBtn.setObjectName("connectBtn")
        self.refreshBtn = QtWidgets.QPushButton(self.centralwidget)
        self.refreshBtn.setGeometry(QtCore.QRect(50, 130, 93, 28))
        self.refreshBtn.setObjectName("refreshBtn")
        self.connectionLabel = QtWidgets.QLabel(self.centralwidget)
        self.connectionLabel.setGeometry(QtCore.QRect(220, 40, 81, 16))
        self.connectionLabel.setObjectName("connectionLabel")
        self.disconnectBtn = QtWidgets.QPushButton(self.centralwidget)
        self.disconnectBtn.setGeometry(QtCore.QRect(250, 130, 93, 28))
        self.disconnectBtn.setObjectName("disconnectBtn")
        self.connectionStatusLabel = QtWidgets.QLabel(self.centralwidget)
        self.connectionStatusLabel.setGeometry(QtCore.QRect(50, 40, 111, 16))
        self.connectionStatusLabel.setObjectName("connectionStatusLabel")
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
        self.connectBtn.setText(_translate("MainWindow", "Connect"))
        self.refreshBtn.setText(_translate("MainWindow", "Refresh"))
        self.connectionLabel.setText(_translate("MainWindow", "No connection"))
        self.disconnectBtn.setText(_translate("MainWindow", "Disconnect"))
        self.connectionStatusLabel.setText(_translate("MainWindow", "Connection status:"))

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())