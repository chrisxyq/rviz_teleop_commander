# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'paint.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1070, 839)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.open_file = QtWidgets.QPushButton(self.centralwidget)
        self.open_file.setGeometry(QtCore.QRect(260, 130, 211, 28))
        self.open_file.setObjectName("open_file")
        self.groupBox_2 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_2.setGeometry(QtCore.QRect(251, 161, 217, 125))
        self.groupBox_2.setObjectName("groupBox_2")
        self.gridLayout_3 = QtWidgets.QGridLayout(self.groupBox_2)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.pause_paint = QtWidgets.QPushButton(self.groupBox_2)
        self.pause_paint.setObjectName("pause_paint")
        self.gridLayout_3.addWidget(self.pause_paint, 2, 0, 1, 1)
        self.label_3 = QtWidgets.QLabel(self.groupBox_2)
        self.label_3.setObjectName("label_3")
        self.gridLayout_3.addWidget(self.label_3, 0, 0, 1, 1)
        self.vratio_slider = QtWidgets.QSlider(self.groupBox_2)
        self.vratio_slider.setOrientation(QtCore.Qt.Horizontal)
        self.vratio_slider.setObjectName("vratio_slider")
        self.gridLayout_3.addWidget(self.vratio_slider, 0, 1, 1, 1)
        self.label_4 = QtWidgets.QLabel(self.groupBox_2)
        self.label_4.setObjectName("label_4")
        self.gridLayout_3.addWidget(self.label_4, 1, 0, 1, 1)
        self.continue_paint = QtWidgets.QPushButton(self.groupBox_2)
        self.continue_paint.setObjectName("continue_paint")
        self.gridLayout_3.addWidget(self.continue_paint, 2, 1, 1, 1)
        self.aratio_slider = QtWidgets.QSlider(self.groupBox_2)
        self.aratio_slider.setOrientation(QtCore.Qt.Horizontal)
        self.aratio_slider.setObjectName("aratio_slider")
        self.gridLayout_3.addWidget(self.aratio_slider, 1, 1, 1, 1)
        self.groupBox_3 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_3.setGeometry(QtCore.QRect(251, 402, 254, 139))
        self.groupBox_3.setObjectName("groupBox_3")
        self.gridLayout_4 = QtWidgets.QGridLayout(self.groupBox_3)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.compute_T = QtWidgets.QPushButton(self.groupBox_3)
        self.compute_T.setObjectName("compute_T")
        self.gridLayout.addWidget(self.compute_T, 1, 1, 1, 1)
        self.record_zero = QtWidgets.QPushButton(self.groupBox_3)
        self.record_zero.setObjectName("record_zero")
        self.gridLayout.addWidget(self.record_zero, 0, 0, 1, 1)
        self.comboBox = QtWidgets.QComboBox(self.groupBox_3)
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.gridLayout.addWidget(self.comboBox, 0, 1, 1, 1)
        self.record_y = QtWidgets.QPushButton(self.groupBox_3)
        self.record_y.setObjectName("record_y")
        self.gridLayout.addWidget(self.record_y, 1, 0, 1, 1)
        self.start_paint = QtWidgets.QPushButton(self.groupBox_3)
        self.start_paint.setObjectName("start_paint")
        self.gridLayout.addWidget(self.start_paint, 2, 0, 1, 2)
        self.gridLayout_4.addLayout(self.gridLayout, 0, 0, 1, 1)
        self.groupBox_4 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_4.setGeometry(QtCore.QRect(251, 293, 217, 102))
        self.groupBox_4.setObjectName("groupBox_4")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.groupBox_4)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.default_paint = QtWidgets.QPushButton(self.groupBox_4)
        self.default_paint.setObjectName("default_paint")
        self.gridLayout_2.addWidget(self.default_paint, 1, 0, 1, 2)
        self.default_start = QtWidgets.QPushButton(self.groupBox_4)
        self.default_start.setObjectName("default_start")
        self.gridLayout_2.addWidget(self.default_start, 0, 1, 1, 1)
        self.home = QtWidgets.QPushButton(self.groupBox_4)
        self.home.setObjectName("home")
        self.gridLayout_2.addWidget(self.home, 0, 0, 1, 1)
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(520, 130, 231, 401))
        self.label.setText("")
        self.label.setObjectName("label")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1070, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.open_file.setText(_translate("MainWindow", "打开"))
        self.groupBox_2.setTitle(_translate("MainWindow", "运动控制"))
        self.pause_paint.setText(_translate("MainWindow", "暂停画图"))
        self.label_3.setText(_translate("MainWindow", "角速度比率"))
        self.label_4.setText(_translate("MainWindow", "角加速度比率"))
        self.continue_paint.setText(_translate("MainWindow", "继续"))
        self.groupBox_3.setTitle(_translate("MainWindow", "标定用户坐标系"))
        self.compute_T.setText(_translate("MainWindow", "计算变换矩阵"))
        self.record_zero.setText(_translate("MainWindow", "记录原点"))
        self.comboBox.setItemText(0, _translate("MainWindow", "重新记录原点"))
        self.comboBox.setItemText(1, _translate("MainWindow", "重新记录Y轴点"))
        self.comboBox.setItemText(2, _translate("MainWindow", "重新记录所有"))
        self.record_y.setText(_translate("MainWindow", "记录Y轴点"))
        self.start_paint.setText(_translate("MainWindow", "开始画图"))
        self.groupBox_4.setTitle(_translate("MainWindow", "默认用户坐标系"))
        self.default_paint.setText(_translate("MainWindow", "开始画图"))
        self.default_start.setText(_translate("MainWindow", "默认预备点"))
        self.home.setText(_translate("MainWindow", "HOME点"))
