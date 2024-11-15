//include ros headfile
#include "ros/ros.h"

//main
int main (int argc,char *argv[]){
	//initialize ros
	ros::init(argc,argv,"hello_node");
	//outlog
	ROS_INFO("hello world!");
	return 0;
}
