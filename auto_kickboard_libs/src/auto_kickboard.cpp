#include <iostream>
#include <vector>
#include <string>

#include "ros/ros.h"
//#include "auto_kickboard/auto_kickboard.hpp"

using namespace std;


int main(int argc, char** argv)
{
    ros::init(argc, argv, "auto_kickboard");
    
    ros::NodeHandle nh("");
    ros::NodeHandle nh_priv("~");
    cout << "TEST" << endl;

    
    Ssingssing sing(&nh, &nh_priv);
    ros::spin();
    return 0;
}
