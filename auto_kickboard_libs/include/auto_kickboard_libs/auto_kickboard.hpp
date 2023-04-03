#ifndef ROBOT_NODE_H_
#define ROBOT_NODE_H_

#include "vector"
#include "string"
#include "ros/ros.h"
#include "iostream"
#include "sensor_msgs/JointState.h"

#include "ssing_msgs/Ssing.h"
#include "ssing_msgs/DynamixelCommand.h"
#include "ssing_msgs/JointPosition.h"

#include <std_srvs/Trigger.h>
//#include <Eigen/Dense>


class Ssingssing
{
    public:
        Ssingssing(ros::NodeHandle *nh, ros::NodeHandle *nh_priv);
        ~Ssingssing();
        void controlLoop(const ros::TimerEvent& event);
        void CommandmsgCallback(const ssing_msgs::Ssing::ConstPtr& msg);
        void publishCommands(std::vector<float> target_joint_position);
        

        
    private:
        ros::Timer loop_timer;
        ros::Publisher serving_command_publisher;
        ros::Publisher dynamixel_command_publisher;
        ros::ServiceServer dynamixel_command;
        ros::ServiceClient client;
        
        ros::Subscriber object_position_subscriber;
        ros::Subscriber control_keyboard_subscriber;
        std::vector<std::vector<double>> target_joint_position;
        int control_command_; // 0: Initialize 1: Pick up , 2: Pull down, 3: Stretch Arm, 4:Pull Arm
        float something;
        //ServingCommand serving_command;
        sensor_msgs::JointState joint_state;
        ssing_msgs::DynamixelCommand ssing;
        std::vector<std::string> joint_name = {"joint1","joint2","joint3","joint4"};
        int x_min, y_min, x_max, y_max;
        int object_x = 0;
        int object_y = 0;

};


#endif
