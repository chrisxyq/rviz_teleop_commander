// Generated by gencpp from file navigator_q2/NMotionCtrl_DefineMotorSpeed_srvRequest.msg
// DO NOT EDIT!


#ifndef NAVIGATOR_Q2_MESSAGE_NMOTIONCTRL_DEFINEMOTORSPEED_SRVREQUEST_H
#define NAVIGATOR_Q2_MESSAGE_NMOTIONCTRL_DEFINEMOTORSPEED_SRVREQUEST_H


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
struct NMotionCtrl_DefineMotorSpeed_srvRequest_
{
  typedef NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> Type;

  NMotionCtrl_DefineMotorSpeed_srvRequest_()
    : s16Wheel1(0)
    , s16Wheel2(0)
    , s16Wheel3(0)
    , s16Wheel4(0)  {
    }
  NMotionCtrl_DefineMotorSpeed_srvRequest_(const ContainerAllocator& _alloc)
    : s16Wheel1(0)
    , s16Wheel2(0)
    , s16Wheel3(0)
    , s16Wheel4(0)  {
  (void)_alloc;
    }



   typedef int16_t _s16Wheel1_type;
  _s16Wheel1_type s16Wheel1;

   typedef int16_t _s16Wheel2_type;
  _s16Wheel2_type s16Wheel2;

   typedef int16_t _s16Wheel3_type;
  _s16Wheel3_type s16Wheel3;

   typedef int16_t _s16Wheel4_type;
  _s16Wheel4_type s16Wheel4;




  typedef boost::shared_ptr< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct NMotionCtrl_DefineMotorSpeed_srvRequest_

typedef ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<std::allocator<void> > NMotionCtrl_DefineMotorSpeed_srvRequest;

typedef boost::shared_ptr< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest > NMotionCtrl_DefineMotorSpeed_srvRequestPtr;
typedef boost::shared_ptr< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest const> NMotionCtrl_DefineMotorSpeed_srvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace navigator_q2

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'navigator_q2': ['/home/cp3/catkin_ws/src/navigator_q2/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "db24e612c07d8371da9190b0b5a79458";
  }

  static const char* value(const ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdb24e612c07d8371ULL;
  static const uint64_t static_value2 = 0xda9190b0b5a79458ULL;
};

template<class ContainerAllocator>
struct DataType< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "navigator_q2/NMotionCtrl_DefineMotorSpeed_srvRequest";
  }

  static const char* value(const ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16  s16Wheel1\n\
int16  s16Wheel2\n\
int16  s16Wheel3\n\
int16  s16Wheel4\n\
";
  }

  static const char* value(const ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.s16Wheel1);
      stream.next(m.s16Wheel2);
      stream.next(m.s16Wheel3);
      stream.next(m.s16Wheel4);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NMotionCtrl_DefineMotorSpeed_srvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::navigator_q2::NMotionCtrl_DefineMotorSpeed_srvRequest_<ContainerAllocator>& v)
  {
    s << indent << "s16Wheel1: ";
    Printer<int16_t>::stream(s, indent + "  ", v.s16Wheel1);
    s << indent << "s16Wheel2: ";
    Printer<int16_t>::stream(s, indent + "  ", v.s16Wheel2);
    s << indent << "s16Wheel3: ";
    Printer<int16_t>::stream(s, indent + "  ", v.s16Wheel3);
    s << indent << "s16Wheel4: ";
    Printer<int16_t>::stream(s, indent + "  ", v.s16Wheel4);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NAVIGATOR_Q2_MESSAGE_NMOTIONCTRL_DEFINEMOTORSPEED_SRVREQUEST_H