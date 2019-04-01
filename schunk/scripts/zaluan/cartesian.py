#!/usr/bin/env python
#-*-coding:utf-8 -*-
"""
    moveit_ik_demo.py - Version 0.1 2014-01-14
    
    Use inverse kinemtatics to move the end effector to a specified pose
    
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
# 导入PlanningSceneInterface使我们可以在场景中添加或移除物体；
from moveit_commander import MoveGroupCommander, PlanningSceneInterface
# 采用ObjectColor消息类型为物体设置不同颜色；采用PlanningScene消息，将物体更新发布到主题planning_scene上。
from moveit_msgs.msg import  PlanningScene, ObjectColor
from geometry_msgs.msg import PoseStamped, Pose
from copy import deepcopy
class MoveItDemo:
    def __init__(self):
        # Initialize the move_group API
        moveit_commander.roscpp_initialize(sys.argv)
        rospy.init_node('moveit_demo')        
        # Construct the initial scene object
        scene = PlanningSceneInterface()        
        # Create a scene publisher to push changes to the scene
        self.scene_pub = rospy.Publisher('planning_scene', PlanningScene)        
        # Create a dictionary to hold object colors
        self.colors = dict()        
        # Pause for the scene to get ready
        rospy.sleep(1)                        
        # Initialize the move group for themanipulator
        manipulator= MoveGroupCommander('manipulator')


        #获得末端执行器连杆的名字，作为笛卡尔空间轨迹规划的控制对象
        arm_6_link = manipulator.get_end_effector_link()        
        # Allow some leeway in position (meters) and orientation (radians)
        manipulator.set_goal_position_tolerance(0.01)
        manipulator.set_goal_orientation_tolerance(0.05)       
        # Allow replanning to increase the odds of a solution
        manipulator.allow_replanning(True)
        #获得参考坐标系，即笛卡尔空间规划的全局坐标系
        manipulator_reference_frame = manipulator.get_planning_frame()        
        # Allow 5 seconds per planning attempt
        manipulator.set_planning_time(5)     


        #控制机械臂运动到初始位姿 stored in the SRDF file
        manipulator.set_named_target('home')
        manipulator.go()
        #rospy.sleep(1)          
        manipulator.set_start_state_to_current_state()


        #设置末端执行器期望位置与姿态(姿态由四元数表示)
        target_pose = PoseStamped()
        target_pose.header.frame_id = manipulator_reference_frame
        target_pose.pose.position.x = 0.391492418117
        target_pose.pose.position.y = 0.00527467536136
        target_pose.pose.position.z = 0.945521678323
        target_pose.pose.orientation.x =  -0.940773021084
        target_pose.pose.orientation.y = -3.70796776407e-06
        target_pose.pose.orientation.z = -0.339037052232
        target_pose.pose.orientation.w = 8.94210443913e-07      
        #为机械臂设置期望位姿，set_pose_target()函数包括两输入参数：末端期望位姿与末端执行器名字。
        manipulator.set_pose_target(target_pose, arm_6_link )        
        #规划并执行运动轨迹
        manipulator.go()        
        #rospy.sleep(1)   


        #机械臂笛卡尔空间轨迹规划
        #初始化用于存储末端轨迹点变量waypoints1、然后将一系列期望轨迹点添加进去
        waypoints1 = []
        #使用get_current_pose()函数获取末端当前位姿，并加入waypoints1中
        start_pose = manipulator.get_current_pose(arm_6_link).pose
        wpose = deepcopy(start_pose)
        waypoints1.append(deepcopy(wpose))    
        #其他轨迹点以此调整  
        wpose.position.x -= 0.1
        wpose.position.y += 0.2
        wpose.position.z += 0.1
        waypoints1.append(deepcopy(wpose))  

        wpose.position.x -= 0.1
        wpose.position.y += 0.2
        wpose.position.z -= 0.1
        waypoints1.append(deepcopy(wpose))


        #使用compute_cartesian_path()函数计算笛卡尔空间轨迹，输入参数包括
        (cartesian_plan, fraction) = manipulator.compute_cartesian_path (
                                        waypoints1,   # waypoint poses
                                        0.01,        # eef_step 插值分辨率1cm
                                        0.0,         # jump_threshold 跳跃阈值
                                        True)        # avoid_collisions 是否需要避障     

        manipulator.execute(cartesian_plan)
        #rospy.sleep(2)     


        moveit_commander.roscpp_shutdown()        
        # Exit the script        
        moveit_commander.os._exit(0)            
if __name__ == "__main__":
    try:
        MoveItDemo()
    except KeyboardInterrupt:
        raise
    
    
    
