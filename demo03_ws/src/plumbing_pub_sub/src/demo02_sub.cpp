//1导包
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

void doMsg(const std_msgs::String::ConstPtr &msg){
    //通过msg获取并操作订阅到的数据
    ROS_INFO("HWB收到的数据:%s",msg->data.c_str());
}

int main(int argc,char *argv[]){

    setlocale(LC_ALL,"");
    //2初始化ros节点
    ros::init(argc,argv,"HWB");
    //3创建节点句柄
    ros::NodeHandle nh;
    //4创建订阅者对象
    ros::Subscriber sub = nh.subscribe<>("fang",10,doMsg);
    //5处理订阅到的数据

    ros::spin();

    return 0;
}