#include <ros/ros.h>
#include <exiv2/exiv2.hpp>
#include "msgs_and_srvs/GpsTaggedImageMsg.h"
namespace ImageReader
{
    class Reader
    {
        public:

        explicit Reader(const ros::NodeHandle& nh);

        private:

        ros::NodeHandle nh_;

        ros::Publisher gps_tagged_image_pub_;

        int queue_limit_;
        std::string image_folder_location_;

        void start();
    };
}