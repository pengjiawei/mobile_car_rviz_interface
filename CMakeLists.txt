cmake_minimum_required(VERSION 3.9)
project(mobile_car_rviz_interface)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(cpr)


#for http and protobuf
find_package(Protobuf REQUIRED)

#for ros
find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        geometry_msgs
        std_msgs
        )
catkin_package(
        CATKIN_DEPENDS
        roscpp
        geometry_msgs
)

include_directories(${CPR_INCLUDE_DIRS} )
include_directories(${catkin_INCLUDE_DIRS})
include_directories(include)

add_executable(mobile_car_rviz_interface main.cpp src/pose.pb.cc src/rviz_display_interface.cpp)
target_link_libraries(mobile_car_rviz_interface ${CPR_LIBRARIES} ${Protobuf_LIBRARIES} ${catkin_LIBRARIES})
