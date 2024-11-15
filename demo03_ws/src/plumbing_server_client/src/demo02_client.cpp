// 1.包含头文件
#include <ros/ros.h>
#include "plumbing_server_client/Addints.h"


int main(int argc,char *argv[]){

    setlocale(LC_ALL,"");
    if (argc != 3)
    {
        ROS_INFO("提交的参数个数不对。");
        return 1;
    }

    // ROS_INFO("%d",argc);
    // for (int i = 0; i < argc; i++)
    // {
    //     ROS_INFO("%d,%s",i,argv[i]);
    // }
    
    // 2.初始化 ROS 节点
    ros::init(argc,argv,"Genshin");
    // 3.创建 ROS 句柄
    ros::NodeHandle nh;
    // 4.创建 客户端 对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::Addints>("addints");
    // 5.请求服务，接收响应
    plumbing_server_client::Addints ai;
    // 5-1.组织请求
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    // 5-2.处理响应

    // 服务器挂起，等待服务器启动，两个函数功能相同
    client.waitForExistence();
    ros::service::waitForService("addints");

    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("响应成功！");
        //获取结果
        ROS_INFO("和等于 = %d",ai.response.sum);
    }else{
        ROS_INFO("响应失败...");
    }

    return 0;
}