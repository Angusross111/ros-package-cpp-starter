#include <ros/ros.h>
#include <boost/thread.hpp>
#include "std_msgs/String.h"

namespace Starter
{
    class Counter
    {
        public:
        ~Counter();
        explicit Counter(const ros::NodeHandle& nh);

        std::shared_ptr<boost::thread> pubThread_;
        
        private:


        ros::NodeHandle nh_;
        bool CAMERAS_INITIALIZED_;
        ros::Subscriber reload_sub_;

        void init_array();

        void start();
        void counter_thread(int i);
        void reloadCallback(const std_msgs::String::ConstPtr& msg);
        
    };
}