#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy, sys
import moveit_commander
import copy
import moveit_msgs.msg
import geometry_msgs.msg
import numpy as np
from PIL import Image
import time
import os
#python2应该这样导入tkinter库
import Tkinter
import tkFileDialog as filedialog
from math import pi

def readtxt():
    '''
    读取txt文件中的数据
    输入：txt文件的路径
    输出：小数格式的数组，行列与txt文件中相同
    '''
    fpath = filedialog.askopenfilename(title='打开画图txt文件', filetypes=[('','*.txt')])
    print "=" * 10,"您选择的文件路径为：",fpath
    pts = np.loadtxt(fpath, dtype=np.float32)
    pts = pts[:, [0, 1]]
    pts=pts/1000
    #print pts
    return pts

def paint(v,a):
    moveit_commander.roscpp_initialize(sys.argv)
    rospy.init_node('schunk_paint',anonymous=True)
    robot = moveit_commander.RobotCommander()
    group = moveit_commander.MoveGroupCommander("arm")
    group.set_max_velocity_scaling_factor(v)
    group.set_max_acceleration_scaling_factor(a)
    group.set_joint_value_target([0,0,pi/2,0,pi/2,0])
    group.go(wait=True)
    pose = group.get_current_pose().pose
    pose.position.y -= 0.18
    pose.position.z -= 0.04
    group.go(pose, wait=True)
    moveit_commander.roscpp_shutdown()


if __name__ == "__main__":
    try:
        paint(0.4,0.2)
    except rospy.ROSInterruptException:
        pass
