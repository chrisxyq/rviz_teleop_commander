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
from std_msgs.msg import Float32MultiArray
class MoveItDemo:
    def __init__(self):
        #初始化moveit_commander and rospy.
        moveit_commander.roscpp_initialize(sys.argv)
        rospy.init_node('moveit_demo')    

        #trajectory_pos_pub = rospy.Publisher('my_trajectory_pos',Float32MultiArray,queue_size=10)
        #trajectory_vel_pub = rospy.Publisher('my_trajectory_vel',Float32MultiArray,queue_size=10)    
        #实例化PlanningSceneInterface对象，机器人周边环境的接口
        scene = PlanningSceneInterface()        
        # Create a scene publisher to push changes to the scene
        self.scene_pub = rospy.Publisher('planning_scene', PlanningScene)        
        # Create a dictionary to hold object colors
        self.colors = dict()        
        # Pause for the scene to get ready
        rospy.sleep(1)                        
        #初始化一个MoveGroupCommander对象，它指定所需规划的运动链,该对象是一组关节的接口。接口可以用来规划和执行该组关节的运动。
        manipulator= MoveGroupCommander('manipulator')
        #初始化一个RobotCommander对象，这个对象是整个机器人的一个接口。
        robot = moveit_commander.RobotCommander()
        #初始化一个PlanningSceneInterface对象，它是设置机械臂工作环境的接口。
        #scene = moveit_commander.PlanningSceneInterface()

        #创建DisplayTrajectory发布器，用于发布RVIZ的轨迹以便可视化。
        display_trajectory_publisher = rospy.Publisher(
                                      '/move_group/display_planned_path',
                                      moveit_msgs.msg.DisplayTrajectory)

        ## Wait for RVIZ to initialize. This sleep is ONLY to allow Rviz to come up.
        print "============ Waiting for RVIZ..."
        rospy.sleep(3)        
        #获取机器人参考坐标系名字
        print "============ Reference frame: %s" % manipulator.get_planning_frame()
        #打印该组的末端执行器连杆的名称
        print "============ Reference frame: %s" % manipulator.get_end_effector_link()
        #获取机器人所有规划组
        print "============ Robot Groups:"
        print robot.get_group_names()
        #有时为调试，打印机器人整个状态
        #print "============ Printing robot state"
        #print robot.get_current_state()
        #print "============"

        object1_id = 'object1'
        obstacle1_id = 'obstacle1'
        # Remove leftover objects from a previous run
        scene.remove_world_object(object1_id)
        obstacle1_size = [0.3, 0.05, 1.5]
        obstacle1_pose = PoseStamped()
        obstacle1_pose.header.frame_id = manipulator.get_planning_frame()
        obstacle1_pose.pose.position.x = 0.8
        obstacle1_pose.pose.position.y = 3
        obstacle1_pose.pose.position.z = 0.04
        obstacle1_pose.pose.orientation.w = 1.0   
        scene.add_box(obstacle1_id, obstacle1_pose, obstacle1_size)
        self.setColor(obstacle1_id, 0.8, 0.4, 0, 1.0)
        self.sendColors()    

        #获得末端执行器连杆的名字，作为笛卡尔空间轨迹规划的控制对象
        arm_6_link = manipulator.get_end_effector_link()        
        # Allow some leeway in position (meters) and orientation (radians)
        manipulator.set_goal_position_tolerance(0.01)
        manipulator.set_goal_orientation_tolerance(0.05)       
        # Allow replanning to increase the odds of a solution
        manipulator.allow_replanning(True)
        #获得参考坐标系，即笛卡尔空间规划的全局坐标系
        manipulator_reference_frame = manipulator.get_planning_frame()        
        #控制机械臂运动到初始位姿
        manipulator.set_named_target('home')
        manipulator.go() 
        #traj =manipulator.plan()
        #manipulator.execute(traj)            
        manipulator.set_start_state_to_current_state()
        #rospy.sleep(5)
        #设置末端执行器期望位置与姿态(姿态由四元数表示)
        radius=0.06
        pose1 = PoseStamped()
        pose2 = PoseStamped()
        pose3 = PoseStamped()
        pose4 = PoseStamped()
        pose1.header.frame_id = manipulator_reference_frame
        pose2.header.frame_id = manipulator_reference_frame
        pose3.header.frame_id = manipulator_reference_frame
        pose4.header.frame_id = manipulator_reference_frame
        pose1.pose.position.x =pose2.pose.position.x=pose3.pose.position.x=pose4.pose.position.x= 0.05392254977
        pose1.pose.position.y =0.00526315443317
        pose2.pose.position.y= pose1.pose.position.y+5*radius/3
        pose3.pose.position.y = pose1.pose.position.y+5*2*radius/3
        pose4.pose.position.y = pose1.pose.position.y+5*3*radius/3
        pose1.pose.position.z =pose2.pose.position.z =pose3.pose.position.z =pose4.pose.position.z = 0.844101017043       
        pose1.pose.orientation.x =pose2.pose.orientation.x =pose3.pose.orientation.x =pose4.pose.orientation.x =0.706780879124
        pose1.pose.orientation.y =pose2.pose.orientation.y =pose3.pose.orientation.y =pose4.pose.orientation.y =1.30234918256e-05
        pose1.pose.orientation.z =pose2.pose.orientation.z =pose3.pose.orientation.z =pose4.pose.orientation.z=0.707432532973
        pose1.pose.orientation.w=pose2.pose.orientation.w =pose3.pose.orientation.w =pose4.pose.orientation.w= 5.25452612264e-06  
        #为机械臂设置期望位姿，set_pose_target()函数包括两输入参数：末端期望位姿与末端执行器名字。
        manipulator.set_pose_target(pose1, arm_6_link )        
        #规划并执行运动轨迹
        manipulator.go()  
        #traj =manipulator.plan()
        #manipulator.execute(traj)          
        #机械臂笛卡尔空间轨迹规划
        manipulator.set_planning_time(5)         
        circleCenter=range(7)
        #得到圆轨迹圆心坐标
        circleCenter[0]=pose1.pose.position.x
        circleCenter[1]= pose1.pose.position.y+radius
        circleCenter[2]= pose1.pose.position.z
        circleCenter[3]=pose1.pose.orientation.x  
        circleCenter[4]=pose1.pose.orientation.y  
        circleCenter[5]=pose1.pose.orientation.z 
        circleCenter[6]=pose1.pose.orientation.w 
        angle= 0.0      
        angle_resolution =6 #两个采样点间的角度值，减小可提高轨迹规划成功率
        d_angle = angle_resolution*3.1415926/180  #两个采样点间的弧度值
        y_center = circleCenter[1]  
        z_center = circleCenter[2]     
        #初始化用于存储末端轨迹点变量waypoints1、然后将一系列期望轨迹点添加进去
        waypoints1 = []
        #使用get_current_pose()函数获取末端当前位姿，并加入waypoints1中
        start_pose = manipulator.get_current_pose(arm_6_link).pose
        wpose = deepcopy(start_pose)
        waypoints1.append(deepcopy(wpose))    
        #采样圆上的点
        print "============ cartesian_plan1"   
        for i in range(1,360/angle_resolution):
          angle+= d_angle
          wpose.position.y= y_center-radius*math.cos(angle)  
          wpose.position.z= z_center+radius*math.sin(angle)    
          print(wpose.position.x, wpose.position.y, wpose.position.z, wpose.orientation.x, wpose.orientation.y, wpose.orientation.z, wpose.orientation.w)  
          waypoints1.append(deepcopy(wpose))        
         #使用compute_cartesian_path()函数计算笛卡尔空间轨迹，输入参数包括
        (cartesian_plan1, fraction) = manipulator.compute_cartesian_path (
                                        waypoints1,   # waypoint poses
                                        0.02,        # eef_step 插值分辨率1cm
                                        0.0,         # jump_threshold 跳跃阈值
                                        True)        # avoid_collisions 是否需要避障    
        #traj =cartesian_plan1                               
        manipulator.execute(cartesian_plan1)
        #print "============ Visualizing cartesian_plan1"
        #display_trajectory = moveit_msgs.msg.DisplayTrajectory()
        #display_trajectory.trajectory_start = robot.get_current_state()
        #display_trajectory.trajectory.append(cartesian_plan1)
        #display_trajectory_publisher.publish(display_trajectory);
        #print "============ Waiting while cartesian_plan1 is visualized"   
        rospy.sleep(1)


        manipulator.set_pose_target(pose2, arm_6_link )        
        #规划并执行运动轨迹
        manipulator.go()
        #traj =manipulator.plan()
        #manipulator.execute(traj)  
        manipulator.set_planning_time(5)      
        angle= 0.0      
        circleCenter[1]= pose2.pose.position.y
        y_center = circleCenter[1]        
        waypoints2 = []
        start_pose = manipulator.get_current_pose(arm_6_link).pose
        wpose = deepcopy(start_pose)
        waypoints2.append(deepcopy(wpose))    
        #采样圆上的点  
        print "============ cartesian_plan2" 
        for i in range(1,360/angle_resolution):
          angle+= d_angle
          wpose.position.y= y_center-radius*math.cos(angle)  
          wpose.position.z= z_center+radius*math.sin(angle)      
          print(wpose.position.x, wpose.position.y, wpose.position.z, wpose.orientation.x, wpose.orientation.y, wpose.orientation.z, wpose.orientation.w)  
          waypoints2.append(deepcopy(wpose))    
         #使用compute_cartesian_path()函数计算笛卡尔空间轨迹，输入参数包括
        (cartesian_plan2, fraction) = manipulator.compute_cartesian_path (
                                        waypoints2,   # waypoint poses
                                        0.02,        # eef_step 插值分辨率1cm
                                        0.0,         # jump_threshold 跳跃阈值
                                        True)        # avoid_collisions 是否需要避障                            
        #traj =cartesian_plan2
        manipulator.execute(cartesian_plan2)
        rospy.sleep(1)


        manipulator.set_pose_target(pose3, arm_6_link )        
        #规划并执行运动轨迹
        manipulator.go()
        #traj =manipulator.plan()
        #manipulator.execute(traj)  
        manipulator.set_planning_time(5)      
        angle= 0.0      
        circleCenter[1]= pose3.pose.position.y
        y_center = circleCenter[1]         
        waypoints3 = []
        start_pose = manipulator.get_current_pose(arm_6_link).pose
        wpose = deepcopy(start_pose)
        waypoints3.append(deepcopy(wpose)) 
        print "============ cartesian_plan3"    
        #采样圆上的点  
        for i in range(1,360/angle_resolution):
          angle+= d_angle
          wpose.position.y= y_center-radius*math.cos(angle)  
          wpose.position.z= z_center+radius*math.sin(angle)   
          print(wpose.position.x, wpose.position.y, wpose.position.z, wpose.orientation.x, wpose.orientation.y, wpose.orientation.z, wpose.orientation.w)  
          waypoints3.append(deepcopy(wpose))    
         #使用compute_cartesian_path()函数计算笛卡尔空间轨迹，输入参数包括
        (cartesian_plan3, fraction) = manipulator.compute_cartesian_path (
                                        waypoints3,   # waypoint poses
                                        0.02,        # eef_step 插值分辨率1cm
                                        0.0,         # jump_threshold 跳跃阈值
                                        True)        # avoid_collisions 是否需要避障                            
        #traj =cartesian_plan3
        manipulator.execute(cartesian_plan3)
        rospy.sleep(1)


        manipulator.set_pose_target(pose4, arm_6_link )        
        #规划并执行运动轨迹
        manipulator.go()
        #traj =manipulator.plan()
        #manipulator.execute(traj)  
        manipulator.set_planning_time(5)      
        angle= 0.0      
        circleCenter[1]= pose4.pose.position.y
        y_center = circleCenter[1]         
        waypoints4 = []
        start_pose = manipulator.get_current_pose(arm_6_link).pose
        wpose = deepcopy(start_pose)
        waypoints4.append(deepcopy(wpose))    
        #采样圆上的点  
        print "============ cartesian_plan4" 
        for i in range(1,360/angle_resolution):
          angle+= d_angle
          wpose.position.y= y_center-radius*math.cos(angle)  
          wpose.position.z= z_center+radius*math.sin(angle)   
          print(wpose.position.x, wpose.position.y, wpose.position.z, wpose.orientation.x, wpose.orientation.y, wpose.orientation.z, wpose.orientation.w)  
          waypoints4.append(deepcopy(wpose))    
         #使用compute_cartesian_path()函数计算笛卡尔空间轨迹，输入参数包括
        (cartesian_plan4, fraction) = manipulator.compute_cartesian_path (
                                        waypoints4,   # waypoint poses
                                        0.02,        # eef_step 插值分辨率1cm
                                        0.0,         # jump_threshold 跳跃阈值
                                        True)        # avoid_collisions 是否需要避障                            
        #traj =cartesian_plan4
        manipulator.execute(cartesian_plan4)
        rospy.sleep(1)

        manipulator.set_named_target('home')
        manipulator.go()    
        #traj =manipulator.plan()
        #manipulator.execute(traj)  
        rospy.sleep(2)    
        moveit_commander.roscpp_shutdown()   




        #traj_joint = Float32MultiArray()
        #traj_joint.data = [0,0,0,0,0,0,0]       
        # Get the number of joints involved
        # n_joints = len(traj.joint_trajectory.joint_names)       
        # Get the number of points on the trajectory
        #n_points = len(traj.joint_trajectory.points)       
        # Cycle through all points and joints and scale the time from start,
        # as well as joint speed and acceleration
        #now_time = 0
        #last_time = 0
        # for i in range(n_points):           
            # The joint positions are not scaled so pull them out first
            #traj_joint.data = traj.joint_trajectory.points[i].positions
            #trajectory_pos_pub.publish(traj_joint)
            #traj_joint.data = traj.joint_trajectory.points[i].velocities
            #trajectory_vel_pub.publish(traj_joint)
            #now_time = traj.joint_trajectory.points[i].time_from_start.secs+traj.joint_trajectory.points[i].time_from_start.nsecs*1.0/1000000000
            #tim = now_time-last_time
            #last_time = now_time
            #print tim
            #rospy.sleep(tim)     
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
    
    
    
