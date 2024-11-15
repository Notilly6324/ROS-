#!/usr/bin/env python3
#导包
import rospy
from std_msgs.msg import String

    # 4.处理订阅的消息(回调函数)
def doMsg(msg):
    rospy.loginfo("我订阅的数据:%s",msg.data)

if __name__ == "__main__":

    # 2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("J6J")
    
    # 3.创建订阅者对象
    sub = rospy.Subscriber("che",String,doMsg,queue_size=10)

    # 5.设置循环调用回调函数
    rospy.spin()