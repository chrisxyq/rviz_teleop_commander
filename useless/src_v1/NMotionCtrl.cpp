#include "Project.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"
#include "stdio.h"
#include "UART.h"
#include "UartNMotion.h"
#include <unistd.h> //sleep()
#include "Algorithm.h"
#include <sys/time.h>
#include <iostream>
#include <string>
#include "navigator_q2/NMotionCtrl_ReadDevInfo_srv.h"
#include "navigator_q2/NMotionCtrl_ReadVersion_srv.h"
#include "navigator_q2/NMotionCtrl_ReadMotionStatus_srv.h"
#include "navigator_q2/NMotionCtrl_ResetAllMotorDriver_srv.h"
#include "navigator_q2/CmdOnly_srv.h"
#include "navigator_q2/NMotionCtrl_StartMotion_srv.h"
#include "navigator_q2/NMotionCtrl_SuspendMotion_srv.h"
#include "navigator_q2/NMotionCtrl_ContinueMotion_srv.h"
#include "navigator_q2/NMotionCtrl_StopMotion_srv.h"
#include "navigator_q2/NMotionCtrl_JumpToNextCmd_srv.h"
#include "navigator_q2/NMotionCtrl_SetInstantVelocity_srv.h"
#include "navigator_q2/NMotionCtrl_DefineMotorSpeed_srv.h"
#include "navigator_q2/NMotionCtrl_JoyCmdMotion_srv.h"
#include "navigator_q2/NMotionCtrl_SetDir_srv.h"
#include "navigator_q2/NMotionCtrl_WaitTime_srv.h"
#include "navigator_q2/NMotionCtrl_SMATSpeedMode_srv.h"
#include "navigator_q2/NMotionCtrl_CMATSpeedMode_srv.h"
#include "navigator_q2/NMotionCtrl_SMATPositionMode_srv.h"
#include "navigator_q2/NMotionCtrl_STATPositionMode_srv.h"
#include "navigator_q2/NMotionCtrl_CMATPositionMode_srv.h"
#include "navigator_q2/NMotionCtrl_CAATPositionMode_srv.h"
// #include "N_Robot/NMotionCtrl_ReadDevInfo_srv.h"
// #include "N_Robot/NMotionCtrl_ReadVersion_srv.h"
// #include "N_Robot/NMotionCtrl_ReadMotionStatus_srv.h"
// #include "N_Robot/NMotionCtrl_ResetAllMotorDriver_srv.h"
// #include "N_Robot/CmdOnly_srv.h"
// #include "N_Robot/NMotionCtrl_StartMotion_srv.h"
// #include "N_Robot/NMotionCtrl_SuspendMotion_srv.h"
// #include "N_Robot/NMotionCtrl_ContinueMotion_srv.h"
// #include "N_Robot/NMotionCtrl_StopMotion_srv.h"
// #include "N_Robot/NMotionCtrl_JumpToNextCmd_srv.h"
// #include "N_Robot/NMotionCtrl_SetInstantVelocity_srv.h"
// #include "N_Robot/NMotionCtrl_DefineMotorSpeed_srv.h"
// #include "N_Robot/NMotionCtrl_JoyCmdMotion_srv.h"
// #include "N_Robot/NMotionCtrl_SetDir_srv.h"
// #include "N_Robot/NMotionCtrl_WaitTime_srv.h"
// #include "N_Robot/NMotionCtrl_SMATSpeedMode_srv.h"
// #include "N_Robot/NMotionCtrl_CMATSpeedMode_srv.h"
// #include "N_Robot/NMotionCtrl_SMATPositionMode_srv.h"
// #include "N_Robot/NMotionCtrl_STATPositionMode_srv.h"
// #include "N_Robot/NMotionCtrl_CMATPositionMode_srv.h"
// #include "N_Robot/NMotionCtrl_CAATPositionMode_srv.h"
//
UartNMotion nMotionUart;

bool ReadDevInfo(N_Robot::NMotionCtrl_ReadDevInfo_srv::Request &req,N_Robot::NMotionCtrl_ReadDevInfo_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
    ROS_INFO("Service NMotionCtrl/ReadDevInfo is called.");
    //
    nErr=nMotionUart.ReadDevInfo(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr ReadDevInfo error:"<<strErr<<"\n";
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
    ROS_INFO("Service NMotionCtrl/ReadVersion is called.");
    //
    nErr=nMotionUart.ReadVersion(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr ReadVersion error:"<<strErr<<"\n";
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
    ROS_INFO("Service NMotionCtrl/Reboot is called.");
    //
    nErr=nMotionUart.Reboot(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr reboot error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}
bool ReadMotionStatus(N_Robot::NMotionCtrl_ReadMotionStatus_srv::Request &req,N_Robot::NMotionCtrl_ReadMotionStatus_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[7];
    ROS_INFO("Service NMotionCtrl/ReadMotionStatus is called.");
    //
    nErr=nMotionUart.ReadMotionStatus(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr ReadMotionStatus error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8MotionStatus=ac[0];
    res.u8SysErrStatus=ac[1];
    res.u8MotorErrStatus=ac[2];
    res.u8MotionBufCnt=ac[3];
    res.u8CrtMotionBufAddr=ac[4];
    res.u8CmdBufCnt=ac[5];
    res.u8CrtCmdBufAddr=ac[6];
    //**
    return true;
}

bool ResetAllMotorDriver(N_Robot::NMotionCtrl_ResetAllMotorDriver_srv::Request &req,N_Robot::NMotionCtrl_ResetAllMotorDriver_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service NMotionCtrl/ResetAllMotorDriver is called.");
    //
    nErr=nMotionUart.ResetAllMotorDriver(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr ResetAllMotorDriver error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}

bool ClearMotionBuff(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service NMotionCtrl/ClearMotionBuff is called.");
    //
    nErr=nMotionUart.ClearMotionBuff(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr ClearMotionBuff error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}

bool ClearErrFlag(N_Robot::CmdOnly_srv::Request &req,N_Robot::CmdOnly_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service NMotionCtrl/ClearErrFlag is called.");
    //
    nErr=nMotionUart.ClearErrFlag(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr ClearErrFlag error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    //**
    return true;
}

bool StartMotion(N_Robot::NMotionCtrl_StartMotion_srv::Request &req,N_Robot::NMotionCtrl_StartMotion_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service NMotionCtrl/StartMotion is called.");
    //
    nErr=nMotionUart.StartMotion(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr StartMotion error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8MotionStatus=ac[0];
    //**
    return true;
}

bool SuspendMotion(N_Robot::NMotionCtrl_SuspendMotion_srv::Request &req,N_Robot::NMotionCtrl_SuspendMotion_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service NMotionCtrl/SuspendMotion is called.");
    //
    nErr=nMotionUart.SuspendMotion(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr SuspendMotion error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8MotionStatus=ac[0];
    //**
    return true;
}

bool ContinueMotion(N_Robot::NMotionCtrl_ContinueMotion_srv::Request &req,N_Robot::NMotionCtrl_ContinueMotion_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[1];
    ROS_INFO("Service NMotionCtrl/ContinueMotion is called.");
    //
    nErr=nMotionUart.ContinueMotion(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr ContinueMotion error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8MotionStatus=ac[0];
    //**
    return true;
}

bool StopMotion(N_Robot::NMotionCtrl_StopMotion_srv::Request &req,N_Robot::NMotionCtrl_StopMotion_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[2];
    ROS_INFO("Service NMotionCtrl/StopMotion is called.");
    //
    nErr=nMotionUart.StopMotion(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr StopMotion error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8MotionStatus=ac[0];
    res.u8SysErrStatus=ac[1];
    //**
    return true;
}

bool JumpToNextCmd(N_Robot::NMotionCtrl_JumpToNextCmd_srv::Request &req,N_Robot::NMotionCtrl_JumpToNextCmd_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[2];
    ROS_INFO("Service NMotionCtrl/JumpToNextCmd is called.");
    //
    nErr=nMotionUart.JumpToNextCmd(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr JumpToNextCmd error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8MotionStatus=ac[0];
    res.u8SysErrStatus=ac[1];
    //**
    return true;
}

bool StopMotionAndSetDir(N_Robot::NMotionCtrl_SetDir_srv::Request &req,N_Robot::NMotionCtrl_SetDir_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[4];
    ROS_INFO("Service NMotionCtrl/StopMotionAndSetDir is called.");
    //
    Union64 union64;

    union64.f32[0]=req.f32Direction;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    ac[2]=union64.u8[2];
    ac[3]=union64.u8[3];
    //
    nErr=nMotionUart.StopMotionAndSetDir(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr StopMotionAndSetDir error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    if(res.u8SysErrStatus!=0){
        res.s32ErrCode=5;
        res.strErrInfo="The angel to set is out of range!";
    }
    //**
    return true;
}
bool SetDirAfterMotion(N_Robot::NMotionCtrl_SetDir_srv::Request &req,N_Robot::NMotionCtrl_SetDir_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[4];
    ROS_INFO("Service NMotionCtrl/SetDirAfterMotion is called.");
    //
    Union64 union64;

    union64.f32[0]=req.f32Direction;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    ac[2]=union64.u8[2];
    ac[3]=union64.u8[3];
    //
    nErr=nMotionUart.SetDirAfterMotion(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr SetDirAfterMotion error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    if(res.u8SysErrStatus!=0){
        res.s32ErrCode=5;
        res.strErrInfo="The angel to set is out of range!";
    }
    //**
    return true;
}
bool WaitTime(N_Robot::NMotionCtrl_WaitTime_srv::Request &req,N_Robot::NMotionCtrl_WaitTime_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[2];
    ROS_INFO("Service NMotionCtrl/WaitTime is called.");
    //
    Union64 union64;

    union64.u16[0]=req.u16Time;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];

    //
    nErr=nMotionUart.WaitTime(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr WaitTime error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}

bool SetInstantVelocity(N_Robot::NMotionCtrl_SetInstantVelocity_srv::Request &req,N_Robot::NMotionCtrl_SetInstantVelocity_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
    ROS_INFO("Service NMotionCtrl/SetInstantVelocity is called.req:direction angle:%d,linearVel:%d,AngularVel:%d",
             req.s16DirectionAngle,req.u16LinearVelocity,req.s16AngularVelocity);
    //
    Union64 union64;

    union64.s16[0]=req.s16DirectionAngle;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.u16[0]=req.u16LinearVelocity;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.s16[0]=req.s16AngularVelocity;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    //
    nErr=nMotionUart.SetInstantVelocity(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr SetInstantVelocity error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}
bool SMATSpeedMode(N_Robot::NMotionCtrl_SMATSpeedMode_srv::Request &req,N_Robot::NMotionCtrl_SMATSpeedMode_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
    ROS_INFO("Service NMotionCtrl/SMATSpeedMode is called.req:direction angle:%d,linearVel:%d,AngularVel:%d",
             req.s16DirectionAngle,req.u16LinearVelocity,req.s16AngularVelocity);
    //
    Union64 union64;

    union64.s16[0]=req.s16DirectionAngle;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.u16[0]=req.u16LinearVelocity;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.s16[0]=req.s16AngularVelocity;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    //
    nErr=nMotionUart.SMATSpeedMode(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr SMATSpeedMode error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}
bool CMATSpeedMode(N_Robot::NMotionCtrl_CMATSpeedMode_srv::Request &req,N_Robot::NMotionCtrl_CMATSpeedMode_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[8];
    ROS_INFO("Service NMotionCtrl/CMATSpeedMode is called.");
    //
    Union64 union64;

    union64.s16[0]=req.s16DirectionAngle;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.u16[0]=req.u16CycleR;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.u16[0]=req.u16LinearVelocity;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    union64.s16[0]=req.s16AngularVelocity;
    ac[6]=union64.u8[0];
    ac[7]=union64.u8[1];
    //
    nErr=nMotionUart.CMATSpeedMode(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr CMATSpeedMode error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}
bool CAATSpeedMode(N_Robot::NMotionCtrl_CMATSpeedMode_srv::Request &req,N_Robot::NMotionCtrl_CMATSpeedMode_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[8];
    ROS_INFO("Service NMotionCtrl/CAATSpeedMode is called.");
    //
    Union64 union64;

    union64.s16[0]=req.s16DirectionAngle;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.u16[0]=req.u16CycleR;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.u16[0]=req.u16LinearVelocity;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    union64.s16[0]=req.s16AngularVelocity;
    ac[6]=union64.u8[0];
    ac[7]=union64.u8[1];
    //
    nErr=nMotionUart.CAATSpeedMode(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr CAATSpeedMode error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}
bool DefineMotorSpeed(N_Robot::NMotionCtrl_DefineMotorSpeed_srv::Request &req,N_Robot::NMotionCtrl_DefineMotorSpeed_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
    ROS_INFO("Service NMotionCtrl/DefineMotorSpeed is called.req:Wheel1:%d,Wheel2:%d,Wheel3:%d,Wheel4:%d",
             req.s16Wheel1,req.s16Wheel2,req.s16Wheel3,req.s16Wheel4);
    //
    Union64 union64;

    union64.s16[0]=req.s16Wheel1;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.s16[0]=req.s16Wheel2;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.s16[0]=req.s16Wheel3;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    union64.s16[0]=req.s16Wheel4;
    ac[6]=union64.u8[0];
    ac[7]=union64.u8[1];
    //
    nErr=nMotionUart.DefineMotorSpeed(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr DefineMotorSpeed error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}

bool SMATPositionMode(N_Robot::NMotionCtrl_SMATPositionMode_srv::Request &req,N_Robot::NMotionCtrl_SMATPositionMode_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[8];
    ROS_INFO("Service NMotionCtrl/SMATPositionMode is called.");
    //
    Union64 union64;

    union64.s16[0]=req.s16X;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.s16[0]=req.s16Y;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.u16[0]=req.u16LinearVelocity;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    union64.s16[0]=req.s16AngularVelocity;
    ac[6]=union64.u8[0];
    ac[7]=union64.u8[1];
    //
    nErr=nMotionUart.SMATPositionMode(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr SMATPositionMode error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}

bool STATPositionMode(N_Robot::NMotionCtrl_STATPositionMode_srv::Request &req,N_Robot::NMotionCtrl_STATPositionMode_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[8];
    ROS_INFO("Service NMotionCtrl/STATPositionMode is called.");
    //
    Union64 union64;

    union64.s16[0]=req.s16DirectionAngle;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.s16[0]=req.s16Distance;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.u16[0]=req.u16LinearVelocity;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    union64.s16[0]=req.s16AngularVelocity;
    ac[6]=union64.u8[0];
    ac[7]=union64.u8[1];
    //
    nErr=nMotionUart.STATPositionMode(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr STATPositionMode error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}

bool CMATPositionMode(N_Robot::NMotionCtrl_CMATPositionMode_srv::Request &req,N_Robot::NMotionCtrl_CMATPositionMode_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[10];
    ROS_INFO("Service NMotionCtrl/CMATPositionMode is called.");
    //
    Union64 union64;

    union64.s16[0]=req.s16X;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.s16[0]=req.s16Y;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.u16[0]=req.u16CycleR;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    union64.u16[0]=req.u16LinearVelocity;
    ac[6]=union64.u8[0];
    ac[7]=union64.u8[1];
    union64.s16[0]=req.s16AngularVelocity;
    ac[8]=union64.u8[0];
    ac[9]=union64.u8[1];
    //
    nErr=nMotionUart.CMATPositionMode(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr CMATPositionMode error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}

bool CAATPositionMode(N_Robot::NMotionCtrl_CAATPositionMode_srv::Request &req,N_Robot::NMotionCtrl_CAATPositionMode_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[10];
    ROS_INFO("Service NMotionCtrl/CAATPositionMode is called.");
    //
    Union64 union64;

    union64.s16[0]=req.s16X;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.s16[0]=req.s16Y;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.u16[0]=req.u16CycleR;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    union64.u16[0]=req.u16LinearVelocity;
    ac[6]=union64.u8[0];
    ac[7]=union64.u8[1];
    union64.s16[0]=req.s16AngularVelocity;
    ac[8]=union64.u8[0];
    ac[9]=union64.u8[1];
    //
    nErr=nMotionUart.CAATPositionMode(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr CAATPositionMode error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}
bool JoyCmdMotion(N_Robot::NMotionCtrl_JoyCmdMotion_srv::Request &req,N_Robot::NMotionCtrl_JoyCmdMotion_srv::Response &res){
    int nErr;
    string strErr;
    //**
    unsigned char ac[6];
    ROS_INFO("Service NMotionCtrl/JoyCmdMotion is called.req:Joy X:%d,Joy Y:%d,Joy Z:%d",
             req.s16JoyX,req.s16JoyY,req.s16JoyZ);
    //
    Union64 union64;

    union64.s16[0]=req.s16JoyX;
    ac[0]=union64.u8[0];
    ac[1]=union64.u8[1];
    union64.s16[0]=req.s16JoyY;
    ac[2]=union64.u8[0];
    ac[3]=union64.u8[1];
    union64.s16[0]=req.s16JoyZ;
    ac[4]=union64.u8[0];
    ac[5]=union64.u8[1];
    //
    nErr=nMotionUart.JoyCmdMotion(ac,strErr);
    if(nErr){
        cout<<"NMotionSvr JoyCmdMotion error:"<<strErr<<"\n";
    }
    res.s32ErrCode=nErr;
    res.strErrInfo=strErr;
    res.u8SysErrStatus=ac[0];
    //**
    return true;
}


int main(int argc,char **argv){
    string strPara1;
    int nErr;
    //

    if(argc>1){
        strPara1=argv[1];
    }else{
        strPara1="";
    }
    ros::init(argc,argv,"NMotionCtrl");
    ros::NodeHandle n;
    ROS_INFO("Chengdu Hangfa N serials robot motion node.v1.507");
    //** set uart parameter
    if(strPara1.find("/dev/tty")==string::npos){
        nMotionUart.pcPortName=UARTPORTNAME_NMOTIONCTRL;//USBcom use PL2303 chip
    }else{
        nMotionUart.pcPortName=argv[1];
    }

    nMotionUart.nUartSpeed=38400;//9600
    nMotionUart.nUartFlowCtrl=0;
    nMotionUart.nUartDatabits=8;
    nMotionUart.nUartStopbits=1;
    nMotionUart.nParity='N';
#ifdef PROJ_DEBUG
    printf("UART Setting:port name =%s,speed=%d,flowctrl=%d,databits=%d,stopbits=%d,parity=%c\n",nMotionUart.pcPortName,nMotionUart.nUartSpeed,nMotionUart.nUartFlowCtrl,nMotionUart.nUartDatabits,nMotionUart.nUartStopbits,nMotionUart.nParity);
#endif
    //** open serial port
    nErr=nMotionUart.InitPort();
    if(nErr){
        ROS_INFO("Fail to init %s.",nMotionUart.pcPortName);
        return -1;
    }
    nMotionUart.ClearRcvBuf();
    //**
    ros::ServiceServer serReadDevInfo = n.advertiseService("NMotionCtrl/ReadDevInfo",ReadDevInfo);
    ROS_INFO("advertise service ReadDevInfo OK.");
    ros::ServiceServer serReadVersion = n.advertiseService("NMotionCtrl/ReadVersion",ReadVersion);
    ROS_INFO("advertise service ReadVersion OK.");
    ros::ServiceServer serReboot = n.advertiseService("NMotionCtrl/Reboot",Reboot);
    ROS_INFO("advertise service Reboot OK.");
    ros::ServiceServer serReadMotionStatus = n.advertiseService("NMotionCtrl/ReadMotionStatus",ReadMotionStatus);
    ROS_INFO("advertise service ReadMotionStatus OK.");
    ros::ServiceServer serResetAllMotorDriver = n.advertiseService("NMotionCtrl/ResetAllMotorDriver",ResetAllMotorDriver);
    ROS_INFO("advertise service ResetAllMotorDriver OK.");
    ros::ServiceServer serClearMotionBuff = n.advertiseService("NMotionCtrl/ClearMotionBuff",ClearMotionBuff);
    ROS_INFO("advertise service ClearMotionBuff OK.");
    ros::ServiceServer serClearErrFlag = n.advertiseService("NMotionCtrl/ClearErrFlag",ClearErrFlag);
    ROS_INFO("advertise service ClearErrFlag OK.");
    ros::ServiceServer serStartMotion = n.advertiseService("NMotionCtrl/StartMotion",StartMotion);
    ROS_INFO("advertise service StartMotion OK.");
    ros::ServiceServer serSuspendMotion = n.advertiseService("NMotionCtrl/SuspendMotion",SuspendMotion);
    ROS_INFO("advertise service SuspendMotion OK.");
    ros::ServiceServer serContinueMotion = n.advertiseService("NMotionCtrl/ContinueMotion",ContinueMotion);
    ROS_INFO("advertise service ContinueMotion OK.");
    ros::ServiceServer serStopMotion = n.advertiseService("NMotionCtrl/StopMotion",StopMotion);
    ROS_INFO("advertise service StopMotion OK.");
    ros::ServiceServer serJumpToNextCmd = n.advertiseService("NMotionCtrl/JumpToNextCmd",JumpToNextCmd);
    ROS_INFO("advertise service JumpToNextCmd OK.");
    ros::ServiceServer serStopMotionAndSetDir = n.advertiseService("NMotionCtrl/StopMotionAndSetDir",StopMotionAndSetDir);
    ROS_INFO("advertise service StopMotionAndSetDir OK.");
    ros::ServiceServer serSetInstantVelocity = n.advertiseService("NMotionCtrl/SetInstantVelocity",SetInstantVelocity);
    ROS_INFO("advertise service SetInstantVelocity OK.");
    ros::ServiceServer serSMATSpeedMode = n.advertiseService("NMotionCtrl/SMATSpeedMode",SMATSpeedMode);
    ROS_INFO("advertise service SMATSpeedMode OK.");
    ros::ServiceServer serCMATSpeedMode = n.advertiseService("NMotionCtrl/CMATSpeedMode",CMATSpeedMode);
    ROS_INFO("advertise service CMATSpeedMode OK.");
    ros::ServiceServer serDefineMotorSpeed = n.advertiseService("NMotionCtrl/DefineMotorSpeed",DefineMotorSpeed);
    ROS_INFO("advertise service DefineMotorSpeed OK.");
    ros::ServiceServer serJoyCmdMotion = n.advertiseService("NMotionCtrl/JoyCmdMotion",JoyCmdMotion);
    ROS_INFO("advertise service JoyCmdMotion OK.");
    ros::ServiceServer serSMATPositionMode = n.advertiseService("NMotionCtrl/SMATPositionMode",SMATPositionMode);
    ROS_INFO("advertise service SMATPositionMode OK.");
    ros::ServiceServer serSTATPositionMode = n.advertiseService("NMotionCtrl/STATPositionMode",STATPositionMode);
    ROS_INFO("advertise service STATPositionMode OK.");
    ros::ServiceServer serCMATPositionMode = n.advertiseService("NMotionCtrl/CMATPositionMode",CMATPositionMode);
    ROS_INFO("advertise service CMATPositionMode OK.");
    ros::ServiceServer serCAATPositionMode = n.advertiseService("NMotionCtrl/CAATPositionMode",CAATPositionMode);
    ROS_INFO("advertise service CAATPositionMode OK.");

    //
    ros::spin();
    //**
    return 0;
}
