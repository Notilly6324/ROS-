#include <ros/ros.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "param_name");
    ros::NodeHandle nh;
    //使用ros：：param 来设置参数
    // 1.全局参数
    ros::param::set("/global_param", 100);
    // 2.相对参数
    ros::param::set("relative_param", 200);
    // 3.私有参数
    ros::param::set("~private_param", 300);

    //使用NodeHandle来设置参数
    // 1.全局参数
    nh.setParam("/global_param_nh", 400);
    // 2.相对参数
    nh.setParam("relative_param_nh", 500);
    // 3.私有参数
    ros::NodeHandle nh2("~");
    nh2.setParam("private_param_nh", 600);

    return 0;
}