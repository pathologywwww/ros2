#pragma once

#include "rclcpp/rclcpp.hpp"
#include<iostream>
#include"std_msgs/msg/string.hpp"

namespace demo
{
class Talker : public rclcpp::Node
{
    public:
    explicit Talker(const std::string& node_name)
    : Node(node_name)
    {
        auto pub_msg = [this]()->void
        {
            std::string msg="Hello:"+std::to_string(count_++);
            RCLCPP_INFO(this->get_logger(),"Pub:%s",msg.c_str());
            return;
        };
        timer_1 = this->create_wall_timer(std::chrono::seconds(1),pub_msg);
    }
    private:
    rclcpp::TimerBase::SharedPtr timer_1;
    int count_=1;
};
} // namespace democlass Talker : public 