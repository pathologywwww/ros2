#!/bin/bash
set -e

source /opt/ros/humble/setup.sh

eval "$(register-python-argcomplete3 ros2)"
eval "$(register-python-argcomplete3 colcon)"

#Set the default build type
BUILD_TYPE=RelWithDebInfo
colcon build \
        --cmake-args "-DCMAKE_BUILD_TYPE=$BUILD_TYPE" "-DCMAKE_EXPORT_COMPILE_COMMANDS=On" \
        -Wall -Wextra -Wpedantic \
        --parallel-workers 8

source install/setup.sh