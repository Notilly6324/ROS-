#! /usr/bin/env python

import rospy
from plumbing_pub_sub.msg import Person

if __name__ == "__main__":
    
    #1.初始化 ROS 节点
    rospy.init_node("sunTJ")

    #2.创建发布者对象
    pub = rospy.Publisher("Genshin",Person,queue_size=10)

    #3.组织发布逻辑并发布数据
    #3.1创建person数据
    p = Person()
    p.name = "派蒙"
    p.age = 18
    p.height = 0.75

    #3.2编写消息发布逻辑
    #创建rate对象
    rate = rospy.Rate(1)

    #循环发布
    while not rospy.is_shutdown():
        pub.publish(p)
        rospy.loginfo("发布的消息：%s,%d,%.2f",p.name,p.age,p.height)
        rate.sleep()