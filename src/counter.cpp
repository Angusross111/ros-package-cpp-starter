/***************************************************************************************************
 * counter.cpp
 *
 *  Created on: 02/07/2021
 *      Author: Angus Ross
 *	   Company: SwarmFarm Robotics
 *     Website: www.swarmfarm.com
 *
 *  @brief - Starter example counter cpp node
 **************************************************************************************************/

#include "cpp_ros_package_starter/counter.hpp"
// #include <image_Counter/Counter.hpp>
namespace Starter 
{
    Counter::~Counter(){
        ROS_WARN("Cleanup");

        if (pubThread_) {
        pubThread_->interrupt();
        pubThread_->join();
        }
        // reset pubThread_
        pubThread_.reset();
    }
    Counter::Counter(const ros::NodeHandle& nh) : nh_(nh)
    {
        ROS_WARN("Counter Init");
        ros::NodeHandle pnh("~");
        CAMERAS_INITIALIZED_ = false;

        init_array();
        reload_sub_ = nh_.subscribe("/RedisConnection/reload_params", 10, &Starter::Counter::reloadCallback,this);
        pubThread_.reset(new boost::thread(boost::bind(&Counter::Counter::start, this)));
        ROS_WARN("After pubThread_.reset");


    }

    void Counter::Counter::init_array() {
    
        ROS_INFO_STREAM("*** FLUSH SEQUENCE ***");

        ROS_WARN("Init Cams");
        sleep(2);

        ROS_WARN("Start Acqu");
        sleep(0.5);

        ROS_WARN("End Acqu");
        sleep(0.5);

        ROS_WARN("Deinit Cams");
        sleep(2.0);

        ROS_WARN("Init Cams");
        CAMERAS_INITIALIZED_ = true;
        ROS_DEBUG_STREAM("Flush sequence done.");
    }

    void Counter::start()
    {
        
        ROS_WARN("Starting Multi-Threading");


        boost::thread_group threads;

        for (int i=0; i<2; i++)
            threads.create_thread(boost::bind(&Counter::counter_thread, this, i));
        ROS_WARN("Before join All");
        threads.join_all();
        ROS_WARN("After join All");
    }


    void Counter::counter_thread(int i){
        ROS_INFO_STREAM("Starting thread: "<<i);
        ros::Rate r(2); // 10 hz
        int count_ = 0;
        while (ros::ok())
        {
            if(!CAMERAS_INITIALIZED_){
                // CAMERAS_INITIALIZED_ = true;
                ROS_INFO_STREAM("Breaking Thread "<<i);
                break;
            }
            ROS_INFO_STREAM("Thread '"<<i<<"' Count: '"<<count_<<"'");
            ros::spinOnce();
            r.sleep();
            count_++;
        }

    }
        
  

    void Counter::reloadCallback(const std_msgs::String::ConstPtr& msg){
        ROS_WARN("Flag: %s",CAMERAS_INITIALIZED_?"true":"false");

        if( msg != nullptr ){
            ROS_WARN("Reload Spinnaker Params");
            CAMERAS_INITIALIZED_ = false;
            
            // if(pubThread_){
            //     pubThread_->interrupt();
            // }
            // pubThread_.reset(new boost::thread(boost::bind(&Counter::Counter::start, this)));
            
            
        }
    
    }
    
}