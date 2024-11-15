#include <ros/ros.h>

int main (int argc,char *argv[]){

    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"wwwww");

    //创建ros节点句柄
    ros::NodeHandle nh;

    //参数增
    //方案1：nh
    nh.setParam("type","xiaoGou");
    nh.setParam("radius",0.15);
    //方案2：ros::param
    ros::param::set("type_param","xiaoMao");
    ros::param::set("radius_param",0.15);

    //参数改
    //方案1：nh
    nh.setParam("radius",0.2);
    //方案2：ros：：param
    ros::param::set("radius_param",0.2);

    return 0;
}