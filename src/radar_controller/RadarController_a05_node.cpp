#include "../../include/radar_controller/a05_radar.h"



int main(int argc, char** argv) {
    ros::init(argc, argv, "distance_monitor");
    ros::NodeHandle nh;
    ros::Publisher cmd_vel;
    geometry_msgs::Twist msg;
    ros::Rate loop_rate(20);

    RadarController_a05 radarController_a05;
    while (ros::ok)
    {
        if(!radarController_a05.getStop_flag()){
            msg.angular.z = 0;  // 设置正角速度以右转
            msg.linear.x = 0.3;
            cmd_vel.publish(msg);
        }
        ros::spinOnce();
        loop_rate.sleep();//以20Hz循环，循环跑太快就在这里睡一会儿
    }
    

    ros::spin();

    return 0;
}