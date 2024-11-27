#include <ros/ros.h>
#include <std_msgs/String.h>
/*
    需求：演示不同类型的话题名称设置
         设置话题名称与命名空间



*/
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hello");
    ros::NodeHandle nh1;
    
    //核心：设置不同类型的话题名称
    //1.全局话题名称 --- 以 / （也可设置自己的命名空间）开头，这种情况下和节点（命名空间和节点名称）无关
    ros::Publisher pub = nh1.advertise<std_msgs::String>("/chatter1", 1000);

    //2.相对话题名称 --- 不以 / 开头，这种情况下和节点的命名空间有关
    ros::Publisher pub2 = nh1.advertise<std_msgs::String>("chatter2", 1000);

    //3.私有话题名称 --- 需要创建特定 NodeHandle ("~"),这种情况下和节点(命名空间和节点名称)有关
    ros::NodeHandle nh2("~");
    ros::Publisher pub3 = nh2.advertise<std_msgs::String>("chatter3", 1000);

    //注意：如果私有话题名称前面加了 / ，则会变成全局话题名称
    ros::Publisher pub4 = nh2.advertise<std_msgs::String>("/chatter4", 1000);

    while (ros::ok())
    {
        
    }
    
  return 0;
}