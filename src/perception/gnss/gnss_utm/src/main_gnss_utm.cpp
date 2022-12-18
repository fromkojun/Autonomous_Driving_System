
#include "gnss_utm.h"







int main(int argc, char **argv) {

    ros::init(argc, argv,"gnss_utm"); // node

    ros::NodeHandle private_nh("~"); // node handler

    GNSS::gnss_utm gps(private_nh);

	gps.register_sub();
	gps.register_pub();

	// main do in callback function in class node_gps
	ros::spin();



}

