// 包含moveit的API头文件
#include <ros/ros.h>
#include <moveit/move_group_interface/move_group.h> 
//int main(int argc, char **argv)

int main()
{
  int argc;
  char **argv;
  //前两个参数确定，第三个参数是节点的名字，实现ros程序的参数与命令行输入的匹配
  ros::init(argc, argv, "move_group_interface_tutorial");
  //NodeHandle 是一个主要的与Ros系统交流的访问点
  //ros::NodeHandle node_handle;
  //这个数字代表什么  
  //ros::AsyncSpinner spinner(1);
  //spinner.start(); 
  //声明move_group 
  moveit::planning_interface::MoveGroup group("arm"); 
  //针对预设姿态进行轨迹规划和控制 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01); 
  group.getEndEffectorLink();
  //Get the pose for the end-effector end_effector_link.   
  double x=group.getCurrentPose().pose.position.x;
  double y=group.getCurrentPose().pose.position.y;
  double z=group.getCurrentPose().pose.position.z-0.01;
  ROS_INFO("Move to : x=%f, y=%f, z=%f",x,y,z);
  group.setPositionTarget(x,y,z);  
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  group.move(); 
  ros::shutdown(); 
  //return 0;
}
