#include <stdio.h>
#include <iostream>
using namespace std;
#include <QApplication>
#include <QPainter>
#include <QPushButton>
//垂直布局
#include <QVBoxLayout>
//水平布局
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <ros/ros.h>
#include <moveit/move_group_interface/move_group.h> 
#include "teleop_pad.h"

namespace rviz_teleop_commander
{
// 构造函数，初始化变量
TeleopPanel::TeleopPanel( QWidget* parent )
  : rviz::Panel( parent )
{
  QVBoxLayout* tran_layout = new QVBoxLayout;
  // 创建末端绕x平移的窗口
  tran_x_add_btn = new QPushButton( "tran_x+" );
  tran_layout->addWidget(tran_x_add_btn);
  tran_x_btn = new QPushButton( "tran_x-" );
  tran_layout->addWidget(tran_x_btn);
  // 创建末端绕y平移的窗口
  tran_y_add_btn = new QPushButton( "tran_y+" );
  tran_layout->addWidget(tran_y_add_btn);
  tran_y_btn = new QPushButton( "tran_y-" );
  tran_layout->addWidget(tran_y_btn);
  // 创建末端绕z平移的窗口
  tran_z_add_btn = new QPushButton( "tran_z+" ); 
  tran_layout->addWidget(tran_z_add_btn);
  tran_z_btn = new QPushButton( "tran_z-" ); 
  tran_layout->addWidget(tran_z_btn);
  QVBoxLayout* rot_layout = new QVBoxLayout;
  // 创建末端绕x旋转的窗口
  rot_x_anti_btn = new QPushButton( "rot_x_anti" );
  rot_layout->addWidget(rot_x_anti_btn);
  rot_x_btn = new QPushButton( "rot_x" );
  rot_layout->addWidget(rot_x_btn);
  // 创建末端绕y旋转的窗口
  rot_y_anti_btn = new QPushButton( "rot_y_anti" );
  rot_layout->addWidget(rot_y_anti_btn);
  rot_y_btn = new QPushButton( "rot_y" );
  rot_layout->addWidget(rot_y_btn);
  // 创建末端绕z旋转的窗口
  rot_z_anti_btn = new QPushButton( "rot_z_anti" );
  rot_layout->addWidget(rot_z_anti_btn);
  rot_z_btn = new QPushButton( "rot_z" );
  rot_layout->addWidget(rot_z_btn);
  // 创建使实际机械臂运动的窗口
  QVBoxLayout* move_layout = new QVBoxLayout;
  home_btn = new QPushButton( "home" );
  move_layout->addWidget(home_btn);
  pos1_btn = new QPushButton( "pos1" );
  move_layout->addWidget(pos1_btn);
  move_btn = new QPushButton( "move" );
  move_layout->addWidget(move_btn);

  QHBoxLayout* layout = new QHBoxLayout;
  layout->addLayout( tran_layout );
  layout->addLayout( rot_layout );
  layout->addLayout( move_layout );
  setLayout( layout );


  // 设置信号与槽的连接
  connect( tran_x_add_btn, SIGNAL( clicked() ), this, SLOT( on_tran_x_add_btn() ));          
  connect( tran_y_add_btn, SIGNAL( clicked() ), this, SLOT( on_tran_y_add_btn() )); 
  connect( tran_z_add_btn, SIGNAL( clicked() ), this, SLOT( on_tran_z_add_btn() ));
  connect( tran_x_btn, SIGNAL( clicked() ), this, SLOT( on_tran_x_btn() ));          
  connect( tran_y_btn, SIGNAL( clicked() ), this, SLOT( on_tran_y_btn() )); 
  connect( tran_z_btn, SIGNAL( clicked() ), this, SLOT( on_tran_z_btn() ));

  connect( rot_x_anti_btn, SIGNAL( clicked() ), this, SLOT( on_rot_x_anti_btn() ));          
  connect( rot_y_anti_btn, SIGNAL( clicked() ), this, SLOT( on_rot_y_anti_btn() )); 
  connect( rot_z_anti_btn, SIGNAL( clicked() ), this, SLOT( on_rot_z_anti_btn() ));
  connect( rot_x_btn, SIGNAL( clicked() ), this, SLOT( on_rot_x_btn() ));          
  connect( rot_y_btn, SIGNAL( clicked() ), this, SLOT( on_rot_y_btn() )); 
  connect( rot_z_btn, SIGNAL( clicked() ), this, SLOT( on_rot_z_btn() ));
  connect( home_btn, SIGNAL( clicked() ), this, SLOT( on_home_btn() ));
  connect( pos1_btn, SIGNAL( clicked() ), this, SLOT( on_pos1_btn() ));
  connect( move_btn, SIGNAL( clicked() ), this, SLOT( on_move_btn() ));

}

// 末端沿x平移
void TeleopPanel::on_tran_x_add_btn()
{
  if( ros::ok() )
  {
  ros::AsyncSpinner spinner(1);
  spinner.start();   
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  geometry_msgs::Pose goal; 
  //k=1时，移动1m
  double k=0.05;
  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;
  cout<<"X :"<<group.getCurrentPose().pose.orientation.x<<" Y :"<<group.getCurrentPose().pose.orientation.y
  <<" Z :"<<group.getCurrentPose().pose.orientation.z<<" W:"<<group.getCurrentPose().pose.orientation.w<<endl;
  goal.position.x = group.getCurrentPose().pose.position.x+k*(x*x+w*w-z*z-y*y);
  goal.position.y = group.getCurrentPose().pose.position.y+k*2*(x*y+z*w);
  goal.position.z = group.getCurrentPose().pose.position.z+k*2*(x*z-y*w);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  group.execute(my_plan);
  }
}

void TeleopPanel::on_tran_x_btn()
{
  if( ros::ok() )
  {
  ros::AsyncSpinner spinner(1);
  spinner.start();   
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  geometry_msgs::Pose goal; 
  //k=1时，移动1m
  double k=-0.05;
  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;
  cout<<"X :"<<group.getCurrentPose().pose.orientation.x<<" Y :"<<group.getCurrentPose().pose.orientation.y
  <<" Z :"<<group.getCurrentPose().pose.orientation.z<<" W:"<<group.getCurrentPose().pose.orientation.w<<endl;
  goal.position.x = group.getCurrentPose().pose.position.x+k*(x*x+w*w-z*z-y*y);
  goal.position.y = group.getCurrentPose().pose.position.y+k*2*(x*y+z*w);
  goal.position.z = group.getCurrentPose().pose.position.z+k*2*(x*z-y*w);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  group.execute(my_plan);
  }
}
// 末端沿y平移
void TeleopPanel::on_tran_y_add_btn()
{
  if( ros::ok() )
  {
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  geometry_msgs::Pose goal; 
  //k=1时，移动1m
  double k=0.05;
  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;
  cout<<"X :"<<group.getCurrentPose().pose.orientation.x<<" Y :"<<group.getCurrentPose().pose.orientation.y
  <<" Z :"<<group.getCurrentPose().pose.orientation.z<<" W:"<<group.getCurrentPose().pose.orientation.w<<endl;
  goal.position.x = group.getCurrentPose().pose.position.x+k*2*(x*y-z*w);
  goal.position.y = group.getCurrentPose().pose.position.y+k*(y*y+w*w-z*z-x*x);
  goal.position.z = group.getCurrentPose().pose.position.z+k*2*(y*z+x*w);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  group.execute(my_plan);
  }
}

void TeleopPanel::on_tran_y_btn()
{
  if( ros::ok() )
  {
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  geometry_msgs::Pose goal; 
  //k=1时，移动1m
  double k=-0.05;
  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;
  cout<<"X :"<<group.getCurrentPose().pose.orientation.x<<" Y :"<<group.getCurrentPose().pose.orientation.y
  <<" Z :"<<group.getCurrentPose().pose.orientation.z<<" W:"<<group.getCurrentPose().pose.orientation.w<<endl;
  goal.position.x = group.getCurrentPose().pose.position.x+k*2*(x*y-z*w);
  goal.position.y = group.getCurrentPose().pose.position.y+k*(y*y+w*w-z*z-x*x);
  goal.position.z = group.getCurrentPose().pose.position.z+k*2*(y*z+x*w);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  group.execute(my_plan);
  }
}

// 末端沿z平移
void TeleopPanel::on_tran_z_add_btn()
{
  if( ros::ok() )
  {
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  geometry_msgs::Pose goal; 
  //k=1时，移动1m
  double k=0.05;
  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;
  cout<<"X :"<<group.getCurrentPose().pose.orientation.x<<" Y :"<<group.getCurrentPose().pose.orientation.y
  <<" Z :"<<group.getCurrentPose().pose.orientation.z<<" W:"<<group.getCurrentPose().pose.orientation.w<<endl;
  goal.position.x = group.getCurrentPose().pose.position.x+k*2*(x*z+y*w);
  goal.position.y = group.getCurrentPose().pose.position.y+k*2*(y*z-x*w);
  goal.position.z = group.getCurrentPose().pose.position.z+k*(z*z+w*w-y*y-x*x);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  group.execute(my_plan);
  }
}

void TeleopPanel::on_tran_z_btn()
{
  if( ros::ok() )
  {
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  geometry_msgs::Pose goal; 
  //k=1时，移动1m
  double k=-0.05;
  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;
  cout<<"X :"<<group.getCurrentPose().pose.orientation.x<<" Y :"<<group.getCurrentPose().pose.orientation.y
  <<" Z :"<<group.getCurrentPose().pose.orientation.z<<" W:"<<group.getCurrentPose().pose.orientation.w<<endl;
  goal.position.x = group.getCurrentPose().pose.position.x+k*2*(x*z+y*w);
  goal.position.y = group.getCurrentPose().pose.position.y+k*2*(y*z-x*w);
  goal.position.z = group.getCurrentPose().pose.position.z+k*(z*z+w*w-y*y-x*x);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  group.execute(my_plan);
  }
}

// 末端绕x旋转
void TeleopPanel::on_rot_x_anti_btn()
{
  if( ros::ok() )
  {
  // 创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  //声明move_group 
  moveit::planning_interface::MoveGroup group("arm"); 
  //针对预设姿态进行轨迹规划和控制 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  //Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;   
  double pi=3.1415926;
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  //n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=(x*x+w*w-z*z-y*y);
  n[1]=2*(x*y+z*w);
  n[2]=2*(x*z-y*w);
  //k为绕末端坐标系x轴转动角度
  double k=20;
  q[0]=cos(k*pi/360);
  q[1]=n[0]*sin(k*pi/360);
  q[2]=n[1]*sin(k*pi/360);
  q[3]=n[2]*sin(k*pi/360);
  goal.orientation.x = q[0]*x+q[1]*w+q[2]*z-q[3]*y;
  goal.orientation.y = q[0]*y-q[1]*z+q[2]*w+q[3]*x;
  goal.orientation.z = q[0]*z+q[1]*y-q[2]*x+q[3]*w;
  goal.orientation.w = q[0]*w-q[1]*x-q[2]*y-q[3]*z;
  goal.position.x = group.getCurrentPose().pose.position.x;
  goal.position.y = group.getCurrentPose().pose.position.y;
  goal.position.z = group.getCurrentPose().pose.position.z;
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  //group.move();
  group.execute(my_plan);
  }
}

void TeleopPanel::on_rot_x_btn()
{
  if( ros::ok() )
  {
  // 创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  //声明move_group 
  moveit::planning_interface::MoveGroup group("arm"); 
  //针对预设姿态进行轨迹规划和控制 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  //Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;   
  double pi=3.1415926;
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  //n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=(x*x+w*w-z*z-y*y);
  n[1]=2*(x*y+z*w);
  n[2]=2*(x*z-y*w);
  //k为绕末端坐标系x轴转动角度
  double k=-20;
  q[0]=cos(k*pi/360);
  q[1]=n[0]*sin(k*pi/360);
  q[2]=n[1]*sin(k*pi/360);
  q[3]=n[2]*sin(k*pi/360);
  goal.orientation.x = q[0]*x+q[1]*w+q[2]*z-q[3]*y;
  goal.orientation.y = q[0]*y-q[1]*z+q[2]*w+q[3]*x;
  goal.orientation.z = q[0]*z+q[1]*y-q[2]*x+q[3]*w;
  goal.orientation.w = q[0]*w-q[1]*x-q[2]*y-q[3]*z;
  goal.position.x = group.getCurrentPose().pose.position.x;
  goal.position.y = group.getCurrentPose().pose.position.y;
  goal.position.z = group.getCurrentPose().pose.position.z;
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  //group.move();
  group.execute(my_plan);
  }
}

// 末端绕y旋转
void TeleopPanel::on_rot_y_anti_btn()
{
  if( ros::ok() )
  {
  // 创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  //声明move_group 
  moveit::planning_interface::MoveGroup group("arm"); 
  //针对预设姿态进行轨迹规划和控制 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  //Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;   
  double pi=3.1415926;
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  //n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=2*(x*y-z*w);
  n[1]=(y*y+w*w-z*z-x*x);
  n[2]=2*(y*z+x*w);
  //k为绕末端坐标系x轴转动角度
  double k=20;
  q[0]=cos(k*pi/360);
  q[1]=n[0]*sin(k*pi/360);
  q[2]=n[1]*sin(k*pi/360);
  q[3]=n[2]*sin(k*pi/360);
  goal.orientation.x = q[0]*x+q[1]*w+q[2]*z-q[3]*y;
  goal.orientation.y = q[0]*y-q[1]*z+q[2]*w+q[3]*x;
  goal.orientation.z = q[0]*z+q[1]*y-q[2]*x+q[3]*w;
  goal.orientation.w = q[0]*w-q[1]*x-q[2]*y-q[3]*z;
  goal.position.x = group.getCurrentPose().pose.position.x;
  goal.position.y = group.getCurrentPose().pose.position.y;
  goal.position.z = group.getCurrentPose().pose.position.z;
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  //group.move();
  group.execute(my_plan);
  }
}

void TeleopPanel::on_rot_y_btn()
{
  if( ros::ok() )
  {
  // 创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  //声明move_group 
  moveit::planning_interface::MoveGroup group("arm"); 
  //针对预设姿态进行轨迹规划和控制 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  //Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;   
  double pi=3.1415926;
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  //n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=2*(x*y-z*w);
  n[1]=(y*y+w*w-z*z-x*x);
  n[2]=2*(y*z+x*w);
  //k为绕末端坐标系x轴转动角度
  double k=-20;
  q[0]=cos(k*pi/360);
  q[1]=n[0]*sin(k*pi/360);
  q[2]=n[1]*sin(k*pi/360);
  q[3]=n[2]*sin(k*pi/360);
  goal.orientation.x = q[0]*x+q[1]*w+q[2]*z-q[3]*y;
  goal.orientation.y = q[0]*y-q[1]*z+q[2]*w+q[3]*x;
  goal.orientation.z = q[0]*z+q[1]*y-q[2]*x+q[3]*w;
  goal.orientation.w = q[0]*w-q[1]*x-q[2]*y-q[3]*z;
  goal.position.x = group.getCurrentPose().pose.position.x;
  goal.position.y = group.getCurrentPose().pose.position.y;
  goal.position.z = group.getCurrentPose().pose.position.z;
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  //group.move();
  group.execute(my_plan);
  }
}


// 末端绕z旋转
void TeleopPanel::on_rot_z_anti_btn()
{
  if( ros::ok() )
  {
  // 创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  //声明move_group 
  moveit::planning_interface::MoveGroup group("arm"); 
  //针对预设姿态进行轨迹规划和控制 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  //Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;   
  double pi=3.1415926;
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  //n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=2*(x*z+y*w);
  n[1]=2*(y*z-x*w);
  n[2]=(z*z+w*w-y*y-x*x);
  //k为绕末端坐标系x轴转动角度
  double k=20;
  q[0]=cos(k*pi/360);
  q[1]=n[0]*sin(k*pi/360);
  q[2]=n[1]*sin(k*pi/360);
  q[3]=n[2]*sin(k*pi/360);
  goal.orientation.x = q[0]*x+q[1]*w+q[2]*z-q[3]*y;
  goal.orientation.y = q[0]*y-q[1]*z+q[2]*w+q[3]*x;
  goal.orientation.z = q[0]*z+q[1]*y-q[2]*x+q[3]*w;
  goal.orientation.w = q[0]*w-q[1]*x-q[2]*y-q[3]*z;
  goal.position.x = group.getCurrentPose().pose.position.x;
  goal.position.y = group.getCurrentPose().pose.position.y;
  goal.position.z = group.getCurrentPose().pose.position.z;
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  //group.move();
  group.execute(my_plan);
  }
}

void TeleopPanel::on_rot_z_btn()
{
  if( ros::ok() )
  {
  // 创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  //声明move_group 
  moveit::planning_interface::MoveGroup group("arm"); 
  //针对预设姿态进行轨迹规划和控制 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01);  
  //Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;   
  double pi=3.1415926;
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  //n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=2*(x*z+y*w);
  n[1]=2*(y*z-x*w);
  n[2]=(z*z+w*w-y*y-x*x);
  //k为绕末端坐标系x轴转动角度
  double k=-20;
  q[0]=cos(k*pi/360);
  q[1]=n[0]*sin(k*pi/360);
  q[2]=n[1]*sin(k*pi/360);
  q[3]=n[2]*sin(k*pi/360);
  goal.orientation.x = q[0]*x+q[1]*w+q[2]*z-q[3]*y;
  goal.orientation.y = q[0]*y-q[1]*z+q[2]*w+q[3]*x;
  goal.orientation.z = q[0]*z+q[1]*y-q[2]*x+q[3]*w;
  goal.orientation.w = q[0]*w-q[1]*x-q[2]*y-q[3]*z;
  goal.position.x = group.getCurrentPose().pose.position.x;
  goal.position.y = group.getCurrentPose().pose.position.y;
  goal.position.z = group.getCurrentPose().pose.position.z;
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan); 
  //group.move();
  group.execute(my_plan);
  }
}


void TeleopPanel::on_home_btn()
{
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01); 
  moveit::planning_interface::MoveGroup::Plan my_plan;
  group.setNamedTarget("home");
  bool success = group.plan(my_plan); 
  if(success)
    group.execute(my_plan);
}

void TeleopPanel::on_pos1_btn()
{
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01); 
  moveit::planning_interface::MoveGroup::Plan my_plan;
  group.setNamedTarget("pos1");
  bool success = group.plan(my_plan); 
  if(success)
    group.execute(my_plan);
}


// 使实际机械臂运动
void TeleopPanel::on_move_btn()
{
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor(0.15);
  group.setMaxAccelerationScalingFactor(0.01); 
  group.move(); 
}

} // end namespace rviz_teleop_commander
// 声明此类是一个rviz的插件
#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_teleop_commander::TeleopPanel,rviz::Panel )
// END_TUTORIAL
