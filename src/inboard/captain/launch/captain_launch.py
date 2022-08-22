from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="captain",
            executable="captain",
            name="captain",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"vna_name": "vna 1/1"}
            ]
        )
    ])
/opt/ros/humble/bin/ros2 launch captain captain_launch.py
