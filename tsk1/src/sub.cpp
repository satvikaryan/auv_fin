    #include "ros/ros.h"
    #include "std_msgs/String.h"
    #include <sstream>
    #include <iostream>
    #include <cstdio>
    #include <bits/stdc++.h>
    #include <string>
    using namespace std;
 
     void chatterCallback(const std_msgs::String::ConstPtr& msg)
     {
       cout<<("input: [%s]", msg->data.c_str())<<endl;
     }
    
     int main(int argc, char **argv)
     {
        std::string username;
        std::cout << "Enter your username: ";
        std::getline(std::cin, username);
        ros::init(argc, argv,username);
        std::string topic;
        std::cout << "Enter your topic: ";
        std::getline(std::cin, topic);
    
        ros::NodeHandle n;
    

        ros::Subscriber sub = n.subscribe(topic, 1000, chatterCallback);
  
        ros::spin();
    
        return 0;
     }