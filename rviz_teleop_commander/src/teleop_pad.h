#ifndef TELEOP_PAD_H
#define TELEOP_PAD_H

//所需要包含的头文件
#include <ros/ros.h>
#include <ros/console.h>
#include <rviz/panel.h>   //plugin基类的头文件

class QPushButton;
class vector;
namespace rviz_teleop_commander
{
// 所有的plugin都必须是rviz::Panel的子类
class TeleopPanel: public rviz::Panel
{
// 后边需要用到Qt的信号和槽，都是QObject的子类，所以需要声明Q_OBJECT宏
Q_OBJECT
public:
  // 构造函数，在类中会用到QWidget的实例来实现GUI界面，这里先初始化为0即可
  TeleopPanel( QWidget* parent = 0 );

  // 公共槽.
public Q_SLOTS:
  // 内部槽.
private Q_SLOTS:
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
  void on_move_btn();          

  // 内部变量.
protected:
  // 末端绕x平移输入框
  QPushButton* tran_x_add_btn;  
  QPushButton* tran_x_btn;    
  // 末端绕y平移输入框
  QPushButton* tran_y_add_btn;  
  QPushButton* tran_y_btn;  
  // 末端绕z平移输入框
  QPushButton* tran_z_add_btn;  
  QPushButton* tran_z_btn;  
  // 末端绕x旋转输入框
  QPushButton* rot_x_anti_btn;  
  QPushButton* rot_x_btn;  
  // 末端绕y旋转输入框
  QPushButton* rot_y_anti_btn;  
  QPushButton* rot_y_btn;  
  // 末端绕z旋转输入框
  QPushButton* rot_z_anti_btn; 
  QPushButton* rot_z_btn;  
  //按下使实际机械臂运动
  QPushButton* home_btn; 
  QPushButton* pos1_btn;  
  QPushButton* move_btn; 
};

} // end namespace rviz_teleop_commander
  //int argc;
  //char **argv;
  //std::vector<double> rpy;
  //ros::init(argc, argv, "move_group_interface_tutorial");  
  // 创建一个异步的自旋线程（spinning thread） 
  //rpy=group.getCurrentRPY();
  //double r=rpy[0],p=rpy[1],w=rpy[2]; 
  //ROS_INFO("Move to : x=%f, y=%f, z=%f, r=%f, p=%f, w=%f",x,y,z,r,p,w);
  //group.setPositionTarget(x,y,z);  
  // (waits for the execution of the trajectory to complete) 
  //and requires an asynchronous spinner to be started. 
  //group.move();

#endif // TELEOP_PANEL_H
