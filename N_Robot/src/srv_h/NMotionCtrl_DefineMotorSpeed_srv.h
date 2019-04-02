// Generated by gencpp from file N_Robot/NMotionCtrl_DefineMotorSpeed_srv.msg
// DO NOT EDIT!


#ifndef N_ROBOT_MESSAGE_NMOTIONCTRL_DEFINEMOTORSPEED_SRV_H
#define N_ROBOT_MESSAGE_NMOTIONCTRL_DEFINEMOTORSPEED_SRV_H

#include <ros/service_traits.h>


#include <N_Robot/NMotionCtrl_DefineMotorSpeed_srvRequest.h>
#include <N_Robot/NMotionCtrl_DefineMotorSpeed_srvResponse.h>


namespace N_Robot
{

struct NMotionCtrl_DefineMotorSpeed_srv
{

typedef NMotionCtrl_DefineMotorSpeed_srvRequest Request;
typedef NMotionCtrl_DefineMotorSpeed_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct NMotionCtrl_DefineMotorSpeed_srv
} // namespace N_Robot


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv > {
  static const char* value()
  {
    return "fec7131151353ec6f11a663d8091d4a1";
  }

  static const char* value(const ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv&) { return value(); }
};

template<>
struct DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv > {
  static const char* value()
  {
    return "N_Robot/NMotionCtrl_DefineMotorSpeed_srv";
  }

  static const char* value(const ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv&) { return value(); }
};


// service_traits::MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvRequest> should match 
// service_traits::MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv > 
template<>
struct MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv >::value();
  }
  static const char* value(const ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvRequest> should match 
// service_traits::DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv > 
template<>
struct DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvRequest>
{
  static const char* value()
  {
    return DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv >::value();
  }
  static const char* value(const ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvResponse> should match 
// service_traits::MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv > 
template<>
struct MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv >::value();
  }
  static const char* value(const ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvResponse> should match 
// service_traits::DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv > 
template<>
struct DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvResponse>
{
  static const char* value()
  {
    return DataType< ::N_Robot::NMotionCtrl_DefineMotorSpeed_srv >::value();
  }
  static const char* value(const ::N_Robot::NMotionCtrl_DefineMotorSpeed_srvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // N_ROBOT_MESSAGE_NMOTIONCTRL_DEFINEMOTORSPEED_SRV_H