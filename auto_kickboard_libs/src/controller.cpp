
#include "auto_kickboard_libs/auto_kickboard.hpp"

Ssingssing::Ssingssing(ros::NodeHandle *nh, ros::NodeHandle *nh_priv)
{
    double loop_rate = 100.0;

    dynamixel_command_publisher = nh -> advertise<ssing_msgs::DynamixelCommand>("dynamixel_workbench/dynamixel_position_command", 1);
    
    control_keyboard_subscriber = nh -> subscribe("ssing_msg", 1000, &Ssingssing::CommandmsgCallback, this);

    client =nh -> serviceClient<std_srvs::Trigger>("/dynamixel_workbench/execution");
    
    loop_timer = nh_priv->createTimer(ros::Duration(1/loop_rate), &Ssingssing::controlLoop, this);
}

Ssingssing::~Ssingssing()
{}

void Ssingssing::controlLoop(const ros::TimerEvent& event)
{
    //publishCommands(target_joint_position);
}

void Ssingssing::CommandmsgCallback(const ssing_msgs::Ssing::ConstPtr& msg)
{

    float motion_num = msg -> motion_command;
    ssing_msgs::JointPosition position_info;
    ROS_INFO("Command info: %f", motion_num);

    if (motion_num == 0.0) // Initialize 
    {
    	std::vector<double> initialize_position;
    	initialize_position = {0.0};
        target_joint_position = {initialize_position};
    }

    else if (motion_num == 1.0) // Go
    {
         
    }

    else if (motion_num == 2.0) // Back
    {
         
    }

    else if (motion_num == 3.0) // Left 
    {
	angle += 0.1;
        target_joint_position = {{angle}};
    }    
    
    else if (motion_num == 4.0) // Right
    {
	angle -= 0.1;
        target_joint_position = {{angle}};
             
    }    
    
    ssing.motion = motion_num;
    //position_info.positions.push_back(target_joint_position);
    //ssing.joint_position = target_joint_position;
    
    dynamixel_command_publisher.publish(ssing);

}


void Ssingssing::publishCommands(std::vector<float> target_joint_position)
{
    // joint_state publisher to RVIZ SIMULATION
    joint_state.header.stamp = ros::Time::now();
    joint_state.name.resize(4);
    joint_state.position.resize(4);
    
    for (int i=0; i<4; i++)
    {
        joint_state.name[i] = joint_name[i];
        joint_state.position[i] = target_joint_position[i];
    }

    //std_srvs::Triger trig;
    //dynamixel_command.DynamixelMsgCallback(trig.request, trig.response);
    serving_command_publisher.publish(joint_state);
}
// Code description
// Needed 1. Dynamixel control 2. Computer vision 3. Camera control 
