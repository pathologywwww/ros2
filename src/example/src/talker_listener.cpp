#include "example/topic/talker.hpp"
#include "example/topic/listener.hpp"
#include<iostream>
#include<iostream>
#include<memory>
using namespace std;
using namespace demo;
using namespace demo2;

int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);
    rclcpp::executors::SingleThreadedExecutor executor;
    auto talker =std::make_shared<Talker>("talker");
    auto listener =std::make_shared<Listener>("listener");


    executor.add_node(talker);
    executor.add_node(listener);
    executor.spin();
    return 0;
}