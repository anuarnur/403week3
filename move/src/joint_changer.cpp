#include "ros/ros.h"
#include <std_msgs/Float64.h>
#include "math.h"
double current_goal;
void checkerCallback(std_msgs::Float64 goal)
{
  if (goal.data > current_goal){
    ROS_INFO("sending goal: [%f]", goal.data);
    current_goal=goal.data;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "joint_changer");
  ros::NodeHandle n;
  current_goal=0;
  ros::Publisher pub = n.advertise<std_msgs::Float64>("/robot/joint4_position_controller/command", 1000);
  ros::Subscriber sub = n.subscribe("checker", 1000, checkerCallback);
  
  ros::Rate loop_rate(10);
   while (ros::ok())
  {
    std_msgs::Float64 msg;
    msg.data = current_goal;
    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }
  // ros::spin();
  return 0;
}
