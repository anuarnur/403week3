#include "ros/ros.h"
#include <std_msgs/Float64.h>
#include "math.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_step");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::Float64>("/robot/joint5_position_controller/command", 1000);
  
  ros::Rate loop_rate(10);
  double startTime = ros::Time::now().toSec();
  double value=0.0;
  while (ros::ok())
  {
    std_msgs::Float64 msg;
    double time_now = ros::Time::now().toSec();
    double time_diff = time_now-startTime;
    if (time_diff>=4.0) {
      if (value==0.0) value=1.0;
      else value=0.0;
      startTime = ros::Time::now().toSec();
    } 
    msg.data = value;
    ROS_INFO("%f", time_diff);
    ROS_INFO("%f", msg.data);
    pub.publish(msg);
    ros::spinOnce();

    loop_rate.sleep();
  }
  // ros::spin();
  return 0;
}
