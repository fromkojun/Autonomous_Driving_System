#ifndef GNSS_SERIAL_H_
#define GNSS_SERIAL_H_



#include "ros/ros.h"
#include "nmea_msgs/Sentence.h" 
#include "serial/serial.h"

#include <iostream>
#include <string>


namespace GNSS{


class node_gnss_serial{

public:

    node_gnss_serial(ros::NodeHandle &nh);

    serial::Serial sp;
    
    nmea_msgs::Sentence sentence;

    void load_param();
    
    void register_pub(); 
    
    void publish_sentence(); 



private:
    ros::NodeHandle n;
    

    int baud;
    
    std::string port;

    ros::Publisher pub_sentence;

    

};




} // namespace GNSS




#endif