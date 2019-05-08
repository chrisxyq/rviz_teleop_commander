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

def disperse(pt1,pt2):
    waypoints = []
    # start with the current pose
    waypoints.append(group.get_current_pose().pose)
    # first orient gripper and move forward (+x)
    wpose = geometry_msgs.msg.Pose()
    wpose.orientation.w = 1.0
    wpose.position.x = waypoints[0].position.x + 0.1
    wpose.position.y = waypoints[0].position.y
    wpose.position.z = waypoints[0].position.z
    waypoints.append(copy.deepcopy(wpose))

    # second move down
    wpose.position.z -= 0.10
    waypoints.append(copy.deepcopy(wpose))

    # third move to the side
    wpose.position.y += 0.05
    waypoints.append(copy.deepcopy(wpose))

def paint(pts,v,a):
    start = time.time()
    moveit_commander.roscpp_initialize(sys.argv)
    rospy.init_node('schunk_paint',anonymous=True)
    robot = moveit_commander.RobotCommander()
    group = moveit_commander.MoveGroupCommander("arm")
    group.set_max_velocity_scaling_factor(v)
    group.set_max_acceleration_scaling_factor(a)
    group.set_joint_value_target([0,0,pi/2,0,pi/2,0])
    group.go(wait=True)
    pose = group.get_current_pose().pose
    print "=" * 10, " 预备点位姿为: "
    print pose
    target=copy.deepcopy(pose)
    for i in range(len(pts)):
        if i%2==0:
            #抬笔点
            target.position.x = pose.position.x + pts[i][1]
            target.position.y = pose.position.y + pts[i][0]
            target.position.z = pose.position.z - 0.04
            group.set_max_velocity_scaling_factor(v)
            group.set_max_acceleration_scaling_factor(a)
            group.go(target, wait=True)
            # 落笔点
            target.position.z = pose.position.z - 0.059
            group.set_max_velocity_scaling_factor(v)
            group.set_max_acceleration_scaling_factor(a)
            group.go(target, wait=True)

        if i%2!=0:
            # 落笔点
            target.position.x = pose.position.x + pts[i][1]
            target.position.y = pose.position.y + pts[i][0]
            group.set_max_velocity_scaling_factor(v)
            group.set_max_acceleration_scaling_factor(a)
            group.go(target, wait=True)
            # 抬笔点
            target.position.z = pose.position.z - 0.04
            group.set_max_velocity_scaling_factor(v)
            group.set_max_acceleration_scaling_factor(a)
            group.go(target, wait=True)
        group.set_max_velocity_scaling_factor(v)
        group.set_max_acceleration_scaling_factor(a)
    end = time.time()
    print "=" * 10,"机器人运动时间=%.2f" %(float(end-start)/60),"分钟\n"
    moveit_commander.roscpp_shutdown()


if __name__ == "__main__":
    try:
        pts=readtxt()
        paint(pts,0.4,0.2)
    except rospy.ROSInterruptException:
        pass
