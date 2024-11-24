//1导包
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main (int argc,char *argv[]){

    setlocale(LC_ALL,"");
    //2初始化ros节点
    /*
    作用：ros初始化函数

    参数：
        1.argc     ---- 封装实参的个数（n+1)
        2.argv     ---- 封装参数的数组
        3.name     ---- 为节点命名（唯一性）
        4.options  ---- 节点启动选项

        返回值：void
    
    使用：
        1.argc 与 argv 的使用
            如果按照ROS中的特定格式传入实参，那么ROS可以加以使用，比如用来设置全局参数、给节点重命名...
        2.options 的使用
            节点名称需要保证唯一性，会导致一个问题：同一个节点不能重复启动
            结果：当有重名的节点启动时，之前的节点会被关闭
            需求：特定场景下，需要一个节点多次启动且能正常运行，怎么办
    */
    ros::init(argc,argv,"jieGou",ros::init_options::AnonymousName);
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
        //如果计数器大于等于50，那么关闭节点
        if(count >= 50){
            ros::shutdown();
        }

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
    ros::spinOnce();
    ROS_INFO("一轮回调执行完毕");

    return 0;
}