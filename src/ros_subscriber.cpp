#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
using namespace std;

class ROS_SUB {
	public:
		ROS_SUB();
		void exercise_cb (std_msgs::StringConstPtr data);

	private:
	ros::NodeHandle _nh;
	ros::Subscriber _exercise_sub ;
};

ROS_SUB::ROS_SUB() {
	_exercise_sub= _nh.subscribe ("/chatter", 1000, &ROS_SUB::exercise_cb, this);

}

void ROS_SUB::exercise_cb(std_msgs::StringConstPtr data) {
	cout<< "Data: "<< data->data << endl;

}


int main (int argc, char** argv) {

	ros::init(argc, argv, "ros_exercise_sub");
	ROS_SUB rs;
	ros::spin();
	return 0;
}

