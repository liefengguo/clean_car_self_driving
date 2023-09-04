#include "udp_action.h"
#include <ros/ros.h>
#include <std_msgs/Bool.h>

class BoolSubscriber {
public:
    udp_action robot_action;

        // 初始化ROS节点和订阅者
    ros::NodeHandle nh;
    BoolSubscriber() {
        
        bool_subscriber = nh.subscribe("pump_app", 10, &BoolSubscriber::boolCallback, this);
    }

    void boolCallback(const std_msgs::Bool::ConstPtr& msg) {
        // 在这里处理接收到的消息，可以调用类的其他方法或执行其他操作
        if (msg->data) {
            robot_action.pump(1);
            ROS_INFO("Received true");
        } else {
            ROS_INFO("Received false");
            robot_action.pump(0);
        }
    }

private:
    ros::Subscriber bool_subscriber;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "bool_subscriber_node");

    BoolSubscriber bool_subscriber;

    // 进入ROS循环
    ros::spin();

    return 0;
}
