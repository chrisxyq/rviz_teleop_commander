// 包含miveit的API头文件
#include <moveit/move_group_interface/move_group.h>
 int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle; 
  ros::AsyncSpinner spinner(1);
  spinner.start();
  moveit::planning_interface::MoveGroup group("manipulator");
  // 设置机器人终端的目标位置
  geometry_msgs::Pose target_pose1;
  target_pose1.orientation.w = 8.94210443913e-07;
  target_pose1.orientation.x= -0.940773021084;
  target_pose1.orientation.y = -3.70796776407e-06;
  target_pose1.orientation.z = -0.339037052232;
  target_pose1.position.x = 0.391492418117;
  target_pose1.position.y =0.00527467536136;
  target_pose1.position.z = 0.945521678323;
  group.setPoseTarget(target_pose1);
  // 进行运动规划，计算机器人移动到目标的运动轨迹，此时只是计算出轨迹，并不会控制机械臂运动
  moveit::planning_interface::MoveGroup::Plan my_plan;
  bool success = group.plan(my_plan);
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");   
  //让机械臂按照规划的轨迹开始运动。
  if(success)
  group.execute(my_plan);
  ros::shutdown(); 
  return 0;
}
