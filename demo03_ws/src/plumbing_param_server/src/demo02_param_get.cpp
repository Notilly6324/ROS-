#include <ros/ros.h>

int main(int argc,char *argv[]){

    //设置编码
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"awa");
    //创建节点句柄
    ros::NodeHandle nh;

    //ros::NodeHandle-------------------------------------------
    // 1.param
    double radius = nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);

    // 2.getParam
    double radius2 = 0.0;
    bool result1 = nh.getParam("radius",radius2);
    if (result1)
    {
        ROS_INFO("radius2 = %.2f",radius2);
    }else{
        ROS_INFO("被查寻的变量不存在");
    }

    // 3.getParamCached 与 getParam 类似，只是性能上有提升，一般测试下看不出来
    double radius3 = 0.0;
    bool result2 = nh.getParamCached("radius",radius3);
    if (result2)
    {
        ROS_INFO("radius3 = %.2f",radius3);
    }else{
        ROS_INFO("被查寻的变量不存在");
    }

    // 4.getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("遍历到的元素：%s",name.c_str());
    }
    
    // 5.hasParam
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxxx");
    ROS_INFO("does radius exist?%d",flag1);
    ROS_INFO("does radiusxxx exist?%d",flag2);

    // 6.searchParam
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果:%s",key.c_str());

    std::cout<<std::endl;

    //ros::param-------------------------------------------
    double radius_param = ros::param::param("radius",100.5);
    ROS_INFO("radius_param = %.2f",radius_param);

    std::vector<std::string> names_param;
    ros::param::getParamNames(names_param);
    for (auto &&name : names_param)
    {
        ROS_INFO("键：%s",name.c_str());        
    }
    

    return 0;
}