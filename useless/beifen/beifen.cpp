#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <QPainter>
#include <QWidget>
// 垂直布局
#include <QVBoxLayout>
// 水平布局
#include <QHBoxLayout>
#include <QGridLayout>
#include <qmessagebox.h>
#include <QGroupBox> 
#include <QTextCodec>

#include "teleop_pad.h"

namespace rviz_teleop_commander
{
//  构造函数，初始化变量
Schunk::Schunk( QWidget* parent )
  : rviz::Panel( parent )
  ,k( )
  ,p( )  
  ,pi( 3.1415926 )
  
  ,jValues()
  ,RPY( )
  ,pos_x( )
  ,pos_y( )
  ,pos_z( )
{ 

//labelA
  QTabWidget *tabWidget = new QTabWidget();    
// 1.Parameter Settings页面  
  QWidget *widget1 = new QWidget();
  // QVBoxLayout* widget1_layout = new QVBoxLayout;
  // QHBoxLayout* Hlayout1 = new QHBoxLayout;
  // QHBoxLayout* Hlayout2 = new QHBoxLayout;
  // QHBoxLayout* Hlayout3 = new QHBoxLayout;
  // QHBoxLayout* Hlayout4 = new QHBoxLayout;
  // // 旋转角度调整QSpinBox  
  // Angle = new QSpinBox(this);
  // Angle->setRange(1,30);   
  // Angle->setSingleStep(1);  
  // Angle->setValue(20);           
   
  // //Hlayout1->addWidget( new QLabel( "Rotate Angle" ));
  // Hlayout1->addWidget( new QLabel( QString::fromUtf8("单步旋转角度(°)") ));
  // Hlayout1->addWidget(Angle);

  // // 平移步长调整QDoubleSpinBox
  // translationstep = new QDoubleSpinBox(this);
  // translationstep->setRange(10,300);    
  // translationstep->setDecimals(1); 
  // translationstep->setValue(20);  
  // translationstep->setSingleStep(0.5);  
    
  // //Hlayout2->addWidget( new QLabel( "Translation Step(mm)" ));
  // Hlayout2->addWidget( new QLabel( QString::fromUtf8("沿末端坐标系平移步长(mm)") ));
  // Hlayout2->addWidget(translationstep); 
  // // Angular Velocity最大72°/s调整QDoubleSpinBox 
  // velo = new QDoubleSpinBox(this);
  // velo->setRange(1,20); 
  // velo->setValue(10); 
  // //设置显示的小数位数  
  // velo->setDecimals(0);   
  // velo->setSingleStep(1);     
  // //Hlayout3->addWidget( new QLabel( "Angular Velocity" ));
  // Hlayout3->addWidget( new QLabel( QString::fromUtf8("关节角速度(°/s)") ));
  // Hlayout3->addWidget(velo);  
  
  // // Angular Acceleration最大300°/s²调整QDoubleSpinBox 
  // acc = new QDoubleSpinBox(this);
  // acc->setRange(1,6);   
  // acc->setValue(3);
  // acc->setDecimals(1);   
  // acc->setSingleStep(0.5);     
  // //Hlayout4->addWidget( new QLabel( "Angular Acceleration" ));
  // Hlayout4->addWidget( new QLabel( QString::fromUtf8("关节角加速度(°/s²)") ));
  // Hlayout4->addWidget(acc);

  // //save_config = new QPushButton( "save config as default" ); 
  // //use_default = new QPushButton( "use default config" ); 
  // use_default = new QPushButton( QString::fromUtf8("使用默认参数") ); 

  // widget1_layout->addLayout(Hlayout1); 
  // widget1_layout->addLayout(Hlayout2); 
  // widget1_layout->addLayout(Hlayout3); 
  // widget1_layout->addLayout(Hlayout4); 
  // //widget1_layout->addWidget(save_config);
  // widget1_layout->addWidget(use_default);
  // widget1->setLayout(widget1_layout);

//  2.Calibration页面  
  // QWidget *widget2 = new QWidget();
  // QGridLayout *layout99 = new QGridLayout();
  // QLabel *rotLabel = new QLabel(QString::fromUtf8("单步旋转角度(°)"));
  // QLabel *tranLabel = new QLabel(QString::fromUtf8("单步旋转角度(°)"));
  // Angle = new QSpinBox(this);
  // Angle->setRange(1,30);   
  // Angle->setSingleStep(1);  
  // Angle->setValue(20);  
  // translationstep = new QDoubleSpinBox(this);
  // translationstep->setRange(10,300);    
  // translationstep->setDecimals(1); 
  // translationstep->setValue(20);  
  // translationstep->setSingleStep(0.5);  
  // layout99->addWidget(rotLabel,0,0,1,1);
  // layout99->addWidget(Angle,0,1,1,1);
  // layout99->addWidget(tranLabel,1,0,1,1);
  
  // layout99->addWidget(translationstep,1,1,1,1);
  // QVBoxLayout *mainLayout = new QVBoxLayout();
  // QGroupBox *gb = new QGroupBox(QString::fromUtf8("运动参数设置"));
  // gb->setLayout(layout99);
  // mainLayout->addWidget(gb);
  // widget2->setLayout(mainLayout);

// //  3.MotionControl页面  
//   QWidget *widget3 = new QWidget();  
//   //  tran_layout
//   QVBoxLayout* tran_layout = new QVBoxLayout;
//   tran_x_add_btn = new QPushButton( "X+" );
//   tran_layout->addWidget(tran_x_add_btn);
//   tran_x_btn = new QPushButton( "X-" );
//   tran_layout->addWidget(tran_x_btn);
//   tran_y_add_btn = new QPushButton( "Y+" );
//   tran_layout->addWidget(tran_y_add_btn);
//   tran_y_btn = new QPushButton( "Y-" );
//   tran_layout->addWidget(tran_y_btn);
//   tran_z_add_btn = new QPushButton( "Z+" ); 
//   tran_layout->addWidget(tran_z_add_btn);
//   tran_z_btn = new QPushButton( "Z-" ); 
//   tran_layout->addWidget(tran_z_btn);
//   //  rot_layout
//   QVBoxLayout* rot_layout = new QVBoxLayout;
//   //rot_x_anti_btn = new QPushButton( "rot x anti" );
//   rot_x_anti_btn = new QPushButton( QString::fromUtf8("X(逆)") );
//   rot_layout->addWidget(rot_x_anti_btn);
//   //rot_x_btn = new QPushButton( "rot x" );
//   rot_x_btn = new QPushButton( QString::fromUtf8("X(顺)") );
//   rot_layout->addWidget(rot_x_btn);
//   //rot_y_anti_btn = new QPushButton( "rot y anti" );
//   rot_y_anti_btn = new QPushButton( QString::fromUtf8("Y(逆)") );
//   rot_layout->addWidget(rot_y_anti_btn);
//   //rot_y_btn = new QPushButton( "rot y" );
//   rot_y_btn = new QPushButton( QString::fromUtf8("Y(顺)") );
//   rot_layout->addWidget(rot_y_btn);
//   //rot_z_anti_btn = new QPushButton( "rot z anti" );
//   rot_z_anti_btn = new QPushButton( QString::fromUtf8("Z(逆)") );
//   rot_layout->addWidget(rot_z_anti_btn);
//   //rot_z_btn = new QPushButton( "rot z" );
//   rot_z_btn = new QPushButton( QString::fromUtf8("Z(顺)") );
//   rot_layout->addWidget(rot_z_btn);
//   //  move_layout
//   QVBoxLayout* move_layout = new QVBoxLayout;
//   home_btn = new QPushButton( "home" );
//   move_layout->addWidget(home_btn);
//   //pos1_btn = new QPushButton( "pos1" );
//   pos1_btn = new QPushButton( QString::fromUtf8("位姿1") );
//   move_layout->addWidget(pos1_btn);
//   //save_pose = new QPushButton( "save pose" );
//   save_pose = new QPushButton( QString::fromUtf8("记录当前位姿") );
//   move_layout->addWidget(save_pose);
//   //move_traj = new QPushButton( "move traj" );
//   move_traj = new QPushButton( QString::fromUtf8("执行轨迹") );
//   move_layout->addWidget(move_traj);
//   //gripper_open_btn = new QPushButton( "gripper open" );
//   gripper_open_btn = new QPushButton( QString::fromUtf8("手爪打开") );
//   move_layout->addWidget(gripper_open_btn);
//   //gripper_close_btn = new QPushButton( "gripper close" );
//   gripper_close_btn = new QPushButton( QString::fromUtf8("手爪关闭") );
//   move_layout->addWidget(gripper_close_btn);
//   //ArmState_layout
//   QVBoxLayout* ArmState_layout = new QVBoxLayout;
//   QHBoxLayout* Hlayout4_1 = new QHBoxLayout;
//   QHBoxLayout* Hlayout4_2 = new QHBoxLayout;
//   QHBoxLayout* Hlayout4_3 = new QHBoxLayout;
//   QHBoxLayout* Hlayout4_4 = new QHBoxLayout;
//   QHBoxLayout* Hlayout4_5 = new QHBoxLayout;
//   QHBoxLayout* Hlayout4_6 = new QHBoxLayout;

//   moveit::planning_interface::MoveGroup group("arm");
//   //用于QLineEdit显示框
//   jValues = group.getCurrentJointValues();
//   RPY = group.getCurrentRPY();
//   pos_x = group.getCurrentPose().pose.position.x;
//   pos_y = group.getCurrentPose().pose.position.y;
//   pos_z = group.getCurrentPose().pose.position.z;
//   // 第一行
//   j1state = new QLineEdit();
//   j1state->setReadOnly(true); 
//   j1state->setText(QString::number(jValues.at(0), 10, 4));   
//   Xstate = new QLineEdit();
//   Xstate->setReadOnly(true);
//   Xstate->setText(QString::number(pos_x, 10, 4)); 
 
//   //Hlayout4_1->addWidget( new QLabel( "Joint 1:" ));
//   Hlayout4_1->addWidget( new QLabel( QString::fromUtf8("关节1") ));
//   Hlayout4_1->addWidget(j1state);
//   Hlayout4_1->addWidget( new QLabel( "X:" ));
//   Hlayout4_1->addWidget(Xstate);  

//   // 第2行 
//   j2state = new QLineEdit();
//   j2state->setReadOnly(true); 
//   j2state->setText(QString::number(jValues.at(1), 10, 4));
//   Ystate = new QLineEdit();
//   Ystate->setReadOnly(true);
//   Ystate->setText(QString::number(pos_y, 10, 4)); 

//   //Hlayout4_2->addWidget( new QLabel( "Joint 2:" ));
//   Hlayout4_2->addWidget( new QLabel( QString::fromUtf8("关节2") ));
//   Hlayout4_2->addWidget(j2state);
//   Hlayout4_2->addWidget( new QLabel( "Y:" ));
//   Hlayout4_2->addWidget(Ystate); 

//   // 第3行 
//   j3state = new QLineEdit();
//   j3state->setReadOnly(true); 
//   j3state->setText(QString::number(jValues.at(2), 10, 4));
//   Zstate = new QLineEdit();
//   Zstate->setReadOnly(true);
//   Zstate->setText(QString::number(pos_z, 10, 4)); 

//   //Hlayout4_3->addWidget( new QLabel( "Joint 3:" ));
//   Hlayout4_3->addWidget( new QLabel( QString::fromUtf8("关节3") ));
//   Hlayout4_3->addWidget(j3state);
//   Hlayout4_3->addWidget( new QLabel( "Z:" ));
//   Hlayout4_3->addWidget(Zstate); 
//   // QString temp_string = Zstate->text();
//   // float lin = temp_string.toFloat();
//   // cout<<"Zstate :"<<lin<<endl; 
//   // 第4行
//   j4state = new QLineEdit();
//   j4state->setReadOnly(true);
//   j4state->setText(QString::number(jValues.at(3), 10, 4));
//   RXstate = new QLineEdit();
//   RXstate->setReadOnly(true);
//   RXstate->setText(QString::number(RPY[0], 10, 4));

//   //Hlayout4_4->addWidget( new QLabel( "Joint 4:" ));
//   Hlayout4_4->addWidget( new QLabel( QString::fromUtf8("关节4") ));
//   Hlayout4_4->addWidget(j4state);
//   Hlayout4_4->addWidget( new QLabel( "R:" ));
//   Hlayout4_4->addWidget(RXstate); 

//   // 第5行
//   j5state = new QLineEdit();
//   j5state->setReadOnly(true);
//   j5state->setText(QString::number(jValues.at(4), 10, 4));
//   RYstate = new QLineEdit();
//   RYstate->setReadOnly(true);
//   RYstate->setText(QString::number(RPY[1], 10, 4));

//   //Hlayout4_5->addWidget( new QLabel( "Joint 5:" ));
//   Hlayout4_5->addWidget( new QLabel( QString::fromUtf8("关节5") ));
//   Hlayout4_5->addWidget(j5state);
//   Hlayout4_5->addWidget( new QLabel( "P:" ));
//   Hlayout4_5->addWidget(RYstate); 
//   // 第6行
//   j6state = new QLineEdit();
//   j6state->setReadOnly(true);
//   j6state->setText(QString::number(jValues.at(5), 10, 4));
//   RZstate = new QLineEdit();
//   RZstate->setReadOnly(true);
//   RZstate->setText(QString::number(RPY[2], 10, 4));

//   //Hlayout4_6->addWidget( new QLabel( "Joint 6:" ));
//   Hlayout4_6->addWidget( new QLabel( QString::fromUtf8("关节6") ));
//   Hlayout4_6->addWidget(j6state);
//   Hlayout4_6->addWidget( new QLabel( "Y:" ));
//   Hlayout4_6->addWidget(RZstate); 


//   ArmState_layout->addLayout(Hlayout4_1 );
//   ArmState_layout->addLayout(Hlayout4_2 );
//   ArmState_layout->addLayout(Hlayout4_3 );
//   ArmState_layout->addLayout(Hlayout4_4 );
//   ArmState_layout->addLayout(Hlayout4_5 );
//   ArmState_layout->addLayout(Hlayout4_6 );

//   QVBoxLayout* Quaternions_layout = new QVBoxLayout;
//   Quaternions_xstate = new QLineEdit();
//   Quaternions_xstate->setReadOnly(true);
//   Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4));    
//   //Quaternions_layout->addWidget( new QLabel( "Quaternions x:" ));
//   Quaternions_layout->addWidget( new QLabel( QString::fromUtf8("四元数(x,y,z,w):") ));
//   Quaternions_layout->addWidget(Quaternions_xstate); 
//   Quaternions_ystate = new QLineEdit();
//   Quaternions_ystate->setReadOnly(true);
//   Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4));
//   //Quaternions_layout->addWidget( new QLabel( "Quaternions y:" ));
//   Quaternions_layout->addWidget(Quaternions_ystate); 
//   Quaternions_zstate = new QLineEdit();
//   Quaternions_zstate->setReadOnly(true);
//   Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4));
//   //Quaternions_layout->addWidget( new QLabel( "Quaternions z:" ));
//   Quaternions_layout->addWidget(Quaternions_zstate); 
//   Quaternions_wstate = new QLineEdit();
//   Quaternions_wstate->setReadOnly(true);
//   Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
//   //Quaternions_layout->addWidget( new QLabel( "Quaternions w:" ));
//   Quaternions_layout->addWidget(Quaternions_wstate); 


//   QHBoxLayout* widget3_layout = new QHBoxLayout;
//   widget3_layout->addLayout( tran_layout );
//   widget3_layout->addLayout( rot_layout );
//   widget3_layout->addLayout( move_layout );
//   widget3_layout->addLayout( ArmState_layout );
//   widget3_layout->addLayout( Quaternions_layout );
//   widget3->setLayout(widget3_layout);

   //5.End Tool页面  
  QWidget *widget5 = new QWidget();



  // 向QTabWidget添加第1个页面    
  //tabWidget->addTab(widget1,  "Parameter Settings");  
  //tabWidget->addTab(widget1, QString::fromUtf8("运动参数设置")); 
  // 向QTabWidget添加第2个页面     
  //tabWidget->addTab(widget2, "Calibration"); 
  //tabWidget->addTab(widget2, QString::fromUtf8("坐标系标定")); 
  // 向QTabWidget中添加第3个页面    
  //tabWidget->addTab(widget3,"MotionControl");   
  //tabWidget->addTab(widget3, QString::fromUtf8("运动控制"));  
  // 向QTabWidget中添加第5个页面     
  //tabWidget->addTab(widget5, "End Tool");
  //tabWidget->addTab(widget5, QString::fromUtf8("工具坐标系"));
  QHBoxLayout* layout = new QHBoxLayout;
  layout->addWidget(tabWidget);
  this->setLayout(layout);

  //  设置信号与槽的连接  
  connect( use_default, SIGNAL( clicked() ), this, SLOT( on_use_default() )); 
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
  //connect( pos1_btn, SIGNAL( clicked() ), this, SLOT( on_terminal_update() ));
  connect( gripper_open_btn, SIGNAL( clicked() ), this, SLOT( on_gripper_open_btn() ));
  connect( gripper_close_btn, SIGNAL( clicked() ), this, SLOT( on_gripper_close_btn() ));
 

}

void Schunk::on_use_default()
{
  velo->setValue(10); 
  acc->setValue(3); 
  translationstep->setValue(20); 
  Angle->setValue(20);  
}

//  末端沿x平移
void Schunk::on_tran_x_add_btn()
{
  if( ros::ok() )
  {
  ros::AsyncSpinner spinner(1);
  spinner.start();   
  moveit::planning_interface::MoveGroup group("arm"); 
  group.setMaxVelocityScalingFactor( velo->value()/72);
  group.setMaxAccelerationScalingFactor(acc->value()/300); 
  geometry_msgs::Pose goal; 
  k=translationstep->value()/1000;
  cout<<"VelocityScalingFactor"<<velo->value()/72<<endl;

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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

void Schunk::on_tran_x_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}
//  末端沿y平移
void Schunk::on_tran_y_add_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

void Schunk::on_tran_y_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

//  末端沿z平移
void Schunk::on_tran_z_add_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

void Schunk::on_tran_z_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

//  末端绕x旋转
void Schunk::on_rot_x_anti_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

void Schunk::on_rot_x_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

//  末端绕y旋转
void Schunk::on_rot_y_anti_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

void Schunk::on_rot_y_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}


//  末端绕z旋转
void Schunk::on_rot_z_anti_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}

void Schunk::on_rot_z_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
}


void Schunk::on_home_btn()
{
  if( ros::ok() )
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4)); 
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4)); 
  }
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
  jValues[0]=0;
  jValues[1]=0;
  jValues[2]=1.57;
  jValues[3]=0;
  jValues[4]=-1.57;
  jValues[5]=0;
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
  j1state->setText(QString::number(jValues.at(0), 10, 4)); 
  j2state->setText(QString::number(jValues.at(1), 10, 4)); 
  j3state->setText(QString::number(jValues.at(2), 10, 4)); 
  j4state->setText(QString::number(jValues.at(3), 10, 4)); 
  j5state->setText(QString::number(jValues.at(4), 10, 4)); 
  j6state->setText(QString::number(jValues.at(5), 10, 4)); 
  RXstate->setText(QString::number(RPY[0], 10, 4));
  RYstate->setText(QString::number(RPY[1], 10, 4));
  RZstate->setText(QString::number(RPY[2], 10, 4));
  Xstate->setText(QString::number(pos_x, 10, 4));
  Ystate->setText(QString::number(pos_y, 10, 4)); 
  Zstate->setText(QString::number(pos_z, 10, 4));  
  Quaternions_xstate->setText(QString::number(group.getCurrentPose().pose.orientation.x, 10, 4)); 
  Quaternions_ystate->setText(QString::number(group.getCurrentPose().pose.orientation.y, 10, 4)); 
  Quaternions_zstate->setText(QString::number(group.getCurrentPose().pose.orientation.z, 10, 4)); 
  Quaternions_wstate->setText(QString::number(group.getCurrentPose().pose.orientation.w, 10, 4));   
 
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

} 
//  end namespace rviz_teleop_commander
 //声明此类是一个rviz的插件
#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_teleop_commander::Schunk,rviz::Panel )


