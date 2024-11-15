#include <ros/ros.h>
#include <iostream>
#include "plumbing_pub_sub/Person.h"

//4.回调函数中处理 person
void doPerson(const plumbing_pub_sub::Person::ConstPtr &person){
    ROS_INFO("订阅到的信息:%s,%d,%.2f",person->name.c_str(),person->age,person->height);
}

int main(int argc,char *argv[]){

    setlocale(LC_ALL,"");
    ROS_INFO("这是订阅方");
    //1.初始化 ROS 节点
    ros::init(argc,argv,"LLY");

    //2.创建 ROS 句柄
    ros::NodeHandle nh;

    //3.创建订阅对象
    ros::Subscriber sub = nh.subscribe<plumbing_pub_sub::Person>("sb",10,doPerson);

    //5.ros::spin();
    ros::spin();

    return 0;
}