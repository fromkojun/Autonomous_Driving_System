#include "gnss_utm.h"

namespace GNSS{

gnss_utm::gnss_utm(ros::NodeHandle &nh){
    n = nh;
	roll_=0;
	pitch_=0;
	yaw_=0;
	lat_=0;
	lon_=0;
	alt_=0;
	x_=0;
	y_=0;
	z_=0;
	gyro_x_=0;
	gyro_y_=0;
	gyro_z_=0;
	acc_x_=0;
	acc_y_=0;
	acc_z_=0;

	warning_=0;
	empty_sign_=true;
	wrong_sign_=true;
}



void gnss_utm::register_sub(){
    ROS_INFO("register subscriber");
    sub_sentence = n.subscribe("/nmea_sentence", 1, &gnss_utm::callback_sentence, this);
}

void gnss_utm::register_pub(){
    ROS_INFO("register publisher");
	pub_pose = n.advertise<geometry_msgs::PoseStamped>("/gnss_pose",1);
	pub_imu = n.advertise<sensor_msgs::Imu>("/imu",1);
}

void gnss_utm::callback_sentence(const nmea_msgs::Sentence::ConstPtr &pmsg){
	sentence_ = (*pmsg);
	
	data_parse();

	if( (!empty_sign_) && (!wrong_sign_) ){

		if((GET_BIT(warning_,0))==1){
			ROS_WARN_STREAM("no GPS message");
		}
		else{
			publish_pose();
			publish_tf();
			publish_imu();
			std::cout<<latitude_letter(lat_)<<" "<<longitude_letter(lat_,lon_)<<std::endl;
		}
		
	}
	else{
		ROS_WARN_STREAM("jump this sentence");
	}
}

void gnss_utm::data_parse(){
	std::string s = sentence_.sentence;
	// DEBUG ############################### ignore it temporarily
	if(!data_check(s)){
		ROS_WARN_STREAM("gps data check_sum wrong !");
		wrong_sign_=true;
		return;
	}
	// DEBUG ########################################################

	
	try{

		// for sudden blank sentence
		if(s.empty()){
			empty_sign_=true;
			std::cout<<"catch an empty sentence"<<std::endl;
			return;
		}
		// data_parse
		std::vector<std::string> buffer_split;
		std::string sp_1 = "*";
		std::string sp_2 = "$";
		std::string sp_3 = ",";
		std::string::size_type pos = 0; 
		std::string::size_type pos_1 = s.find(sp_1);
		std::string::size_type pos_2 = s.find(sp_2);
		// modify sentence
		if (pos_1 != std::string::npos) {
			s = s.substr(pos_2 + 1, pos_1 - pos_2 - 1);
		}
		else
		{
			wrong_sign_=true;
			ROS_WARN_STREAM("no found * in sentence");
			return;
		}
		s = s + ",";
		// modify sentence finally add a comma
		// split sentence into a vector
		while (  (pos = s.find(',')) != std::string::npos ) 
		{
		buffer_split.push_back(s.substr(0, pos));
		s = s.substr(pos + 1);
		}
		// split sentence into a vector


		yaw_ = deg2rad(safe_double(buffer_split[3]));
		pitch_ = deg2rad(safe_double(buffer_split[4]));
		roll_ = deg2rad(safe_double(buffer_split[5]));
		lat_ = safe_double(buffer_split[12]);
		lon_ = safe_double(buffer_split[13]);
		alt_ = safe_double(buffer_split[14]);
		z_ = alt_;
		warning_ = safe_int(buffer_split[23]);

		// /utm /gnss_pose
		roll_= roll_;
		pitch_= -1 * pitch_;
		yaw_= -1 * yaw_ + 3.1415926/2 ;
		
		// lla 2 utm
		lla2utm(lat_,lon_,x_,y_);

		// imu  // imu origin coordinate in ENU turn it to FLU
		gyro_x_ = safe_double(buffer_split[7]);
		gyro_y_ = -1 * safe_double(buffer_split[6]);
		gyro_z_ = safe_double(buffer_split[8]);
		acc_x_ = safe_double(buffer_split[10]);
		acc_y_ = -1 * safe_double(buffer_split[9]);
		acc_z_ = safe_double(buffer_split[11]);

		//sign
		wrong_sign_=false;
		empty_sign_=false;
		return;

	}
	catch(...){
		ROS_WARN_STREAM("something wrong : invalid range ?");
		wrong_sign_=true;
		return;
	}
	

}


void gnss_utm::publish_pose(){

	geometry_msgs::PoseStamped pose;
	pose.header.frame_id="/world";
	pose.header.stamp = ros::Time::now();
	
	pose.pose.position.x=x_;
	pose.pose.position.y=y_;
	pose.pose.position.z=z_;
	
	pose.pose.orientation=tf::createQuaternionMsgFromRollPitchYaw(roll_,pitch_,yaw_);
	pub_pose.publish(pose);

}

void gnss_utm::publish_imu(){
	sensor_msgs::Imu imu;
	imu.header.frame_id="/base_link";
	imu.header.stamp=ros::Time::now();
	
	// imu.orientation=tf::createQuaternionMsgFromRollPitchYaw(roll_,pitch_,yaw_);

	imu.angular_velocity.x = gyro_x_;
	imu.angular_velocity.y = gyro_y_;
	imu.angular_velocity.z = gyro_z_;
	imu.linear_acceleration.x = acc_x_;
	imu.linear_acceleration.y = acc_y_;
	imu.linear_acceleration.z = acc_z_;

	pub_imu.publish(imu);
}


void gnss_utm::publish_tf(){
  	tf::Transform transform;
  	transform.setOrigin(tf::Vector3(x_,y_,z_));
  	tf::Quaternion quaternion;
  	quaternion.setRPY(roll_, pitch_, yaw_);
  	transform.setRotation(quaternion);
  	br_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/world", "/base_link"));


}




// data_check
bool gnss_utm::data_check(std::string s) {
	std::stringstream sstream;
	std::string check_value_str;
	std::string check_sum_str;
	int check_sum = 0;
	std::string ss;
	std::string sp_1 = "*";
	std::string sp_2 = "$";
	std::string sp_3 = ",";
	std::string::size_type pos = 0;
	std::string::size_type pos_1 = s.find(sp_1);
	std::string::size_type pos_2 = s.find(sp_2);
	// modify sentence no $ *
	if (pos_1 != std::string::npos) {
		check_value_str = s.substr(pos_1 + 1, 2);
		ss = s.substr(pos_2 + 1, pos_1 - pos_2 - 1);
	}
	else
	{
		ROS_WARN_STREAM("no found * in sentence data_check()");	
		return false;
	}
	// checksum
	for (int i = 0; i < ss.size(); i++) {
		check_sum ^= int(ss[i]);
	}
	sstream << std::hex << std::setfill('0') << std::setw(2) << check_sum;
	check_sum_str = sstream.str();
	std::transform(check_sum_str.begin(), check_sum_str.end(), check_sum_str.begin(), ((int(*)(int)) (std::toupper)) );// std::toupper in <cctype> use int(*)(int) form
	if (check_sum_str == check_value_str) {
		ROS_INFO("check right"); // comment
		return true;
	}
	else
	{
		ROS_WARN_STREAM("check wrong");
		return false;
	}
}


int gnss_utm::safe_int(const std::string &s) {
	int result;
	try {
		result = std::stoi(s);
		return result;
	}
	catch (...) {
		result = 0;
		ROS_WARN_STREAM("wrong in stoi() no sentence data");
		return result;
	}

}

double gnss_utm::safe_double(const std::string& s) {
	double result;
	try {
		result = std::stod(s);
		return result;
	}
	catch (...) {
		result = 0;
		ROS_WARN_STREAM("wrong in stod() no sentence data");
		return result;
	}
}

double gnss_utm::deg2rad (double degrees) {
    return degrees * 3.1415926 / 180.0;
}







void gnss_utm::lla2utm(const double &lat,const double &lon,double &easting,double &northing){



	double a = WGS84_A;
	double eccSquared = UTM_E2;
	double k0 = UTM_K0;

	double LongOrigin;
	double eccPrimeSquared;
	double N, T, C, A, M;

	double LatRad = deg2rad(lat);
	double LongRad = deg2rad(lon);
	double LongOriginRad;

    LongOrigin = (longitude_letter(lat,lon) - 1)*6 - 180 + 3;
	LongOriginRad = deg2rad(LongOrigin);



    eccPrimeSquared = (eccSquared)/(1-eccSquared);

	N = a/sqrt(1-eccSquared*sin(LatRad)*sin(LatRad));
	T = tan(LatRad)*tan(LatRad);
	C = eccPrimeSquared*cos(LatRad)*cos(LatRad);
	A = cos(LatRad)*(LongRad-LongOriginRad);

	M = a*((1	- eccSquared/4		- 3*eccSquared*eccSquared/64	- 5*eccSquared*eccSquared*eccSquared/256)*LatRad
				- (3*eccSquared/8	+ 3*eccSquared*eccSquared/32	+ 45*eccSquared*eccSquared*eccSquared/1024)*sin(2*LatRad)
									+ (15*eccSquared*eccSquared/256 + 45*eccSquared*eccSquared*eccSquared/1024)*sin(4*LatRad)
									- (35*eccSquared*eccSquared*eccSquared/3072)*sin(6*LatRad));

	easting = (double)(k0*N*(A+(1-T+C)*A*A*A/6
					+ (5-18*T+T*T+72*C-58*eccPrimeSquared)*A*A*A*A*A/120)
					+ 500000.0);

	northing = (double)(k0*(M+N*tan(LatRad)*(A*A/2+(5-T+9*C+4*C*C)*A*A*A*A/24
				 + (61-58*T+T*T+600*C-330*eccPrimeSquared)*A*A*A*A*A*A/720)));
	if(lat < 0)
		northing += 10000000.0; //10000000 meter offset for southern hemisphere


}

char gnss_utm::latitude_letter(const double &lat){
	char LetterDesignator;

	if ((84 >= lat) && (lat >= 72))  LetterDesignator = 'X';
	else if ((72 > lat) && (lat >= 64))  LetterDesignator = 'W';
	else if ((64 > lat) && (lat >= 56))  LetterDesignator = 'V';
	else if ((56 > lat) && (lat >= 48))  LetterDesignator = 'U';
	else if ((48 > lat) && (lat >= 40))  LetterDesignator = 'T';
	else if ((40 > lat) && (lat >= 32))  LetterDesignator = 'S';
	else if ((32 > lat) && (lat >= 24))  LetterDesignator = 'R';
	else if ((24 > lat) && (lat >= 16))  LetterDesignator = 'Q';
	else if ((16 > lat) && (lat >= 8))   LetterDesignator = 'P';
	else if ((8 > lat) && (lat >= 0))   LetterDesignator = 'N';
	else if ((0 > lat) && (lat >= -8))  LetterDesignator = 'M';
	else if ((-8 > lat) && (lat >= -16)) LetterDesignator = 'L';
	else if ((-16 > lat) && (lat >= -24)) LetterDesignator = 'K';
	else if ((-24 > lat) && (lat >= -32)) LetterDesignator = 'J';
	else if ((-32 > lat) && (lat >= -40)) LetterDesignator = 'H';
	else if ((-40 > lat) && (lat >= -48)) LetterDesignator = 'G';
	else if ((-48 > lat) && (lat >= -56)) LetterDesignator = 'F';
	else if ((-56 > lat) && (lat >= -64)) LetterDesignator = 'E';
	else if ((-64 > lat) && (lat >= -72)) LetterDesignator = 'D';
	else if ((-72 > lat) && (lat >= -80)) LetterDesignator = 'C';
	// 'Z' is an error flag, the Latitude is outside the UTM limits
	else LetterDesignator = 'Z';
	return LetterDesignator;

}


int gnss_utm::longitude_letter(const double &lat,const double &lon){
	int ZoneNumber;

	ZoneNumber = int((lon + 180) / 6) + 1;

	if (lat >= 56.0 && lat < 64.0 && lon >= 3.0 && lon < 12.0)
		ZoneNumber = 32;

	// Special zones for Svalbard
	if (lat >= 72.0 && lat < 84.0)
	{
		if (lon >= 0.0 && lon < 9.0) ZoneNumber = 31;
		else if (lon >= 9.0 && lon < 21.0) ZoneNumber = 33;
		else if (lon >= 21.0 && lon < 33.0) ZoneNumber = 35;
		else if (lon >= 33.0 && lon < 42.0) ZoneNumber = 37;
	}
	return ZoneNumber;

}

} // namespace GNSS
