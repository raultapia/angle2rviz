# angle2rviz
The node subscribes to `/angle2rviz/angle` topic and waits for messages of type `std_msgs::Float64`.

The node publishes into `/angle2rviz/rviz` messages of type `geometry_msgs::PoseStamped`.
