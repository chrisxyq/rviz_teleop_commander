/* Auto-generated by genmsg_cpp for file /home/ubuntu/dev/ros/N_Robot/srv/OFPS1_ReadPosition_srv.srv */
#ifndef N_ROBOT_SERVICE_OFPS1_READPOSITION_SRV_H
#define N_ROBOT_SERVICE_OFPS1_READPOSITION_SRV_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace N_Robot
{
template <class ContainerAllocator>
struct OFPS1_ReadPosition_srvRequest_ {
  typedef OFPS1_ReadPosition_srvRequest_<ContainerAllocator> Type;

  OFPS1_ReadPosition_srvRequest_()
  {
  }

  OFPS1_ReadPosition_srvRequest_(const ContainerAllocator& _alloc)
  {
  }


  typedef boost::shared_ptr< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator>  const> ConstPtr;
}; // struct OFPS1_ReadPosition_srvRequest
typedef  ::N_Robot::OFPS1_ReadPosition_srvRequest_<std::allocator<void> > OFPS1_ReadPosition_srvRequest;

typedef boost::shared_ptr< ::N_Robot::OFPS1_ReadPosition_srvRequest> OFPS1_ReadPosition_srvRequestPtr;
typedef boost::shared_ptr< ::N_Robot::OFPS1_ReadPosition_srvRequest const> OFPS1_ReadPosition_srvRequestConstPtr;



template <class ContainerAllocator>
struct OFPS1_ReadPosition_srvResponse_ {
  typedef OFPS1_ReadPosition_srvResponse_<ContainerAllocator> Type;

  OFPS1_ReadPosition_srvResponse_()
  : s32ErrCode(0)
  , strErrInfo()
  , f32PositionX(0.0)
  , f32PositionY(0.0)
  , f32PositionTh(0.0)
  {
  }

  OFPS1_ReadPosition_srvResponse_(const ContainerAllocator& _alloc)
  : s32ErrCode(0)
  , strErrInfo(_alloc)
  , f32PositionX(0.0)
  , f32PositionY(0.0)
  , f32PositionTh(0.0)
  {
  }

  typedef int32_t _s32ErrCode_type;
  int32_t s32ErrCode;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _strErrInfo_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  strErrInfo;

  typedef float _f32PositionX_type;
  float f32PositionX;

  typedef float _f32PositionY_type;
  float f32PositionY;

  typedef float _f32PositionTh_type;
  float f32PositionTh;


  typedef boost::shared_ptr< ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator>  const> ConstPtr;
}; // struct OFPS1_ReadPosition_srvResponse
typedef  ::N_Robot::OFPS1_ReadPosition_srvResponse_<std::allocator<void> > OFPS1_ReadPosition_srvResponse;

typedef boost::shared_ptr< ::N_Robot::OFPS1_ReadPosition_srvResponse> OFPS1_ReadPosition_srvResponsePtr;
typedef boost::shared_ptr< ::N_Robot::OFPS1_ReadPosition_srvResponse const> OFPS1_ReadPosition_srvResponseConstPtr;


struct OFPS1_ReadPosition_srv
{

typedef OFPS1_ReadPosition_srvRequest Request;
typedef OFPS1_ReadPosition_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct OFPS1_ReadPosition_srv
} // namespace N_Robot

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const  ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/OFPS1_ReadPosition_srvRequest";
  }

  static const char* value(const  ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "\n\
";
  }

  static const char* value(const  ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "28746d7c2abbc6dbcdd104d5e6a7a891";
  }

  static const char* value(const  ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x28746d7c2abbc6dbULL;
  static const uint64_t static_value2 = 0xcdd104d5e6a7a891ULL;
};

template<class ContainerAllocator>
struct DataType< ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/OFPS1_ReadPosition_srvResponse";
  }

  static const char* value(const  ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32  s32ErrCode\n\
string strErrInfo\n\
float32  f32PositionX\n\
float32  f32PositionY\n\
float32  f32PositionTh\n\
\n\
\n\
";
  }

  static const char* value(const  ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct OFPS1_ReadPosition_srvRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.s32ErrCode);
    stream.next(m.strErrInfo);
    stream.next(m.f32PositionX);
    stream.next(m.f32PositionY);
    stream.next(m.f32PositionTh);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct OFPS1_ReadPosition_srvResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<N_Robot::OFPS1_ReadPosition_srv> {
  static const char* value() 
  {
    return "28746d7c2abbc6dbcdd104d5e6a7a891";
  }

  static const char* value(const N_Robot::OFPS1_ReadPosition_srv&) { return value(); } 
};

template<>
struct DataType<N_Robot::OFPS1_ReadPosition_srv> {
  static const char* value() 
  {
    return "N_Robot/OFPS1_ReadPosition_srv";
  }

  static const char* value(const N_Robot::OFPS1_ReadPosition_srv&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "28746d7c2abbc6dbcdd104d5e6a7a891";
  }

  static const char* value(const N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/OFPS1_ReadPosition_srv";
  }

  static const char* value(const N_Robot::OFPS1_ReadPosition_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "28746d7c2abbc6dbcdd104d5e6a7a891";
  }

  static const char* value(const N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/OFPS1_ReadPosition_srv";
  }

  static const char* value(const N_Robot::OFPS1_ReadPosition_srvResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // N_ROBOT_SERVICE_OFPS1_READPOSITION_SRV_H
