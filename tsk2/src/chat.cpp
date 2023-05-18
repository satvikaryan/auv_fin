#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <iostream>

using namespace std;
std::string user;

// ros::NodeHandle nh;
ros::Publisher pub ;//= nh.advertise<std_msgs::String>("chat_topic", 1000);;

void messageCallback(const std_msgs::String::ConstPtr& msg)
{
  cout<<("[%s] Received message: %s", user.c_str(), msg->data.c_str())<<endl;
}

void sendMessage(const std::string& message)
{
  std_msgs::String msg;
  msg.data = "[" + user + "] " + message;
  pub.publish(msg);
}

int main(int argc, char** argv)
{
  std::string username;
  std::cout << "Enter your username: ";
  std::getline(std::cin, username);
  user = username;

  ros::init(argc, argv, user);
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("chat_topic", 1000, messageCallback);
  pub = nh.advertise<std_msgs::String>("chat_topic", 1000);

  ros::Rate loop_rate(10);

  

  while (ros::ok())
  {
    std::string message;
    std::cout << "[" << user << "] Enter your message: ";
    std::getline(std::cin, message);
    sendMessage(message);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}