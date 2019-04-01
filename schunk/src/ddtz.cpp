#include <ros/ros.h>
#include <moveit/move_group_interface/move_group.h> 
int main(int argc, char **argv)
{ 
  //第三个参数是节点的名字，实现ros程序的参数与命令行输入的匹配
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm");  
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01); 
  group.setNamedTarget("pos1");

  moveit::planning_interface::MoveGroup::Plan my_plan;
  bool success = group.plan(my_plan); 
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");  
  //让机械臂按照预设速度和加速度实际运动。
  if(success)
    group.execute(my_plan);
  //仅指定末端姿态，每次末端位置随机
  group.setOrientationTarget(0.0005,-0.3367,-0.9416,0.0002);
  moveit::planning_interface::MoveGroup::Plan my_plan2;
  bool success2 = group.plan(my_plan2); 
  ROS_INFO("Visualizing plan 2 (pose goal) %s",success2?"":"FAILED");  
  //让机械臂按照预设速度和加速度实际运动。
  if(success2)
    group.execute(my_plan2);
  ros::shutdown(); 
  return 0;
}
