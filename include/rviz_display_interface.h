//
// Created by root on 18-6-20.
//

#ifndef MOBILE_CAR_RVIZ_INTERFACE_RVIZ_DISPLAY_INTERFACE_H
#define MOBILE_CAR_RVIZ_INTERFACE_RVIZ_DISPLAY_INTERFACE_H

//ros
#include <ros/node_handle.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/OccupancyGrid.h>
//proto
#include <pose.pb.h>
#include <map.pb.h>
class DisplayInterface {
public:
    DisplayInterface(ros::NodeHandle nh = ros::NodeHandle("~")) : nh_(nh){
        //rviz can only subscribe PoseStamped
        pose_publisher = nh_.advertise<geometry_msgs::PoseStamped>("Pose",1);
        map_publisher = nh_.advertise<nav_msgs::OccupancyGrid>("Map",1);
        //the same
    }

    virtual ~DisplayInterface(){
        ROS_INFO("reset");
        reset();
    }

    void displayPose(const Pose& pose);
    void displayMap(const Map& map);
    void update(){
        pose_publisher.publish(geo_pose);
        map_publisher.publish(occ_grid);
    }
    void reset(){
        pose_publisher.publish(geometry_msgs::PoseStamped());
        map_publisher.publish(nav_msgs::OccupancyGrid());
    }
private:
    ros::Publisher pose_publisher;
    ros::Publisher map_publisher;
//    const std::string scan_topic_name,pose_topic_name,pose_covariance_topic_name,point_topic_name;
    ros::NodeHandle nh_;

    geometry_msgs::PoseStamped geo_pose;
    nav_msgs::OccupancyGrid occ_grid;
};

#endif //MOBILE_CAR_RVIZ_INTERFACE_RVIZ_DISPLAY_INTERFACE_H