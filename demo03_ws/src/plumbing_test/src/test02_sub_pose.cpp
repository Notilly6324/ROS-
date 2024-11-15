#include <ros/ros.h>
#include <iostream>
#include "turtlesim/Pose.h"

void doPose(const turtlesim::Pose::ConstPtr &pose){
ROS_INFO("乌龟的坐标: (%.2f, %.2f), 角度: %.2f, 线速度: %.2f, 角速度: %.2f", 
         pose->x, pose->y, pose->theta, pose->linear_velocity, pose->angular_velocity);
}

int main(int argc,char *argv[]){

    setlocale(LC_ALL,"");
    ros::init(argc,argv,"turtlePose");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose",10,doPose);
    ros::Rate rate(10);
    rate.sleep();

    ros::spin();
    return 0;
}