#include "Project.h"
#include <ros/ros.h>
#include <string>
    using namespace std;
#include "Algorithm.h"
#include "UartOFPS1.h"
#include "N_Robot/OFPS1_ReadDevInfo_srv.h"
#include "N_Robot/CmdOnly_srv.h"
#include "N_Robot/OFPS1_ReadPosition_srv.h"
#include "N_Robot/NMotionCtrl_ReadVersion_srv.h"
#include "N_Robot/OFPS1_ReadEncoder_srv.h"
#include "N_Robot/OFPS1_SetPosition_srv.h"
//
UartOFPS1 uartOFPS1;
//
bool ReadDevInfo(N_Robot::OFPS1_ReadDevInfo_srv::Request &req,N_Robot::OFPS1_ReadDevInfo_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
#ifdef PROJ_DEBUG
    ROS_INFO("Service OFPS1/ReadDevInfo is called.");
#endif
    //
    nErr=uartOFPS1.ReadDevInfo(ac,strErr);
    if(nErr){
        cout<<"OFPS1 Svr ReadDevInfo error:"<<strErr<<"\n";
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
    ROS_INFO("Service OFPS1/ReadVersion is called.");
    //
    nErr=uartOFPS1.ReadVersion(ac,strErr);
    if(nErr){
        cout<<"Service OFPS1 ReadVersion error:"<<strErr<<"\n";
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
    ROS_INFO("Service OFPS1//Reboot is called.");
    //
    nErr=uartOFPS1.Reboot(ac,strErr);
    if(nErr){
        cout<<"Service OFPS1 reboot error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool StartCalc(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service OFPS1/StartCalc is called.");
    //
    nErr=uartOFPS1.StartCalc(ac,strErr);
    if(nErr){
        cout<<"Service OFPS1 StartCalc error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool StopCalc(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service OFPS1/StopCalc is called.");
    //
    nErr=uartOFPS1.StopCalc(ac,strErr);
    if(nErr){
        cout<<"Service OFPS1 StopCalc error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool ZeroOdometry(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
#ifdef PROJ_DEBUG
    ROS_INFO("Service OFPS1/ZeroOdometry is called.");
#endif
    //
    nErr=uartOFPS1.ZeroOdometry(ac,strErr);
    if(nErr){
        cout<<"OFPS1 Svr ZeroOdometry error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool ReadEncoder(N_Robot::OFPS1_ReadEncoder_srv::Request &req,N_Robot::OFPS1_ReadEncoder_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[12];
#ifdef PROJ_DEBUG
    ROS_INFO("Service OFPS1/ReadEncoder is called.");
#endif
    //
    nErr=uartOFPS1.ReadEncoder(ac,strErr);
    if(nErr){
        cout<<"OFPS1 Svr ReadEncoder error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;

    Union64 union64;

    union64.u8[0]=ac[0];
    union64.u8[1]=ac[1];
    union64.u8[2]=ac[2];
    union64.u8[3]=ac[3];
    res.f32Encoder1=union64.f32[0];
    union64.u8[0]=ac[4];
    union64.u8[1]=ac[5];
    union64.u8[2]=ac[6];
    union64.u8[3]=ac[7];
    res.f32Encoder2=union64.f32[0];
    union64.u8[0]=ac[8];
    union64.u8[1]=ac[9];
    union64.u8[2]=ac[10];
    union64.u8[3]=ac[11];
    res.f32Encoder3=union64.f32[0];
    //**
    return true;
}
bool ReadPosition(N_Robot::OFPS1_ReadPosition_srv::Request &req,N_Robot::OFPS1_ReadPosition_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[12];
#ifdef PROJ_DEBUG
    ROS_INFO("Service OFPS1/ReadPosition is called.");
#endif
    //
    nErr=uartOFPS1.ReadPosition(ac,strErr);
    if(nErr){
        cout<<"OFPS1 Svr ReadPosition error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;

    Union64 union64;

    union64.u8[0]=ac[0];
    union64.u8[1]=ac[1];
    union64.u8[2]=ac[2];
    union64.u8[3]=ac[3];
    res.f32PositionX=union64.f32[0];
    union64.u8[0]=ac[4];
    union64.u8[1]=ac[5];
    union64.u8[2]=ac[6];
    union64.u8[3]=ac[7];
    res.f32PositionY=union64.f32[0];
    union64.u8[0]=ac[8];
    union64.u8[1]=ac[9];
    union64.u8[2]=ac[10];
    union64.u8[3]=ac[11];
    res.f32PositionTh=union64.f32[0];
    //**
    return true;
}
//
bool SetPosition(N_Robot::OFPS1_SetPosition_srv::Request &req,N_Robot::OFPS1_SetPosition_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[12];

    Union64 union64;

    union64.f32[0]=req.f32PositionX;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    ac[2]=union64.u8[2];
    ac[3]=union64.u8[3];
    union64.f32[0]=req.f32PositionY;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    ac[6]=union64.u8[2];
    ac[7]=union64.u8[3];
    union64.f32[0]=req.f32PositionTh;
    ac[8]=union64.u8[0];
    ac[9]=union64.u8[1];
    ac[10]=union64.u8[2];
    ac[11]=union64.u8[3];
#ifdef PROJ_DEBUG
    ROS_INFO("Service OFPS1/SetPosition is called.");
#endif
    //
    nErr=uartOFPS1.SetPosition(ac,strErr);
    if(nErr){
        cout<<"OFPS1 Svr SetPosition error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
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
    ros::init(argc,argv,"OFPS1");
    ros::NodeHandle n;
    ROS_INFO("Chengdu Hangfa OFPS1 node.v1.507");
    //** set uart parameter
    //printf("%s,%d,%d\n",argv[1],strPara1.find("/dev/tty"),string::npos);
    if(strPara1.find("/dev/tty")==string::npos){
        uartOFPS1.pcPortName=UARTPORTNAME_OFPS1;//USBcom use PL2303 chip
    }else{
        uartOFPS1.pcPortName=argv[1];
    }
    uartOFPS1.nUartSpeed=38400;
    uartOFPS1.nUartFlowCtrl=0;
    uartOFPS1.nUartDatabits=8;
    uartOFPS1.nUartStopbits=1;
    uartOFPS1.nParity='N';
#ifdef PROJ_DEBUG
    printf("UART Setting:port name =%s,speed=%d,flowctrl=%d,databits=%d,stopbits=%d,parity=%c\n",uartOFPS1.pcPortName,uartOFPS1.nUartSpeed,uartOFPS1.nUartFlowCtrl,uartOFPS1.nUartDatabits,uartOFPS1.nUartStopbits,uartOFPS1.nParity);
#endif
    //** open serial port
    nErr=uartOFPS1.InitPort();
    if(nErr){
        ROS_INFO("Fail to init %s.",uartOFPS1.pcPortName);
        return -1;
    }
    uartOFPS1.ClearRcvBuf();
    //**
    ros::ServiceServer serReadDevInfo =    n.advertiseService("OFPS1/ReadDevInfo",ReadDevInfo);
    ROS_INFO("advertise service ReadDevInfo OK.");
    ros::ServiceServer serReadVersion = n.advertiseService("OFPS1/ReadVersion",ReadVersion);
    ROS_INFO("advertise service ReadVersion OK.");
    ros::ServiceServer serReboot = n.advertiseService("OFPS1/Reboot",Reboot);
    ROS_INFO("advertise service Reboot OK.");
    ros::ServiceServer serZeroOdometry =   n.advertiseService("OFPS1/ZeroOdometry",ZeroOdometry);
    ROS_INFO("advertise service ZeroOdometry OK.");
    ros::ServiceServer serReadPosition =    n.advertiseService("OFPS1/ReadPosition",ReadPosition);
    ROS_INFO("advertise service ReadPosition OK.");
    ros::ServiceServer serStartCalc = n.advertiseService("OFPS1/StartCalc",StartCalc);
    ROS_INFO("advertise service StartCalc OK.");
    ros::ServiceServer serStopCalc = n.advertiseService("OFPS1/StopCalc",StopCalc);
    ROS_INFO("advertise service StopCalc OK.");
    ros::ServiceServer serReadEncoder =    n.advertiseService("OFPS1/ReadEncoder",ReadEncoder);
    ROS_INFO("advertise service ReadEncoder OK.");
    ros::ServiceServer serSetPosition =    n.advertiseService("OFPS1/SetPosition",SetPosition);
    ROS_INFO("advertise service SetPosition OK.");
    //
    ros::spin();
    //**
    return 0;
}

