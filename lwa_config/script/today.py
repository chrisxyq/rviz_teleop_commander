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
from math import *

def readtxt():
    fpath = filedialog.askopenfilename(title='打开画图txt文件', filetypes=[('','*.txt')])
    print "=" * 10,"您选择的文件路径为：",fpath,"=" * 10,
    pts = np.loadtxt(fpath, dtype=np.float32)
    pts = pts[:, [0, 1]]
    pts=pts/1000
    print "=" * 10, " 共%d段画图轨迹" %(len(pts)/2),"=" * 10,"\n"
    return pts

def sort(pts):
    sorted_pts=[]
    i=0
    rate=10
    while i<len(pts):
        sorted_pts.append(pts[i])
        sorted_pts.append(pts[i+1])
        i+=rate
    print "=" * 10, " 采样率为", rate/2," 采样前后txt长度分别为", len(sorted_pts),len(pts),"=" * 10,"\n"

    np.savetxt('sorted_pts.txt', np.array(sorted_pts)*1000)
    print "sorted_pts已保存"
    return sorted_pts


def cartesian(group,target,v,a):
    waypoints = []
    #current=group.get_current_pose().pose
    #waypoints.append(current)
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
            print "plan could not be executed"
    else:
        rospy.logerr("Could not find valid cartesian path")
        pass


def paint(pts,h1,h2,v,a):
    '''
    画图主程序
    输入：
    pts：txt文件要画的数据点
    h1:抬笔点相对预备点的高度差
    h2:落笔点相对预备点的高度差
    v、a：运动速度和加速度比率
    '''
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
    '''
    实际预备点的微调
    调y：让画图平台左右与机器人对称
    调z：机器人画图位置高一点更合适
    '''
    pose.position.y -= 0.18
    pose.position.z += 0.04
    print "=" * 10, " 预备点位姿为: ","=" * 10
    print pose
    target=copy.deepcopy(pose)
    deltax=0.015
    deltay=0.03
    for i in range(len(pts)):
        if i%2==0:
            '''抬笔点:绝对赋值'''
            target.position.x = pose.position.x + deltax + pts[i][1]
            target.position.y = pose.position.y + deltay + pts[i][0]
            target.position.z = pose.position.z - h1
            '''偶抬→奇抬：使用笛卡尔路径规划'''
            cartesian(group,target,v,a)
            #time.sleep(0.15)
            '''抬笔点到落笔点'''
            target.position.x = pose.position.x + deltax +  pts[i][1]
            target.position.y = pose.position.y + deltay + pts[i][0]
            target.position.z = pose.position.z - h2
            cartesian(group,target,v,a)
            #time.sleep(0.15)

        if i%2!=0:
            '''落笔点:绝对赋值'''
            target.position.x = pose.position.x + deltax + pts[i][1]
            target.position.y = pose.position.y + deltay + pts[i][0]
            target.position.z = pose.position.z - h2
            '''奇落→偶落：使用笛卡尔路径规划'''
            cartesian(group,target,v,a)
            #time.sleep(0.15)
            print "=" * 10, " 已画%d段，共%d段画图轨迹" % ((i + 1) / 2, (len(pts) / 2)), "=" * 10, "\n"
            '''抬笔点:绝对赋值'''
            target.position.x = pose.position.x + deltax + pts[i][1]
            target.position.y = pose.position.y + deltay + pts[i][0]
            target.position.z = pose.position.z - h1
            cartesian(group,target,v,a)
            #time.sleep(0.15)
    end = time.time()
    print "=" * 10,"机器人运动时间=%.2f" %(float(end-start)/60),"分钟","=" * 10,"\n"
    moveit_commander.roscpp_shutdown()


if __name__ == "__main__":
    try:
        pts=readtxt()
        print len(pts)
        #sorted_pts=sort(pts)
        '''txt文件要画的数据点、抬笔点和落笔点相对预备点的高度差、运动速度和加速度比率'''
        paint(pts,0.1,0.133,1,1)
    except rospy.ROSInterruptException:
        pass
