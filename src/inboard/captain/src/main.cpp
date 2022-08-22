//
// Created by pat on 23/08/22.
//

#include "../include/captain.h"

int main(int _argc, char * _argv[])
{
	rclcpp::init(_argc, _argv);
	rclcpp::spin(std::make_shared<Captain>());
	rclcpp::shutdown();
	return 0;
}
