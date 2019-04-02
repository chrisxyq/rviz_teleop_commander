// Generated by gencpp from file navigator_q2/PBUTTING_ReadStatus_srvResponse.msg
// DO NOT EDIT!


#ifndef NAVIGATOR_Q2_MESSAGE_PBUTTING_READSTATUS_SRVRESPONSE_H
#define NAVIGATOR_Q2_MESSAGE_PBUTTING_READSTATUS_SRVRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace navigator_q2
{
template <class ContainerAllocator>
struct PBUTTING_ReadStatus_srvResponse_
{
  typedef PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> Type;

  PBUTTING_ReadStatus_srvResponse_()
    : s32ErrCode(0)
    , strErrInfo()
    , u8Switch(0)
    , f32Position(0.0)  {
    }
  PBUTTING_ReadStatus_srvResponse_(const ContainerAllocator& _alloc)
    : s32ErrCode(0)
    , strErrInfo(_alloc)
    , u8Switch(0)
    , f32Position(0.0)  {
  (void)_alloc;
    }



   typedef int32_t _s32ErrCode_type;
  _s32ErrCode_type s32ErrCode;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _strErrInfo_type;
  _strErrInfo_type strErrInfo;

   typedef uint8_t _u8Switch_type;
  _u8Switch_type u8Switch;

   typedef float _f32Position_type;
  _f32Position_type f32Position;




  typedef boost::shared_ptr< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct PBUTTING_ReadStatus_srvResponse_

typedef ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<std::allocator<void> > PBUTTING_ReadStatus_srvResponse;

typedef boost::shared_ptr< ::navigator_q2::PBUTTING_ReadStatus_srvResponse > PBUTTING_ReadStatus_srvResponsePtr;
typedef boost::shared_ptr< ::navigator_q2::PBUTTING_ReadStatus_srvResponse const> PBUTTING_ReadStatus_srvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace navigator_q2

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'navigator_q2': ['/home/cp3/catkin_ws/src/navigator_q2/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3713bac249ff5edea25dc7f5bbaac80b";
  }

  static const char* value(const ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3713bac249ff5edeULL;
  static const uint64_t static_value2 = 0xa25dc7f5bbaac80bULL;
};

template<class ContainerAllocator>
struct DataType< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "navigator_q2/PBUTTING_ReadStatus_srvResponse";
  }

  static const char* value(const ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32  s32ErrCode\n\
string strErrInfo\n\
uint8  u8Switch\n\
float32 f32Position\n\
\n\
\n\
";
  }

  static const char* value(const ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.s32ErrCode);
      stream.next(m.strErrInfo);
      stream.next(m.u8Switch);
      stream.next(m.f32Position);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PBUTTING_ReadStatus_srvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::navigator_q2::PBUTTING_ReadStatus_srvResponse_<ContainerAllocator>& v)
  {
    s << indent << "s32ErrCode: ";
    Printer<int32_t>::stream(s, indent + "  ", v.s32ErrCode);
    s << indent << "strErrInfo: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.strErrInfo);
    s << indent << "u8Switch: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.u8Switch);
    s << indent << "f32Position: ";
    Printer<float>::stream(s, indent + "  ", v.f32Position);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NAVIGATOR_Q2_MESSAGE_PBUTTING_READSTATUS_SRVRESPONSE_H