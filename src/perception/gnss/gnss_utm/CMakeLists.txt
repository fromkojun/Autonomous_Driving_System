cmake_minimum_required(VERSION 3.0.2)
project(gnss_utm)
find_package(autoware_build_flags REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  nmea_msgs
  tf
)


catkin_package(

)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)



add_library(
  lib_gnss_utm
  include/gnss_utm.h
  src/gnss_utm.cpp
)

target_link_libraries(
  lib_gnss_utm
  ${catkin_LIBRARIES}
)




add_executable(gnss_utm src/main_gnss_utm.cpp)

target_link_libraries(
  gnss_utm
  lib_gnss_utm
  ${catkin_LIBRARIES}
)