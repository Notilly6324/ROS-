//1导包
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main (int argc,char *argv[]){

    setlocale(LC_ALL,"");
    //2初始化ros节点
    ros::init(argc,argv,"JieGou");
    //3创建节点句柄
    ros::NodeHandle nh;
    //4创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
    //5编写发布逻辑并发布数据
    //要求以 10HZ 的频率发布数据，并且文本后编号
    //先创建被发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(5);
    //设置编号
    int count = 0;
    //编写循环，循环中发布数据
    ros::Duration(3.0).sleep();

    while (ros::ok())
    {

        count++;
        // msg.data = "hello";
        //实现字符串拼接
        std::stringstream ss;
        ss<< "hello --->" <<count;
        msg.data = ss.str();

        pub.publish(msg);
        //添加日志：
        ROS_INFO("发布的数据是:%s", ss.str().c_str());
        rate.sleep();
        ros::spinOnce();//官方建议，处理回调函数

    }

    return 0;

}