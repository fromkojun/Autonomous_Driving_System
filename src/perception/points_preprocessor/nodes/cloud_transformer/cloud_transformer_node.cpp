
#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>

// #include <velodyne_pointcloud/point_types.h>

#include <tf/transform_listener.h>
#include <pcl_ros/transforms.h>

class CloudTransformerNode
{
private:

	ros::NodeHandle     node_handle_;
	ros::Subscriber     points_node_sub_;
	ros::Publisher      transformed_points_pub_;

	std::string         input_point_topic_;
	std::string         target_frame_;
	std::string         output_point_topic_;

	tf::TransformListener *tf_listener_ptr_;

	bool                transform_ok_;

	void publish_cloud(const ros::Publisher& in_publisher,
	                   const sensor_msgs::PointCloud2 &in_cloud_msg)
	{
		in_publisher.publish(in_cloud_msg);
	}

	void transformXYZICloud(const pcl::PointCloud<pcl::PointXYZI>& in_cloud,
	                         pcl::PointCloud<pcl::PointXYZI>& out_cloud,
	                         const tf::StampedTransform& in_tf_stamped_transform)
	{
		Eigen::Matrix4f transform;
		pcl_ros::transformAsMatrix(in_tf_stamped_transform, transform);

		if (&in_cloud != &out_cloud)
		{
			out_cloud.header   = in_cloud.header;
			out_cloud.is_dense = in_cloud.is_dense;
			out_cloud.width    = in_cloud.width;
			out_cloud.height   = in_cloud.height;
			out_cloud.points.reserve (out_cloud.points.size ());
			out_cloud.points.assign (in_cloud.points.begin (), in_cloud.points.end ());
			out_cloud.sensor_orientation_ = in_cloud.sensor_orientation_;
			out_cloud.sensor_origin_      = in_cloud.sensor_origin_;
			}
		if (in_cloud.is_dense)
			{
			for (size_t i = 0; i < out_cloud.points.size (); ++i)
				{
				//out_cloud.points[i].getVector3fMap () = transform * in_cloud.points[i].getVector3fMap ();
				Eigen::Matrix<float, 3, 1> pt (in_cloud[i].x, in_cloud[i].y, in_cloud[i].z);
				out_cloud[i].x = static_cast<float> (transform (0, 0) * pt.coeffRef (0) +
													transform (0, 1) * pt.coeffRef (1) +
													transform (0, 2) * pt.coeffRef (2) +
													transform (0, 3));
				out_cloud[i].y = static_cast<float> (transform (1, 0) * pt.coeffRef (0) +
													transform (1, 1) * pt.coeffRef (1) +
													transform (1, 2) * pt.coeffRef (2) +
													transform (1, 3));
				out_cloud[i].z = static_cast<float> (transform (2, 0) * pt.coeffRef (0) +
													transform (2, 1) * pt.coeffRef (1) +
													transform (2, 2) * pt.coeffRef (2) +
													transform (2, 3));
				}
			}
		else
		{
			// Dataset might contain NaNs and Infs, so check for them first,
			for (size_t i = 0; i < out_cloud.points.size (); ++i)
			{
				if (!pcl_isfinite (in_cloud.points[i].x) ||
				           !pcl_isfinite (in_cloud.points[i].y) ||
				           !pcl_isfinite (in_cloud.points[i].z))
					{continue;}
				//out_cloud.points[i].getVector3fMap () = transform * in_cloud.points[i].getVector3fMap ();
				Eigen::Matrix<float, 3, 1> pt (in_cloud[i].x, in_cloud[i].y, in_cloud[i].z);
				out_cloud[i].x = static_cast<float> (transform (0, 0) * pt.coeffRef (0) +
													transform (0, 1) * pt.coeffRef (1) +
													transform (0, 2) * pt.coeffRef (2) +
													transform (0, 3));
				out_cloud[i].y = static_cast<float> (transform (1, 0) * pt.coeffRef (0) +
													transform (1, 1) * pt.coeffRef (1) +
													transform (1, 2) * pt.coeffRef (2) +
													transform (1, 3));
				out_cloud[i].z = static_cast<float> (transform (2, 0) * pt.coeffRef (0) +
													transform (2, 1) * pt.coeffRef (1) +
													transform (2, 2) * pt.coeffRef (2) +
													transform (2, 3));
			}
		}
	}

	void CloudCallback(const sensor_msgs::PointCloud2::ConstPtr &in_sensor_cloud_ros)
	{
		
		pcl::PointCloud<pcl::PointXYZI>::Ptr in_sensor_cloud (new pcl::PointCloud<pcl::PointXYZI>);
		
		// sensor_msgs::PointCloud2 in_sensor_cloud_ros_go new(in_sensor_cloud_ros);
		pcl::fromROSMsg(*in_sensor_cloud_ros,*in_sensor_cloud);

		// std::cout<< in_sensor_cloud -> header.frame_id;
		
		pcl::PointCloud<pcl::PointXYZI>::Ptr transformed_cloud_ptr (new pcl::PointCloud<pcl::PointXYZI>);
		
		// pcl::PointCloud<velodyne_pointcloud::PointXYZIR>::Ptr transformed_cloud_ptr (new pcl::PointCloud<velodyne_pointcloud::PointXYZIR>);

		bool do_transform = false;
		tf::StampedTransform transform;
		if (target_frame_ != in_sensor_cloud->header.frame_id)
		{
			try {
				tf_listener_ptr_->lookupTransform(target_frame_, in_sensor_cloud->header.frame_id, ros::Time(0),
				                                  transform);
				do_transform = true;
			}
			catch (tf::TransformException ex) {
				ROS_ERROR("cloud_transformer: %s NOT Transforming.", ex.what());
				do_transform = false;
				transform_ok_ = false;
			}
		}
		if (do_transform)
		{
			transformXYZICloud(*in_sensor_cloud, *transformed_cloud_ptr, transform);
			transformed_cloud_ptr->header.frame_id = target_frame_;
			if (!transform_ok_)
				{ROS_INFO("cloud_transformer: Correctly Transformed"); transform_ok_=true;}
		}
		else
			{ pcl::copyPointCloud(*in_sensor_cloud, *transformed_cloud_ptr);}

		
		//changing
		sensor_msgs::PointCloud2::Ptr transformed_cloud_ptr_ros (new sensor_msgs::PointCloud2);
		pcl::toROSMsg(*transformed_cloud_ptr,*transformed_cloud_ptr_ros);
		
		// std::cout<< (*transformed_cloud_ptr_ros).header.frame_id;
		publish_cloud(transformed_points_pub_, *transformed_cloud_ptr_ros);
	}

public:
	CloudTransformerNode(tf::TransformListener* in_tf_listener_ptr):node_handle_("~"), transform_ok_(false)
	{
		tf_listener_ptr_ = in_tf_listener_ptr;
	}
	void Run()
	{
		ROS_INFO("Initializing Cloud Transformer, please wait...");
		node_handle_.param<std::string>("input_point_topic", input_point_topic_, "/points_raw");
		ROS_INFO("Input point_topic: %s", input_point_topic_.c_str());

		node_handle_.param<std::string>("target_frame", target_frame_, "base_link");
		ROS_INFO("Target Frame in TF (target_frame) : %s", target_frame_.c_str());

		node_handle_.param<std::string>("output_point_topic", output_point_topic_, "/points_transformed");
		ROS_INFO("output_point_topic: %s", output_point_topic_.c_str());

		ROS_INFO("Subscribing to... %s", input_point_topic_.c_str());
		points_node_sub_ = node_handle_.subscribe(input_point_topic_, 10, &CloudTransformerNode::CloudCallback, this);

		transformed_points_pub_ = node_handle_.advertise<sensor_msgs::PointCloud2>(output_point_topic_, 10);

		ROS_INFO("Ready");

		ros::spin();

	}

};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "cloud_transformer");
	tf::TransformListener tf_listener;
	CloudTransformerNode app(&tf_listener);

	app.Run();

	return 0;

}
