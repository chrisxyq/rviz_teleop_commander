#include "Project.h"
#include "Algorithm.h"
#include <ros/ros.h>
#include <sys/time.h>
#include <string>
    using namespace std;
#include <unistd.h> //sleep()


#include "navigator_q2/PBUTTING_ReadDevInfo_srv.h"
#include "navigator_q2/CmdOnly_srv.h"
#include "navigator_q2/NMotionCtrl_ReadVersion_srv.h"
#include "navigator_q2/PBUTTING_ReadStatus_srv.h"

// #include "N_Robot/PBUTTING_ReadDevInfo_srv.h"
// #include "N_Robot/CmdOnly_srv.h"
// #include "N_Robot/NMotionCtrl_ReadVersion_srv.h"
// #include "N_Robot/PBUTTING_ReadStatus_srv.h"
//
int main(int argc,char ** argv){
    string strPara1;
    ros::init(argc,argv,"TestPowerSource");
    ros::NodeHandle n;
    int nErr=0;
    string strErr;
    ROS_INFO("Chengdu Hangfa PBUTTING test node.v1.607");
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
        ROS_INFO("calling service PBUTTING/ReadDevInfo.");
        ros::ServiceClient clientReadDevInfo=n.serviceClient<N_Robot::PBUTTING_ReadDevInfo_srv>("PBUTTING/ReadDevInfo");
        N_Robot::PBUTTING_ReadDevInfo_srv srvReadDevInfo;
        if(clientReadDevInfo.call(srvReadDevInfo)){
            ROS_INFO("Success to call service PBUTTING/ReadDevInfo");
            if(srvReadDevInfo.response.s32ErrCode){
                strErr=srvReadDevInfo.response.strErrInfo;
                ROS_INFO("ReadDevInfo error:ErrCode:%d;ErrInfo:",srvReadDevInfo.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("Type=%x,Address=%x,SN=%d ",srvReadDevInfo.response.u8DevType,srvReadDevInfo.response.u8DevAddr,srvReadDevInfo.response.u32DevSN);
            }
        }else{
            ROS_INFO("Failed to call service PBUTTING/ReadDevInfo");
        }
    }else if(strPara1=="ReadVersion"){
        ROS_INFO("calling service PBUTTING/ReadVersion.");
        ros::ServiceClient clientReadVersion=n.serviceClient<N_Robot::NMotionCtrl_ReadVersion_srv>("PBUTTING/ReadVersion");
        N_Robot::NMotionCtrl_ReadVersion_srv srvReadVersion;
        if(clientReadVersion.call(srvReadVersion)){
            ROS_INFO("Success to call service PBUTTING/ReadVersion");
            if(srvReadVersion.response.s32ErrCode){
                strErr=srvReadVersion.response.strErrInfo;
                ROS_INFO("ReadVersion error:ErrCode:%d;ErrInfo:",srvReadVersion.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("hardware version=%d,software version=%f",srvReadVersion.response.u16HrdVer,srvReadVersion.response.f32SwVer);
            }
        }else{
            ROS_INFO("Failed to call service PBUTTING/ReadVersion");
        }
    }else if(strPara1=="Reboot"){
        ROS_INFO("calling service PBUTTING/Reboot.");
        ros::ServiceClient clientReboot=n.serviceClient<N_Robot::CmdOnly_srv>("PBUTTING/Reboot");
        N_Robot::CmdOnly_srv srvReboot;
        if(clientReboot.call(srvReboot)){
            ROS_INFO("Success to call service PBUTTING/Reboot");
            if(srvReboot.response.s32ErrCode){
                strErr=srvReboot.response.strErrInfo;
                ROS_INFO("Reboot error:ErrCode:%d;ErrInfo:",srvReboot.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("reboot ok");
            }
        }else{
            ROS_INFO("Failed to call service PBUTTING/Reboot");
        }
    }else if(strPara1=="ReadStatus"){
        ROS_INFO("calling service PBUTTING/ReadStatus.");
        ros::ServiceClient clientReadStatus=n.serviceClient<N_Robot::PBUTTING_ReadStatus_srv>("PBUTTING/ReadStatus");
        N_Robot::PBUTTING_ReadStatus_srv srvReadStatus;
        if(clientReadStatus.call(srvReadStatus)){
            ROS_INFO("Success to call service PBUTTING/ReadStatus");
            if(srvReadStatus.response.s32ErrCode){
                strErr=srvReadStatus.response.strErrInfo;
                ROS_INFO("ReadStatus error:ErrCode:%d;ErrInfo:",srvReadStatus.response.s32ErrCode);
                cout<<strErr<<"\n";
            }else{
                ROS_INFO("switch=%d,light position=%f ",srvReadStatus.response.u8Switch,srvReadStatus.response.f32Position);
            }
        }else{
            ROS_INFO("Failed to call service PBUTTING/ReadStatus");
        }
    }

    //
    return 0;
}

