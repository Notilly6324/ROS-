// 1.包含头文件
#include <ros/ros.h>
/*
    需求1：演示时间相关的API
    实现：
        1.准备（头文件,初始化ros节点,NodeHandle对象）
        2.获取当前时刻
        3.设置指定时刻

    需求2：程序执行中停顿5秒
    实现：
        1.创建一个持续时间对象
        2.调用sleep函数休眠5秒

    需求3：已知程序开始运行的时刻和程序运行的时间，求程序结束的时刻
    实现：
        1.获取程序开始运行的时刻
        2.模拟运行时间（n秒）
        3.计算程序结束的时刻 = 开始时刻 + 运行时间

    需求4：每隔1秒在控制台输出一段文字
    实现：
        策略1：ros::Rate()不演示
        策略2：定时器
    注意：
        创建：nh.createTimer();
        参数1：时间间隔
        参数2：回调函数（时间事件 TimeEvent）
        参数3：是否只执行一次
        参数4：是否自动启动（当为false时，需要手动调用timer.start()启动定时器）

        定时器启动后：ros::spin()会自动调用回调函数

*/
void cb(const ros::TimerEvent &event){
    ROS_INFO("------------");
    ROS_INFO("定时器被调用的时刻：%.2f",event.current_real.toSec());
}





int main(int argc, char *argv[])
{
    //1.准备（头文件,初始化ros节点,NodeHandle对象）
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "time_demo");
    ros::NodeHandle nh;//注意：必须。否则会导致时间api无法使用(再NodeHandle会初始化时间操作)

    //2.获取当前时刻
    //now函数会将当前时刻封装到Time对象中并返回
    //参考系：1970年1月1日0时0分0秒 东八区：1970年1月1日8时0分0秒
    ros::Time right_now = ros::Time::now();
    ROS_INFO("当前时间是：%.2f", right_now.toSec());
    ROS_INFO("当前时间是：%d", right_now.sec);
    //把right_now换算为年月日时分秒
    // int year, month, day, hour, minute, second;
    // right_now.sec += 8 * 60 * 60;//换算为东八区时间
    // year = right_now.sec / (365 * 24 * 60 * 60) + 1970;
    // month = (right_now.sec % (365 * 24 * 60 * 60)) / (30 * 24 * 60 * 60) + 1;
    // day = (right_now.sec % (30 * 24 * 60 * 60)) / (24 * 60 * 60) + 1;
    // hour = (right_now.sec % (24 * 60 * 60)) / (60 * 60);
    // minute = (right_now.sec % (60 * 60)) / 60;
    // second = right_now.sec % 60;
    // ROS_INFO("当前时刻是：%d年%d月%d日%d时%d分%d秒", year, month, day, hour, minute, second);

    //3.设置指定时刻
    ros::Time t1(30,312345678);
    ros::Time t2(100.35);
    ROS_INFO("指定时刻是：%.2f", t1.toSec());
    ROS_INFO("指定时刻是：%.2f", t2.toSec());

    //--------------------------------------------
    ROS_INFO("----------------------持续时间---------------------------");
    ros::Time start = ros::Time::now();
    ROS_INFO("开始休眠:%.2f", start.toSec());
    ros::Duration du(0.5);
    du.sleep();
    ros::Time end = ros::Time::now();
    ROS_INFO("休眠结束:%.2f", end.toSec());

    //--------------------------------------------
    ROS_INFO("----------------------时间运算---------------------------");
    //时刻与持续时间之间的运算
    // 1.获取程序开始运行的时刻
    ros::Time begin = ros::Time::now();
    // 2.模拟运行时间（n秒）
    ros::Duration du1(5);
    // 3.计算程序结束的时刻 = 开始时刻 + 运行时间
    ros::Time stop = begin + du1;//也可以减
    ROS_INFO("程序开始的时刻：%.2f", begin.toSec());
    ROS_INFO("程序结束的时刻：%.2f", stop.toSec());

    //时刻与时刻之间的运算
    // ros::Time sum = begin + stop;//不可以相加
    ros::Duration du2 = begin - stop;
    ROS_INFO("时刻与时刻之间相减：%.2f", du2.toSec());

    //持续时间与持续时间之间的运算
    ros::Duration du3 = du1 + du2;//0
    ros::Duration du4 = du1 - du2;//10
    ROS_INFO("持续时间与持续时间之间相加：%.2f", du3.toSec());
    ROS_INFO("持续时间与持续时间之间相减：%.2f", du4.toSec());

    //--------------------------------------------
    ROS_INFO("----------------------定时器---------------------------");
    /*
    ros::Timer createTimer
        (ros::Duration period,                  //时间间隔 --- 1s
        const ros::TimerCallback &callback,     //回调函数 --- 封装业务
        bool oneshot = false,                   //是否只执行一次 --- false
        bool autostart = true);                 //是否自动启动 --- true
    
    */

    // ros::Timer timer = nh.createTimer(ros::Duration(1),cb);
    // ros::Timer timer = nh.createTimer(ros::Duration(1),cb,true);
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);
    timer.start();

    ros::spin();

}