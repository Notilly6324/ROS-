// 1. 包含头文件
#include <ros/ros.h>
/*
    ROS 中日志：
        演示不同级别日志的基本使用
*/

// 2. 主函数
int main(int argc, char *argv[])
{
    // 3. 初始化ROS节点
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "hello_log");
    // 4. 创建节点句柄
    ros::NodeHandle nh;

    // 5. 打印不同级别的日志
    ROS_DEBUG("调试信息");
    ROS_INFO("一般信息");
    ROS_WARN("警告信息");
    ROS_ERROR("错误信息");
    ROS_FATAL("严重错误");

    return 0;
}
