#include "Project.h"
#include "Algorithm.h"
#include <ros/ros.h>
#include <sys/time.h>
#include <string>
    using namespace std;
#include <unistd.h> //sleep()


#include "navigator_q2/PS_ReadDevInfo_srv.h"
#include "navigator_q2/CmdOnly_srv.h"
#include "navigator_q2/NMotionCtrl_ReadVersion_srv.h"
#include "navigator_q2/PS_ReadRawData_srv.h"
#include "navigator_q2/PS_ReadTransData_srv.h"
#include "navigator_q2/PS_ReadStatus_srv.h"

// #include "N_Robot/PS_ReadDevInfo_srv.h"
// #include "N_Robot/CmdOnly_srv.h"
// #include "N_Robot/NMotionCtrl_ReadVersion_srv.h"
// #include "N_Robot/PS_ReadRawData_srv.h"
// #include "N_Robot/PS_ReadTransData_srv.h"
// #include "N_Robot/PS_ReadStatus_srv.h"
//
int main(int argc,char ** argv){
    string strPara1;
    ros::init(argc,argv,"TestPowerSource");
    ros::NodeHandle n;
    int nErr=0;
    string strErr;
    ROS_INFO("Chengdu Hangfa PS test node.v1.607");
    //
    printf("argument count:%d,running para:\n",argc);
    for(int i=0;i<argc;i++){
        printf("%s\n",argv[i]);
    }
    if(argc>1){
        strPara1=argv[1];
    }else{
        strPara1="";
    }

    if(strPara1=="ReadDevInfo"){
        ROS_INFO("calling service PS/ReadDevInfo.");
        ros::ServiceClient clientReadDevInfo=n.serviceClient<N_Robot::PS_ReadDevInfo_srv>("PS/ReadDevInfo");
        N_Robot::PS_ReadDevInfo_srv srvReadDevInfo;
        if(clientReadDevInfo.call(srvReadDevInfo)){
            ROS_INFO("Success to call service PS/ReadDevInfo");
            if(srvReadDevInfo.response.s32ErrCode){
                strErr=srvReadDevInfo.response.strErrInfo;
                ROS_INFO("ReadDevInfo error:ErrCode:%d;ErrInfo:",srvReadDevInfo.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("Type=%x,Address=%x,SN=%d ",srvReadDevInfo.response.u8DevType,srvReadDevInfo.response.u8DevAddr,srvReadDevInfo.response.u32DevSN);
            }
        }else{
            ROS_INFO("Failed to call service PS/ReadDevInfo");
        }
    }else if(strPara1=="ReadVersion"){
        ROS_INFO("calling service PS/ReadVersion.");
        ros::ServiceClient clientReadVersion=n.serviceClient<N_Robot::NMotionCtrl_ReadVersion_srv>("PS/ReadVersion");
        N_Robot::NMotionCtrl_ReadVersion_srv srvReadVersion;
        if(clientReadVersion.call(srvReadVersion)){
            ROS_INFO("Success to call service PS/ReadVersion");
            if(srvReadVersion.response.s32ErrCode){
                strErr=srvReadVersion.response.strErrInfo;
                ROS_INFO("ReadVersion error:ErrCode:%d;ErrInfo:",srvReadVersion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("hardware version=%d,software version=%f",srvReadVersion.response.u16HrdVer,srvReadVersion.response.f32SwVer);
            }
        }else{
            ROS_INFO("Failed to call service PS/ReadVersion");
        }
    }else if(strPara1=="Reboot"){
        ROS_INFO("calling service PS/Reboot.");
        ros::ServiceClient clientReboot=n.serviceClient<N_Robot::CmdOnly_srv>("PS/Reboot");
        N_Robot::CmdOnly_srv srvReboot;
        if(clientReboot.call(srvReboot)){
            ROS_INFO("Success to call service PS/Reboot");
            if(srvReboot.response.s32ErrCode){
                strErr=srvReboot.response.strErrInfo;
                ROS_INFO("Reboot error:ErrCode:%d;ErrInfo:",srvReboot.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("reboot ok");
            }
        }else{
            ROS_INFO("Failed to call service PS/Reboot");
        }
    }else if(strPara1=="StartTrans"){
        ROS_INFO("calling service PS/StartTrans.");
        ros::ServiceClient clientStartTrans=n.serviceClient<N_Robot::CmdOnly_srv>("PS/StartTrans");
        N_Robot::CmdOnly_srv srvStartTrans;
        if(clientStartTrans.call(srvStartTrans)){
            ROS_INFO("Success to call service PS/StartTrans");
            if(srvStartTrans.response.s32ErrCode){
                strErr=srvStartTrans.response.strErrInfo;
                ROS_INFO("StartTrans error:ErrCode:%d;ErrInfo:",srvStartTrans.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("StartTrans ok");
            }
        }else{
            ROS_INFO("Failed to call service PS/StartTrans");
        }
    }else if(strPara1=="ReadStatus"){
        ROS_INFO("calling service PS/ReadStatus.");
        ros::ServiceClient clientReadStatus=n.serviceClient<N_Robot::PS_ReadStatus_srv>("PS/ReadStatus");
        N_Robot::PS_ReadStatus_srv srvReadStatus;
        if(clientReadStatus.call(srvReadStatus)){
            ROS_INFO("Success to call service PS/ReadStatus");
            if(srvReadStatus.response.s32ErrCode){
                strErr=srvReadStatus.response.strErrInfo;
                ROS_INFO("ReadStatus error:ErrCode:%d;ErrInfo:",srvReadStatus.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("BattOpen=%d,SwitchDown=%d,ChargerIn=%d,ChargeComp=%d,ChargeOverFlow=%d,ChargerOverVolt=%d,ChargerVoltLow=%d,ChargerOverFlow=%d ",srvReadStatus.response.u8BattOpen,srvReadStatus.response.u8SwitchDown,srvReadStatus.response.u8ChargerIn,srvReadStatus.response.u8ChargeComp,srvReadStatus.response.u8ChargeOverFlow,srvReadStatus.response.u8ChargerOverVolt,srvReadStatus.response.u8ChargerVoltLow,srvReadStatus.response.u8ChargerOverFlow);
            }
        }else{
            ROS_INFO("Failed to call service PS/ReadStatus");
        }
    }else if(strPara1=="OpenUp"){
        ROS_INFO("calling service PS/OpenUp.");
        ros::ServiceClient clientOpenUp=n.serviceClient<N_Robot::CmdOnly_srv>("PS/OpenUp");
        N_Robot::CmdOnly_srv srvOpenUp;
        if(clientOpenUp.call(srvOpenUp)){
            ROS_INFO("Success to call service PS/OpenUp");
            if(srvOpenUp.response.s32ErrCode){
                strErr=srvOpenUp.response.strErrInfo;
                ROS_INFO("OpenUp error:ErrCode:%d;ErrInfo:",srvOpenUp.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("OpenUp ok");
            }
        }else{
            ROS_INFO("Failed to call service PS/OpenUp");
        }
    }else if(strPara1=="CloseDown"){
        ROS_INFO("calling service PS/CloseDown.");
        ros::ServiceClient clientCloseDown=n.serviceClient<N_Robot::CmdOnly_srv>("PS/CloseDown");
        N_Robot::CmdOnly_srv srvCloseDown;
        if(clientCloseDown.call(srvCloseDown)){
            ROS_INFO("Success to call service PS/CloseDown");
            if(srvCloseDown.response.s32ErrCode){
                strErr=srvCloseDown.response.strErrInfo;
                ROS_INFO("CloseDown error:ErrCode:%d;ErrInfo:",srvCloseDown.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("CloseDown ok");
            }
        }else{
            ROS_INFO("Failed to call service PS/CloseDown");
        }
    }else if(strPara1=="ReadRawData"){
        ROS_INFO("calling service PS/ReadRawData.");
        ros::ServiceClient clientReadRawData=n.serviceClient<N_Robot::PS_ReadRawData_srv>("PS/ReadRawData");
        N_Robot::PS_ReadRawData_srv srvReadRawData;
        if(clientReadRawData.call(srvReadRawData)){
            ROS_INFO("Success to call service PS/ReadRawData");
            if(srvReadRawData.response.s32ErrCode){
                strErr=srvReadRawData.response.strErrInfo;
                ROS_INFO("ReadRawData error:ErrCode:%d;ErrInfo:",srvReadRawData.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("volt=%d,batt curr=%d,batt charge curr=%d,Temp=%d ",srvReadRawData.response.u16BattVolt,srvReadRawData.response.u16BattCurr,srvReadRawData.response.u16BattChargeCurr,srvReadRawData.response.u16Temperture);
            }
        }else{
            ROS_INFO("Failed to call service PS/ReadRawData");
        }
    }else if(strPara1=="ReadTransData"){
        ROS_INFO("calling service PS/ReadTransData.");
        ros::ServiceClient clientReadTransData=n.serviceClient<N_Robot::PS_ReadTransData_srv>("PS/ReadTransData");
        N_Robot::PS_ReadTransData_srv srvReadTransData;
        if(clientReadTransData.call(srvReadTransData)){
            ROS_INFO("Success to call service PS/ReadTransData");
            if(srvReadTransData.response.s32ErrCode){
                strErr=srvReadTransData.response.strErrInfo;
                ROS_INFO("ReadTransData error:ErrCode:%d;ErrInfo:",srvReadTransData.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("volt=%d,batt curr=%d,batt charge curr=%d,Temp=%d ",srvReadTransData.response.u16BattVolt,srvReadTransData.response.s16BattCurr,srvReadTransData.response.s16BattChargeCurr,srvReadTransData.response.u8Temperture);
            }
        }else{
            ROS_INFO("Failed to call service PS/ReadTransData");
        }
    }else if(strPara1=="EnableUartData"){
        ROS_INFO("calling service PS/EnableUartData.");
        ros::ServiceClient clientEnableUartData=n.serviceClient<N_Robot::CmdOnly_srv>("PS/EnableUartData");
        N_Robot::CmdOnly_srv srvEnableUartData;
        if(clientEnableUartData.call(srvEnableUartData)){
            ROS_INFO("Success to call service PS/EnableUartData");
            if(srvEnableUartData.response.s32ErrCode){
                strErr=srvEnableUartData.response.strErrInfo;
                ROS_INFO("EnableUartData error:ErrCode:%d;ErrInfo:",srvEnableUartData.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("EnableUartData ok");
            }
        }else{
            ROS_INFO("Failed to call service PS/EnableUartData");
        }
    }else if(strPara1=="DisableUartData"){
        ROS_INFO("calling service PS/DisableUartData.");
        ros::ServiceClient clientDisableUartData=n.serviceClient<N_Robot::CmdOnly_srv>("PS/DisableUartData");
        N_Robot::CmdOnly_srv srvDisableUartData;
        if(clientDisableUartData.call(srvDisableUartData)){
            ROS_INFO("Success to call service PS/DisableUartData");
            if(srvDisableUartData.response.s32ErrCode){
                strErr=srvDisableUartData.response.strErrInfo;
                ROS_INFO("DisableUartData error:ErrCode:%d;ErrInfo:",srvDisableUartData.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("DisableUartData ok");
            }
        }else{
            ROS_INFO("Failed to call service PS/DisableUartData");
        }
    }

    //
    return 0;
}

