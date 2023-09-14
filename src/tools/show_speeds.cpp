#include <ros/ros.h>
#include <turn_on_wheeltec_robot/Speed.h>
#include <fstream>

void speedCallback(const turn_on_wheeltec_robot::Speed::ConstPtr& msg)
{
    // 打开一个txt文件以追加保存speeds数据
    std::ofstream outFile("/home/glf/data/hefei/speeds.txt", std::ios::app);
    if (!outFile.is_open())
    {
        ROS_ERROR("无法打开文件以保存speeds数据.");
        return;
    }

    // 将speeds数据写入txt文件
    for (size_t i = 0; i < msg->speeds.size(); ++i)
    {
        outFile << msg->speeds[i] << " ";
    }
    outFile << "\n";  // 添加换行以区分不同的数据记录

    outFile.close();
    ROS_INFO("speeds数据已追加保存到speeds.txt文件.");
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "speed_subscriber_node");
    ros::NodeHandle nh;

    // 创建一个订阅器，订阅名为"/your_topic_name"的话题
    ros::Subscriber sub = nh.subscribe<turn_on_wheeltec_robot::Speed>("/fixposition/speed", 10, speedCallback);

    ros::spin();  // 进入ROS主循环，等待消息

    return 0;
}
