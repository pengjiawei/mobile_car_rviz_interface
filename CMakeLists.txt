cmake_minimum_required(VERSION 3.9)
project(mobile_car_rviz_interface)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(cpr)

add_executable(mobile_car_rviz_interface main.cpp)