// Generated by gencpp from file N_Robot/NMotionCtrl_CAATPositionMode_srv.msg
// DO NOT EDIT!


#ifndef N_ROBOT_MESSAGE_NMOTIONCTRL_CAATPOSITIONMODE_SRV_H
#define N_ROBOT_MESSAGE_NMOTIONCTRL_CAATPOSITIONMODE_SRV_H

#include <ros/service_traits.h>


#include <N_Robot/NMotionCtrl_CAATPositionMode_srvRequest.h>
#include <N_Robot/NMotionCtrl_CAATPositionMode_srvResponse.h>


namespace N_Robot
{

struct NMotionCtrl_CAATPositionMode_srv
{

typedef NMotionCtrl_CAATPositionMode_srvRequest Request;
typedef NMotionCtrl_CAATPositionMode_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct NMotionCtrl_CAATPositionMode_srv
} // namespace N_Robot


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srv > {
  static const char* value()
  {
    return "2e100e4b205106a41054daa1ff7e3342";
  }

  static const char* value(const ::N_Robot::NMotionCtrl_CAATPositionMode_srv&) { return value(); }
};

template<>
struct DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srv > {
  static const char* value()
  {
    return "N_Robot/NMotionCtrl_CAATPositionMode_srv";
  }

  static const char* value(const ::N_Robot::NMotionCtrl_CAATPositionMode_srv&) { return value(); }
};


// service_traits::MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srvRequest> should match 
// service_traits::MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srv > 
template<>
struct MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srv >::value();
  }
  static const char* value(const ::N_Robot::NMotionCtrl_CAATPositionMode_srvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srvRequest> should match 
// service_traits::DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srv > 
template<>
struct DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srvRequest>
{
  static const char* value()
  {
    return DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srv >::value();
  }
  static const char* value(const ::N_Robot::NMotionCtrl_CAATPositionMode_srvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srvResponse> should match 
// service_traits::MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srv > 
template<>
struct MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::N_Robot::NMotionCtrl_CAATPositionMode_srv >::value();
  }
  static const char* value(const ::N_Robot::NMotionCtrl_CAATPositionMode_srvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srvResponse> should match 
// service_traits::DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srv > 
template<>
struct DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srvResponse>
{
  static const char* value()
  {
    return DataType< ::N_Robot::NMotionCtrl_CAATPositionMode_srv >::value();
  }
  static const char* value(const ::N_Robot::NMotionCtrl_CAATPositionMode_srvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // N_ROBOT_MESSAGE_NMOTIONCTRL_CAATPOSITIONMODE_SRV_H