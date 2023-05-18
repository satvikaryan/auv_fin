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

       ros::init(argc, argv, "listener2");
    
       ros::NodeHandle n1;
    

        ros::Subscriber sub = n1.subscribe("rata", 1000, chatterCallback);
  
       ros::spin();
    
       return 0;
     }