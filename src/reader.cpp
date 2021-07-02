/***************************************************************************************************
 * data_collector.cpp
 *
 *  Created on: 02/07/2021
 *      Author: Angus Ross
 *	   Company: SwarmFarm Robotics
 *     Website: www.swarmfarm.com
 *
 *  @brief - Reads in a folder of images and passes them to the image processor
 **************************************************************************************************/

#include "image_reader/reader.hpp"
// #include <image_reader/reader.hpp>
namespace ImageReader
{
    Reader::Reader(const ros::NodeHandle& nh) : nh_(nh), image_folder_location_(""), queue_limit_(0)
    {
        ROS_WARN("The Image Reader is starting");

        ros::NodeHandle pnh("~");
        pnh.param("/ImageReader/image_folder", image_folder_location_, image_folder_location_);
        pnh.param("/ImageReader/queue_limit", queue_limit_, queue_limit_);

        gps_tagged_image_pub_ = nh_.advertise<msgs_and_srvs::GpsTaggedImageMsg>("camera_array/cam0/gps_image",1,true);

        start();
    }

    void Reader::start()
    {
        ROS_WARN("The Image Reader is starting");
        ROS_WARN("path: '%s'", image_folder_location_.c_str());
        ROS_WARN("queue Limit: '%d'", queue_limit_);

    }
    
}