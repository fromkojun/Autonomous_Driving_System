// Generated by gencpp from file autoware_msgs/ImageLaneObjects.msg
// DO NOT EDIT!


#ifndef AUTOWARE_MSGS_MESSAGE_IMAGELANEOBJECTS_H
#define AUTOWARE_MSGS_MESSAGE_IMAGELANEOBJECTS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace autoware_msgs
{
template <class ContainerAllocator>
struct ImageLaneObjects_
{
  typedef ImageLaneObjects_<ContainerAllocator> Type;

  ImageLaneObjects_()
    : header()
    , lane_l_x1(0)
    , lane_l_y1(0)
    , lane_l_x2(0)
    , lane_l_y2(0)
    , lane_r_x1(0)
    , lane_r_y1(0)
    , lane_r_x2(0)
    , lane_r_y2(0)  {
    }
  ImageLaneObjects_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , lane_l_x1(0)
    , lane_l_y1(0)
    , lane_l_x2(0)
    , lane_l_y2(0)
    , lane_r_x1(0)
    , lane_r_y1(0)
    , lane_r_x2(0)
    , lane_r_y2(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _lane_l_x1_type;
  _lane_l_x1_type lane_l_x1;

   typedef int32_t _lane_l_y1_type;
  _lane_l_y1_type lane_l_y1;

   typedef int32_t _lane_l_x2_type;
  _lane_l_x2_type lane_l_x2;

   typedef int32_t _lane_l_y2_type;
  _lane_l_y2_type lane_l_y2;

   typedef int32_t _lane_r_x1_type;
  _lane_r_x1_type lane_r_x1;

   typedef int32_t _lane_r_y1_type;
  _lane_r_y1_type lane_r_y1;

   typedef int32_t _lane_r_x2_type;
  _lane_r_x2_type lane_r_x2;

   typedef int32_t _lane_r_y2_type;
  _lane_r_y2_type lane_r_y2;





  typedef boost::shared_ptr< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> const> ConstPtr;

}; // struct ImageLaneObjects_

typedef ::autoware_msgs::ImageLaneObjects_<std::allocator<void> > ImageLaneObjects;

typedef boost::shared_ptr< ::autoware_msgs::ImageLaneObjects > ImageLaneObjectsPtr;
typedef boost::shared_ptr< ::autoware_msgs::ImageLaneObjects const> ImageLaneObjectsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator1> & lhs, const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.lane_l_x1 == rhs.lane_l_x1 &&
    lhs.lane_l_y1 == rhs.lane_l_y1 &&
    lhs.lane_l_x2 == rhs.lane_l_x2 &&
    lhs.lane_l_y2 == rhs.lane_l_y2 &&
    lhs.lane_r_x1 == rhs.lane_r_x1 &&
    lhs.lane_r_y1 == rhs.lane_r_y1 &&
    lhs.lane_r_x2 == rhs.lane_r_x2 &&
    lhs.lane_r_y2 == rhs.lane_r_y2;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator1> & lhs, const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace autoware_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >
{
  static const char* value()
  {
    return "851175a106269dc1f4c64f0c36bafb05";
  }

  static const char* value(const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x851175a106269dc1ULL;
  static const uint64_t static_value2 = 0xf4c64f0c36bafb05ULL;
};

template<class ContainerAllocator>
struct DataType< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >
{
  static const char* value()
  {
    return "autoware_msgs/ImageLaneObjects";
  }

  static const char* value(const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"int32 lane_l_x1 # Left Lane\n"
"int32 lane_l_y1\n"
"int32 lane_l_x2\n"
"int32 lane_l_y2\n"
"int32 lane_r_x1 # Right Lane\n"
"int32 lane_r_y1\n"
"int32 lane_r_x2\n"
"int32 lane_r_y2\n"
"\n"
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

  static const char* value(const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.lane_l_x1);
      stream.next(m.lane_l_y1);
      stream.next(m.lane_l_x2);
      stream.next(m.lane_l_y2);
      stream.next(m.lane_r_x1);
      stream.next(m.lane_r_y1);
      stream.next(m.lane_r_x2);
      stream.next(m.lane_r_y2);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ImageLaneObjects_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::autoware_msgs::ImageLaneObjects_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::autoware_msgs::ImageLaneObjects_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "lane_l_x1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lane_l_x1);
    s << indent << "lane_l_y1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lane_l_y1);
    s << indent << "lane_l_x2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lane_l_x2);
    s << indent << "lane_l_y2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lane_l_y2);
    s << indent << "lane_r_x1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lane_r_x1);
    s << indent << "lane_r_y1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lane_r_y1);
    s << indent << "lane_r_x2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lane_r_x2);
    s << indent << "lane_r_y2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lane_r_y2);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOWARE_MSGS_MESSAGE_IMAGELANEOBJECTS_H
