#ifndef TELEOP_PAD_H
#define TELEOP_PAD_H

//所需要包含的头文件
#include <ros/ros.h>
#include <ros/console.h>
#include <rviz/panel.h>   //plugin基类的头文件
#include <moveit/move_group_interface/move_group.h> 
#include <string>

#include <QPushButton>

#include <QRadioButton>
#include <QButtonGroup>
#include <QComboBox> 
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

#include <QTreeView>
#include <QHeaderView>
#include <QFileSystemModel>
#include <QListView>
#include <QDirModel>
#include <QScrollArea>


#include <QPainter> 
#include <QMouseEvent> 

#include <iostream>
#include <fstream>

#include <QFileDialog>  
#include <QWidget> 
#include <QFile>  
#include <QIODevice>  
#include <QTextStream>  
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
  void on_fresh_state();
  void onRadioClick();
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
  void on_sure_btn();
  void on_gorecord_btn();
  void on_gripper_open_btn(); 
  void on_gripper_close_btn();   
  // void pictureShow(const QModelIndex &index);  
  void on_openfileBtn();
  void on_dealdtBtn();
  // void on_dealdtBtn2();
 

  
  // 内部槽.
private Q_SLOTS:
  //void slotSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected); 
  void on_tfcombox(int index);
  void on_tfcombox2(int index);

  void on_ddtz_btn();
  void on_cczx_btn();
         

  // 内部变量.
protected:  
  QSpinBox* Angle;
  QDoubleSpinBox* translationstep;
  QDoubleSpinBox* velo;
  QDoubleSpinBox* acc; 
  QPushButton* use_default;  
  QPushButton* fresh_state;  
  QButtonGroup *btnGroup;
  QRadioButton *radian_radio;
  QRadioButton *angle_radio;


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
  QLineEdit* posrecord_name;
  //tf
  QLineEdit* tool_X;
  QLineEdit* tool_Y;
  QLineEdit* tool_Z;
  QLineEdit* tool_x;
  QLineEdit* tool_y;
  QLineEdit* tool_z;
  QLineEdit* tool_w;
  QLineEdit* ctbedtf_delta_X;
  QLineEdit* ctbedtf_delta_Y;
  QLineEdit* ctbedtf_delta_Z;
  QLineEdit* ctbedtf_X;
  QLineEdit* ctbedtf_Y;
  QLineEdit* ctbedtf_Z;
  QLineEdit* mantf_delta_X;
  QLineEdit* mantf_delta_Y;
  QLineEdit* mantf_delta_Z;

 
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
  QPushButton* sure_btn; 
  QPushButton* gorecord_btn;
 
  QComboBox *combox;
  QComboBox *combox2;
  QPushButton* gripper_open_btn;  
  QPushButton* gripper_close_btn; 

  QPushButton* sure_tf_btn;  
  QPushButton* edit_tf_btn; 

  // QFileSystemModel *model;
  // QTreeView *treeView;
  // QListView *view;
  // QSplitter *splitterMain;
  // QSplitter *splitterRight;
  // QLabel *ctpic_label;
  // QLineEdit* target_spot;
  // QLineEdit* entry_spot;
  // QPushButton* choose_target_btn; 
  // QPushButton* choose_entry_btn; 
  // QPushButton* determine_traj_btn; 
  // QPushButton* clear_traj_btn; 
  // QPushButton* edit_traj_btn; 

  //page3
  // QPushButton* openfileBtn;
  // QPushButton* dealdtBtn;
  // // QPushButton* dealdtBtn2;     
  // // QTextEdit* fileshowText; 
  // QLabel* fileshowText;
  // QComboBox *tfcombox;
  // QComboBox *tfcombox2;
  // QLineEdit* needlept_X;
  // QLineEdit* needlept_Y;
  // QLineEdit* needlept_Z;
  // QLineEdit* targetpt_X;
  // QLineEdit* targetpt_Y;
  // QLineEdit* targetpt_Z;
  
  QLineEdit* tg_X;
  QLineEdit* tg_Y;
  QLineEdit* tg_Z;
  QLineEdit* XYZW_X;
  QLineEdit* XYZW_Y;
  QLineEdit* XYZW_Z;
  QLineEdit* XYZW_W;
  QLineEdit* H;
  QPushButton* ddtz_btn;
  QPushButton* cczx_btn;

 

  
  // k=1时，移动1m
  double k;
  // p为绕末端坐标系x轴转动角度
  double p;
  double pi; 
  double T;
 
 
  
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
  int combox2_num;
};
} 
#endif // TELEOP_PANEL_H