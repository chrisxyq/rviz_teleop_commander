#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"
#include "stdio.h"
//#include <unistd.h> //sleep()
#include <iostream>
#include <string>
    using namespace std;
#include <sys/time.h>
#include "N_Robot/NMotionCtrl_ReadDevInfo_srv.h"
#include "N_Robot/NMotionCtrl_ReadVersion_srv.h"
#include "N_Robot/NMotionCtrl_ReadMotionStatus_srv.h"
#include "N_Robot/NMotionCtrl_ResetAllMotorDriver_srv.h"
#include "N_Robot/CmdOnly_srv.h"
#include "N_Robot/NMotionCtrl_StartMotion_srv.h"
#include "N_Robot/NMotionCtrl_SuspendMotion_srv.h"
#include "N_Robot/NMotionCtrl_ContinueMotion_srv.h"
#include "N_Robot/NMotionCtrl_StopMotion_srv.h"
#include "N_Robot/NMotionCtrl_JumpToNextCmd_srv.h"
#include "N_Robot/NMotionCtrl_SetInstantVelocity_srv.h"
#include "N_Robot/NMotionCtrl_DefineMotorSpeed_srv.h"
#include "N_Robot/NMotionCtrl_JoyCmdMotion_srv.h"
#include "N_Robot/PathFinder_msg.h"
#include "N_Robot/CyberJoy_msg.h"
#include <nav_msgs/Odometry.h>
#include "N_Robot/NMotionCtrl_SetDir_srv.h"
#include "N_Robot/NMotionCtrl_WaitTime_srv.h"
#include "N_Robot/NMotionCtrl_SMATSpeedMode_srv.h"
#include "N_Robot/NMotionCtrl_CMATSpeedMode_srv.h"
#include "N_Robot/NMotionCtrl_SMATPositionMode_srv.h"
#include "N_Robot/NMotionCtrl_STATPositionMode_srv.h"
#include "N_Robot/NMotionCtrl_CMATPositionMode_srv.h"
#include "N_Robot/NMotionCtrl_CAATPositionMode_srv.h"
//
ros::NodeHandle * pN;
void msgcbPathfinder(const N_Robot::PathFinder_msg::ConstPtr & msgptr){
    string strErr;
    //
    if(msgptr->bValid){
        ROS_INFO("JOY1:[%d],[%d],[%d] JOY2:[%d],[%d]",msgptr->i16JOY1X,msgptr->i16JOY1Y,msgptr->i16JOY1Z,msgptr->i16JOY2X,msgptr->i16JOY2Y);
        //
        ROS_INFO("calling service NMotionCtrl/JoyCmdMotion.");
        ros::ServiceClient clientJoyCmdMotion=pN->serviceClient<N_Robot::NMotionCtrl_JoyCmdMotion_srv>("NMotionCtrl/JoyCmdMotion");
        N_Robot::NMotionCtrl_JoyCmdMotion_srv srvJoyCmdMotion;
        //
        srvJoyCmdMotion.request.s16JoyX=-msgptr->i16JOY1Y;//-500~500
        srvJoyCmdMotion.request.s16JoyY=msgptr->i16JOY1X;//-500~500
        srvJoyCmdMotion.request.s16JoyZ=msgptr->i16JOY1Z;//-500~500
        //
        if(clientJoyCmdMotion.call(srvJoyCmdMotion)){
            ROS_INFO("Success to call service NMotionCtrl/JoyCmdMotion");
            if(srvJoyCmdMotion.response.s32ErrCode){
                strErr=srvJoyCmdMotion.response.strErrInfo;
                ROS_INFO("JoyCmdMotion error:ErrCode:%d;ErrInfo:",srvJoyCmdMotion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvJoyCmdMotion.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/JoyCmdMotion");
        }
    }else{
        ROS_INFO("No valid data!");
    }
}

struct timeval tvJoy;
void msgcbTcpJoy(const N_Robot::CyberJoy_msg::ConstPtr & msgptr){
    string strErr;
    //
    struct timeval tv;
    gettimeofday(&tv,NULL);
    //
    if(msgptr->bValid){
        ROS_INFO("TcpJoy:Y=[%d],X=[%d],R=[%d],R2=[%d]",msgptr->i16VelY,msgptr->i16VelY,msgptr->i16VelR,msgptr->i16VelR2);
        //
        if(msgptr->i16VelY==0 && msgptr->i16VelX==0 && msgptr->i16VelR==0 && tv.tv_sec-tvJoy.tv_sec>2){
             //do nothing
        }else{
            if(msgptr->i16VelY!=0 || msgptr->i16VelX!=0 || msgptr->i16VelR!=0){
                tvJoy.tv_sec=tv.tv_sec;
            }
            ROS_INFO("calling service NMotionCtrl/JoyCmdMotion.");
            ros::ServiceClient clientJoyCmdMotion=pN->serviceClient<N_Robot::NMotionCtrl_JoyCmdMotion_srv>("NMotionCtrl/JoyCmdMotion");
            N_Robot::NMotionCtrl_JoyCmdMotion_srv srvJoyCmdMotion;
            //
            srvJoyCmdMotion.request.s16JoyX=-msgptr->i16VelY;//-500~500
            srvJoyCmdMotion.request.s16JoyY=msgptr->i16VelX;//-500~500
            srvJoyCmdMotion.request.s16JoyZ=msgptr->i16VelR;//-500~500
            //
            if(clientJoyCmdMotion.call(srvJoyCmdMotion)){
                ROS_INFO("Success to call service NMotionCtrl/JoyCmdMotion");
                if(srvJoyCmdMotion.response.s32ErrCode){
                    strErr=srvJoyCmdMotion.response.strErrInfo;
                    ROS_INFO("JoyCmdMotion error:ErrCode:%d;ErrInfo:",srvJoyCmdMotion.response.s32ErrCode);
                    cout<<strErr<<"\n";
                }else{
                    ROS_INFO(" success.system error code:%d.",srvJoyCmdMotion.response.u8SysErrStatus);
                }
            }else{
                ROS_INFO("Failed to call service NMotionCtrl/JoyCmdMotion");
            }
        }

    }else{
        ROS_INFO("No valid data!");
    }
}

struct timeval tvCmdVel;
void msgcbCmdVel(const geometry_msgs::Twist & twistAux){
    string strErr;
    //
    static geometry_msgs::Twist oldTwist;
    static unsigned long int ltvus=0;
    static unsigned long int ltvs=0;
    struct timeval tv;
    gettimeofday(&tv,NULL);
    if(tv.tv_sec-tvJoy.tv_sec<10){
        ROS_INFO("skipping CmdVel message,in cyber joy ctrl!");
        return;
    }
    //
    gettimeofday(&tvCmdVel,NULL);
    if(tvCmdVel.tv_sec-ltvs>0/*(tvCmdVel.tv_usec-ltvus>500000 && tvCmdVel.tv_sec-ltvs>0) || tvCmdVel.tv_sec-ltvs>1*/){
        ltvus=tvCmdVel.tv_usec;
        ltvs=tvCmdVel.tv_sec;
        ROS_INFO("responsing cmd_vel message.");
        oldTwist.linear.x =twistAux.linear.x;
        oldTwist.linear.y =twistAux.linear.y;
        oldTwist.angular.z =twistAux.angular.z;
    }else if(oldTwist.linear.x !=twistAux.linear.x || oldTwist.linear.y !=twistAux.linear.y || oldTwist.angular.z !=twistAux.angular.z){
        ltvus=tvCmdVel.tv_usec;
        ltvs=tvCmdVel.tv_sec;
        ROS_INFO("responsing updated cmd_vel message.");
        oldTwist.linear.x =twistAux.linear.x;
        oldTwist.linear.y =twistAux.linear.y;
        oldTwist.angular.z =twistAux.angular.z;
    }else{
        ROS_INFO("skipping cmd_vel message.");
        return;
    }
    //
    short s16JoyY,s16JoyX,s16JoyR;
    s16JoyY=twistAux.linear.x/0.003;
    s16JoyX=-twistAux.linear.y/0.003;//0.05*10;
    s16JoyR=twistAux.angular.z/0.015; //0.175*20;

    //
    if(s16JoyY>500){
        s16JoyY=500;
    }else if(s16JoyY<-500){
        s16JoyY=-500;
    }

    if(s16JoyX>500){
        s16JoyX=500;
    }else if(s16JoyX<-500){
        s16JoyX=-500;
    }

    if(s16JoyR>500){
        s16JoyR=500;
    }else if(s16JoyR<-500){
        s16JoyR=-500;
    }
    //

    ROS_INFO("Twist Joy:Y=[%d],X=[%d],R=[%d]",s16JoyY,s16JoyX,s16JoyR);
    //
    ROS_INFO("calling service NMotionCtrl/JoyCmdMotion.");
    ros::ServiceClient clientJoyCmdMotion=pN->serviceClient<N_Robot::NMotionCtrl_JoyCmdMotion_srv>("NMotionCtrl/JoyCmdMotion");
    N_Robot::NMotionCtrl_JoyCmdMotion_srv srvJoyCmdMotion;
    //
    srvJoyCmdMotion.request.s16JoyX=-s16JoyY;//-500~500
    srvJoyCmdMotion.request.s16JoyY=s16JoyX;//-500~500
    srvJoyCmdMotion.request.s16JoyZ=s16JoyR;//-500~500
    //
    if(clientJoyCmdMotion.call(srvJoyCmdMotion)){
        ROS_INFO("Success to call service NMotionCtrl/JoyCmdMotion");
        if(srvJoyCmdMotion.response.s32ErrCode){
            strErr=srvJoyCmdMotion.response.strErrInfo;
            ROS_INFO("JoyCmdMotion error:ErrCode:%d;ErrInfo:",srvJoyCmdMotion.response.s32ErrCode);
            cout<<strErr<<"\n";
        }else{
            ROS_INFO(" success.system error code:%d.",srvJoyCmdMotion.response.u8SysErrStatus);
        }
    }else{
        ROS_INFO("Failed to call service NMotionCtrl/JoyCmdMotion");
    }

}
//
int main(int argc,char ** argv){
    //int nErr;
    string strPara1;
    string strErr;
    ros::init(argc,argv,"TestNMotion");
    ros::NodeHandle n;
    pN=&n;
    ROS_INFO("Chengdu Hangfa N serials robot motion test node.");
    gettimeofday(&tvCmdVel,NULL);
    //
    printf("running para:%s\n%s,%s\n",argv[0],argv[1],argv[2]);
    if(argv[1]!=0){
        strPara1=argv[1];
    }else{
        strPara1="";
    }

    if(strPara1=="ReadDevInfo"){
        ROS_INFO("calling service NMotionCtrl/ReadDevInfo.");
        ros::ServiceClient clientReadDevInfo=n.serviceClient<N_Robot::NMotionCtrl_ReadDevInfo_srv>("NMotionCtrl/ReadDevInfo");
        N_Robot::NMotionCtrl_ReadDevInfo_srv srvReadDevInfo;
        if(clientReadDevInfo.call(srvReadDevInfo)){
            ROS_INFO("Success to call service NMotionCtrl/ReadDevInfo");
            if(srvReadDevInfo.response.s32ErrCode){
                strErr=srvReadDevInfo.response.strErrInfo;
                ROS_INFO("ReadDevInfo error:ErrCode:%d;ErrInfo:",srvReadDevInfo.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("Type=%x,Address=%x,SN=%d ",srvReadDevInfo.response.u8DevType,srvReadDevInfo.response.u8DevAddr,srvReadDevInfo.response.u32DevSN);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/ReadDevInfo");
        }
    }else if(strPara1=="ReadVersion"){
        ROS_INFO("calling service NMotionCtrl/ReadVersion.");
        ros::ServiceClient clientReadVersion=n.serviceClient<N_Robot::NMotionCtrl_ReadVersion_srv>("NMotionCtrl/ReadVersion");
        N_Robot::NMotionCtrl_ReadVersion_srv srvReadVersion;
        if(clientReadVersion.call(srvReadVersion)){
            ROS_INFO("Success to call service NMotionCtrl/ReadVersion");
            if(srvReadVersion.response.s32ErrCode){
                strErr=srvReadVersion.response.strErrInfo;
                ROS_INFO("ReadVersion error:ErrCode:%d;ErrInfo:",srvReadVersion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("hardware version=%d,software version=%f",srvReadVersion.response.u16HrdVer,srvReadVersion.response.f32SwVer);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/ReadVersion");
        }
    }else if(strPara1=="Reboot"){
        ROS_INFO("calling service NMotionCtrl/Reboot.");
        ros::ServiceClient clientReboot=n.serviceClient<N_Robot::CmdOnly_srv>("NMotionCtrl/Reboot");
        N_Robot::CmdOnly_srv srvReboot;
        if(clientReboot.call(srvReboot)){
            ROS_INFO("Success to call service NMotionCtrl/Reboot");
            if(srvReboot.response.s32ErrCode){
                strErr=srvReboot.response.strErrInfo;
                ROS_INFO("Reboot error:ErrCode:%d;ErrInfo:",srvReboot.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("reboot ok");
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/Reboot");
        }
    }else if(strPara1=="ReadMotionStatus"){
        ROS_INFO("calling service NMotionCtrl/ReadMotionStatus.");
        ros::ServiceClient clientReadMotionStatus=n.serviceClient<N_Robot::NMotionCtrl_ReadMotionStatus_srv>("NMotionCtrl/ReadMotionStatus");
        N_Robot::NMotionCtrl_ReadMotionStatus_srv srvReadMotionStatus;
        if(clientReadMotionStatus.call(srvReadMotionStatus)){
            ROS_INFO("Success to call service NMotionCtrl/ReadMotionStatus");
            if(srvReadMotionStatus.response.s32ErrCode){
                strErr=srvReadMotionStatus.response.strErrInfo;
                ROS_INFO("ReadMotionStatus error:ErrCode:%d;ErrInfo:",srvReadMotionStatus.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("MotionStatus=%x,SysErrStatus=%x,MotorErrStatus=%x,MotionBufCnt=%x,CrtMotionBufAddr=%x,CmdBufCnt=%x,CrtCmdBufAddr=%x",
                         srvReadMotionStatus.response.u8MotionStatus,srvReadMotionStatus.response.u8SysErrStatus,
                         srvReadMotionStatus.response.u8MotorErrStatus,srvReadMotionStatus.response.u8MotionBufCnt,
                         srvReadMotionStatus.response.u8CrtMotionBufAddr,srvReadMotionStatus.response.u8CmdBufCnt,
                         srvReadMotionStatus.response.u8CrtCmdBufAddr);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/ReadMotionStatus");
        }
    }else if(strPara1=="ResetAllMotorDriver"){
        ROS_INFO("calling service NMotionCtrl/ResetAllMotorDriver.");
        ros::ServiceClient clientResetAllMotorDriver=n.serviceClient<N_Robot::NMotionCtrl_ResetAllMotorDriver_srv>("NMotionCtrl/ResetAllMotorDriver");
        N_Robot::NMotionCtrl_ResetAllMotorDriver_srv srvResetAllMotorDriver;
        if(clientResetAllMotorDriver.call(srvResetAllMotorDriver)){
            ROS_INFO("Success to call service NMotionCtrl/ResetAllMotorDriver");
            if(srvResetAllMotorDriver.response.s32ErrCode){
                strErr=srvResetAllMotorDriver.response.strErrInfo;
                ROS_INFO("ResetAllMotorDriver error:ErrCode:%d;ErrInfo:",srvResetAllMotorDriver.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("Reset success.");
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/ResetAllMotorDriver");
        }
    }else if(strPara1=="ClearMotionBuff"){
        ROS_INFO("calling service NMotionCtrl/ClearMotionBuff.");
        ros::ServiceClient clientClearMotionBuff=n.serviceClient<N_Robot::CmdOnly_srv>("NMotionCtrl/ClearMotionBuff");
        N_Robot::CmdOnly_srv srvClearMotionBuff;
        if(clientClearMotionBuff.call(srvClearMotionBuff)){
            ROS_INFO("Success to call service NMotionCtrl/ClearMotionBuff");
            if(srvClearMotionBuff.response.s32ErrCode){
                strErr=srvClearMotionBuff.response.strErrInfo;
                ROS_INFO("ClearMotionBuff error:ErrCode:%d;ErrInfo:",srvClearMotionBuff.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.");
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/ClearMotionBuff");
        }
    }else if(strPara1=="ClearErrFlag"){
        ROS_INFO("calling service NMotionCtrl/ClearErrFlag.");
        ros::ServiceClient clientClearErrFlag=n.serviceClient<N_Robot::CmdOnly_srv>("NMotionCtrl/ClearErrFlag");
        N_Robot::CmdOnly_srv srvClearErrFlag;
        if(clientClearErrFlag.call(srvClearErrFlag)){
            ROS_INFO("Success to call service NMotionCtrl/ClearErrFlag");
            if(srvClearErrFlag.response.s32ErrCode){
                strErr=srvClearErrFlag.response.strErrInfo;
                ROS_INFO("ClearErrFlag error:ErrCode:%d;ErrInfo:",srvClearErrFlag.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.");
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/ClearErrFlag");
        }
    }else if(strPara1=="StartMotion"){
        ROS_INFO("calling service NMotionCtrl/StartMotion.");
        ros::ServiceClient clientStartMotion=n.serviceClient<N_Robot::NMotionCtrl_StartMotion_srv>("NMotionCtrl/StartMotion");
        N_Robot::NMotionCtrl_StartMotion_srv srvStartMotion;
        if(clientStartMotion.call(srvStartMotion)){
            ROS_INFO("Success to call service NMotionCtrl/StartMotion");
            if(srvStartMotion.response.s32ErrCode){
                strErr=srvStartMotion.response.strErrInfo;
                ROS_INFO("StartMotion error:ErrCode:%d;ErrInfo:",srvStartMotion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.The motion status code is %d.",srvStartMotion.response.u8MotionStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/StartMotion");
        }
    }else if(strPara1=="SuspendMotion"){
        ROS_INFO("calling service NMotionCtrl/SuspendMotion.");
        ros::ServiceClient clientSuspendMotion=n.serviceClient<N_Robot::NMotionCtrl_SuspendMotion_srv>("NMotionCtrl/SuspendMotion");
        N_Robot::NMotionCtrl_SuspendMotion_srv srvSuspendMotion;
        if(clientSuspendMotion.call(srvSuspendMotion)){
            ROS_INFO("Success to call service NMotionCtrl/SuspendMotion");
            if(srvSuspendMotion.response.s32ErrCode){
                strErr=srvSuspendMotion.response.strErrInfo;
                ROS_INFO("SuspendMotion error:ErrCode:%d;ErrInfo:",srvSuspendMotion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.The motion status code is %d.",srvSuspendMotion.response.u8MotionStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/SuspendMotion");
        }
    }else if(strPara1=="ContinueMotion"){
        ROS_INFO("calling service NMotionCtrl/ContinueMotion.");
        ros::ServiceClient clientContinueMotion=n.serviceClient<N_Robot::NMotionCtrl_ContinueMotion_srv>("NMotionCtrl/ContinueMotion");
        N_Robot::NMotionCtrl_ContinueMotion_srv srvContinueMotion;
        if(clientContinueMotion.call(srvContinueMotion)){
            ROS_INFO("Success to call service NMotionCtrl/ContinueMotion");
            if(srvContinueMotion.response.s32ErrCode){
                strErr=srvContinueMotion.response.strErrInfo;
                ROS_INFO("ContinueMotion error:ErrCode:%d;ErrInfo:",srvContinueMotion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.The motion status code is %d.",srvContinueMotion.response.u8MotionStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/ContinueMotion");
        }
    }else if(strPara1=="StopMotion"){
        ROS_INFO("calling service NMotionCtrl/StopMotion.");
        ros::ServiceClient clientStopMotion=n.serviceClient<N_Robot::NMotionCtrl_StopMotion_srv>("NMotionCtrl/StopMotion");
        N_Robot::NMotionCtrl_StopMotion_srv srvStopMotion;
        if(clientStopMotion.call(srvStopMotion)){
            ROS_INFO("Success to call service NMotionCtrl/StopMotion");
            if(srvStopMotion.response.s32ErrCode){
                strErr=srvStopMotion.response.strErrInfo;
                ROS_INFO("StopMotion error:ErrCode:%d;ErrInfo:",srvStopMotion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.The motion status code:%d,system error code:%d.",srvStopMotion.response.u8MotionStatus,
                         srvStopMotion.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/StopMotion");
        }
    }else if(strPara1=="JumpToNextCmd"){
        ROS_INFO("calling service NMotionCtrl/JumpToNextCmd.");
        ros::ServiceClient clientJumpToNextCmd=n.serviceClient<N_Robot::NMotionCtrl_JumpToNextCmd_srv>("NMotionCtrl/JumpToNextCmd");
        N_Robot::NMotionCtrl_JumpToNextCmd_srv srvJumpToNextCmd;
        if(clientJumpToNextCmd.call(srvJumpToNextCmd)){
            ROS_INFO("Success to call service NMotionCtrl/JumpToNextCmd");
            if(srvJumpToNextCmd.response.s32ErrCode){
                strErr=srvJumpToNextCmd.response.strErrInfo;
                ROS_INFO("JumpToNextCmd error:ErrCode:%d;ErrInfo:",srvJumpToNextCmd.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.The motion status code:%d,system error code:%d.",srvJumpToNextCmd.response.u8MotionStatus,
                         srvJumpToNextCmd.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/JumpToNextCmd");
        }
    }else if(strPara1=="StopMotionAndSetDir"){
        ROS_INFO("calling service NMotionCtrl/StopMotionAndSetDir.");
        ros::ServiceClient clientStopMotionAndSetDir=n.serviceClient<N_Robot::NMotionCtrl_SetDir_srv>("NMotionCtrl/StopMotionAndSetDir");
        N_Robot::NMotionCtrl_SetDir_srv srvStopMotionAndSetDir;
        //
        srvStopMotionAndSetDir.request.f32Direction=atof(argv[2]);
        //
        if(clientStopMotionAndSetDir.call(srvStopMotionAndSetDir)){
            ROS_INFO("Success to call service NMotionCtrl/StopMotionAndSetDir");
            if(srvStopMotionAndSetDir.response.s32ErrCode){
                strErr=srvStopMotionAndSetDir.response.strErrInfo;
                ROS_INFO("StopMotionAndSetDir error:ErrCode:%d;ErrInfo:",srvStopMotionAndSetDir.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvStopMotionAndSetDir.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/StopMotionAndSetDir");
        }
    }else if(strPara1=="SetDirAfterMotion"){
        ROS_INFO("calling service NMotionCtrl/SetDirAfterMotion.");
        ros::ServiceClient clientSetDirAfterMotion=n.serviceClient<N_Robot::NMotionCtrl_SetDir_srv>("NMotionCtrl/SetDirAfterMotion");
        N_Robot::NMotionCtrl_SetDir_srv srvSetDirAfterMotion;
        //
        srvSetDirAfterMotion.request.f32Direction=atof(argv[2]);
        //
        if(clientSetDirAfterMotion.call(srvSetDirAfterMotion)){
            ROS_INFO("Success to call service NMotionCtrl/SetDirAfterMotion");
            if(srvSetDirAfterMotion.response.s32ErrCode){
                strErr=srvSetDirAfterMotion.response.strErrInfo;
                ROS_INFO("SetDirAfterMotion error:ErrCode:%d;ErrInfo:",srvSetDirAfterMotion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvSetDirAfterMotion.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/SetDirAfterMotion");
        }
    }else if(strPara1=="WaitTime"){
        ROS_INFO("calling service NMotionCtrl/WaitTime.");
        ros::ServiceClient clientWaitTime=n.serviceClient<N_Robot::NMotionCtrl_WaitTime_srv>("NMotionCtrl/WaitTime");
        N_Robot::NMotionCtrl_WaitTime_srv srvWaitTime;
        //
        srvWaitTime.request.u16Time=atoll(argv[2]);//10ms/1
        //
        if(clientWaitTime.call(srvWaitTime)){
            ROS_INFO("Success to call service NMotionCtrl/WaitTime");
            if(srvWaitTime.response.s32ErrCode){
                strErr=srvWaitTime.response.strErrInfo;
                ROS_INFO("WaitTime error:ErrCode:%d;ErrInfo:",srvWaitTime.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvWaitTime.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/WaitTime");
        }
    }else if(strPara1=="SetInstantVelocity"){
        ROS_INFO("calling service NMotionCtrl/SetInstantVelocity.");
        ros::ServiceClient clientSetInstantVelocity=n.serviceClient<N_Robot::NMotionCtrl_SetInstantVelocity_srv>("NMotionCtrl/SetInstantVelocity");
        N_Robot::NMotionCtrl_SetInstantVelocity_srv srvSetInstantVelocity;
        //
        srvSetInstantVelocity.request.s16DirectionAngle=atoll(argv[2]);//=deg*100
        srvSetInstantVelocity.request.u16LinearVelocity=atoll(argv[3]);//=m/s*10000
        srvSetInstantVelocity.request.s16AngularVelocity=atoll(argv[4]);//=deg/s*100
        //
        if(clientSetInstantVelocity.call(srvSetInstantVelocity)){
            ROS_INFO("Success to call service NMotionCtrl/SetInstantVelocity");
            if(srvSetInstantVelocity.response.s32ErrCode){
                strErr=srvSetInstantVelocity.response.strErrInfo;
                ROS_INFO("SetInstantVelocity error:ErrCode:%d;ErrInfo:",srvSetInstantVelocity.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvSetInstantVelocity.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/SetInstantVelocity");
        }
    }else if(strPara1=="SMATSpeedMode"){
        ROS_INFO("calling service NMotionCtrl/SMATSpeedMode.");
        ros::ServiceClient clientSMATSpeedMode=n.serviceClient<N_Robot::NMotionCtrl_SMATSpeedMode_srv>("NMotionCtrl/SMATSpeedMode");
        N_Robot::NMotionCtrl_SMATSpeedMode_srv srvSMATSpeedMode;
        //
        srvSMATSpeedMode.request.s16DirectionAngle=atoll(argv[2]);//=deg*100
        srvSMATSpeedMode.request.u16LinearVelocity=atoll(argv[3]);//=m/s*10000
        srvSMATSpeedMode.request.s16AngularVelocity=atoll(argv[4]);//=deg/s*100
        //
        if(clientSMATSpeedMode.call(srvSMATSpeedMode)){
            ROS_INFO("Success to call service NMotionCtrl/SMATSpeedMode");
            if(srvSMATSpeedMode.response.s32ErrCode){
                strErr=srvSMATSpeedMode.response.strErrInfo;
                ROS_INFO("SMATSpeedMode error:ErrCode:%d;ErrInfo:",srvSMATSpeedMode.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvSMATSpeedMode.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/SMATSpeedMode");
        }
    }else if(strPara1=="CMATSpeedMode"){
        ROS_INFO("calling service NMotionCtrl/CMATSpeedMode.");
        ros::ServiceClient clientCMATSpeedMode=n.serviceClient<N_Robot::NMotionCtrl_CMATSpeedMode_srv>("NMotionCtrl/CMATSpeedMode");
        N_Robot::NMotionCtrl_CMATSpeedMode_srv srvCMATSpeedMode;
        //
        srvCMATSpeedMode.request.s16DirectionAngle=atoll(argv[2]);//=deg*100
        srvCMATSpeedMode.request.u16CycleR=atoll(argv[3]);
        srvCMATSpeedMode.request.u16LinearVelocity=atoll(argv[4]);//=m/s*10000
        srvCMATSpeedMode.request.s16AngularVelocity=atoll(argv[5]);//=deg/s*100
        //
        if(clientCMATSpeedMode.call(srvCMATSpeedMode)){
            ROS_INFO("Success to call service NMotionCtrl/CMATSpeedMode");
            if(srvCMATSpeedMode.response.s32ErrCode){
                strErr=srvCMATSpeedMode.response.strErrInfo;
                ROS_INFO("CMATSpeedMode error:ErrCode:%d;ErrInfo:",srvCMATSpeedMode.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvCMATSpeedMode.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/CMATSpeedMode");
        }
    }else if(strPara1=="CAATSpeedMode"){
        ROS_INFO("calling service NMotionCtrl/CAATSpeedMode.");
        ros::ServiceClient clientCAATSpeedMode=n.serviceClient<N_Robot::NMotionCtrl_CMATSpeedMode_srv>("NMotionCtrl/CAATSpeedMode");
        N_Robot::NMotionCtrl_CMATSpeedMode_srv srvCAATSpeedMode;
        //
        srvCAATSpeedMode.request.s16DirectionAngle=atoll(argv[2]);//=deg*100
        srvCAATSpeedMode.request.u16CycleR=atoll(argv[3]);
        srvCAATSpeedMode.request.u16LinearVelocity=atoll(argv[4]);//=m/s*10000
        srvCAATSpeedMode.request.s16AngularVelocity=atoll(argv[5]);//=deg/s*100
        //
        if(clientCAATSpeedMode.call(srvCAATSpeedMode)){
            ROS_INFO("Success to call service NMotionCtrl/CAATSpeedMode");
            if(srvCAATSpeedMode.response.s32ErrCode){
                strErr=srvCAATSpeedMode.response.strErrInfo;
                ROS_INFO("CAATSpeedMode error:ErrCode:%d;ErrInfo:",srvCAATSpeedMode.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvCAATSpeedMode.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/CAATSpeedMode");
        }
    }else if(strPara1=="DefineMotorSpeed"){
        ROS_INFO("calling service NMotionCtrl/DefineMotorSpeed.");
        ros::ServiceClient clientDefineMotorSpeed=n.serviceClient<N_Robot::NMotionCtrl_DefineMotorSpeed_srv>("NMotionCtrl/DefineMotorSpeed");
        N_Robot::NMotionCtrl_DefineMotorSpeed_srv srvDefineMotorSpeed;
        //
        srvDefineMotorSpeed.request.s16Wheel1=atoll(argv[2]);//=rpm*100
        srvDefineMotorSpeed.request.s16Wheel2=atoll(argv[3]);//=rpm*100
        srvDefineMotorSpeed.request.s16Wheel3=atoll(argv[4]);//=rpm*100
        srvDefineMotorSpeed.request.s16Wheel4=atoll(argv[5]);//=rpm*100
        //
        if(clientDefineMotorSpeed.call(srvDefineMotorSpeed)){
            ROS_INFO("Success to call service NMotionCtrl/DefineMotorSpeed");
            if(srvDefineMotorSpeed.response.s32ErrCode){
                strErr=srvDefineMotorSpeed.response.strErrInfo;
                ROS_INFO("DefineMotorSpeed error:ErrCode:%d;ErrInfo:",srvDefineMotorSpeed.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvDefineMotorSpeed.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/SetInstantVelocity");
        }
    }else if(strPara1=="SMATPositionMode"){
        ROS_INFO("calling service NMotionCtrl/SMATPositionMode.");
        ros::ServiceClient clientSMATPositionMode=n.serviceClient<N_Robot::NMotionCtrl_SMATPositionMode_srv>("NMotionCtrl/SMATPositionMode");
        N_Robot::NMotionCtrl_SMATPositionMode_srv srvSMATPositionMode;
        //
        srvSMATPositionMode.request.s16X=atoll(argv[2]);
        srvSMATPositionMode.request.s16Y=atoll(argv[3]);
        srvSMATPositionMode.request.u16LinearVelocity=atoll(argv[4]);
        srvSMATPositionMode.request.s16AngularVelocity=atoll(argv[5]);
        //
        if(clientSMATPositionMode.call(srvSMATPositionMode)){
            ROS_INFO("Success to call service NMotionCtrl/SMATPositionMode");
            if(srvSMATPositionMode.response.s32ErrCode){
                strErr=srvSMATPositionMode.response.strErrInfo;
                ROS_INFO("SMATPositionMode error:ErrCode:%d;ErrInfo:",srvSMATPositionMode.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvSMATPositionMode.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/SMATPositionMode");
        }
    }else if(strPara1=="STATPositionMode"){
        ROS_INFO("calling service NMotionCtrl/STATPositionMode.");
        ros::ServiceClient clientSTATPositionMode=n.serviceClient<N_Robot::NMotionCtrl_STATPositionMode_srv>("NMotionCtrl/STATPositionMode");
        N_Robot::NMotionCtrl_STATPositionMode_srv srvSTATPositionMode;
        //
        srvSTATPositionMode.request.s16DirectionAngle=atoll(argv[2]);
        srvSTATPositionMode.request.s16Distance=atoll(argv[3]);
        srvSTATPositionMode.request.u16LinearVelocity=atoll(argv[4]);
        srvSTATPositionMode.request.s16AngularVelocity=atoll(argv[5]);
        //
        if(clientSTATPositionMode.call(srvSTATPositionMode)){
            ROS_INFO("Success to call service NMotionCtrl/STATPositionMode");
            if(srvSTATPositionMode.response.s32ErrCode){
                strErr=srvSTATPositionMode.response.strErrInfo;
                ROS_INFO("STATPositionMode error:ErrCode:%d;ErrInfo:",srvSTATPositionMode.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvSTATPositionMode.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/STATPositionMode");
        }
    }else if(strPara1=="CMATPositionMode"){
        ROS_INFO("calling service NMotionCtrl/CMATPositionMode.");
        ros::ServiceClient clientCMATPositionMode=n.serviceClient<N_Robot::NMotionCtrl_CMATPositionMode_srv>("NMotionCtrl/CMATPositionMode");
        N_Robot::NMotionCtrl_CMATPositionMode_srv srvCMATPositionMode;
        //
        srvCMATPositionMode.request.s16X=atoll(argv[2]);
        srvCMATPositionMode.request.s16Y=atoll(argv[3]);
        srvCMATPositionMode.request.u16CycleR=atoll(argv[4]);
        srvCMATPositionMode.request.u16LinearVelocity=atoll(argv[5]);
        srvCMATPositionMode.request.s16AngularVelocity=atoll(argv[6]);
        //
        if(clientCMATPositionMode.call(srvCMATPositionMode)){
            ROS_INFO("Success to call service NMotionCtrl/CMATPositionMode");
            if(srvCMATPositionMode.response.s32ErrCode){
                strErr=srvCMATPositionMode.response.strErrInfo;
                ROS_INFO("CMATPositionMode error:ErrCode:%d;ErrInfo:",srvCMATPositionMode.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvCMATPositionMode.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/CMATPositionMode");
        }
    }else if(strPara1=="CAATPositionMode"){
        ROS_INFO("calling service NMotionCtrl/CAATPositionMode.");
        ros::ServiceClient clientCAATPositionMode=n.serviceClient<N_Robot::NMotionCtrl_CAATPositionMode_srv>("NMotionCtrl/CAATPositionMode");
        N_Robot::NMotionCtrl_CAATPositionMode_srv srvCAATPositionMode;
        //
        srvCAATPositionMode.request.s16X=atoll(argv[2]);
        srvCAATPositionMode.request.s16Y=atoll(argv[3]);
        srvCAATPositionMode.request.u16CycleR=atoll(argv[4]);
        srvCAATPositionMode.request.u16LinearVelocity=atoll(argv[5]);
        srvCAATPositionMode.request.s16AngularVelocity=atoll(argv[6]);
        //
        if(clientCAATPositionMode.call(srvCAATPositionMode)){
            ROS_INFO("Success to call service NMotionCtrl/CAATPositionMode");
            if(srvCAATPositionMode.response.s32ErrCode){
                strErr=srvCAATPositionMode.response.strErrInfo;
                ROS_INFO("CAATPositionMode error:ErrCode:%d;ErrInfo:",srvCAATPositionMode.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvCAATPositionMode.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/CAATPositionMode");
        }
    }else if(strPara1=="JoyCmdMotion"){
        ROS_INFO("calling service NMotionCtrl/JoyCmdMotion.");
        ros::ServiceClient clientJoyCmdMotion=n.serviceClient<N_Robot::NMotionCtrl_JoyCmdMotion_srv>("NMotionCtrl/JoyCmdMotion");
        N_Robot::NMotionCtrl_JoyCmdMotion_srv srvJoyCmdMotion;
        //
        srvJoyCmdMotion.request.s16JoyX=atoll(argv[2]);//-500~500
        srvJoyCmdMotion.request.s16JoyY=atoll(argv[3]);//-500~500
        srvJoyCmdMotion.request.s16JoyZ=atoll(argv[4]);//-500~500
        //
        if(clientJoyCmdMotion.call(srvJoyCmdMotion)){
            ROS_INFO("Success to call service NMotionCtrl/JoyCmdMotion");
            if(srvJoyCmdMotion.response.s32ErrCode){
                strErr=srvJoyCmdMotion.response.strErrInfo;
                ROS_INFO("JoyCmdMotion error:ErrCode:%d;ErrInfo:",srvJoyCmdMotion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvJoyCmdMotion.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/JoyCmdMotion");
        }
        //nSec is the walk time in seconds
        int nSec=2;
        ros::Rate loop_rate(2);
        for(int i=0;i<nSec*2-1;i++){
          loop_rate.sleep();
          if(clientJoyCmdMotion.call(srvJoyCmdMotion)){
              ROS_INFO("Success to call service NMotionCtrl/JoyCmdMotion");
              if(srvJoyCmdMotion.response.s32ErrCode){
                    strErr=srvJoyCmdMotion.response.strErrInfo;
                    ROS_INFO("JoyCmdMotion error:ErrCode:%d;ErrInfo:",srvJoyCmdMotion.response.s32ErrCode);
                    cout<<strErr<<"\n";
              }else{
                    ROS_INFO(" success.system error code:%d.",
                               srvJoyCmdMotion.response.u8SysErrStatus);
              }
          }else{
              ROS_INFO("Failed to call service NMotionCtrl/JoyCmdMotion");
          }
        }
        loop_rate.sleep();
        srvJoyCmdMotion.request.s16JoyX=0;//-500~500
        srvJoyCmdMotion.request.s16JoyY=0;//-500~500
        srvJoyCmdMotion.request.s16JoyZ=0;//-500~500
        if(clientJoyCmdMotion.call(srvJoyCmdMotion)){
            ROS_INFO("Success to call service NMotionCtrl/JoyCmdMotion");
            if(srvJoyCmdMotion.response.s32ErrCode){
                strErr=srvJoyCmdMotion.response.strErrInfo;
                ROS_INFO("JoyCmdMotion error:ErrCode:%d;ErrInfo:",srvJoyCmdMotion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO(" success.system error code:%d.",
                         srvJoyCmdMotion.response.u8SysErrStatus);
            }
        }else{
            ROS_INFO("Failed to call service NMotionCtrl/JoyCmdMotion");
        }
    }else if(strPara1=="pathfinder"){
        ros::Subscriber subPathfinder=n.subscribe("pathfinderRcvr/pathfinderRcvrData",1,msgcbPathfinder);
        ROS_INFO("Substribe pathfinderRcvr/pathfinderRcvrData.");
        while(ros::ok()){
            ros::spinOnce();
            sleep(0);
        }
        //ros::spin();
        ROS_INFO("The end of substribing pathfinderRcvr/pathfinderRcvrData.");
    }else if(strPara1=="CMD_VEL"){
        ros::Subscriber subCyberJoy=n.subscribe("CyberJoyMsg",1,msgcbTcpJoy);
        ROS_INFO("Substribe CyberJoyMsg.");
        ros::Subscriber subCmdVel=n.subscribe("cmd_vel",1,msgcbCmdVel);
        ROS_INFO("Substribe cmd_vel.");
        ros::spin();
        ROS_INFO("The end of cyber control.");
    }else{
        ROS_INFO("calling no service ,the service name should be input as a running parameter.");
    }
    //
    ROS_INFO("The end of TestNMotion.");
    return 0;
}

