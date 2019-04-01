#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <QWidget>
// 垂直布局
#include <QVBoxLayout>
// 水平布局
#include <QHBoxLayout>
#include <QGridLayout>
#include <qmessagebox.h>
#include <QGroupBox> 
#include <QTextCodec>
#include <QScrollArea>

#include "teleop_pad.h"

namespace rviz_teleop_commander
{
//  构造函数，初始化变量
Schunk::Schunk( QWidget* parent )
  : rviz::Panel( parent )
  ,k( )
  ,p( )  
  ,pi( 3.1415926 )
  ,T(180/pi)
  
  ,jValues()
  ,RPY( )
  ,pos_x( )
  ,pos_y( )
  ,pos_z( )
  ,combox2_num()

   
{ 
  QTabWidget *tabWidget = new QTabWidget(); 
  //tabWidget->setStyleSheet("background-color:white;");

  //新建第1个页面的部件   
  QWidget *widget1 = new QWidget();
  QVBoxLayout* paraset_layout = new QVBoxLayout;
  QHBoxLayout* H_para_layout1 = new QHBoxLayout;
  QHBoxLayout* H_para_layout2 = new QHBoxLayout;
  QHBoxLayout* H_para_layout3 = new QHBoxLayout;
  QHBoxLayout* H_para_layout4 = new QHBoxLayout;
  
  Angle = new QSpinBox(this);
  Angle->setRange(1,30);   
  Angle->setSingleStep(1);  
  Angle->setValue(20);         
  H_para_layout1->addWidget( new QLabel( QString::fromUtf8("单步旋转角度(°)") ));
  H_para_layout1->addWidget(Angle);
  
  translationstep = new QDoubleSpinBox(this);
  translationstep->setRange(10,300);    
  translationstep->setDecimals(1); 
  translationstep->setValue(20);  
  translationstep->setSingleStep(0.5);  
  H_para_layout2->addWidget( new QLabel( QString::fromUtf8("沿末端坐标系平移步长(mm)") ));
  H_para_layout2->addWidget(translationstep); 

  // Angular Velocity最大72°/s调整QDoubleSpinBox 
  velo = new QDoubleSpinBox(this);
  velo->setRange(1,20); 
  velo->setValue(10); 
  //设置显示的小数位数  
  velo->setDecimals(0);   
  velo->setSingleStep(1);   
  H_para_layout3->addWidget( new QLabel( QString::fromUtf8("关节角速度(°/s)") ));
  H_para_layout3->addWidget(velo);  
  
  // Angular Acceleration最大300°/s²调整QDoubleSpinBox 
  acc = new QDoubleSpinBox(this);
  acc->setRange(1,6);   
  acc->setValue(3);
  acc->setDecimals(1);   
  acc->setSingleStep(0.5);     
  H_para_layout4->addWidget( new QLabel( QString::fromUtf8("关节角加速度(°/s²)") ));
  H_para_layout4->addWidget(acc);

  use_default = new QPushButton( QString::fromUtf8("使用默认参数") ); 
  fresh_state = new QPushButton( QString::fromUtf8("刷新机械臂状态显示") ); 

  // 单位选择QButtonGroup
  btnGroup = new QButtonGroup();  
  angle_radio = new QRadioButton( QString::fromUtf8("角度") );
  radian_radio = new QRadioButton( QString::fromUtf8("弧度") );   
  btnGroup->addButton(angle_radio,0);     
  btnGroup->addButton(radian_radio,1); 
  angle_radio->setChecked(true); 
  QHBoxLayout *btnGroup_layout = new QHBoxLayout();  
  btnGroup_layout->addWidget(angle_radio);
  btnGroup_layout->addWidget(radian_radio);

  paraset_layout->addLayout(H_para_layout1); 
  paraset_layout->addLayout(H_para_layout2); 
  paraset_layout->addLayout(H_para_layout3); 
  paraset_layout->addLayout(H_para_layout4); 
  paraset_layout->addWidget(use_default);
  paraset_layout->addWidget(fresh_state);
  paraset_layout->addLayout(btnGroup_layout); 

  QVBoxLayout *paraset_GroupBox_layout = new QVBoxLayout();
  QGroupBox *paraset_GroupBox = new QGroupBox(QString::fromUtf8("运动参数设置"));
  paraset_GroupBox->setLayout(paraset_layout);
  paraset_GroupBox_layout->addWidget(paraset_GroupBox);  

  //参数定义赋值
  moveit::planning_interface::MoveGroup group("arm");  
  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;

  //jstate_GroupBox控件定义
  j1state = new QLineEdit();
  j1state->setReadOnly(true); 
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state = new QLineEdit();
  j2state->setReadOnly(true); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state = new QLineEdit();
  j3state->setReadOnly(true); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state = new QLineEdit();
  j4state->setReadOnly(true); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state = new QLineEdit();
  j5state->setReadOnly(true); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state = new QLineEdit();
  j6state->setReadOnly(true); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
    //jstate_GroupBox
  QVBoxLayout* jstate_layout = new QVBoxLayout;
  QHBoxLayout* H_jstate_layout1 = new QHBoxLayout;
  QHBoxLayout* H_jstate_layout2 = new QHBoxLayout;
  QHBoxLayout* H_jstate_layout3 = new QHBoxLayout;
  QHBoxLayout* H_jstate_layout4 = new QHBoxLayout;
  QHBoxLayout* H_jstate_layout5 = new QHBoxLayout;
  QHBoxLayout* H_jstate_layout6 = new QHBoxLayout;
  H_jstate_layout1->addWidget( new QLabel( QString::fromUtf8("关节1") ));
  H_jstate_layout1->addWidget(j1state);
  H_jstate_layout2->addWidget( new QLabel( QString::fromUtf8("关节2") ));
  H_jstate_layout2->addWidget(j2state);
  H_jstate_layout3->addWidget( new QLabel( QString::fromUtf8("关节3") ));
  H_jstate_layout3->addWidget(j3state);
  H_jstate_layout4->addWidget( new QLabel( QString::fromUtf8("关节4") ));
  H_jstate_layout4->addWidget(j4state);
  H_jstate_layout5->addWidget( new QLabel( QString::fromUtf8("关节5") ));
  H_jstate_layout5->addWidget(j5state);
  H_jstate_layout6->addWidget( new QLabel( QString::fromUtf8("关节6") ));
  H_jstate_layout6->addWidget(j6state);
  jstate_layout->addLayout(H_jstate_layout1);
  jstate_layout->addLayout(H_jstate_layout2);
  jstate_layout->addLayout(H_jstate_layout3);
  jstate_layout->addLayout(H_jstate_layout4);
  jstate_layout->addLayout(H_jstate_layout5);
  jstate_layout->addLayout(H_jstate_layout6);
  QVBoxLayout *jstate_GroupBox_layout = new QVBoxLayout();
  QGroupBox *jstate_GroupBox = new QGroupBox(QString::fromUtf8("关节角度(°)"));
  jstate_GroupBox->setLayout(jstate_layout);
  jstate_GroupBox_layout->addWidget(jstate_GroupBox);

  //endpos_GroupBox控件定义
  Xstate = new QLineEdit();
  Xstate->setReadOnly(true);
  Xstate->setText(QString::number(pos_x, 10, 4)); 
  Ystate = new QLineEdit();
  Ystate->setReadOnly(true);
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate = new QLineEdit();
  Zstate->setReadOnly(true);
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  //endpos_GroupBox
  QHBoxLayout* endpos_layout = new QHBoxLayout;
  endpos_layout->addWidget( new QLabel( "X:" ));
  endpos_layout->addWidget(Xstate); 
  endpos_layout->addWidget( new QLabel( "Y:" ));
  endpos_layout->addWidget(Ystate); 
  endpos_layout->addWidget( new QLabel( "Z:" ));
  endpos_layout->addWidget(Zstate);   
  QGroupBox *endpos_GroupBox = new QGroupBox(QString::fromUtf8("末端位置(m)"));
  endpos_GroupBox->setLayout(endpos_layout);

  //euler_layout控件定义
  RXstate = new QLineEdit();
  RXstate->setReadOnly(true);
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate = new QLineEdit();
  RYstate->setReadOnly(true);
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate = new QLineEdit();
  RZstate->setReadOnly(true);
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  //euler_layout
  QHBoxLayout* euler_layout = new QHBoxLayout;
  euler_layout->addWidget( new QLabel( "R:" ));
  euler_layout->addWidget(RXstate); 
  euler_layout->addWidget( new QLabel( "P:" ));
  euler_layout->addWidget(RYstate); 
  euler_layout->addWidget( new QLabel( "Y:" ));
  euler_layout->addWidget(RZstate);   
  QGroupBox *euler_GroupBox = new QGroupBox(QString::fromUtf8("欧拉角(°)"));
  euler_GroupBox->setLayout(euler_layout);

  //quaternion_GroupBox控件定义
  Quaternions_xstate = new QLineEdit();
  Quaternions_xstate->setReadOnly(true);
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate = new QLineEdit();
  Quaternions_ystate->setReadOnly(true);
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4));
  Quaternions_zstate = new QLineEdit();
  Quaternions_zstate->setReadOnly(true);
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4));
  Quaternions_wstate = new QLineEdit();
  Quaternions_wstate->setReadOnly(true);
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4));
  //quaternion_GroupBox
  QHBoxLayout* quaternion_layout = new QHBoxLayout;
  quaternion_layout->addWidget( new QLabel( "x:" ));
  quaternion_layout->addWidget(Quaternions_xstate); 
  quaternion_layout->addWidget( new QLabel( "y:" ));
  quaternion_layout->addWidget(Quaternions_ystate); 
  quaternion_layout->addWidget( new QLabel( "z:" ));
  quaternion_layout->addWidget(Quaternions_zstate); 
  quaternion_layout->addWidget( new QLabel( "w:" ));
  quaternion_layout->addWidget(Quaternions_wstate); 
  QGroupBox *quaternion_GroupBox = new QGroupBox(QString::fromUtf8("四元数"));
  quaternion_GroupBox->setLayout(quaternion_layout);
  //three_GroupBox
  QVBoxLayout *three_GroupBox_layout = new QVBoxLayout();  
  three_GroupBox_layout->addWidget(endpos_GroupBox);
  three_GroupBox_layout->addWidget(euler_GroupBox);
  three_GroupBox_layout->addWidget(quaternion_GroupBox);

  //arm_GroupBox控件定义
  tran_x_add_btn = new QPushButton( "X+" );
  tran_x_btn = new QPushButton( "X-" );
  tran_y_add_btn = new QPushButton( "Y+" );
  tran_y_btn = new QPushButton( "Y-" );
  tran_z_add_btn = new QPushButton( "Z+" ); 
  tran_z_btn = new QPushButton( "Z-" ); 
  rot_x_anti_btn = new QPushButton( QString::fromUtf8("X(逆)") );
  rot_x_btn = new QPushButton( QString::fromUtf8("X(顺)") );
  rot_y_anti_btn = new QPushButton( QString::fromUtf8("Y(逆)") );
  rot_y_btn = new QPushButton( QString::fromUtf8("Y(顺)") );
  rot_z_anti_btn = new QPushButton( QString::fromUtf8("Z(逆)") );
  rot_z_btn = new QPushButton( QString::fromUtf8("Z(顺)") );
  //arm_GroupBox
  QVBoxLayout* arm_layout = new QVBoxLayout;
  QHBoxLayout* H_arm_layout1 = new QHBoxLayout;
  QHBoxLayout* H_arm_layout2 = new QHBoxLayout;
  H_arm_layout1->addWidget(tran_x_add_btn);
  H_arm_layout1->addWidget(tran_x_btn);
  H_arm_layout1->addWidget(tran_y_add_btn);
  H_arm_layout1->addWidget(tran_y_btn);
  H_arm_layout1->addWidget(tran_z_add_btn);
  H_arm_layout1->addWidget(tran_z_btn);
  H_arm_layout2->addWidget(rot_x_anti_btn);
  H_arm_layout2->addWidget(rot_x_btn);
  H_arm_layout2->addWidget(rot_y_anti_btn);
  H_arm_layout2->addWidget(rot_y_btn);
  H_arm_layout2->addWidget(rot_z_anti_btn);
  H_arm_layout2->addWidget(rot_z_btn);
  arm_layout->addLayout(H_arm_layout1); 
  arm_layout->addLayout(H_arm_layout2); 
  QVBoxLayout *arm_GroupBox_layout = new QVBoxLayout();
  QGroupBox *arm_GroupBox = new QGroupBox(QString::fromUtf8("沿末端坐标轴平移/旋转"));
  arm_GroupBox->setLayout(arm_layout);
  arm_GroupBox_layout->addWidget(arm_GroupBox);

  //gripper_GroupBox控件定义
  gripper_open_btn = new QPushButton( QString::fromUtf8("手爪打开") );
  gripper_close_btn = new QPushButton( QString::fromUtf8("手爪关闭") );
  //gripper_GroupBox
  QVBoxLayout* gripper_layout = new QVBoxLayout;
  gripper_layout->addWidget(gripper_open_btn);
  gripper_layout->addWidget(gripper_close_btn);
  QVBoxLayout *gripper_GroupBox_layout = new QVBoxLayout();
  QGroupBox *gripper_GroupBox = new QGroupBox(QString::fromUtf8("手爪开合"));
  gripper_GroupBox->setLayout(gripper_layout);
  gripper_GroupBox_layout->addWidget(gripper_GroupBox);

  //motion_GroupBox
  QHBoxLayout *motion_GroupBox_layout = new QHBoxLayout();  
  motion_GroupBox_layout->addWidget(arm_GroupBox);
  motion_GroupBox_layout->addWidget(gripper_GroupBox);

  //traj_GroupBox控件定义
  home_btn = new QPushButton( "home" );
  pos1_btn = new QPushButton( "pos1" );
  posrecord_name = new QLineEdit(); 
  sure_btn = new QPushButton( QString::fromUtf8("确定") );
  gorecord_btn = new QPushButton( QString::fromUtf8("运动") );
  // combox = new QComboBox();
  // combox->setEditable(true);
  // combox->insertItem( 0,QString::fromUtf8("入针准备位") );
  // combox->insertItem( 1,QString::fromUtf8("pos1") );
  // combox->insertItem( 2,QString::fromUtf8("pos2") );  
  combox2 = new QComboBox();
  combox2->setEditable(false);  
  //traj_GroupBox 水平布局
  QHBoxLayout *traj_layout = new QHBoxLayout();  
  traj_layout->addWidget(home_btn);
  traj_layout->addWidget(pos1_btn);
  traj_layout->addWidget( new QLabel( QString::fromUtf8("记录当前位姿为") ));   
  traj_layout->addWidget(posrecord_name);  
  traj_layout->addWidget(sure_btn);
  // traj_layout->addWidget(combox);
  traj_layout->addWidget( new QLabel( QString::fromUtf8("选择运动目标点") ));
  traj_layout->addWidget(combox2);
  traj_layout->addWidget(gorecord_btn);
  QVBoxLayout *traj_GroupBox_layout = new QVBoxLayout();
  QGroupBox *traj_GroupBox = new QGroupBox(QString::fromUtf8("轨迹运动"));
  traj_GroupBox->setLayout(traj_layout);
  traj_GroupBox_layout->addWidget(traj_GroupBox);

  //穿刺模块
  QVBoxLayout *chuanci_GroupBox_layout = new QVBoxLayout();  
  QVBoxLayout *chuanci_layout = new QVBoxLayout();  
  QGroupBox *chuanci_GroupBox = new QGroupBox(QString::fromUtf8("穿刺模块"));
  // //穿刺文件显示部分
  // QHBoxLayout *fileshow_layout = new QHBoxLayout();
  // openfileBtn = new QPushButton( QString::fromUtf8("选择入针点/靶点位置文件") );
  // dealdtBtn = new QPushButton( QString::fromUtf8("位置文件处理") );
  // // dealdtBtn2 = new QPushButton( QString::fromUtf8("位置数据提取") );
  // // fileshowText = new QTextEdit(); 
  // fileshowText = new QLabel(); 
  // fileshow_layout->addWidget( openfileBtn ); 
  // fileshow_layout->addWidget( dealdtBtn );
  // // fileshow_layout->addWidget( dealdtBtn2 );
  // fileshow_layout->addWidget( fileshowText ); 
  // chuanci_layout->addLayout(fileshow_layout);
  // //目标点靶点坐标显示部分
  // QHBoxLayout* H_targetshow_layout1 = new QHBoxLayout;
  // QHBoxLayout* H_targetshow_layout2 = new QHBoxLayout; 
  // H_targetshow_layout1->addWidget( new QLabel( QString::fromUtf8("入针点在") ));
  // tfcombox = new QComboBox();
  // tfcombox->setEditable(false); 
  // tfcombox->insertItem( 0,QString::fromUtf8("dicom图像坐标系") );
  // tfcombox->insertItem( 1,QString::fromUtf8("机械臂基坐标系") );
  // H_targetshow_layout1->addWidget( tfcombox ); 
  // H_targetshow_layout1->addWidget( new QLabel( QString::fromUtf8("下的位置xyz(mm)") ));
  // needlept_X = new QLineEdit();
  // needlept_X->setReadOnly(true); 
  // needlept_Y = new QLineEdit();
  // needlept_Y->setReadOnly(true); 
  // needlept_Z = new QLineEdit();
  // needlept_Z->setReadOnly(true); 
  // H_targetshow_layout1->addWidget( needlept_X ); 
  // H_targetshow_layout1->addWidget( needlept_Y ); 
  // H_targetshow_layout1->addWidget( needlept_Z ); 

  // H_targetshow_layout2->addWidget( new QLabel( QString::fromUtf8("靶点在") ));
  // tfcombox2 = new QComboBox();
  // tfcombox2->setEditable(false);
  // tfcombox2->insertItem( 0,QString::fromUtf8("dicom图像坐标系") );
  // tfcombox2->insertItem( 1,QString::fromUtf8("机械臂基坐标系") );
  // H_targetshow_layout2->addWidget( tfcombox2 );
  // H_targetshow_layout2->addWidget( new QLabel( QString::fromUtf8("下的位置xyz(mm)") ));
  // targetpt_X = new QLineEdit();
  // targetpt_X->setReadOnly(true); 
  // targetpt_Y = new QLineEdit();
  // targetpt_Y->setReadOnly(true); 
  // targetpt_Z = new QLineEdit();
  // targetpt_Z->setReadOnly(true); 
  // H_targetshow_layout2->addWidget( targetpt_X ); 
  // H_targetshow_layout2->addWidget( targetpt_Y ); 
  // H_targetshow_layout2->addWidget( targetpt_Z ); 
  // chuanci_layout->addLayout(H_targetshow_layout1);
  // chuanci_layout->addLayout(H_targetshow_layout2);

  QHBoxLayout* H_chuanci_layout1 = new QHBoxLayout; 
  QHBoxLayout* H_chuanci_layout2 = new QHBoxLayout; 
  H_chuanci_layout1->addWidget( new QLabel( QString::fromUtf8("输入靶点坐标") ));
  tg_X = new QLineEdit();
  tg_Y = new QLineEdit();  
  tg_Z = new QLineEdit();
  H_chuanci_layout1->addWidget( tg_X ); 
  H_chuanci_layout1->addWidget( tg_Y ); 
  H_chuanci_layout1->addWidget( tg_Z ); 
  //额外加的
  H_chuanci_layout1->addWidget( new QLabel( QString::fromUtf8("输入目标四元数") ));
  XYZW_X = new QLineEdit();
  XYZW_Y = new QLineEdit();  
  XYZW_Z = new QLineEdit();
  XYZW_W = new QLineEdit();
  H_chuanci_layout1->addWidget( XYZW_X ); 
  H_chuanci_layout1->addWidget( XYZW_Y ); 
  H_chuanci_layout1->addWidget( XYZW_Z ); 
  H_chuanci_layout1->addWidget( XYZW_W ); 
  //
  chuanci_layout->addLayout(H_chuanci_layout1);
  ddtz_btn = new QPushButton( QString::fromUtf8("定点调姿") );
  cczx_btn = new QPushButton( QString::fromUtf8("穿刺执行") );  
  H_chuanci_layout2->addWidget( ddtz_btn ); 
  //额外加的
  H_chuanci_layout2->addWidget( new QLabel( QString::fromUtf8("输入穿刺进针深度") ));
  H = new QLineEdit();
  H_chuanci_layout2->addWidget( H ); 
  H_chuanci_layout2->addWidget( cczx_btn ); 
  chuanci_layout->addLayout(H_chuanci_layout2);
  chuanci_GroupBox->setLayout(chuanci_layout);
  chuanci_GroupBox_layout->addWidget(chuanci_GroupBox); 
 

  QVBoxLayout* widget1_layout = new QVBoxLayout;
  QHBoxLayout* H_widget1_layout = new QHBoxLayout;
  H_widget1_layout->addLayout(paraset_GroupBox_layout);
  H_widget1_layout->addLayout(jstate_GroupBox_layout);
  H_widget1_layout->addLayout(three_GroupBox_layout);
  widget1_layout->addLayout(H_widget1_layout);
  widget1_layout->addLayout(motion_GroupBox_layout);
  widget1_layout->addWidget(traj_GroupBox); 
  widget1_layout->addLayout(chuanci_GroupBox_layout);
  widget1->setLayout(widget1_layout);


  
 
  QWidget *widget2 = new QWidget(); 
  QVBoxLayout* pic_layout = new QVBoxLayout; 
  //将图像文件加载进QImage对象中
  QImage image;
  image.load("/home/cp3/catkin_ws/src/rviz_teleop_commander/demo.PNG");  
  QLabel *pic_label = new QLabel();
  //再用QPixmap对象获得图像；最后用QLabel选择QPixmap图像对象显示。
  pic_label->setPixmap(QPixmap::fromImage(image));
  // pic_label->resize(QSize(image.width(),image.height()));
  // QScrollArea *scrollImag=new QScrollArea;
  // scrollImag->setWidget(pic_label);
  pic_layout->addWidget( pic_label );

  // tooltf  
  QVBoxLayout* tooltf_layout = new QVBoxLayout;  
  QHBoxLayout* H_tooltf_layout1 = new QHBoxLayout;
  QHBoxLayout* H_tooltf_layout2 = new QHBoxLayout;
   

  H_tooltf_layout1->addWidget( new QLabel( QString::fromUtf8("相对末端法兰Z向偏移h(cm)") )); 
  // tool_X = new QLineEdit(); 
  //-?表示前面可以有一个可选的减号
  //\d+表示一到多个数字
  //?表示(\.\d+)?部分是可选的
  QRegExp regx("^(-?\\d+)(\\.\\d+)?$　");
  //QRegExpValidator    --  只让用户按照正则表达式定义好的样式进行输入
  QValidator *validator = new QRegExpValidator(regx);
  // tool_X->setValidator( validator );
  // tool_Y = new QLineEdit(); 
  // tool_Y->setValidator( validator );
  tool_Z = new QLineEdit(); 
  tool_Z->setValidator( validator );
  // H_tooltf_layout1->addWidget( tool_X ); 
  // H_tooltf_layout1->addWidget( tool_Y ); 
  H_tooltf_layout1->addWidget( tool_Z ); 
  // H_tooltf_layout2->addWidget( new QLabel( QString::fromUtf8("四元数(x,y,z,w)") )); 
  // tool_x = new QLineEdit(); 
  // tool_y = new QLineEdit(); 
  // tool_z = new QLineEdit(); 
  // tool_w = new QLineEdit(); 
  // H_tooltf_layout2->addWidget( tool_x ); 
  // H_tooltf_layout2->addWidget( tool_y ); 
  // H_tooltf_layout2->addWidget( tool_z );
  // H_tooltf_layout2->addWidget( tool_w );
  tooltf_layout->addLayout(H_tooltf_layout1);
  // tooltf_layout->addLayout(H_tooltf_layout2);
  QVBoxLayout *tooltf_GroupBox_layout = new QVBoxLayout();
  QGroupBox *tooltf_GroupBox = new QGroupBox(QString::fromUtf8("工具坐标系设置"));
  tooltf_GroupBox->setLayout(tooltf_layout);
  tooltf_GroupBox_layout->addWidget(tooltf_GroupBox);
   // ctbedtf
  QVBoxLayout* ctbedtf_layout = new QVBoxLayout;
  QHBoxLayout* H_ctbedtf_layout1 = new QHBoxLayout;
  QHBoxLayout* H_ctbedtf_layout2 = new QHBoxLayout; 
  //默认CT床坐标系标定(原点位置)
  H_ctbedtf_layout1->addWidget( new QLabel( QString::fromUtf8("标定默认原点坐标A,B,C(cm)") ));
  ctbedtf_X = new QLineEdit(); 
  ctbedtf_X->setValidator( validator );
  ctbedtf_Y = new QLineEdit(); 
  ctbedtf_Y->setValidator( validator );
  ctbedtf_Z = new QLineEdit(); 
  ctbedtf_Z->setValidator( validator );
  H_ctbedtf_layout1->addWidget( ctbedtf_X ); 
  H_ctbedtf_layout1->addWidget( ctbedtf_Y ); 
  H_ctbedtf_layout1->addWidget( ctbedtf_Z );
  //相对默认CT床原点位置
  H_ctbedtf_layout2->addWidget( new QLabel( QString::fromUtf8("相对默认CT床原点偏移a,b,c(cm)") ));
  ctbedtf_delta_X = new QLineEdit(); 
  ctbedtf_delta_X->setValidator( validator );
  ctbedtf_delta_Y = new QLineEdit();
  ctbedtf_delta_Y->setValidator( validator ); 
  ctbedtf_delta_Z = new QLineEdit();
  ctbedtf_delta_Z->setValidator( validator ); 
  H_ctbedtf_layout2->addWidget( ctbedtf_delta_X ); 
  H_ctbedtf_layout2->addWidget( ctbedtf_delta_Y ); 
  H_ctbedtf_layout2->addWidget( ctbedtf_delta_Z ); 

  ctbedtf_layout->addLayout(H_ctbedtf_layout1);
  ctbedtf_layout->addLayout(H_ctbedtf_layout2);
  //ctbedtf_GroupBox
  QVBoxLayout *ctbedtf_GroupBox_layout = new QVBoxLayout();
  QGroupBox *ctbedtf_GroupBox = new QGroupBox(QString::fromUtf8("CT床坐标系设置"));
  ctbedtf_GroupBox->setLayout(ctbedtf_layout);
  ctbedtf_GroupBox_layout->addWidget(ctbedtf_GroupBox);

  //人体坐标系设置
  QHBoxLayout* mantf_layout = new QHBoxLayout;
  mantf_layout->addWidget( new QLabel( QString::fromUtf8("相对实时CT床原点位置U,V,W(cm)") ));
  mantf_delta_X = new QLineEdit(); 
  mantf_delta_X->setValidator( validator );
  mantf_delta_Y = new QLineEdit();
  mantf_delta_Y->setValidator( validator ); 
  mantf_delta_Z = new QLineEdit();
  mantf_delta_Z->setValidator( validator ); 
  mantf_layout->addWidget( mantf_delta_X ); 
  mantf_layout->addWidget( mantf_delta_Y ); 
  mantf_layout->addWidget( mantf_delta_Z ); 
  //mantf_GroupBox
  QVBoxLayout *mantf_GroupBox_layout = new QVBoxLayout();
  QGroupBox *mantf_GroupBox = new QGroupBox(QString::fromUtf8("人体坐标系设置"));
  mantf_GroupBox->setLayout(mantf_layout);
  mantf_GroupBox_layout->addWidget(mantf_GroupBox);
  
  //确定 编辑
  QGridLayout *w2_grid_layout = new QGridLayout();
  sure_tf_btn = new QPushButton( QString::fromUtf8("确定") );
  edit_tf_btn = new QPushButton( QString::fromUtf8("编辑") );
  w2_grid_layout->addWidget( sure_tf_btn,0,4,1,1 ); 
  w2_grid_layout->addWidget( edit_tf_btn,0,5,1,1 );




  //widget2_layout加各种GroupBox块
  QVBoxLayout* widget2_layout = new QVBoxLayout;
  QHBoxLayout* widget2_H_layout = new QHBoxLayout;
  QVBoxLayout* widget2_V_layout = new QVBoxLayout;
  widget2_layout->addLayout( pic_layout );
  widget2_V_layout->addLayout( tooltf_GroupBox_layout );   
  widget2_V_layout->addLayout( mantf_GroupBox_layout ); 
  widget2_H_layout->addLayout( widget2_V_layout );
  widget2_H_layout->addLayout( ctbedtf_GroupBox_layout ); 
  widget2_layout->addLayout( widget2_H_layout ); 
  widget2_layout->addLayout( w2_grid_layout );
  widget2->setLayout(widget2_layout);

   



  // //早期选病灶点页面splitterMain
  // //新建第3个页面的部件    
  // splitterMain=new QSplitter(Qt::Horizontal,tabWidget);     
  
  // model = new QFileSystemModel;
  // model->setReadOnly(false);            
  // model->setRootPath("/home/cp3/Pictures");
  // treeView = new QTreeView;
  // treeView->setModel(model);  
  // treeView->header()->setClickable(true);  
  // treeView->setRootIndex(model->index("/home/cp3/Pictures"));   
  // treeView->setColumnHidden(1, true);
  // treeView->setColumnHidden(2, true);
  // treeView->setColumnHidden(3, true);   
  // splitterMain->addWidget(treeView); 

  // splitterRight = new QSplitter(Qt::Vertical, splitterMain); 
  // //将图像文件加载进QImage对象中
  // QImage ctimage;
  // ctimage.load("/home/cp3/Pictures/basketball.png");
  // //图像缩放采用scaled函数,scaled函数中width和height表示缩放后图像的宽和高，即将原图像缩放到(width,height)大小
  // QImage ctimgscaled;
  // ctimgscaled = ctimage.scaled(512,512); 
  // ctpic_label = new QLabel();
  // //用QPixmap对象获得图像；最后用QLabel选择QPixmap图像对象显示。
  // ctpic_label->setPixmap(QPixmap::fromImage(ctimgscaled));  
  // splitterRight->addWidget( ctpic_label );

  // //
  // QWidget *button_widget = new QWidget(); 
  // QVBoxLayout* button_widget_layout = new QVBoxLayout;
  // QHBoxLayout* button_H1_layout = new QHBoxLayout;
  // QHBoxLayout* button_H2_layout = new QHBoxLayout;
  // QHBoxLayout* button_H3_layout = new QHBoxLayout;
  // choose_target_btn = new QPushButton( QString::fromUtf8("选择靶点") );
  // button_H1_layout->addWidget( choose_target_btn ); 
  // button_H1_layout->addWidget( new QLabel( QString::fromUtf8("当前靶点位置") ));
  // target_spot = new QLineEdit();
  // button_H1_layout->addWidget( target_spot );  
  

  // choose_entry_btn = new QPushButton( QString::fromUtf8("选择进针点") ); 
  // button_H2_layout->addWidget( choose_entry_btn ); 
  // button_H2_layout->addWidget( new QLabel( QString::fromUtf8("当前进针位置") ));
  // entry_spot = new QLineEdit();
  // button_H2_layout->addWidget( entry_spot );
  

  // determine_traj_btn = new QPushButton( QString::fromUtf8("确定轨迹") ); 
  // button_H3_layout->addWidget( determine_traj_btn ); 
  // clear_traj_btn = new QPushButton( QString::fromUtf8("清空轨迹") ); 
  // button_H3_layout->addWidget( clear_traj_btn ); 
  // edit_traj_btn = new QPushButton( QString::fromUtf8("编辑轨迹") ); 
  // button_H3_layout->addWidget( edit_traj_btn ); 

  // button_widget_layout->addLayout( button_H1_layout );
  // button_widget_layout->addLayout( button_H2_layout );
  // button_widget_layout->addLayout( button_H3_layout );
  // button_widget->setLayout(button_widget_layout);
  // splitterRight->addWidget( button_widget );  
  // splitterMain->setChildrenCollapsible ( false ); 
 
  // // view = new QListView();  
  // splitterMain->show();
  // //早期选病灶点页面splitterMain部分结束

 



  tabWidget->addTab(widget1, QString::fromUtf8("运动控制"));   
  tabWidget->addTab(widget2, QString::fromUtf8("坐标系"));    
  // tabWidget->addTab(splitterMain, QString::fromUtf8("进针点选择"));
  //tabWidget->addTab(widget3, QString::fromUtf8("目标点及运动规划")); 
  QHBoxLayout* layout = new QHBoxLayout;
  layout->addWidget(tabWidget); 
  this->setLayout(layout); 


  //  设置信号与槽的连接  
  connect( use_default, SIGNAL( clicked() ), this, SLOT( on_use_default() )); 
  connect( fresh_state, SIGNAL( clicked() ), this, SLOT( on_fresh_state() )); 
  connect( radian_radio, SIGNAL(clicked()), this, SLOT( onRadioClick() ));  
  connect( angle_radio, SIGNAL(clicked()), this, SLOT( onRadioClick() )); 
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
  connect( sure_btn, SIGNAL( clicked() ), this, SLOT( on_sure_btn() ));

  connect( gripper_open_btn, SIGNAL( clicked() ), this, SLOT( on_gripper_open_btn() ));
  connect( gripper_close_btn, SIGNAL( clicked() ), this, SLOT( on_gripper_close_btn() ));
   
  // connect( treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(pictureShow(QModelIndex)));

  // connect(openfileBtn, SIGNAL(clicked()), this, SLOT(on_openfileBtn()));  
  // connect(dealdtBtn, SIGNAL(clicked()), this, SLOT(on_dealdtBtn())); 
  // connect(dealdtBtn2, SIGNAL(clicked()), this, SLOT(on_dealdtBtn2())); 
  // connect(tfcombox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_tfcombox(int)));  
  // connect(tfcombox2, SIGNAL(currentIndexChanged(int)), this, SLOT(on_tfcombox2(int))); 
  connect( ddtz_btn, SIGNAL( clicked() ), this, SLOT( on_ddtz_btn() ));
  connect( cczx_btn, SIGNAL( clicked() ), this, SLOT( on_cczx_btn() )); 
 

}

void Schunk::on_use_default()
{
  velo->setValue(10); 
  acc->setValue(3); 
  translationstep->setValue(20); 
  Angle->setValue(20);  
  // int wx=combox2->count();
  // qDebug() << "wx=" << wx<<endl;

}

void Schunk::on_fresh_state()
{
  ros::AsyncSpinner spinner(1);
  spinner.start();   
  moveit::planning_interface::MoveGroup group("arm"); 
  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
}

void Schunk::onRadioClick()  
{
   moveit::planning_interface::MoveGroup group("arm"); 
   jValues = group.getCurrentJointValues();
   RPY = group.getCurrentRPY();
   pos_x = group.getCurrentPose().pose.position.x;
   pos_y = group.getCurrentPose().pose.position.y;
   pos_z = group.getCurrentPose().pose.position.z;  
   switch(btnGroup->checkedId())  
   {  
   case 0: 
       j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
       j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
       j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
       j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
       j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
       j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
       RXstate->setText(QString::number(RPY[0]*T, 10, 2));
       RYstate->setText(QString::number(RPY[1]*T, 10, 2));
       RZstate->setText(QString::number(RPY[2]*T, 10, 2)); 
       break;  
   case 1:   
       j1state->setText(QString::number(jValues.at(0), 10, 3)); 
       j2state->setText(QString::number(jValues.at(1), 10, 3)); 
       j3state->setText(QString::number(jValues.at(2), 10, 3)); 
       j4state->setText(QString::number(jValues.at(3), 10, 3)); 
       j5state->setText(QString::number(jValues.at(4), 10, 3)); 
       j6state->setText(QString::number(jValues.at(5), 10, 3)); 
       RXstate->setText(QString::number(RPY[0], 10, 3));
       RYstate->setText(QString::number(RPY[1], 10, 3));
       RZstate->setText(QString::number(RPY[2], 10, 3));         
       break;     
   }  
} 

//  末端沿x平移
void Schunk::on_tran_x_add_btn()
{
  
  ros::AsyncSpinner spinner(1);
  spinner.start();   
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  geometry_msgs::Pose goal; 
  k=translationstep->value()/1000;

  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;

  goal.position.x = group.getCurrentPose().pose.position.x+k*(x*x+w*w-z*z-y*y);
  goal.position.y = group.getCurrentPose().pose.position.y+k*2*(x*y+z*w);
  goal.position.z = group.getCurrentPose().pose.position.z+k*2*(x*z-y*w);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan; 
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));
    

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
 
}

void Schunk::on_tran_x_btn()
{
 
  ros::AsyncSpinner spinner(1);
  spinner.start();   
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300);  
  geometry_msgs::Pose goal; 
  k=translationstep->value()/1000;
  cout<<"k="<<k<<endl;

  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;
 
  goal.position.x = group.getCurrentPose().pose.position.x-k*(x*x+w*w-z*z-y*y);
  goal.position.y = group.getCurrentPose().pose.position.y-k*2*(x*y+z*w);
  goal.position.z = group.getCurrentPose().pose.position.z-k*2*(x*z-y*w);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan; 
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
 
}
//  末端沿y平移
void Schunk::on_tran_y_add_btn()
{

  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300);  
  geometry_msgs::Pose goal; 
  k=translationstep->value()/1000;
  cout<<"k="<<k<<endl;

  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;
  //向量加法op1=oo1+o1p1
  //沿y平移相当于求基坐标系的(0,1,0)沿当前(任意状态下)四元数旋转之后的y单位向量o1p1
  //oo1为getCurrentPose().pose.position，当前坐标系原点在基坐标系下的坐标
  //op1为沿y轴平移之后的坐标系原点在基坐标系下的坐标goal.position
  goal.position.x = group.getCurrentPose().pose.position.x+k*2*(x*y-z*w);
  goal.position.y = group.getCurrentPose().pose.position.y+k*(y*y+w*w-z*z-x*x);
  goal.position.z = group.getCurrentPose().pose.position.z+k*2*(y*z+x*w);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
 
}

void Schunk::on_tran_y_btn()
{

  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300);  
  geometry_msgs::Pose goal; 
  k=translationstep->value()/1000;
  cout<<"k="<<k<<endl;

  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;

  goal.position.x = group.getCurrentPose().pose.position.x-k*2*(x*y-z*w);
  goal.position.y = group.getCurrentPose().pose.position.y-k*(y*y+w*w-z*z-x*x);
  goal.position.z = group.getCurrentPose().pose.position.z-k*2*(y*z+x*w);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4));  
}

//  末端沿z平移
void Schunk::on_tran_z_add_btn()
{

  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  geometry_msgs::Pose goal; 
  k=translationstep->value()/1000;
  cout<<"k="<<k<<endl;

  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;

  goal.position.x = group.getCurrentPose().pose.position.x+k*2*(x*z+y*w);
  goal.position.y = group.getCurrentPose().pose.position.y+k*2*(y*z-x*w);
  goal.position.z = group.getCurrentPose().pose.position.z+k*(z*z+w*w-y*y-x*x);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;    
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  
}

void Schunk::on_tran_z_btn()
{
 
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  geometry_msgs::Pose goal; 
  k=translationstep->value()/1000;
  cout<<"k="<<k<<endl;

  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;

  goal.position.x = group.getCurrentPose().pose.position.x-k*2*(x*z+y*w);
  goal.position.y = group.getCurrentPose().pose.position.y-k*2*(y*z-x*w);
  goal.position.z = group.getCurrentPose().pose.position.z-k*(z*z+w*w-y*y-x*x);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  
}

//  末端绕x旋转
void Schunk::on_rot_x_anti_btn()
{

  //  创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start();   
  moveit::planning_interface::MoveGroup group("arm");   
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  // Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;   
  p = Angle->value();
  cout<<"p="<<p<<endl;
  
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  // n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=(x*x+w*w-z*z-y*y);
  n[1]=2*(x*y+z*w);
  n[2]=2*(x*z-y*w);
 
  q[0]=cos(p*pi/360);
  q[1]=n[0]*sin(p*pi/360);
  q[2]=n[1]*sin(p*pi/360);
  q[3]=n[2]*sin(p*pi/360);
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
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
 
}

void Schunk::on_rot_x_btn()
{
 
  //  创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  
  moveit::planning_interface::MoveGroup group("arm");   
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300);  
  // Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;  
  p = Angle->value();
  cout<<"p="<<p<<endl; 
  
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  // n为原末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=(x*x+w*w-z*z-y*y);
  n[1]=2*(x*y+z*w);
  n[2]=2*(x*z-y*w);
  // q为绕原末端坐标系x轴的单位向量转动角度p的转动四元数
  q[0]=cos(-p*pi/360);
  q[1]=n[0]*sin(-p*pi/360);
  q[2]=n[1]*sin(-p*pi/360);
  q[3]=n[2]*sin(-p*pi/360);
  // 新的四元数=转动四元数*原四元数
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
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
 
}

//  末端绕y旋转
void Schunk::on_rot_y_anti_btn()
{

  //  创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("arm");  
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  // Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;  
  p = Angle->value();
  cout<<"p="<<p<<endl; 
 
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  // n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=2*(x*y-z*w);
  n[1]=(y*y+w*w-z*z-x*x);
  n[2]=2*(y*z+x*w);
 
  q[0]=cos(p*pi/360);
  q[1]=n[0]*sin(p*pi/360);
  q[2]=n[1]*sin(p*pi/360);
  q[3]=n[2]*sin(p*pi/360);
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
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 

}

void Schunk::on_rot_y_btn()
{

  //  创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm");  
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  // Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal; 
  p = Angle->value();
  cout<<"p="<<p<<endl;  

  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  // n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=2*(x*y-z*w);
  n[1]=(y*y+w*w-z*z-x*x);
  n[2]=2*(y*z+x*w);

  q[0]=cos(-p*pi/360);
  q[1]=n[0]*sin(-p*pi/360);
  q[2]=n[1]*sin(-p*pi/360);
  q[3]=n[2]*sin(-p*pi/360);
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
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
 
}


//  末端绕z旋转
void Schunk::on_rot_z_anti_btn()
{

  //  创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("arm");   
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  // Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;  
  p = Angle->value();
  cout<<"p="<<p<<endl; 
 
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  // n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=2*(x*z+y*w);
  n[1]=2*(y*z-x*w);
  n[2]=(z*z+w*w-y*y-x*x);
 
  q[0]=cos(p*pi/360);
  q[1]=n[0]*sin(p*pi/360);
  q[2]=n[1]*sin(p*pi/360);
  q[3]=n[2]*sin(p*pi/360);
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
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4));   
}

void Schunk::on_rot_z_btn()
{ 
  //  创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300);  
  // Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;  
  p = Angle->value();
  cout<<"p="<<p<<endl; 
  
  double x = group.getCurrentPose().pose.orientation.x;
  double y = group.getCurrentPose().pose.orientation.y;
  double z = group.getCurrentPose().pose.orientation.z;
  double w = group.getCurrentPose().pose.orientation.w;
  // n为末端坐标系x轴的单位向量
  double n[3];
  double q[4];
  n[0]=2*(x*z+y*w);
  n[1]=2*(y*z-x*w);
  n[2]=(z*z+w*w-y*y-x*x);

  q[0]=cos(-p*pi/360);
  q[1]=n[0]*sin(-p*pi/360);
  q[2]=n[1]*sin(-p*pi/360);
  q[3]=n[2]*sin(-p*pi/360);
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
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4));  
}


void Schunk::on_home_btn()
{
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  jValues[0]=0;
  jValues[1]=0;
  jValues[2]=0;
  jValues[3]=0;
  jValues[4]=0;
  jValues[5]=0;
  group.setJointValueTarget(jValues);
  //group.setNamedTarget("home");
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4));  
}

void Schunk::on_pos1_btn()
{
  // 创建一个异步的自旋线程（spinning thread）
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("arm");    
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  qDebug() << "velo=" << velo->value()/72<<endl;
  qDebug() << "acc=" << acc->value()/300<<endl;
  qDebug() << "Angle=" << Angle->value()<<endl;
  qDebug() << "trans=" << translationstep->value()<<endl;  
  jValues[0]=0.0040143;
  jValues[1]=0.5269149;
  jValues[2]=1.9346975;
  jValues[3]=-0.0403171;
  jValues[4]=0.164061;
  jValues[5]=0.0394444;
  group.setJointValueTarget(jValues);
  //group.setNamedTarget("pos1");
  moveit::planning_interface::MoveGroup::Plan my_plan;
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4));  
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4));   
 
}

//定点调姿,c来计算需要的姿态
// void Schunk::on_ddtz_btn()
// {
//    //  创建一个异步的自旋线程（spinning thread）  
//   ros::AsyncSpinner spinner(1);
//   spinner.start(); 
//   moveit::planning_interface::MoveGroup group("arm");   
//   group.setMaxVelocityScalingFactor( velo->value()/72);
//   group.setMaxAccelerationScalingFactor(acc->value()/300); 
//   // Get the pose for the end-effector end_effector_link.  
//   geometry_msgs::Pose goal; 
//   //获取和定义当前和目标位置   
//   double cux = group.getCurrentPose().pose.position.x;
//   double cuy = group.getCurrentPose().pose.position.y;
//   double cuz = group.getCurrentPose().pose.position.z;
//   double tgx = tg_X->text().toDouble();
//   double tgy = tg_Y->text().toDouble();
//   double tgz = tg_Z->text().toDouble(); 
//   //定义并计算调姿后目标四元数,原理同沿末端z平移
//   double d,x,y,z,w;
//   //计算当前和目标之间距离
//   d=(tgx-cux)*(tgx-cux)+(tgy-cuy)*(tgy-cuy)+(tgz-cuz)*(tgz-cuz);
//   k=sqrt(d);
//   qDebug() << "k=" << k<<endl; 
//   if(tgx==cux+k*2*(x*z+y*w) && tgy==cuy+k*2*(y*z+x*w) 
//   && tgz==cuz+k*(z*z+w*w-y*y-x*x)&&x*x+y*y+z*z+w*w==1)   
//   {
//    qDebug() << "x=" << x<<endl; 
//    qDebug() << "y=" << y<<endl; 
//    qDebug() << "z=" << z<<endl; 
//    qDebug() << "w=" << w<<endl; 
//    goal.orientation.x = x;
//    goal.orientation.y = y;
//    goal.orientation.z = z;
//    goal.orientation.w = w;
//   }
//   goal.position.x = group.getCurrentPose().pose.position.x;
//   goal.position.y = group.getCurrentPose().pose.position.y;
//   goal.position.z = group.getCurrentPose().pose.position.z;
//   group.setPoseTarget(goal);
//   moveit::planning_interface::MoveGroup::Plan my_plan;  
//   bool success = group.plan(my_plan);
//   if(success)
//     group.execute(my_plan);
//   else
//     QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达")); 
// }

//定点调姿,matlab计算需要的姿态
void Schunk::on_ddtz_btn()
{
   //  创建一个异步的自旋线程（spinning thread）  
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("arm");   
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  // Get the pose for the end-effector end_effector_link.  
  geometry_msgs::Pose goal;   
  goal.position.x = group.getCurrentPose().pose.position.x;
  goal.position.y = group.getCurrentPose().pose.position.y;
  goal.position.z = group.getCurrentPose().pose.position.z;
  goal.orientation.x = XYZW_X->text().toDouble();
  goal.orientation.y = XYZW_Y->text().toDouble();
  goal.orientation.z = XYZW_Z->text().toDouble();
  goal.orientation.w = XYZW_W->text().toDouble();
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;  
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达")); 
}

void Schunk::on_cczx_btn()
{
  ros::AsyncSpinner spinner(1);
  spinner.start();  
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  geometry_msgs::Pose goal; 
  k = H->text().toDouble();
  cout<<"k="<<k<<endl;

  double x = goal.orientation.x = group.getCurrentPose().pose.orientation.x;
  double y = goal.orientation.y = group.getCurrentPose().pose.orientation.y;
  double z = goal.orientation.z = group.getCurrentPose().pose.orientation.z;
  double w = goal.orientation.w = group.getCurrentPose().pose.orientation.w;

  goal.position.x = group.getCurrentPose().pose.position.x+k*2*(x*z+y*w);
  goal.position.y = group.getCurrentPose().pose.position.y+k*2*(y*z-x*w);
  goal.position.z = group.getCurrentPose().pose.position.z+k*(z*z+w*w-y*y-x*x);
  group.setPoseTarget(goal);
  moveit::planning_interface::MoveGroup::Plan my_plan;    
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));

  jValues = group.getCurrentJointValues();
  RPY = group.getCurrentRPY();
  pos_x = group.getCurrentPose().pose.position.x;
  pos_y = group.getCurrentPose().pose.position.y;
  pos_z = group.getCurrentPose().pose.position.z;
  j1state->setText(QString::number(jValues.at(0)*T, 10, 2)); 
  j2state->setText(QString::number(jValues.at(1)*T, 10, 2)); 
  j3state->setText(QString::number(jValues.at(2)*T, 10, 2)); 
  j4state->setText(QString::number(jValues.at(3)*T, 10, 2)); 
  j5state->setText(QString::number(jValues.at(4)*T, 10, 2)); 
  j6state->setText(QString::number(jValues.at(5)*T, 10, 2)); 
  RXstate->setText(QString::number(RPY[0]*T, 10, 2));
  RYstate->setText(QString::number(RPY[1]*T, 10, 2));
  RZstate->setText(QString::number(RPY[2]*T, 10, 2));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
}



// 把当前位姿记录点保存并添加到目标点list里
void Schunk::on_sure_btn()
{
  moveit::planning_interface::MoveGroup group("arm");
  if(posrecord_name->text().isEmpty())
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标点名字不能为空(ps:火箭总冠军！)"));
  else     
    jValues = group.getCurrentJointValues();
    string str = posrecord_name->text().toStdString().data();
    // can be used by setNamedTarget(). These values are remembered locally in the client
    group.rememberJointValues("str", jValues);
    combox2_num = combox2->count()-1;
    //qDebug() << "num-1=" << combox2_num <<endl;
    combox2->insertItem( combox2_num , tr( posrecord_name->text().toStdString().data() ) ); 
}

void Schunk::on_gorecord_btn()
{
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("arm");
  group.setNamedTarget("str");
  group.move();
}

void Schunk::on_gripper_open_btn()
{
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("gripper"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  moveit::planning_interface::MoveGroup::Plan my_plan;
  group.setNamedTarget("open");
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));
}


//  使实际机械臂运动
void Schunk::on_gripper_close_btn()
{
  ros::AsyncSpinner spinner(1);
  spinner.start(); 
  moveit::planning_interface::MoveGroup group("gripper"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  moveit::planning_interface::MoveGroup::Plan my_plan;
  group.setNamedTarget("close");
  bool success = group.plan(my_plan);
  if(success)
    group.execute(my_plan);
  else
    QMessageBox::warning(this,"schunk",QString::fromUtf8("目标位置不可达"));
}

// ////点击列表，QLabel显示相应的图片
// void Schunk::pictureShow(const QModelIndex &index)
// {
//     //qDebug("clicked");
//     //获取ct图的文件名
//     QString filepath = index.data(Qt::DisplayRole).toString();
//     QStringList str;
//     str.clear();    
//     str.append("/home/cp3/Pictures/SE7-Contrast A  1.5  B30f/");
//     str.append(filepath);
//     filepath = str.join("");
//     //qDebug() << "filepath" << filepath;
//     str.clear();    
//     ctpic_label->setPixmap(QPixmap(filepath));
       
// }

//用QTextEdit显示txt的方法
// void Schunk::on_openfileBtn()
// {
//     //---获取文件名  
//     QString fileName = QFileDialog :: getOpenFileName(this, NULL, NULL, "*.txt");   
//     //---打开文件并读取文件内容  
//     QFile file(fileName);    
//     //--打开文件成功  
//     if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))  
//     {  
//         //清空QTextEdit内容，再显示文本
//         fileshowText->clear();  
//         QTextStream textStream(&file);  
//         while (!textStream.atEnd())  
//         {  
//             //---QtextEdit按行显示文件内容  
//             fileshowText->append(textStream.readLine());  
//         }  
//     }  
//     else    //---打开文件失败  
//     {  
//        QMessageBox::warning(this,"schunk",QString::fromUtf8("打开文件失败")); 
//     }  
// }

//用QLabel显示txt的方法
// void Schunk::on_openfileBtn()
// {
//     //---获取文件名  
//     QString fileName = QFileDialog :: getOpenFileName(this, NULL, NULL, "*.txt");   
//     //---打开文件并读取文件内容  
//     QFile file(fileName);  
//     QString displayString;   
//     //--打开文件成功  
//     if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))  
//     {  
//         //清空QTextEdit内容，再显示文本
//         // fileshowText->clear();           
//         while(!file.atEnd())
//         {  
//             QByteArray line = file.readLine();
//             //QString str(line);  
//             //转化 hex QString to UTF-8 QString,以显示中文
//             QString str = QString::fromUtf8(line);                  
//             displayString.append(str);           
//         }          
//         fileshowText->setText(displayString);
//     }  
//     else    //---打开文件失败  
//     {  
//        QMessageBox::warning(this,"schunk",QString::fromUtf8("打开文件失败")); 
//     }  
// }


// void Schunk::on_dealdtBtn()
// {
//   //  if(fileshowText->text().isEmpty())
//   //  {  
//   //      QMessageBox::warning(this,"schunk",QString::fromUtf8("请选择进针位置文件")); 
//   //  }
//   //  else
//      ifstream myfile("/home/cp3/Downloads/位置文件示例.txt");
//      char str[256] = {0};
//      char buff[256] = {0};
//      FILE *pFile; //写入文件     
//      pFile = fopen ("/home/cp3/Downloads/位置文件示例(2).txt","w"); //以读/写方式打开或建立一个文本文件     
//      while(!myfile.eof()) 
//       {
//        myfile.getline (str,256);
//        sscanf(str, "%*[^[]%*c%[^]]", buff);//*[^[]先过滤掉[之前的字符串   //(%[^]]匹配字符串直到]
//        fputs (buff,pFile);
//       //  cout << buff << endl;
//        memset( buff, 0, sizeof(buff) ); 
//        fputc('\n', pFile);                 
//       } 
//      fclose(pFile);         
// }

// void Schunk::on_dealdtBtn2()
// {
        
         
// }

// void Schunk::on_tfcombox(int index)
// {
//      FILE *rFile; 
//      rFile = fopen ("/home/cp3/Downloads/位置文件示例(2).txt","r, ccs = utf-8"); //以读/写方式打开或建立一个文本文件
//      //位置文件所有的数
//      double a[100];
//      int i,j;
//      //ct片左上角在人体坐标系的位置
//      int S[3];
//      //ct片相对人体的旋转
//      int R[6];
//      //像素与实际比值
//      int K[2];
//      //入针点在ct片上的索引
//      int P[2];
//      double nm;
//      if(rFile == NULL)
//      {
//       printf("ERROR!");      
//      }
//      while(!feof(rFile)) //如果读成功，fscanf返回成功读取的字符的个数，如果失败，返回EOF
//      {
//       fscanf(rFile,"%lf",&nm);   
//       a[i]=nm;   
//       i++;
//      }  
//      fclose(rFile);  
//      for(i=0;i<3;i++)
//      {
//        S[i]=a[i];
//      }
//      for(i=3;i<9;i++)
//      {
//        R[i-3]=a[i];
//      }
//      for(i=9;i<11;i++)
//      {
//        K[i-9]=a[i];
//      }
//      for(i=11;i<13;i++)
//      {
//        P[i-11]=a[i];
//      }
//      switch(tfcombox->currentIndex() )  
//      {  
//      case 0: 
       
//        needlept_X->setText(QString::number( R[0]*K[0]*P[0]+R[3]*K[1]*P[1]+S[0] ,10, 3 )); 
//        needlept_Y->setText(QString::number( R[1]*K[0]*P[0]+R[4]*K[1]*P[1]+S[1] ,10, 3 )); 
//        needlept_Z->setText(QString::number( R[2]*K[0]*P[0]+R[5]*K[1]*P[1]+S[2] ,10, 3)); 
//        break; 

//      case 1:   
//        needlept_X->setText(QString::number(6)); 
//        needlept_Y->setText(QString::number(6)); 
//        needlept_Z->setText(QString::number(6));  
//        break;     
//      }  
    
// }

// void Schunk::on_tfcombox2(int index)
// {
//    if(fileshowText->text().isEmpty())
//    {  
//        QMessageBox::warning(this,"schunk",QString::fromUtf8("请选择进针位置文件")); 
//    }
//    else
//    {    
      
//      switch(tfcombox2->currentIndex() )  
//      {  
//      case 0: 
    
//        break; 

//      case 1:   
        
//        break;     
//      } 
//    }
// }

} // end namespace rviz_teleop_commander
// 声明此类是一个rviz的插件
#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_teleop_commander::Schunk,rviz::Panel )
// END_TUTORIAL