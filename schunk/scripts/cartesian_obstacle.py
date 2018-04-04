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
##要使用move_group的python接口，导入moveit_commander模块,还导入了rospy和所需消息。
import sys
import rospy, sys
import moveit_msgs.msg
import geometry_msgs.msg
import moveit_commander
import math
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
        #初始化一个MoveGroupCommander对象，它指定所需规划的运动链
        manipulator= MoveGroupCommander('manipulator')
        #初始化一个RobotCommander对象，它是获取机械臂信息的接口。
        robot = moveit_commander.RobotCommander()
        #创建DisplayTrajectory发布器，用于发布RVIZ的轨迹以便可视化。
        #display_trajectory_publisher = rospy.Publisher( '/move_group/display_planned_path',moveit_msgs.msg.DisplayTrajectory)

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

        #设置末端执行器期望位置
        #xyz=range(3) 
        #xyz[0]=0.05
        #xyz[1]= 0.05
        #xyz[2]= 1.0
        #manipulator.set_position_target(xyz, arm_6_link )     

        #manipulator.set_named_target('collision')
        #manipulator.go()
        #rospy.sleep(3)    

        manipulator.set_named_target('pos4bz')
            #x: 0.448014710435
            #y: 0.00529645274375
            #z: 0.961053500704
            #orientation: 
            #x: -0.655372454217
            #y: 1.62459127234e-06
            #z: -0.755305860294
            #w: 6.04692799521e-05 
        manipulator.go()
        rospy.sleep(3)   

        obstacle1_id = 'obstacle1'
        obstacle1_size = [0.1, 0.02, 0.05]
        obstacle1_pose = PoseStamped()
        obstacle1_pose.header.frame_id = manipulator.get_planning_frame()
        obstacle1_pose.pose.position.x = 0.5
        #obstacle1_pose.pose.position.y = 0.2
        obstacle1_pose.pose.position.y = 2
        obstacle1_pose.pose.position.z = 0.8
        obstacle1_pose.pose.orientation.w = 1.0   
        scene.add_box(obstacle1_id, obstacle1_pose, obstacle1_size)
        self.setColor(obstacle1_id, 0.8, 0.4, 0, 1.0)
        self.sendColors()    


        #机械臂笛卡尔空间轨迹规划
        #初始化用于存储末端轨迹点变量waypoints1、然后将一系列期望轨迹点添加进去
        waypoints1 = []
        #使用get_current_pose()函数获取末端当前位姿，并加入waypoints1中
        start_pose = manipulator.get_current_pose(arm_6_link).pose
        wpose = deepcopy(start_pose)
        waypoints1.append(deepcopy(wpose))    

        wpose.position.z -= 0.3
        waypoints1.append(deepcopy(wpose))  

        wpose.position.y += 0.24
        wpose.position.z += 0.3
        waypoints1.append(deepcopy(wpose))

        #使用compute_cartesian_path()函数计算笛卡尔空间轨迹，输入参数包括
        (cartesian_plan, fraction) = manipulator.compute_cartesian_path (
                                        waypoints1,   # waypoint poses
                                        0.01,        # eef_step 插值分辨率1cm
                                        0.0,         # jump_threshold 跳跃阈值
                                        True)        # avoid_collisions 是否需要避障     
        manipulator.execute(cartesian_plan)

        moveit_commander.roscpp_shutdown()        
        # Exit the script        
        moveit_commander.os._exit(0)     

    # Set the color of an object
    def setColor(self, name, r, g, b, a = 0.9):
        # Initialize a MoveIt color object
        color = ObjectColor()        
        # Set the id to the name given as an argument
        color.id = name        
        # Set the rgb and alpha values given as input
        color.color.r = r
        color.color.g = g
        color.color.b = b
        color.color.a = a        
        # Update the global color dictionary
        self.colors[name] = color
    # Actually send the colors to MoveIt!
    def sendColors(self):
        # Initialize a planning scene object
        p = PlanningScene()
        # Need to publish a planning scene diff        
        p.is_diff = True        
        # Append the colors from the global color dictionary 
        for color in self.colors.values():
            p.object_colors.append(color)       
        # Publish the scene diff
        self.scene_pub.publish(p)


if __name__ == "__main__":
    try:
        MoveItDemo()
    except KeyboardInterrupt:
        raise
    
    
    
