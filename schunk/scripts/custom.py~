#!/usr/bin/env python
#-*-coding:utf-8 -*-
"""
    moveit_fk_demo.py - Version 0.1 2014-01-14
    
    Use forward kinemtatics to move the arm to a specified set of joint angles
    
    Created for the Pi Robot Project: http://www.pirobot.org
    Copyright (c) 2014 Patrick Goebel.  All rights reserved.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.5
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details at:
    
    http://www.gnu.org/licenses/gpl.html
"""
import rospy, sys
# 导入moveit_commander接口，该接口提供控制机械臂的函数
import moveit_commander
class MoveItDemo:
    def __init__(self):
        # Initialize the move_group API
        moveit_commander.roscpp_initialize(sys.argv)
        # Initialize the ROS node
        rospy.init_node('moveit_demo', anonymous=True)
        print "===== It is OK ===="
       

        # 定义位于moveit_commander库中的MoveGroupCommander类的对象，用于控制特定规划组，传入参数为规划组名称，如manipulator
        manipulator = moveit_commander.MoveGroupCommander('manipulator')
        # 设置关节角位移控制误差
        manipulator.set_goal_joint_tolerance(0.001)
        # 初始化数组，用于存储机械臂各关节期望角位移         
        joint_position1 = [0, 1, 0, 1, 0, 0]
        # 使用set_joint_value_target()函数，设置规划组各关节期望位移
        manipulator .set_joint_value_target(joint_position1)
        manipulator .go()
        rospy.sleep(2)


         # Cleanly shut down MoveIt
        moveit_commander.roscpp_shutdown()
        # Exit the script
        moveit_commander.os._exit(0)
if __name__ == "__main__":
    try:
        MoveItDemo()
    except rospy.ROSInterruptException:
        pass
