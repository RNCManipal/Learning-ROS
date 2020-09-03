
//This prog publishes randomly-generated velocity msg for turtlesim

#include <ros/ros.h>
#include <geometry_msgs/Twist.h> //For geometry msgs :: Twist
#include <stdlib.h> //For rand() and RAND_MAX

int main (int argc, char **argv) {

	// Initialize the ROS system and become a node .
	ros::init(argc, argv, "publish_velocity") ;

	ros::NodeHandle nh ;

	// Create a publisher object.
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>(
	"turtle1/cmd_vel" , 1000);

	// Seed the random number generator .
	srand(time(0));

	// Loop at 2Hz until the node is shut down.
	ros::Rate rate(2);
	while (ros::ok()) {
		// Create and fill in the message. The other four
		// fields, which are ignored by turtlesim , default to 0.
		geometry_msgs::Twist msg ;
		msg.linear.x=double(rand())/double(RAND_MAX); //sets linear ve bw 0 and 1
		msg.angular.z=2*double(rand())/double(RAND_MAX)-1;  //sets linear vel bw -1 and 1

		// Publish the message .
		pub.publish(msg);
		//adds msgs to publisher's outgoing queue

		// Send a message to rosout with the details.
		// ROS_INFO_STREAM("Sending ␣random␣ velocity ␣command : "
		// << " ␣ l i n e a r=" << msg . l i n e a r . x
		// << " ␣ a n g u l a r=" << msg . a n g u l a r . z ) ;

		// Wait until it's time for another iteration.
		rate.sleep();

	}

}