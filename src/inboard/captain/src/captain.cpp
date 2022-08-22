//
// Created by pat on 22/08/22.
//

#include "../include/captain.h"

Captain::Captain() : Node("captain")
					 , m_count(0)
{
	this->declare_parameter<std::string>("vna_name", "vna1");
	this->get_parameter("vna_name", m_vna_name);
	RCLCPP_INFO(this->get_logger(), "%s - Starting", m_vna_name.c_str());

	m_publisher = this->create_publisher<std_msgs::msg::String>("topic", 10);
	m_timer     = this->create_wall_timer(1s, std::bind(&Captain::timer_callback, this));
}

Captain::~Captain()
{
	RCLCPP_INFO(this->get_logger(), "%s - Stopping", m_vna_name.c_str());
}

void Captain::timer_callback()
{
	auto message = std_msgs::msg::String();
	message.data = "Hello, world! " + std::to_string(m_count++);
	RCLCPP_INFO(this->get_logger(), "%s - Publishing: '%s'", m_vna_name.c_str(), message.data.c_str());
	m_publisher->publish(message);
}
