//
// Created by pat on 22/08/22.
//

#pragma once

#include <chrono>
using namespace std::chrono_literals;
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Captain
		: public rclcpp::Node
{
public:

	Captain();
	virtual ~Captain();

private:

	void timer_callback();

private:

	rclcpp::TimerBase::SharedPtr                        m_timer;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_publisher;
	size_t                                              m_count;
	std::string                                         m_vna_name;
};
