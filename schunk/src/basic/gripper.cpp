// 包含moveit的API头文件
#include <moveit/move_group_interface/move_group.h> 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle;
  //这个数字代表什么  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  //声明move_group 
  moveit::planning_interface::MoveGroup group("gripper"); 
  //针对预设姿态进行轨迹规划和控制 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01); 
  // 进行运动规划，计算机器人移动到目标的运动轨迹，此时只是计算出轨迹，并不会控制机械臂运动
  moveit::planning_interface::MoveGroup::Plan my_plan;
  group.setNamedTarget("open");
  bool success = group.plan(my_plan); 
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");   
  //让机械臂按照规划的轨迹开始运动。
  //if(success)
  //    group.execute(my_plan);
 
  ros::shutdown(); 
  return 0;
}
