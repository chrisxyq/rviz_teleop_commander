// Generated by gencpp from file N_Robot/PS_ReadTransData_srv.msg
// DO NOT EDIT!


#ifndef N_ROBOT_MESSAGE_PS_READTRANSDATA_SRV_H
#define N_ROBOT_MESSAGE_PS_READTRANSDATA_SRV_H

#include <ros/service_traits.h>


#include <N_Robot/PS_ReadTransData_srvRequest.h>
#include <N_Robot/PS_ReadTransData_srvResponse.h>


namespace N_Robot
{

struct PS_ReadTransData_srv
{

typedef PS_ReadTransData_srvRequest Request;
typedef PS_ReadTransData_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct PS_ReadTransData_srv
} // namespace N_Robot


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::N_Robot::PS_ReadTransData_srv > {
  static const char* value()
  {
    return "abaef58b7907806e78b13d105be847a3";
  }

  static const char* value(const ::N_Robot::PS_ReadTransData_srv&) { return value(); }
};

template<>
struct DataType< ::N_Robot::PS_ReadTransData_srv > {
  static const char* value()
  {
    return "N_Robot/PS_ReadTransData_srv";
  }

  static const char* value(const ::N_Robot::PS_ReadTransData_srv&) { return value(); }
};


// service_traits::MD5Sum< ::N_Robot::PS_ReadTransData_srvRequest> should match 
// service_traits::MD5Sum< ::N_Robot::PS_ReadTransData_srv > 
template<>
struct MD5Sum< ::N_Robot::PS_ReadTransData_srvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::N_Robot::PS_ReadTransData_srv >::value();
  }
  static const char* value(const ::N_Robot::PS_ReadTransData_srvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::N_Robot::PS_ReadTransData_srvRequest> should match 
// service_traits::DataType< ::N_Robot::PS_ReadTransData_srv > 
template<>
struct DataType< ::N_Robot::PS_ReadTransData_srvRequest>
{
  static const char* value()
  {
    return DataType< ::N_Robot::PS_ReadTransData_srv >::value();
  }
  static const char* value(const ::N_Robot::PS_ReadTransData_srvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::N_Robot::PS_ReadTransData_srvResponse> should match 
// service_traits::MD5Sum< ::N_Robot::PS_ReadTransData_srv > 
template<>
struct MD5Sum< ::N_Robot::PS_ReadTransData_srvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::N_Robot::PS_ReadTransData_srv >::value();
  }
  static const char* value(const ::N_Robot::PS_ReadTransData_srvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::N_Robot::PS_ReadTransData_srvResponse> should match 
// service_traits::DataType< ::N_Robot::PS_ReadTransData_srv > 
template<>
struct DataType< ::N_Robot::PS_ReadTransData_srvResponse>
{
  static const char* value()
  {
    return DataType< ::N_Robot::PS_ReadTransData_srv >::value();
  }
  static const char* value(const ::N_Robot::PS_ReadTransData_srvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // N_ROBOT_MESSAGE_PS_READTRANSDATA_SRV_H