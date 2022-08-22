cmake_minimum_required(VERSION 3.8)
project(captain)

if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(captain
        src/captain.cpp
        include/captain.h
        src/main.cpp
        )

install(
        DIRECTORY launch
        DESTINATION share/${PROJECT_NAME}
        )
toto
ament_target_dependencies(captain rclcpp std_msgs)

install(TARGETS
        captain
        DESTINATION lib/${PROJECT_NAME})

ament_package()
