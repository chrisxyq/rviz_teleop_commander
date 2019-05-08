#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
为了使窗口显示和业务逻辑分离，新建一个调用窗口显示的文件main,导入对应的类并且继承
'''
import sys
import rospy, sys
import moveit_commander
import copy
import moveit_msgs.msg
import geometry_msgs.msg


from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
import paint
from usual import *
import cv2
import numpy as np
from math import *
from PIL import Image
import time
#import os
#python2应该这样导入tkinter库,暂时不用
# import Tkinter
# import tkFileDialog as filedialog
'''
----------变量定义--------
i:负责记录当前运行到的行数
flag：记录这次暂停之前的几次暂停运行的行数积累
pts：txt文件要画的数据点
h1:抬笔点相对预备点的高度差
h2:落笔点相对预备点的高度差
v、a：运动速度和加速度比率
'''
txtpath=r'sorted_pts.txt'
i=0
pts=[]
h1,h2=0.1,0.133
v,a=1,1
'''------坐标系转换使用变量--------'''
piczero=[]
picy=[]
R=[]
T=[]


moveit_commander.roscpp_initialize(sys.argv)
rospy.init_node('schunk_paint', anonymous=True)
group = moveit_commander.MoveGroupCommander("arm")
group.set_max_velocity_scaling_factor(v)
group.set_max_acceleration_scaling_factor(a)

class MainCode(QMainWindow, paint.Ui_MainWindow):
    def __init__(self):
        # '''
        # 在类的初始化中，为信号绑定自定义的槽函数
        # 在下面可以def所有的槽函数
        # '''
        QMainWindow.__init__(self)
        paint.Ui_MainWindow.__init__(self)
        self.setupUi(self)

        '''--------槽函数连接--------'''
        self.open_file.clicked.connect(self.on_open_file)
        # #'''运动控制groupbox'''
        self.pause_paint.clicked.connect(self.on_pause_paint)
        # self.continue_paint.clicked.connect(self.on_continue_paint)
        # #'''默认用户坐标系groupbox'''
        self.home.clicked.connect(self.on_home)
        #self.default_start.clicked.connect(self.on_default_start)
        self.default_paint.clicked.connect(self.on_default_paint)
        # #'''标定用户坐标系groupbox'''
        # self.record_zero.clicked.connect(self.on_record_zero)
        # self.record_x.clicked.connect(self.on_record_x)
        # self.record_y.clicked.connect(self.on_record_y)
        # self.comboBox.currentIndexChanged.connect(self.on_comboBox)
        # self.compute_T.clicked.connect(self.on_compute_T)
        # self.start_paint.clicked.connect(self.on_start_paint)
        self.statusbar.showMessage("点击“打开”，选择画图txt所在文件夹。")



    def on_open_file(self):
        '''打开文件按钮'''
        dir, _ = QFileDialog.getOpenFileName(self, "选取要画的jpg图片", "/home/cp3/catkin_ws/src/lwa_config/new_ui", "Image files(*.jpg)")
        '''1.label显示图片'''
        self.label.setPixmap(QPixmap(dir))
        self.label.setScaledContents(True)
        #self.statusbar.showMessage("打开图片路径为："+dir)
        self.statusbar.showMessage( dir)
        '''2.jpg转为要画的txt保存在self.txtpath'''
        Width,Height = 180,240
        img = cv2.imread(dir, 0)
        img = cv2.resize(img, (Width,Height))
        img_point = np.array(img)
        add = 255 * np.ones((Height, 1))
        img_point = np.concatenate((img_point, add), axis=1)
        img_point = np.concatenate((add, img_point), axis=1)
        f = open(txtpath, 'w')
        for i in range(0, Height):
            if ((i + 1) % 2 == 0):
                sketch_k = img_point[i][0]
                img_point[i] = Flip_180(img_point[i])
                for j in range(0, Width + 2):
                    if (int((img_point[i][j] - sketch_k) == -255)):
                        f.write(str(Width + 2 - j) + str(' ') + str(i + 1) + str(' ') + str(200) + str(' '))
                        f.write(str('0 ') + str('0 ') + str('135 ') + str('1 '))
                        f.write('\n')
                    if (int((img_point[i][j] - sketch_k) == 255)):
                        f.write(str(Width + 2 - j) + str(' ') + str(i + 1) + str(' ') + str(240) + str(' '))
                        f.write(str('0 ') + str('0 ') + str('135 ') + str('0 '))
                        f.write('\n')
                sketch_k = int(img_point[i][j])
            if ((i + 1) % 2 != 0):
                sketch_k = img_point[i][0]
                for j in range(0, Width + 2):
                    if (int((img_point[i][j] - sketch_k) == -255)):
                        f.write(str(j) + str(' ') + str(i + 1) + str(' ') + str(200) + str(' '))
                        f.write(str('0 ') + str('0 ') + str('135 ') + str('1 '))
                        f.write('\n')

                    if (int((img_point[i][j] - sketch_k) == 255)):
                        f.write(str(j) + str(' ') + str(i + 1) + str(' ') + str(240) + str(' '))
                        f.write(str('0 ') + str('0 ') + str('135 ') + str('0 '))
                        f.write('\n')
                sketch_k = int(img_point[i][j])

    def on_pause_paint(self):
        #'''暂停画图按钮'''
        time.sleep(5)
        print "=" * 10, " 成功暂停，已画%d段，共%d段画图轨迹" % ((i + 1) / 2, (len(pts) / 2)), "=" * 10, "\n"
    #
    # def on_continue_paint(self):
    #     #'''继续画图按钮'''
    #     print "=" * 10, " 画图继续，从%d段继续，共%d段画图轨迹" % ((i + 1) / 2, (len(pts) / 2)), "=" * 10, "\n"
    #     group.set_joint_value_target([0, 0, pi / 2, 0, pi / 2, 0])
    #     group.go(wait=True)
    #     pose = group.get_current_pose().pose
    #     pose.position.y -= 0.18
    #     pose.position.z += 0.04
    #     print "=" * 10, " 预备点位姿为: ", "=" * 10
    #     print pose
    #     target = copy.deepcopy(pose)
    #     deltax = 0.015
    #     deltay = 0.03
    #     #'''3.主运动程序，循环调用笛卡尔函数'''
    #     while i<len(pts):
    #         if i % 2 == 0:
    #             #'''抬笔点:绝对赋值'''
    #             target.position.x = pose.position.x + deltax + pts[i][1]
    #             target.position.y = pose.position.y + deltay + pts[i][0]
    #             target.position.z = pose.position.z - h1
    #             #'''偶抬→奇抬：使用笛卡尔路径规划'''
    #             MainCode.cartesian(target)
    #             #'''抬笔点到落笔点'''
    #             target.position.x = pose.position.x + deltax + pts[i][1]
    #             target.position.y = pose.position.y + deltay + pts[i][0]
    #             target.position.z = pose.position.z - h2
    #             MainCode.cartesian(target)
    #
    #         if i % 2 != 0:
    #             #'''落笔点:绝对赋值'''
    #             target.position.x = pose.position.x + deltax + pts[i][1]
    #             target.position.y = pose.position.y + deltay + pts[i][0]
    #             target.position.z = pose.position.z - h2
    #             #'''奇落→偶落：使用笛卡尔路径规划'''
    #             MainCode.cartesian(target)
    #             print
    #             "=" * 10, " 已画%d段，共%d段画图轨迹" % ((i + 1) / 2, (len(pts) / 2)), "=" * 10, "\n"
    #             #'''抬笔点:绝对赋值'''
    #             target.position.x = pose.position.x + deltax + pts[i][1]
    #             target.position.y = pose.position.y + deltay + pts[i][0]
    #             target.position.z = pose.position.z - h1
    #             MainCode.cartesian(target)
    #     moveit_commander.roscpp_shutdown()
    #
    def on_home(self):
        '''回home点按钮'''
        group.set_joint_value_target([0, 0, 0, 0, 0, 0])
        group.go(wait=True)
    #
    #
    #
    # def on_default_start(self):
    #     '''回默认预备点按钮'''
    #
    #
    def cartesian(self, target):
        '''工具：笛卡尔规划函数'''
        waypoints = []
        waypoints.append(target)
        group.set_start_state_to_current_state()
        fraction = 0.0
        max_attempts = 10
        attempts = 0
        while fraction < 1.0 and attempts < max_attempts:
            (plan, fraction) = group.compute_cartesian_path(waypoints, 0.01, 0.0)
            attempts += 1
            if attempts % 10 == 0:
                rospy.loginfo("Still trying after " + str(attempts) + " attempts...")
        if fraction == 1.0:
            # rospy.loginfo("Path computed successfully. Moving the arm.")
            group.set_max_velocity_scaling_factor(v)
            group.set_max_acceleration_scaling_factor(a)
            try:
                group.execute(plan, wait=True)
            except:
                print
                "plan could not be executed"
        else:
            rospy.logerr("Could not find valid cartesian path")
            pass
    #
    def on_default_paint(self):
        '''默认不标定坐标系开始画图'''
        if txtpath is not None:
            '''1.读取txt保存在数组pts'''
            pts = np.loadtxt(txtpath, dtype=np.float32)
            pts = pts[:, [0, 1]]
            pts = pts / 1000
            print
            "=" * 10, " 共%d段画图轨迹" % (len(pts) / 2), "=" * 10, "\n"
            '''2.运动到准备位'''
            group.set_joint_value_target([0, 0, pi / 2, 0, pi / 2, 0])
            group.go(wait=True)
            '''实际预备点的微调：调y：让画图平台左右与机器人对称、调z：机器人画图位置高一点更合适'''
            pose = group.get_current_pose().pose
            pose.position.y -= 0.18
            pose.position.z += 0.04
            print "=" * 10, " 预备点位姿为: ", "=" * 10
            print pose
            target = copy.deepcopy(pose)
            deltax = 0.015
            deltay = 0.03
            '''3.主运动程序，循环调用笛卡尔函数'''
            for i in range(len(pts)):
                if i % 2 == 0:
                    '''抬笔点:绝对赋值'''
                    target.position.x = pose.position.x + deltax + pts[i][1]
                    target.position.y = pose.position.y + deltay + pts[i][0]
                    target.position.z = pose.position.z - h1
                    '''偶抬→奇抬：使用笛卡尔路径规划'''
                    self.cartesian(target)
                    '''抬笔点到落笔点'''
                    target.position.x = pose.position.x + deltax + pts[i][1]
                    target.position.y = pose.position.y + deltay + pts[i][0]
                    target.position.z = pose.position.z - h2
                    self.cartesian(target)

                if i % 2 != 0:
                    '''落笔点:绝对赋值'''
                    target.position.x = pose.position.x + deltax + pts[i][1]
                    target.position.y = pose.position.y + deltay + pts[i][0]
                    target.position.z = pose.position.z - h2
                    '''奇落→偶落：使用笛卡尔路径规划'''
                    self.cartesian(target)
                    print
                    "=" * 10, " 已画%d段，共%d段画图轨迹" % ((i + 1) / 2, (len(pts) / 2)), "=" * 10, "\n"
                    '''抬笔点:绝对赋值'''
                    target.position.x = pose.position.x + deltax + pts[i][1]
                    target.position.y = pose.position.y + deltay + pts[i][0]
                    target.position.z = pose.position.z - h1
                    self.cartesian(target)
            moveit_commander.roscpp_shutdown()
        else:
            print "=" * 10,"txt路径为空\n","=" * 10
    #
    #
    #
    # def on_record_zero(self):
    #     '''记录图像坐标系零点piczero'''
    #     piczero=[group.get_current_pose().pose.position.x,
    #              group.get_current_pose().pose.position.y,group.get_current_pose().pose.position.z]
    #
    # def on_record_y(self):
    #     '''记录图像坐标系y轴点picy'''
    #     picy=[group.get_current_pose().pose.position.x,
    #              group.get_current_pose().pose.position.y,group.get_current_pose().pose.position.z]
    #
    # def on_comboBox(self):
    #     '''重新记录图像坐标系的点'''
    #     if self.comboBox.currentIndex()==0:
    #         piczero =[]
    #         self.statusbar.showMessage("图像坐标系原点已清空，请重新记录。")
    #     elif self.comboBox.currentIndex()==1:
    #         picy = []
    #         self.statusbar.showMessage("图像坐标系y轴点已清空，请重新记录。")
    #     else:
    #         piczero = []
    #         picy = []
    #         self.statusbar.showMessage("图像坐标系所有点已清空，请重新记录。")
    #
    #
    # def on_compute_T(self):
    #     '''计算图像坐标系→基坐标系变换矩阵'''
    #     if piczero is None and picy is None:
    #         self.statusbar.showMessage("图像坐标系点尚未记录，无法计算变换矩阵。")
    #     elif piczero is None:
    #         self.statusbar.showMessage("图像坐标系原点尚未记录，无法计算变换矩阵。")
    #     elif picy is None:
    #         self.statusbar.showMessage("图像坐标系y轴点尚未记录，无法计算变换矩阵。")
    #     else:
    #         print 1



    # def on_start_paint(self):
    #     '''标定完坐标系开始画图'''

if __name__ == '__main__':
    app = QApplication(sys.argv)
    md = MainCode()  # 创建主窗体对象
    md.show()  # 显示主窗体
    sys.exit(app.exec_())






