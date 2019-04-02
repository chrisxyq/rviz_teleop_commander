#include "Project.h"
#include "Algorithm.h"
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <sys/time.h>
#include <string>
    using namespace std;
#include <unistd.h> //sleep()

#include "navigator_q2/OFPS1_ReadDevInfo_srv.h"
#include "navigator_q2/CmdOnly_srv.h"
#include "navigator_q2/OFPS1_ReadPosition_srv.h"

// #include "N_Robot/OFPS1_ReadDevInfo_srv.h"
// #include "N_Robot/CmdOnly_srv.h"
// #include "N_Robot/OFPS1_ReadPosition_srv.h"

#define STATIC_Z 0.171
//
int main(int argc,char ** argv){
    ros::init(argc,argv,"odometry_publisher");
    ros::NodeHandle n;
    int nErr=0;
    string strErr;
    ROS_INFO("Chengdu Hangfa OFPS1 odometry node.v1.507");
    //
    ros::Publisher pubOdom= n.advertise<nav_msgs::Odometry>("odom",50);
    tf::TransformBroadcaster odomBroadcaster;
    //init the odometry
    ros::ServiceClient clientReadDevInfo=n.serviceClient<N_Robot::OFPS1_ReadDevInfo_srv>("OFPS1/ReadDevInfo");
    N_Robot::OFPS1_ReadDevInfo_srv srvReadDevInfo;
    for(int i=0;i<40;i++){
        if(clientReadDevInfo.call(srvReadDevInfo)){
           if(srvReadDevInfo.response.s32ErrCode){
                strErr=srvReadDevInfo.response.strErrInfo;
                ROS_INFO("ReadDevInfo error:ErrCode:%d;ErrInfo:",srvReadDevInfo.response.s32ErrCode);
                cout<<strErr<<"\n";
           }else{
              ROS_INFO("Device Type=%x,Address=%x,SN=%d ",srvReadDevInfo.response.u8DevType,srvReadDevInfo.response.u8DevAddr,srvReadDevInfo.response.u32DevSN);
              break;
           }
        }else{
            ROS_INFO("Failed to call service OFPS1/ReadDevInfo");
        }
        sleep(0.01);
    }
    //
    //sleep(0.2);
    //
    ros::ServiceClient clientZeroOdometry=n.serviceClient<N_Robot::CmdOnly_srv>("OFPS1/ZeroOdometry");
    N_Robot::CmdOnly_srv srvZeroOdometry;
    for(int i=0;i<40;i++){
        if(clientZeroOdometry.call(srvZeroOdometry)){
           if(srvZeroOdometry.response.s32ErrCode){
                strErr=srvZeroOdometry.response.strErrInfo;
                ROS_INFO("ZeroOdometry error:ErrCode:%d;ErrInfo:",srvZeroOdometry.response.s32ErrCode);
                cout<<strErr<<"\n";
           }else{
              ROS_INFO("ZeroOdometry OK");
              break;
           }
        }else{
            ROS_INFO("Failed to call service OFPS1/ZeroOdometry");
        }
        sleep(0.01);
    }
    //
    ros::ServiceClient clientReadPosition=n.serviceClient<N_Robot::OFPS1_ReadPosition_srv>("OFPS1/ReadPosition");
    N_Robot::OFPS1_ReadPosition_srv srvReadPosition;

    double dLstX=0,dLstY=0,dLstTh=0;
    double dCrtX=0,dCrtY=0,dCrtTh=0;
    double dVX=0,dVY=0,dVTh=0;
    double dDeltaTime=0.1;
    double dDeltaX=0,dDeltaY=0,dDeltaTh=0,dAverageTh=0;

    ros::Time tCrt,tLst;
    tCrt=ros::Time::now();
    tLst=ros::Time::now();
    ros::Rate r(10);
    while(n.ok()){
        //
        for(int i=0;i<4;i++){
            if(clientReadPosition.call(srvReadPosition)){
               if(srvReadPosition.response.s32ErrCode){
                   strErr=srvReadPosition.response.strErrInfo;
                   ROS_INFO("ReadPosition error:ErrCode:%d;ErrInfo:",srvReadPosition.response.s32ErrCode);
                   cout<<strErr<<"\n";
                   nErr=1;
               }else{
                   nErr=0;
#ifdef PROJ_DEBUG
                   ROS_INFO("X=%f,Y=%f,Th=%f ",srvReadPosition.response.f32PositionX,srvReadPosition.response.f32PositionY,srvReadPosition.response.f32PositionTh);
#endif
                   dCrtX=srvReadPosition.response.f32PositionY/1000*-1;//srvReadPosition.response.f32PositionX/1000*-1;
                   dCrtY=srvReadPosition.response.f32PositionX/1000;//srvReadPosition.response.f32PositionY/1000*-1;
                   dCrtTh=srvReadPosition.response.f32PositionTh/360*(2*PI);
#ifdef PROJ_DEBUG
                   ROS_INFO("CrtPosition:X=%f,Y=%f,Th=%f ",dCrtX,dCrtY,dCrtTh);
#endif
                   break;
               }
            }else{
                ROS_INFO("Failed to call service OFPS1/ReadPosition");
                nErr=1;
            }
            sleep(0.01);
        }
        if(nErr==0){
            tCrt=ros::Time::now();
            dDeltaTime=(tCrt-tLst).toSec();
            dDeltaX=dCrtX-dLstX;
            dDeltaY=dCrtY-dLstY;
            dDeltaTh=dCrtTh-dLstTh;
            dAverageTh=(dCrtTh+dLstTh)/2;
            //
            dVX=(dDeltaX*cos(dAverageTh)+dDeltaY*sin(dAverageTh))/dDeltaTime;
            dVY=(dDeltaY*cos(dAverageTh)-dDeltaX*sin(dAverageTh))/dDeltaTime;
            dVTh=dDeltaTh/dDeltaTime;
#ifdef PROJ_DEBUG
            ROS_INFO("Time:%f,Vel:X=%f,Y=%f,Th=%f ",tCrt.toSec(),dVX,dVY,dVTh);
#endif
            //
            geometry_msgs::Quaternion odom_quat=tf::createQuaternionMsgFromYaw(dCrtTh);
            geometry_msgs::TransformStamped odom_trans;

            odom_trans.header.stamp=tCrt;
            odom_trans.header.frame_id = "odom";
            odom_trans.child_frame_id ="gyro";

            odom_trans.transform.translation.x=dCrtX;
            odom_trans.transform.translation.y=dCrtY;
            odom_trans.transform.translation.z=STATIC_Z;
            odom_trans.transform.rotation=odom_quat;
#ifdef PROJ_DEBUG
            ROS_INFO("tranform:X=%f,Y=%f,Z=%f ",odom_trans.transform.translation.x,odom_trans.transform.translation.y,odom_trans.transform.translation.z);
#endif
            odomBroadcaster.sendTransform(odom_trans);
            //
            nav_msgs::Odometry odom;
            odom.header.stamp=tCrt;
            odom.header.frame_id = "odom";

            odom.pose.pose.position.x=dCrtX;
            odom.pose.pose.position.y=dCrtY;
            odom.pose.pose.position.z=STATIC_Z;
            odom.pose.pose.orientation = odom_quat;

            odom.child_frame_id ="gyro";
            odom.twist.twist.linear.x=dVX;
            odom.twist.twist.linear.y=dVY;
            odom.twist.twist.angular.z=dVTh;

            pubOdom.publish(odom);
            //
            dLstX=dCrtX;
            dLstY=dCrtY;
            dLstTh=dCrtTh;
            tLst=tCrt;
        }
        r.sleep();
    }
    //
    return 0;
}

