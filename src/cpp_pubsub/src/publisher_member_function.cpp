#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"     // CHANGE

using namespace std::chrono_literals;

class Captain
		: public rclcpp::Node
{
public:
	Captain() : Node("minimal_publisher")
				, m_count(0)
	{
		m_publisher = this->create_publisher<tutorial_interfaces::msg::Num>("topic", 10);    // CHANGE
		m_timer     = this->create_wall_timer(500ms, std::bind(&Captain::timer_callback, this));
	}

private:
	void timer_callback()
	{
		auto message = tutorial_interfaces::msg::Num();                               // CHANGE
		message.num = this->m_count++;                                        // CHANGE
		RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.num);    // CHANGE
		m_publisher->publish(message);
	}

	rclcpp::TimerBase::SharedPtr                                m_timer;
	rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr m_publisher;         // CHANGE
	size_t m_count;
};

int main(int argc, char * argv[])
{
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<Captain>());
	rclcpp::shutdown();
	return 0;
}
