#include "Project.h"
#include <ros/ros.h>
#include <string>
    using namespace std;
#include "Algorithm.h"
#include "UartPS.h"
#include "N_Robot/PS_ReadDevInfo_srv.h"
#include "N_Robot/CmdOnly_srv.h"
#include "N_Robot/NMotionCtrl_ReadVersion_srv.h"
#include "N_Robot/PS_ReadStatus_srv.h"
#include "N_Robot/PS_ReadRawData_srv.h"
#include "N_Robot/PS_ReadTransData_srv.h"

//
UartPS uartPS;
//
bool StartTrans(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service PS/StartTrans is called.");
    //
    nErr=uartPS.StartTrans(ac,strErr);
    if(nErr){
        cout<<"Service PS StartTrans error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool ReadDevInfo(N_Robot::PS_ReadDevInfo_srv::Request &req,N_Robot::PS_ReadDevInfo_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
#ifdef PROJ_DEBUG
    ROS_INFO("Service PS/ReadDevInfo is called.");
#endif
    //
    nErr=uartPS.ReadDevInfo(ac,strErr);
    if(nErr){
        cout<<"PS Svr ReadDevInfo error:"<<strErr<<"\n";
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
    ROS_INFO("Service PS/ReadVersion is called.");
    //
    nErr=uartPS.ReadVersion(ac,strErr);
    if(nErr){
        cout<<"Service PS ReadVersion error:"<<strErr<<"\n";
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
    ROS_INFO("Service PS/Reboot is called.");
    //
    nErr=uartPS.Reboot(ac,strErr);
    if(nErr){
        cout<<"Service PS reboot error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool ReadStatus(N_Robot::PS_ReadStatus_srv::Request &req,N_Robot::PS_ReadStatus_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[8];
#ifdef PROJ_DEBUG
    ROS_INFO("Service PS/ReadStatus is called.");
#endif
    //
    nErr=uartPS.ReadStatus(ac,strErr);
    if(nErr){
        cout<<"PS Svr ReadStatus error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8BattOpen=ac[0];
    res.u8SwitchDown=ac[1];
    res.u8ChargerIn=ac[2];
    res.u8ChargeComp=ac[3];
    res.u8ChargeOverFlow=ac[4];
    res.u8ChargerOverVolt=ac[5];
    res.u8ChargerVoltLow=ac[6];
    res.u8ChargerOverFlow=ac[7];
    //**
    return true;
}
bool OpenUp(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service PS/OpenUp is called.");
    //
    nErr=uartPS.OpenUp(ac,strErr);
    if(nErr){
        cout<<"Service PS OpenUp error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool CloseDown(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service PS/CloseDown is called.");
    //
    nErr=uartPS.CloseDown(ac,strErr);
    if(nErr){
        cout<<"Service PS CloseDown error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool ReadRawData(N_Robot::PS_ReadRawData_srv::Request &req,N_Robot::PS_ReadRawData_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[8];
#ifdef PROJ_DEBUG
    ROS_INFO("Service PS/ReadRawData is called.");
#endif
    //
    nErr=uartPS.ReadRawData(ac,strErr);
    if(nErr){
        cout<<"PS Svr ReadRawData error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    Union64 union64;

    union64.u8[0]=ac[0];
    union64.u8[1]=ac[1];
    res.u16BattVolt=union64.u16[0];
    union64.u8[0]=ac[2];
    union64.u8[1]=ac[3];
    res.u16BattCurr=union64.u16[0];
    union64.u8[0]=ac[4];
    union64.u8[1]=ac[5];
    res.u16BattChargeCurr=union64.u16[0];
    union64.u8[0]=ac[6];
    union64.u8[1]=ac[7];
    res.u16Temperture=union64.u16[0];
    //**
    return true;
}
bool ReadTransData(N_Robot::PS_ReadTransData_srv::Request &req,N_Robot::PS_ReadTransData_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[8];
#ifdef PROJ_DEBUG
    ROS_INFO("Service PS/ReadTransData is called.");
#endif
    //
    nErr=uartPS.ReadTransData(ac,strErr);
    if(nErr){
        cout<<"PS Svr ReadTransData error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    Union64 union64;

    union64.u8[0]=ac[0];
    union64.u8[1]=ac[1];
    res.u16BattVolt=union64.u16[0];
    union64.u8[0]=ac[2];
    union64.u8[1]=ac[3];
    res.s16BattCurr=union64.s16[0];
    union64.u8[0]=ac[4];
    union64.u8[1]=ac[5];
    res.s16BattChargeCurr=union64.s16[0];
    union64.u8[0]=ac[6];
    res.u8Temperture=union64.u8[0];
    //**
    return true;
}
bool EnableUartData(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service PS/EnableUartData is called.");
    //
    nErr=uartPS.EnableUartData(ac,strErr);
    if(nErr){
        cout<<"Service PS EnableUartData error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool DisableUartData(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service PS/DisableUartData is called.");
    //
    nErr=uartPS.DisableUartData(ac,strErr);
    if(nErr){
        cout<<"Service PS DisableUartData error:"<<strErr<<"\n";
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
    ros::init(argc,argv,"PS");
    ros::NodeHandle n;
    ROS_INFO("Chengdu Hangfa PS node.v1.607");
    //** set uart parameter
    //printf("%s,%d,%d\n",argv[1],strPara1.find("/dev/tty"),string::npos);
    if(strPara1.find("/dev/tty")==string::npos){
        uartPS.pcPortName=UARTPORTNAME_PS;//USBcom use PL2303 chip
    }else{
        uartPS.pcPortName=argv[1];
    }
    uartPS.nUartSpeed=38400;
    uartPS.nUartFlowCtrl=0;
    uartPS.nUartDatabits=8;
    uartPS.nUartStopbits=1;
    uartPS.nParity='N';
#ifdef PROJ_DEBUG
    printf("UART Setting:port name =%s,speed=%d,flowctrl=%d,databits=%d,stopbits=%d,parity=%c\n",uartPS.pcPortName,uartPS.nUartSpeed,uartPS.nUartFlowCtrl,uartPS.nUartDatabits,uartPS.nUartStopbits,uartPS.nParity);
#endif
    //** open serial port
    nErr=uartPS.InitPort();
    if(nErr){
        ROS_INFO("Fail to init %s.",uartPS.pcPortName);
        return -1;
    }
    uartPS.ClearRcvBuf();
    //**
    ros::ServiceServer serStartTrans = n.advertiseService("PS/StartTrans",StartTrans);
    ROS_INFO("advertise service StartTrans OK.");
    ros::ServiceServer serReadDevInfo =    n.advertiseService("PS/ReadDevInfo",ReadDevInfo);
    ROS_INFO("advertise service ReadDevInfo OK.");
    ros::ServiceServer serReadVersion = n.advertiseService("PS/ReadVersion",ReadVersion);
    ROS_INFO("advertise service ReadVersion OK.");
    ros::ServiceServer serReboot = n.advertiseService("PS/Reboot",Reboot);
    ROS_INFO("advertise service Reboot OK.");
    ros::ServiceServer serReadStatus =    n.advertiseService("PS/ReadStatus",ReadStatus);
    ROS_INFO("advertise service ReadStatus OK.");
    ros::ServiceServer serOpenUp = n.advertiseService("PS/OpenUp",OpenUp);
    ROS_INFO("advertise service OpenUp OK.");
    ros::ServiceServer serCloseDown = n.advertiseService("PS/CloseDown",CloseDown);
    ROS_INFO("advertise service CloseDown OK.");
    ros::ServiceServer serReadRawData = n.advertiseService("PS/ReadRawData",ReadRawData);
    ROS_INFO("advertise service ReadRawData OK.");
    ros::ServiceServer serReadTransData = n.advertiseService("PS/ReadTransData",ReadTransData);
    ROS_INFO("advertise service ReadTransData OK.");
    ros::ServiceServer serEnableUartData = n.advertiseService("PS/EnableUartData",EnableUartData);
    ROS_INFO("advertise service EnableUartData OK.");
    ros::ServiceServer serDisableUartData = n.advertiseService("PS/DisableUartData",DisableUartData);
    ROS_INFO("advertise service DisableUartData OK.");
    //
    ros::spin();
    //**
    return 0;
}

