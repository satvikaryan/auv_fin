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
    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    ros::init(argc, argv, username);
    ros::NodeHandle nh;
    std::string topic;
    std::cout << "Enter your topic: ";
    std::getline(std::cin, topic);
    ros::Publisher pub =nh.advertise<std_msgs::String>(topic, 1000);
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