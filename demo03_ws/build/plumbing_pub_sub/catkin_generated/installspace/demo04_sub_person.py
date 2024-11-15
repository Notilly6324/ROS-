#!/usr/bin/env python3

import rospy
from plumbing_pub_sub.msg import Person

def doMsg(p):
    rospy.loginfo("我订阅的数据:%s,%d,%.2f",p.name,p.age,p.height)

if __name__ == "__main__":
    
    #1.初始化 ROS 节点
    rospy.init_node("panMJ")

    # 3.创建订阅者对象
    sub = rospy.Subscriber("Genshin",Person,doMsg,queue_size=10)

    # 5.设置循环调用回调函数
    rospy.spin()