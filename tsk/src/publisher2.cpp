#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
    ros::init(argc, argv, "Publisher2");
    ros::NodeHandle n2;
    ros::Publisher pub =n2.advertise<std_msgs::String>("rata", 1000);
    ros::Rate loop_rate(10);
    cout << "Node has been initialised\n";
    while (ros::ok())
    {
        std_msgs::String msg;
        string message;
        cout << "Ready to take input\n";
        getline(cin, message);
        cout << "\" " << message << " \""
             << " will be sent\n";
        msg.data = message;
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}