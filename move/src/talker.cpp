#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "math.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;
  ros::Publisher checker_pub = n.advertise<std_msgs::Float64>("checker", 1000);
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::Float64 msg;
    msg.data = 2.0;

    ROS_INFO("%f", msg.data);


    checker_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
