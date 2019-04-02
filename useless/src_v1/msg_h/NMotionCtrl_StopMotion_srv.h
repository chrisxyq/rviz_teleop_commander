// Generated by gencpp from file navigator_q2/NMotionCtrl_StopMotion_srv.msg
// DO NOT EDIT!


#ifndef NAVIGATOR_Q2_MESSAGE_NMOTIONCTRL_STOPMOTION_SRV_H
#define NAVIGATOR_Q2_MESSAGE_NMOTIONCTRL_STOPMOTION_SRV_H

#include <ros/service_traits.h>


#include <navigator_q2/NMotionCtrl_StopMotion_srvRequest.h>
#include <navigator_q2/NMotionCtrl_StopMotion_srvResponse.h>


namespace navigator_q2
{

struct NMotionCtrl_StopMotion_srv
{

typedef NMotionCtrl_StopMotion_srvRequest Request;
typedef NMotionCtrl_StopMotion_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct NMotionCtrl_StopMotion_srv
} // namespace navigator_q2


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srv > {
  static const char* value()
  {
    return "91b32a73c3781768b7ade6d95aeb80ea";
  }

  static const char* value(const ::navigator_q2::NMotionCtrl_StopMotion_srv&) { return value(); }
};

template<>
struct DataType< ::navigator_q2::NMotionCtrl_StopMotion_srv > {
  static const char* value()
  {
    return "navigator_q2/NMotionCtrl_StopMotion_srv";
  }

  static const char* value(const ::navigator_q2::NMotionCtrl_StopMotion_srv&) { return value(); }
};


// service_traits::MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srvRequest> should match 
// service_traits::MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srv > 
template<>
struct MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srv >::value();
  }
  static const char* value(const ::navigator_q2::NMotionCtrl_StopMotion_srvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::navigator_q2::NMotionCtrl_StopMotion_srvRequest> should match 
// service_traits::DataType< ::navigator_q2::NMotionCtrl_StopMotion_srv > 
template<>
struct DataType< ::navigator_q2::NMotionCtrl_StopMotion_srvRequest>
{
  static const char* value()
  {
    return DataType< ::navigator_q2::NMotionCtrl_StopMotion_srv >::value();
  }
  static const char* value(const ::navigator_q2::NMotionCtrl_StopMotion_srvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srvResponse> should match 
// service_traits::MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srv > 
template<>
struct MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::navigator_q2::NMotionCtrl_StopMotion_srv >::value();
  }
  static const char* value(const ::navigator_q2::NMotionCtrl_StopMotion_srvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::navigator_q2::NMotionCtrl_StopMotion_srvResponse> should match 
// service_traits::DataType< ::navigator_q2::NMotionCtrl_StopMotion_srv > 
template<>
struct DataType< ::navigator_q2::NMotionCtrl_StopMotion_srvResponse>
{
  static const char* value()
  {
    return DataType< ::navigator_q2::NMotionCtrl_StopMotion_srv >::value();
  }
  static const char* value(const ::navigator_q2::NMotionCtrl_StopMotion_srvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // NAVIGATOR_Q2_MESSAGE_NMOTIONCTRL_STOPMOTION_SRV_H