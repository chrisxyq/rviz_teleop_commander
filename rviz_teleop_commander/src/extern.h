//所需要包含的头文件
#include <ros/ros.h>
#include <ros/console.h>
#include <rviz/panel.h>   //plugin基类的头文件
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

extern double k;
  // p为绕末端坐标系x轴转动角度
extern double p;
extern double pi;
  // MaxVelocityScalingFactor
extern double v;
  // MaxAccelerationScalingFactor
extern double a;
extern double Angel_value;
extern double translationstep_value;
extern double velo_value;
extern double acc_value;
  
extern vector<double> jValues;
extern vector<double> RPY; 
extern double x;
extern double y;
extern double z;

extern ifstream fin;
extern string cstr;
extern int lines;
extern QString qstring; 
extern std::vector<string> strvect;