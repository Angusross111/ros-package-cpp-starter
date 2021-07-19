/***************************************************************************************************
 * counter_node.cpp
 *
 *  Created on: 02/07/2021
 *      Author: Angus Ross
 *	   Company: SwarmFarm Robotics
 *     Website: www.swarmfarm.com
 *
 *  @brief - Entry point for the Counter node
 **************************************************************************************************/

// ROS
#include <ros/ros.h>

// Apple Data Capture
#include "cpp_ros_package_starter/counter.hpp"

int main(int argc, char **argv)
{
    // Set up ROS.
    ros::init(argc, argv, "Counter");
    ros::NodeHandle nh;

    // Create a new node_example::Counter object.
    Starter::Counter node(nh);

    // Let ROS handle all callbacks.
    ros::spin();

    return 0;
}  // end main()