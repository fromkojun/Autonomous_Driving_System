cmake_minimum_required(VERSION 3.0.2)
project(gnss_serial)
find_package(autoware_build_flags REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  roscpp  
  nmea_msgs
  serial
)



# must open it => catkin_package()

catkin_package(


)




include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)






add_library(
  lib_gnss_serial
  include/node_gnss_serial.h
  src/node_gnss_serial.cpp
)

target_link_libraries(
  lib_gnss_serial
  ${catkin_LIBRARIES}
)




add_executable(gnss_serial src/main_gnss_serial.cpp)

target_link_libraries(
  gnss_serial
  lib_gnss_serial
  ${catkin_LIBRARIES}
)
