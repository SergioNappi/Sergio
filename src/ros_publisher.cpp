#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
using namespace std;

int main (int argc, char **argv) {
	ros::init(argc,argv,"ros_exercise_publisher");
	ros::NodeHandle nh;
	ros::Publisher exercise_pub=nh.advertise<std_msgs::String>("/chatter",1000);
	
	string message;
	while (ros::ok()) {
		std_msgs::String msg;
		cout<< "Please, text your message: " ;
		getline (cin,message);
		msg.data=message;
		exercise_pub.publish(msg);
		
	}
	return 0;
}
