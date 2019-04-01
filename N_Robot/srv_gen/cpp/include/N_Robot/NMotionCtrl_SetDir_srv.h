/* Auto-generated by genmsg_cpp for file /home/ubuntu/dev/ros/N_Robot/srv/NMotionCtrl_SetDir_srv.srv */
#ifndef N_ROBOT_SERVICE_NMOTIONCTRL_SETDIR_SRV_H
#define N_ROBOT_SERVICE_NMOTIONCTRL_SETDIR_SRV_H
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
struct NMotionCtrl_SetDir_srvRequest_ {
  typedef NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> Type;

  NMotionCtrl_SetDir_srvRequest_()
  : f32Direction(0.0)
  {
  }

  NMotionCtrl_SetDir_srvRequest_(const ContainerAllocator& _alloc)
  : f32Direction(0.0)
  {
  }

  typedef float _f32Direction_type;
  float f32Direction;


  typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator>  const> ConstPtr;
}; // struct NMotionCtrl_SetDir_srvRequest
typedef  ::N_Robot::NMotionCtrl_SetDir_srvRequest_<std::allocator<void> > NMotionCtrl_SetDir_srvRequest;

typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_SetDir_srvRequest> NMotionCtrl_SetDir_srvRequestPtr;
typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_SetDir_srvRequest const> NMotionCtrl_SetDir_srvRequestConstPtr;



template <class ContainerAllocator>
struct NMotionCtrl_SetDir_srvResponse_ {
  typedef NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> Type;

  NMotionCtrl_SetDir_srvResponse_()
  : s32ErrCode(0)
  , strErrInfo()
  , u8SysErrStatus(0)
  {
  }

  NMotionCtrl_SetDir_srvResponse_(const ContainerAllocator& _alloc)
  : s32ErrCode(0)
  , strErrInfo(_alloc)
  , u8SysErrStatus(0)
  {
  }

  typedef int32_t _s32ErrCode_type;
  int32_t s32ErrCode;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _strErrInfo_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  strErrInfo;

  typedef uint8_t _u8SysErrStatus_type;
  uint8_t u8SysErrStatus;


  typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator>  const> ConstPtr;
}; // struct NMotionCtrl_SetDir_srvResponse
typedef  ::N_Robot::NMotionCtrl_SetDir_srvResponse_<std::allocator<void> > NMotionCtrl_SetDir_srvResponse;

typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_SetDir_srvResponse> NMotionCtrl_SetDir_srvResponsePtr;
typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_SetDir_srvResponse const> NMotionCtrl_SetDir_srvResponseConstPtr;


struct NMotionCtrl_SetDir_srv
{

typedef NMotionCtrl_SetDir_srvRequest Request;
typedef NMotionCtrl_SetDir_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct NMotionCtrl_SetDir_srv
} // namespace N_Robot

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "b2588eb942817885065e2708697c90ab";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xb2588eb942817885ULL;
  static const uint64_t static_value2 = 0x065e2708697c90abULL;
};

template<class ContainerAllocator>
struct DataType< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_SetDir_srvRequest";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float32  f32Direction\n\
\n\
";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "aa73ec8fc53a03fe5edb2bc5267bea65";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xaa73ec8fc53a03feULL;
  static const uint64_t static_value2 = 0x5edb2bc5267bea65ULL;
};

template<class ContainerAllocator>
struct DataType< ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_SetDir_srvResponse";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32  s32ErrCode\n\
string strErrInfo\n\
uint8  u8SysErrStatus\n\
\n\
\n\
";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.f32Direction);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct NMotionCtrl_SetDir_srvRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.s32ErrCode);
    stream.next(m.strErrInfo);
    stream.next(m.u8SysErrStatus);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct NMotionCtrl_SetDir_srvResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<N_Robot::NMotionCtrl_SetDir_srv> {
  static const char* value() 
  {
    return "3c0466cf448f658bf8c511c00f4f5d44";
  }

  static const char* value(const N_Robot::NMotionCtrl_SetDir_srv&) { return value(); } 
};

template<>
struct DataType<N_Robot::NMotionCtrl_SetDir_srv> {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_SetDir_srv";
  }

  static const char* value(const N_Robot::NMotionCtrl_SetDir_srv&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "3c0466cf448f658bf8c511c00f4f5d44";
  }

  static const char* value(const N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_SetDir_srv";
  }

  static const char* value(const N_Robot::NMotionCtrl_SetDir_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "3c0466cf448f658bf8c511c00f4f5d44";
  }

  static const char* value(const N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_SetDir_srv";
  }

  static const char* value(const N_Robot::NMotionCtrl_SetDir_srvResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // N_ROBOT_SERVICE_NMOTIONCTRL_SETDIR_SRV_H
