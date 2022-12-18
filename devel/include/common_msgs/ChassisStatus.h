// Generated by gencpp from file common_msgs/ChassisStatus.msg
// DO NOT EDIT!


#ifndef COMMON_MSGS_MESSAGE_CHASSISSTATUS_H
#define COMMON_MSGS_MESSAGE_CHASSISSTATUS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace common_msgs
{
template <class ContainerAllocator>
struct ChassisStatus_
{
  typedef ChassisStatus_<ContainerAllocator> Type;

  ChassisStatus_()
    : header()
    , real_throttle(0)
    , real_brake_pressure(0)
    , real_steer_angle(0.0)
    , vehicle_run_mode(0)  {
    }
  ChassisStatus_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , real_throttle(0)
    , real_brake_pressure(0)
    , real_steer_angle(0.0)
    , vehicle_run_mode(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _real_throttle_type;
  _real_throttle_type real_throttle;

   typedef uint8_t _real_brake_pressure_type;
  _real_brake_pressure_type real_brake_pressure;

   typedef double _real_steer_angle_type;
  _real_steer_angle_type real_steer_angle;

   typedef uint8_t _vehicle_run_mode_type;
  _vehicle_run_mode_type vehicle_run_mode;





  typedef boost::shared_ptr< ::common_msgs::ChassisStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::common_msgs::ChassisStatus_<ContainerAllocator> const> ConstPtr;

}; // struct ChassisStatus_

typedef ::common_msgs::ChassisStatus_<std::allocator<void> > ChassisStatus;

typedef boost::shared_ptr< ::common_msgs::ChassisStatus > ChassisStatusPtr;
typedef boost::shared_ptr< ::common_msgs::ChassisStatus const> ChassisStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::common_msgs::ChassisStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::common_msgs::ChassisStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::common_msgs::ChassisStatus_<ContainerAllocator1> & lhs, const ::common_msgs::ChassisStatus_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.real_throttle == rhs.real_throttle &&
    lhs.real_brake_pressure == rhs.real_brake_pressure &&
    lhs.real_steer_angle == rhs.real_steer_angle &&
    lhs.vehicle_run_mode == rhs.vehicle_run_mode;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::common_msgs::ChassisStatus_<ContainerAllocator1> & lhs, const ::common_msgs::ChassisStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace common_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::common_msgs::ChassisStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::common_msgs::ChassisStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common_msgs::ChassisStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common_msgs::ChassisStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common_msgs::ChassisStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common_msgs::ChassisStatus_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::common_msgs::ChassisStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3318ade59e28d0d24b09394333e12cbc";
  }

  static const char* value(const ::common_msgs::ChassisStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3318ade59e28d0d2ULL;
  static const uint64_t static_value2 = 0x4b09394333e12cbcULL;
};

template<class ContainerAllocator>
struct DataType< ::common_msgs::ChassisStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "common_msgs/ChassisStatus";
  }

  static const char* value(const ::common_msgs::ChassisStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::common_msgs::ChassisStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"\n"
"# real acc throttle value\n"
"uint8 real_throttle\n"
"\n"
"# real brake pressure\n"
"uint8 real_brake_pressure\n"
"\n"
"# real steer angle\n"
"float64 real_steer_angle\n"
"\n"
"# vehicle run mode\n"
"uint8 vehicle_run_mode\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::common_msgs::ChassisStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::common_msgs::ChassisStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.real_throttle);
      stream.next(m.real_brake_pressure);
      stream.next(m.real_steer_angle);
      stream.next(m.vehicle_run_mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ChassisStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::common_msgs::ChassisStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::common_msgs::ChassisStatus_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "real_throttle: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.real_throttle);
    s << indent << "real_brake_pressure: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.real_brake_pressure);
    s << indent << "real_steer_angle: ";
    Printer<double>::stream(s, indent + "  ", v.real_steer_angle);
    s << indent << "vehicle_run_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.vehicle_run_mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMON_MSGS_MESSAGE_CHASSISSTATUS_H
