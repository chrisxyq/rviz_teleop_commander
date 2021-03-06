// Generated by gencpp from file N_Robot/PS_ReadStatus_srv.msg
// DO NOT EDIT!


#ifndef N_ROBOT_MESSAGE_PS_READSTATUS_SRV_H
#define N_ROBOT_MESSAGE_PS_READSTATUS_SRV_H

#include <ros/service_traits.h>


#include <N_Robot/PS_ReadStatus_srvRequest.h>
#include <N_Robot/PS_ReadStatus_srvResponse.h>


namespace N_Robot
{

struct PS_ReadStatus_srv
{

typedef PS_ReadStatus_srvRequest Request;
typedef PS_ReadStatus_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct PS_ReadStatus_srv
} // namespace N_Robot


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::N_Robot::PS_ReadStatus_srv > {
  static const char* value()
  {
    return "733c182a56016889a83d22c5e6a7517f";
  }

  static const char* value(const ::N_Robot::PS_ReadStatus_srv&) { return value(); }
};

template<>
struct DataType< ::N_Robot::PS_ReadStatus_srv > {
  static const char* value()
  {
    return "N_Robot/PS_ReadStatus_srv";
  }

  static const char* value(const ::N_Robot::PS_ReadStatus_srv&) { return value(); }
};


// service_traits::MD5Sum< ::N_Robot::PS_ReadStatus_srvRequest> should match 
// service_traits::MD5Sum< ::N_Robot::PS_ReadStatus_srv > 
template<>
struct MD5Sum< ::N_Robot::PS_ReadStatus_srvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::N_Robot::PS_ReadStatus_srv >::value();
  }
  static const char* value(const ::N_Robot::PS_ReadStatus_srvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::N_Robot::PS_ReadStatus_srvRequest> should match 
// service_traits::DataType< ::N_Robot::PS_ReadStatus_srv > 
template<>
struct DataType< ::N_Robot::PS_ReadStatus_srvRequest>
{
  static const char* value()
  {
    return DataType< ::N_Robot::PS_ReadStatus_srv >::value();
  }
  static const char* value(const ::N_Robot::PS_ReadStatus_srvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::N_Robot::PS_ReadStatus_srvResponse> should match 
// service_traits::MD5Sum< ::N_Robot::PS_ReadStatus_srv > 
template<>
struct MD5Sum< ::N_Robot::PS_ReadStatus_srvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::N_Robot::PS_ReadStatus_srv >::value();
  }
  static const char* value(const ::N_Robot::PS_ReadStatus_srvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::N_Robot::PS_ReadStatus_srvResponse> should match 
// service_traits::DataType< ::N_Robot::PS_ReadStatus_srv > 
template<>
struct DataType< ::N_Robot::PS_ReadStatus_srvResponse>
{
  static const char* value()
  {
    return DataType< ::N_Robot::PS_ReadStatus_srv >::value();
  }
  static const char* value(const ::N_Robot::PS_ReadStatus_srvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // N_ROBOT_MESSAGE_PS_READSTATUS_SRV_H
