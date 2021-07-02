/***************************************************************************************************
 * data_collector_node.cpp
 *
 *  Created on: 02/07/2021
 *      Author: Angus Ross
 *	   Company: SwarmFarm Robotics
 *     Website: www.swarmfarm.com
 *
 *  @brief - Entry point for the Image Reader node
 **************************************************************************************************/

// ROS
#include <ros/ros.h>

// Apple Data Capture
#include "image_reader/reader.hpp"

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "Reader");
  ros::NodeHandle nh;

  // Create a new node_example::Talker object.
  ImageReader::Reader node(nh);

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
}  // end main()