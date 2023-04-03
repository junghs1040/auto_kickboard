#include <iostream>
#include <vector>
#include <string>

#include "ros/ros.h"
#include "auto_kickboard_libs/auto_kickboard.hpp"

using namespace std;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "auto_kickboard");
    
    ros::NodeHandle nh("");
    ros::NodeHandle nh_priv("~");
    cout << "TEST" << endl;
    
    Ssingssing ssing(&nh, &nh_priv);

    ros::spin();
    return 0;
}
