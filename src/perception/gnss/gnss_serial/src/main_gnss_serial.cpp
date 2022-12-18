

#include "node_gnss_serial.h"



int main(int argc, char **argv)
{
    ros::init(argc, argv,"gnss_serial"); // node

    ros::NodeHandle private_nh("~"); // node handler
    
    GNSS::node_gnss_serial serial(private_nh);  

    serial.load_param();

    serial.register_pub();
        
    try{
        serial.sp.open();
    }
    catch(...){
        ROS_WARN_STREAM("fail to open serial");
        return -1;
    }

    if(serial.sp.isOpen()){
        ROS_INFO("serial initialized");
    }
    else{
        ROS_WARN_STREAM("serial initialize fail, not open");
        return -1;           
    }

    try{

        while (serial.sp.isOpen()){

            serial.sentence.sentence = serial.sp.readline();
            serial.sentence.header.frame_id="/nmea_sentence";
            serial.sentence.header.stamp=ros::Time::now();
        
            serial.publish_sentence();

            // DEBUG
            double time_debug= ros::Time::now().toSec();
            std::cout<<std::fixed<<time_debug<<" "<<serial.sp.readline()<<std::endl;
            // DEBUG

        }
    }
    catch(...){                 
        ROS_WARN_STREAM("serial out");
        serial.sp.close();
        ROS_WARN_STREAM("serial is closed");
        return -1;
    }
        
    serial.sp.close();
    ROS_WARN_STREAM("serial is closed");
    

    return 0;
}












