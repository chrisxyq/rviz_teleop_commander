#ifndef TELEOP_PAD_H
#define TELEOP_PAD_H

//所需要包含的头文件
#include <ros/ros.h>
#include <ros/console.h>
#include <rviz/panel.h>   //plugin基类的头文件
#include <moveit/move_group_interface/move_group.h> 
#include <string>

#include <QPushButton>
#include <QTabWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextBrowser>
#include <QSplitter>  
#include <QTextCodec> 
#include <QLabel> 
#include <QTimer>
#include <QDebug>


#include <iostream>
#include <fstream>
using namespace std;

class QTabWidget; 

 
namespace rviz_teleop_commander
{

// 所有的plugin都必须是rviz::Panel的子类
class Schunk: public rviz::Panel
{
// 后边需要用到Qt的信号和槽，都是QObject的子类，所以需要声明Q_OBJECT宏
Q_OBJECT
public:
  // 构造函数，在类中会用到QWidget的实例来实现GUI界面，这里先初始化为0即可
  Schunk( QWidget* parent = 0 );

  // 公共槽.
protected Q_SLOTS: 

  void on_use_default();
  void on_tran_x_add_btn(); 
  void on_tran_x_btn(); 
  void on_tran_y_add_btn();  
  void on_tran_y_btn();
  void on_tran_z_add_btn();  
  void on_tran_z_btn(); 
  void on_rot_x_anti_btn(); 
  void on_rot_x_btn();
  void on_rot_y_anti_btn();  
  void on_rot_y_btn(); 
  void on_rot_z_anti_btn();
  void on_rot_z_btn();
  void on_home_btn(); 
  void on_pos1_btn();
  void on_gripper_open_btn(); 
  void on_gripper_close_btn();   
  // 内部槽.
private Q_SLOTS:
         

  // 内部变量.
protected:  
  QSpinBox* Angle;
  QDoubleSpinBox* translationstep;
  QDoubleSpinBox* velo;
  QDoubleSpinBox* acc; 
  QPushButton* use_default;  

  QLineEdit* j1state;
  QLineEdit* Xstate;
  QLineEdit* Quaternions_xstate;
  QLineEdit* j2state;
  QLineEdit* Ystate;
  QLineEdit* Quaternions_ystate;
  QLineEdit* j3state;
  QLineEdit* Zstate;
  QLineEdit* Quaternions_zstate;
  QLineEdit* j4state;
  QLineEdit* RXstate;
  QLineEdit* Quaternions_wstate;
  QLineEdit* j5state;
  QLineEdit* RYstate;
  QLineEdit* j6state;
  QLineEdit* RZstate;

 
  QPushButton* tran_x_add_btn;  
  QPushButton* tran_x_btn; 
  QPushButton* tran_y_add_btn;  
  QPushButton* tran_y_btn; 
  QPushButton* tran_z_add_btn;  
  QPushButton* tran_z_btn;  
  QPushButton* rot_x_anti_btn;  
  QPushButton* rot_x_btn;  
  QPushButton* rot_y_anti_btn;  
  QPushButton* rot_y_btn;  
  QPushButton* rot_z_anti_btn; 
  QPushButton* rot_z_btn;  
  QPushButton* home_btn; 
  QPushButton* pos1_btn;
  QPushButton* save_pose;
  QPushButton* move_traj;
  QPushButton* gripper_open_btn;  
  QPushButton* gripper_close_btn; 

  // k=1时，移动1m
  double k;
  // p为绕末端坐标系x轴转动角度
  double p;
  double pi; 
  
  //当前各关节角度值
  vector<double> jValues;
  //末端欧拉角
  vector<double> RPY; 
  //末端的xyz坐标
  double pos_x;
  double pos_y;
  double pos_z;
  double n[3];
  double q[4];
};
} 
#endif // TELEOP_PANEL_H
