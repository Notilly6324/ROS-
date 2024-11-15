#include <ros/ros.h>
#include <iostream>
#include "plumbing_pub_sub/Person.h"

int main(int argc,char *argv[]){

    setlocale(LC_ALL,"");
    ROS_INFO("这是发布方");
    //1.初始化 ROS 节点
    ros::init(argc,argv,"Minefealina");

    //2.创建 ROS 句柄
    ros::NodeHandle nh;

    //3.创建发布者对象
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("sb",1000);

    //4.组织被发布的消息，编写发布逻辑并发布消息
    //4.1创建发布的数据
    plumbing_pub_sub::Person person;
    person.name = "李凌岳";
    person.age = 0;
    person.height = 1.99;

    //4.2设置发布频率
    ros::Rate rate(1);

    //4.3循环发布数据
    while (ros::ok())
    {
        //修改数据
        person.age += 1;
        //核心：数据发布
        pub.publish(person);
        ROS_INFO("发布的数据是:%s,%d,%.2f",person.name.c_str(),person.age,person.height);
        //休眠
        rate.sleep();
        //建议
        ros::spinOnce();
    }
    return 0;
}