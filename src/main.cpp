#include <stdio.h>
#include <ros/ros.h>
#include <queue>
#include <boost/thread.hpp>
#include <nav_msgs/Path.h>

using namespace std;

#include "AGVCallBack.h"

int main(int argc, char** argv) {

	ros::init(argc, argv, "top");

    ros::NodeHandle nh("~");
    
    // recipelab cmd_vel topic
    ros::Subscriber rcpl_cmd_vel_sub = nh.subscribe("/recipelab/cmd_vel", 10, rcplCmdvelCallBack);

    // vel topic
    ros::Publisher vel_pub = nh.advertise<mecanum::WrapTwist>("/mecanum/md_vel_topic", 10);

    mecanum::WrapTwist wrapTwist;
	    
    ros::Rate maintimer(1000);
    ros::Time ts_now = ros::Time::now();

    while(ros::ok()){
        if (rcpl_cmd_vel_flag) {
            rcpl_cmd_vel_flag = 0;
            wrapTwist.header.stamp = ros::Time::now();
            wrapTwist.twist = rcpl_cmd_vel_.twist;
            vel_pub.publish(wrapTwist);
        }

    	ros::spinOnce();
    	maintimer.sleep();
    }

    return 0;
}