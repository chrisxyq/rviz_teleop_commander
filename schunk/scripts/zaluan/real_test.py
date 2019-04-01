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

        rospy.sleep(2)     


        moveit_commander.roscpp_shutdown()        
        # Exit the script        
        moveit_commander.os._exit(0)            
if __name__ == "__main__":
    try:
        MoveItDemo()
    except KeyboardInterrupt:
        raise
    