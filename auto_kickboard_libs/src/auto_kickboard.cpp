#include <iostream>
#include <vector>
#include <string>

#include "ros/ros.h"
#include "auto_kickboard_libs/auto_kickboard.hpp"

using namespace std;

// This node is the main node to control the ssing ssing
int main(int argc, char** argv)
{
    ros::init(argc, argv, "auto_kickboard");
    
    ros::NodeHandle nh("");
    ros::NodeHandle nh_priv("~");
    
    Ssingssing ssing_command(&nh, &nh_priv);

    ros::spin();
    return 0;
}
