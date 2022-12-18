#ifndef GNSS_UTM_H_
#define GNSS_UTM_H_


#define	GET_BIT(x, bit)	((x & (1 << bit)) >> bit)

#include "ros/ros.h"
#include "nmea_msgs/Sentence.h"  
#include "geometry_msgs/Vector3Stamped.h"
#include "geometry_msgs/QuaternionStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/transform_broadcaster.h"
#include "tf/LinearMath/Quaternion.h"
#include "sensor_msgs/Imu.h"



#include <iostream>
#include <vector>
#include <iterator>	
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cctype>
#include <ctime>
#include <cmath>

namespace GNSS{
    
const double PI = 3.14159265359;

// WGS84 Parameters
const double WGS84_A = 6378137.0;		// major axis
const double WGS84_B = 6356752.31424518;	// minor axis
const double WGS84_F = 0.0033528107;		// ellipsoid flattening
const double WGS84_E = 0.0818191908;		// first eccentricity
const double WGS84_EP = 0.0820944379;		// second eccentricity

// UTM Parameters
const double UTM_K0 = 0.9996;			// scale factor
const double UTM_FE = 500000.0;		// false easting
const double UTM_FN_N = 0.0;			// false northing on north hemisphere
const double UTM_FN_S = 10000000.0;		// false northing on south hemisphere
const double UTM_E2 = (WGS84_E * WGS84_E);	// e^2
const double UTM_E4 = (UTM_E2 * UTM_E2);		// e^4
const double UTM_E6 = (UTM_E4 * UTM_E2);		// e^6
const double UTM_EP2 = (UTM_E2 / (1 - UTM_E2));	// e'^2

class gnss_utm{

public:

    gnss_utm(ros::NodeHandle &nh);
    
    void register_sub(); 
    void register_pub(); 
    void callback_sentence(const nmea_msgs::Sentence::ConstPtr &pmsg); 
    void data_parse();
    void publish_pose();
    void publish_tf();
    void publish_imu();


    bool data_check(std::string s);

    void lla2utm(const double &lat,const double &lon,double &easting,double &northing);
    char latitude_letter(const double &lat);
    int longitude_letter(const double &lat,const double &lon);



    int safe_int(const std::string& s);
    double safe_double(const std::string& s);
    double deg2rad (double degrees);

private:
    ros::NodeHandle n;
    nmea_msgs::Sentence sentence_;
    int baud;
    std::string port;

    bool empty_sign_;
    bool wrong_sign_;


    double yaw_,pitch_,roll_,lat_,lon_,alt_;

    double x_,y_,z_;

    int warning_;

    double gyro_x_,gyro_y_,gyro_z_;

    double acc_x_,acc_y_,acc_z_;


    ros::Publisher pub_pose;       
    ros::Publisher pub_imu;                                     
    ros::Subscriber sub_sentence;

    tf::TransformBroadcaster br_;




};



}  // namespace GNSS



#endif