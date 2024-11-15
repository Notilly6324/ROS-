#include <ros/ros.h>
#include <turtlesim/Spawn.h>


int main(int argc,char *argv[]){

    setlocale(LC_ALL,"");

    ros::init(argc,argv,"turtleSpawn");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn spawn;

    spawn.request.x = atof(argv[1]);
    spawn.request.y = atof(argv[2]);
    spawn.request.theta = atof(argv[3]);
    spawn.request.name = argv[4];

    ros::service::waitForService("/spawn");

    bool flag = client.call(spawn);
    if (flag)
    {
        ROS_INFO("响应成功！");
    }else{
        ROS_INFO("响应失败...");
    }
    

}