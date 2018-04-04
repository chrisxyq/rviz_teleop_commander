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
import moveit_commander

##发布到主题消息类型为Float32MultiArray
from std_msgs.msg import Float32MultiArray
class MoveItDemo:
    def __init__(self):
        # Initialize the move_group API
        moveit_commander.roscpp_initialize(sys.argv)
        # Initialize the ROS node
        rospy.init_node('moveit_demo', anonymous=True)


        # #将规划轨迹的部分信息以主题的形式重新发布
        # #trajectory_pos_pub用于发布轨迹中的关节角位移
        # #trajectory_vel_pub用于发布轨迹中的关节角速度
        trajectory_pos_pub = rospy.Publisher('my_trajectory_pos',Float32MultiArray,queue_size=10)
        trajectory_vel_pub = rospy.Publisher('my_trajectory_vel',Float32MultiArray,queue_size=10)
        print "===== It is OK ===="
       # rospy.sleep(3)
    
        
        # 定义位于moveit_commander库中的MoveGroupCommander类的对象，用于控制特定规划组，传入参数为规划组名称，如manipulator
        manipulator = moveit_commander.MoveGroupCommander('manipulator')

        ##
        traj = manipulator.plan()
        # 设置关节角位移控制误差
        manipulator.set_goal_joint_tolerance(0.001)
        # 初始化数组，用于存储机械臂各关节期望角位移         
        joint_position1 = [0,0,0,0,0,0]    
        # 使用set_joint_value_target()函数，设置规划组各关节期望位移
        manipulator .set_joint_value_target(joint_position1)
        manipulator .go()
        rospy.sleep(2)
 

        ##定义并初始化一个Float32MultiArray类型的变量
        traj_joint = Float32MultiArray()
        traj_joint.data = [0,0,0,0,0,0]       
        ##获得规划的关节数目
        n_joints = len(traj.joint_trajectory.joint_names)
        ##获得规划的点的数目
        n_points = len(traj.joint_trajectory.points)     
        now_time = 0
        last_time = 0
        ##将各规划点的角位移与角速度发布到主题上
        for i in range(n_points):
               # The joint positions are not scaled so pull them out first
          traj_joint.data = traj.joint_trajectory.points[i].positions
          trajectory_pos_pub.publish(traj_joint)
          traj_joint.data = traj.joint_trajectory.points[i].velocities
          trajectory_vel_pub.publish(traj_joint)
          ##计算两规划点之间时间间隔
          now_time = traj.joint_trajectory.points[i].time_from_start.secs+traj.joint_trajectory.points[i].time_from_start.nsecs*1.0/1000000000
          tim = now_time-last_time
          last_time = now_time
          print tim
          rospy.sleep(tim)


        # Cleanly shut down MoveIt
        moveit_commander.roscpp_shutdown()
        # Exit the script
        moveit_commander.os._exit(0)
if __name__ == "__main__":
    try:
        MoveItDemo()
    except rospy.ROSInterruptException:
        pass
