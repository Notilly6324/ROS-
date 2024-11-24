// File: demo.cpp

// 1. 包含头文件
#include <ros/ros.h>
#include <std_msgs/String.h>

// 2. 回调函数
void callback(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("订阅的数据是:%s", msg->data.c_str());
}

// 3. 主函数
int main(int argc, char *argv[])
{
    // 4. 初始化ROS节点
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "jieGou", ros::init_options::AnonymousName);

    // 5. 创建节点句柄
    ros::NodeHandle nh;

    // 6. 创建订阅者对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("fang", 10, callback);

    // 7. 循环等待回调函数
    ros::spin();
    ROS_INFO("执行一轮回调函数");
    return 0;
}