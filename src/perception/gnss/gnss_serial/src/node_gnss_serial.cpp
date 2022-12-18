


#include "node_gnss_serial.h"


namespace GNSS{


node_gnss_serial::node_gnss_serial(ros::NodeHandle &nh){
    n = nh;
}

void node_gnss_serial::load_param(){

    if(!n.param<std::string>("port",port,"/dev/ttyUSB0")){
        ROS_WARN_STREAM("load param error , default value is "<<"/dev/ttyUSB0");
    }
    
    if(!n.param<int>("baud",baud,115200)){
        ROS_WARN_STREAM("load param error , default value is "<<115200);
    }
    serial::Timeout to = serial::Timeout::simpleTimeout(1000); // 0.1s
    sp.setPort(port);
    sp.setBaudrate(baud);
    sp.setTimeout(to); // 0.1s

}

void node_gnss_serial::register_pub(){
    pub_sentence = n.advertise<nmea_msgs::Sentence>("/nmea_sentence", 1);
}

void node_gnss_serial::publish_sentence(){
    pub_sentence.publish(sentence);
}





} // namespace GNSS
