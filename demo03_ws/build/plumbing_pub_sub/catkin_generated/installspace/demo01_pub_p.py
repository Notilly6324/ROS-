#!/usr/bin/env python3

# 1.导包 
import rospy
from std_msgs.msg import String#发布消息的类型

if __name__ == "__main__":

    # 2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("JG")#传入节点名称
    # 3.实例化 发布者 对象
    pub = rospy.Publisher("che",String,queue_size=10)
    # 4.组织被发布的数据，并编写逻辑发布数据
    #创建数据
    msg_front = "hello你好"
    msg = String()
    #计数器
    count = 0
    #设置循环频率
    rate = rospy.Rate(1)
    #使用循环发布数据
    rospy.sleep(3)
    while not rospy.is_shutdown():

        #拼接数据
        msg.data = msg_front + str(count)

        #发布数据
        pub.publish(msg)
        rospy.loginfo("发出的数据是%s",msg.data)
        rate.sleep()
        count += 1
