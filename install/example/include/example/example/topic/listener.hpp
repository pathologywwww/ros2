#pragma once

#include "rclcpp/rclcpp.hpp"
#include<iostream>
#include"std_msgs/msg/string.h"


namespace demo2
{   
    class Listener : public rclcpp::Node
    {
        public :
        explicit Listener(const std::string& node_name)
        :Node(node_name)
        {
            auto msg2=[this]()->void
            {
                std::string msg="I can hear you:"+std::to_string(sum++);
                RCLCPP_INFO(this->get_logger(),"Pub:%s",msg.c_str());
                return;
            };
            timer_2=this->create_wall_timer(std::chrono::seconds(1),msg2);
        }
        private:
        rclcpp::TimerBase::SharedPtr timer_2;
        size_t sum=1;
    } ;
}