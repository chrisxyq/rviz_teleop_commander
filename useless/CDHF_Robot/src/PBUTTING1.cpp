#include "Project.h"
#include <ros/ros.h>
#include <string>
    using namespace std;
#include "Algorithm.h"
#include "UartPBUTTING.h"
#include "N_Robot/PBUTTING_ReadDevInfo_srv.h"
#include "N_Robot/CmdOnly_srv.h"
#include "N_Robot/NMotionCtrl_ReadVersion_srv.h"
#include "N_Robot/PBUTTING_ReadStatus_srv.h"

//
UartPBUTTING uartPBUTTING;
//
bool ReadDevInfo(N_Robot::PBUTTING_ReadDevInfo_srv::Request &req,N_Robot::PBUTTING_ReadDevInfo_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
#ifdef PROJ_DEBUG
    ROS_INFO("Service PBUTTING/ReadDevInfo is called.");
#endif
    //
    nErr=uartPBUTTING.ReadDevInfo(ac,strErr);
    if(nErr){
        cout<<"PBUTTING Svr ReadDevInfo error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8DevAddr=ac[0];
    res.u8DevType=ac[1];
    res.u32DevSN=ac[2]+ac[3]*0x100+ac[4]*0x10000+ac[5]*0x1000000;
    //**
    return true;
}
bool ReadVersion(N_Robot::NMotionCtrl_ReadVersion_srv::Request &req,N_Robot::NMotionCtrl_ReadVersion_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
    ROS_INFO("Service PBUTTING/ReadVersion is called.");
    //
    nErr=uartPBUTTING.ReadVersion(ac,strErr);
    if(nErr){
        cout<<"Service PBUTTING ReadVersion error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u16HrdVer= (float)ac[0]/10+ac[1];
    res.f32SwVer= (float)ac[2]/1000+(float)ac[3]/100+(float)ac[4]/10+(float)ac[5];
    //**
    return true;
}
bool Reboot(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service PBUTTING/Reboot is called.");
    //
    nErr=uartPBUTTING.Reboot(ac,strErr);
    if(nErr){
        cout<<"Service PBUTTING reboot error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool ReadStatus(N_Robot::PBUTTING_ReadStatus_srv::Request &req,N_Robot::PBUTTING_ReadStatus_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[8];
#ifdef PROJ_DEBUG
    ROS_INFO("Service PBUTTING/ReadStatus is called.");
#endif
    //
    nErr=uartPBUTTING.ReadStatus(ac,strErr);
    if(nErr){
        cout<<"PBUTTING Svr ReadStatus error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8Switch=ac[0];

    Union64 union64;

    union64.u8[0]=ac[1];
    union64.u8[1]=ac[2];
    union64.u8[2]=ac[3];
    union64.u8[3]=ac[4];
    res.f32Position=union64.f32[0];
    //**
    return true;
}
//
int main(int argc,char ** argv){
    string strPara1;
    int nErr;
    //
    if(argv[1]!=0){
        strPara1=argv[1];
    }else{
        strPara1="";
    }
    ros::init(argc,argv,"PBUTTING");
    ros::NodeHandle n;
    ROS_INFO("Chengdu Hangfa PBUTTING node.v1.607");
    //** set uart parameter
    //printf("%s,%d,%d\n",argv[1],strPara1.find("/dev/tty"),string::npos);
    if(strPara1.find("/dev/tty")==string::npos){
        uartPBUTTING.pcPortName=UARTPORTNAME_PBUTTING;//USBcom use PL2303 chip
    }else{
        uartPBUTTING.pcPortName=argv[1];
    }
    uartPBUTTING.nUartSpeed=38400;
    uartPBUTTING.nUartFlowCtrl=0;
    uartPBUTTING.nUartDatabits=8;
    uartPBUTTING.nUartStopbits=1;
    uartPBUTTING.nParity='N';
#ifdef PROJ_DEBUG
    printf("UART Setting:port name =%s,speed=%d,flowctrl=%d,databits=%d,stopbits=%d,parity=%c\n",uartPBUTTING.pcPortName,uartPBUTTING.nUartSpeed,uartPBUTTING.nUartFlowCtrl,uartPBUTTING.nUartDatabits,uartPBUTTING.nUartStopbits,uartPBUTTING.nParity);
#endif
    //** open serial port
    nErr=uartPBUTTING.InitPort();
    if(nErr){
        ROS_INFO("Fail to init %s.",uartPBUTTING.pcPortName);
        return -1;
    }
    uartPBUTTING.ClearRcvBuf();
    //**
    ros::ServiceServer serReadDevInfo =    n.advertiseService("PBUTTING/ReadDevInfo",ReadDevInfo);
    ROS_INFO("advertise service ReadDevInfo OK.");
    ros::ServiceServer serReadVersion = n.advertiseService("PBUTTING/ReadVersion",ReadVersion);
    ROS_INFO("advertise service ReadVersion OK.");
    ros::ServiceServer serReboot = n.advertiseService("PBUTTING/Reboot",Reboot);
    ROS_INFO("advertise service Reboot OK.");
    ros::ServiceServer serReadStatus =    n.advertiseService("PBUTTING/ReadStatus",ReadStatus);
    ROS_INFO("advertise service ReadStatus OK.");
    //
    ros::spin();
    //**
    return 0;
}

