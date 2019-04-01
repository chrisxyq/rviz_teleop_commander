#!/usr/bin/env python
#-*-coding:utf-8 -*-
import rospy, sys
# 导入moveit_commander接口，该接口提供控制机械臂的函数
import moveit_commander
from control_msgs.msg import GripperCommand
class MoveItDemo:
    def __init__(self):
        # Initialize the move_group API
        moveit_commander.roscpp_initialize(sys.argv)
        # Initialize the ROS node
        rospy.init_node('moveit_demo', anonymous=True)
        # 定义位于moveit_commander库中的MoveGroupCommander类的对象，用于控制特定规划组，传入参数为规划组名称，如manipulator
        gripper = moveit_commander.MoveGroupCommander('gripper')
        gripper.set_goal_position_tolerance(0.01)
        gripper.set_named_target('open')
        gripper.go()
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
