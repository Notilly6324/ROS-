#include <ros/ros.h>

int main(int argc,char *argv[]){

    ros::init(argc,argv,"turtleBackground");

    ros::NodeHandle nh("turtle1");

    nh.setParam("background_b",atoi(argv[1]));
    nh.setParam("background_g",atoi(argv[2]));
    nh.setParam("background_r",atoi(argv[3]));

    // ros::param::set("/turtle1/background_b",atoi(argv[1]));
    // ros::param::set("/turtle1/background_g",atoi(argv[2]));
    // ros::param::set("/turtle1/background_r",atoi(argv[3]));

    return 0;
}