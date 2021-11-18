#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/PoseStamped.h"
#include <tf2/LinearMath/Quaternion.h>

ros::Publisher publisher;
ros::Subscriber subscriber;

void callback(const std_msgs::Float64::ConstPtr& msg_angle){
  geometry_msgs::PoseStamped msg_rviz;

  msg_rviz.header.stamp = ros::Time::now();
  msg_rviz.header.frame_id = "map";

  msg_rviz.pose.position.x = 0;
  msg_rviz.pose.position.y = 0;
  msg_rviz.pose.position.z = 0;

  tf2::Quaternion q;
  q.setRPY(0,0,-msg_angle->data*M_PI/180.0);
  q.normalize();
  msg_rviz.pose.orientation.x = q.x();
  msg_rviz.pose.orientation.y = q.y();
  msg_rviz.pose.orientation.z = q.z();
  msg_rviz.pose.orientation.w = q.w();

  publisher.publish(msg_rviz);
  std::cout << "ok" << std::endl;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "angle2rviz");
  ros::NodeHandle n;

  publisher = n.advertise<geometry_msgs::PoseStamped>("/angle2rviz/rviz", 1);
  subscriber = n.subscribe("/angle2rviz/angle", 1, callback);
  ros::spin();

  return 0;
}
