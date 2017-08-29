#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include "scaraBot.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "scaraBot");
    ros::NodeHandle nh;
    
    scaraBot robot;
    controller_manager::ControllerManager cm(&robot,nh);
    
    
    //  ros::AsyncSpinner spinner(1);
    //  spinner.start();
    
    // The Control Loop
    ros::Time last_time = ros::Time::now();
    ros::Rate rate(10);
    
    while (ros::ok())
    {
        ros::Time current_time = ros::Time::now();
        ros::Duration elapsed_time = current_time - last_time;
        last_time = current_time;
        robot.read();
        cm.update(current_time, elapsed_time);
        robot.writeR(elapsed_time);
        ros::spin();
    }
    
    //  spinner.stop();
    
    return 0;
}

