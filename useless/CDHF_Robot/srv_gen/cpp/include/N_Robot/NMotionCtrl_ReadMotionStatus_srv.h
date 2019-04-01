/* Auto-generated by genmsg_cpp for file /home/ubuntu/dev/ros/N_Robot/srv/NMotionCtrl_ReadMotionStatus_srv.srv */
#ifndef N_ROBOT_SERVICE_NMOTIONCTRL_READMOTIONSTATUS_SRV_H
#define N_ROBOT_SERVICE_NMOTIONCTRL_READMOTIONSTATUS_SRV_H
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
struct NMotionCtrl_ReadMotionStatus_srvRequest_ {
  typedef NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> Type;

  NMotionCtrl_ReadMotionStatus_srvRequest_()
  {
  }

  NMotionCtrl_ReadMotionStatus_srvRequest_(const ContainerAllocator& _alloc)
  {
  }


  typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator>  const> ConstPtr;
}; // struct NMotionCtrl_ReadMotionStatus_srvRequest
typedef  ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<std::allocator<void> > NMotionCtrl_ReadMotionStatus_srvRequest;

typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest> NMotionCtrl_ReadMotionStatus_srvRequestPtr;
typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest const> NMotionCtrl_ReadMotionStatus_srvRequestConstPtr;



template <class ContainerAllocator>
struct NMotionCtrl_ReadMotionStatus_srvResponse_ {
  typedef NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> Type;

  NMotionCtrl_ReadMotionStatus_srvResponse_()
  : s32ErrCode(0)
  , strErrInfo()
  , u8MotionStatus(0)
  , u8SysErrStatus(0)
  , u8MotorErrStatus(0)
  , u8MotionBufCnt(0)
  , u8CrtMotionBufAddr(0)
  , u8CmdBufCnt(0)
  , u8CrtCmdBufAddr(0)
  {
  }

  NMotionCtrl_ReadMotionStatus_srvResponse_(const ContainerAllocator& _alloc)
  : s32ErrCode(0)
  , strErrInfo(_alloc)
  , u8MotionStatus(0)
  , u8SysErrStatus(0)
  , u8MotorErrStatus(0)
  , u8MotionBufCnt(0)
  , u8CrtMotionBufAddr(0)
  , u8CmdBufCnt(0)
  , u8CrtCmdBufAddr(0)
  {
  }

  typedef int32_t _s32ErrCode_type;
  int32_t s32ErrCode;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _strErrInfo_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  strErrInfo;

  typedef uint8_t _u8MotionStatus_type;
  uint8_t u8MotionStatus;

  typedef uint8_t _u8SysErrStatus_type;
  uint8_t u8SysErrStatus;

  typedef uint8_t _u8MotorErrStatus_type;
  uint8_t u8MotorErrStatus;

  typedef uint8_t _u8MotionBufCnt_type;
  uint8_t u8MotionBufCnt;

  typedef uint8_t _u8CrtMotionBufAddr_type;
  uint8_t u8CrtMotionBufAddr;

  typedef uint8_t _u8CmdBufCnt_type;
  uint8_t u8CmdBufCnt;

  typedef uint8_t _u8CrtCmdBufAddr_type;
  uint8_t u8CrtCmdBufAddr;


  typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator>  const> ConstPtr;
}; // struct NMotionCtrl_ReadMotionStatus_srvResponse
typedef  ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<std::allocator<void> > NMotionCtrl_ReadMotionStatus_srvResponse;

typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse> NMotionCtrl_ReadMotionStatus_srvResponsePtr;
typedef boost::shared_ptr< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse const> NMotionCtrl_ReadMotionStatus_srvResponseConstPtr;


struct NMotionCtrl_ReadMotionStatus_srv
{

typedef NMotionCtrl_ReadMotionStatus_srvRequest Request;
typedef NMotionCtrl_ReadMotionStatus_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct NMotionCtrl_ReadMotionStatus_srv
} // namespace N_Robot

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_ReadMotionStatus_srvRequest";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "\n\
";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cab3d3372c649fc51ca4cd10570bd6c5";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xcab3d3372c649fc5ULL;
  static const uint64_t static_value2 = 0x1ca4cd10570bd6c5ULL;
};

template<class ContainerAllocator>
struct DataType< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_ReadMotionStatus_srvResponse";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32  s32ErrCode\n\
string strErrInfo\n\
uint8  u8MotionStatus\n\
uint8  u8SysErrStatus\n\
uint8  u8MotorErrStatus\n\
uint8  u8MotionBufCnt\n\
uint8  u8CrtMotionBufAddr\n\
uint8  u8CmdBufCnt\n\
uint8  u8CrtCmdBufAddr\n\
\n\
\n\
";
  }

  static const char* value(const  ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct NMotionCtrl_ReadMotionStatus_srvRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.s32ErrCode);
    stream.next(m.strErrInfo);
    stream.next(m.u8MotionStatus);
    stream.next(m.u8SysErrStatus);
    stream.next(m.u8MotorErrStatus);
    stream.next(m.u8MotionBufCnt);
    stream.next(m.u8CrtMotionBufAddr);
    stream.next(m.u8CmdBufCnt);
    stream.next(m.u8CrtCmdBufAddr);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct NMotionCtrl_ReadMotionStatus_srvResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<N_Robot::NMotionCtrl_ReadMotionStatus_srv> {
  static const char* value() 
  {
    return "cab3d3372c649fc51ca4cd10570bd6c5";
  }

  static const char* value(const N_Robot::NMotionCtrl_ReadMotionStatus_srv&) { return value(); } 
};

template<>
struct DataType<N_Robot::NMotionCtrl_ReadMotionStatus_srv> {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_ReadMotionStatus_srv";
  }

  static const char* value(const N_Robot::NMotionCtrl_ReadMotionStatus_srv&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cab3d3372c649fc51ca4cd10570bd6c5";
  }

  static const char* value(const N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_ReadMotionStatus_srv";
  }

  static const char* value(const N_Robot::NMotionCtrl_ReadMotionStatus_srvRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cab3d3372c649fc51ca4cd10570bd6c5";
  }

  static const char* value(const N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "N_Robot/NMotionCtrl_ReadMotionStatus_srv";
  }

  static const char* value(const N_Robot::NMotionCtrl_ReadMotionStatus_srvResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // N_ROBOT_SERVICE_NMOTIONCTRL_READMOTIONSTATUS_SRV_H
