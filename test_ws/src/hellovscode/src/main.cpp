#include "ros/ros.h"
#include "ros/console.h"

using namespace ros;

int main(int agrc,char *agrv[]){

    setlocale(LC_ALL,"");
    init(agrc,agrv,"hellovscode");
    ROS_INFO("hello,哈哈");
    

    return 0;
}