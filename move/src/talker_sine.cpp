#include "ros/ros.h"
#include <std_msgs/Float64.h>
#include "math.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_sine");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::Float64>("/robot/joint1_position_controller/command", 1000);
  
  //ros::Rate loop_rate(0.33);
  ros::Rate loop_rate(10);
  //double startTime = ros::Time::now().toSec();

  while (ros::ok())
  {
    std_msgs::Float64 msg;
    msg.data = sin(0.5*ros::Time::now().toSec());
    
    ROS_INFO("%f", msg.data);
    pub.publish(msg);
    ros::spinOnce();

    loop_rate.sleep();
  }
  // ros::spin();
  return 0;
}
