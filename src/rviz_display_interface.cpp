//
// Created by root on 18-6-20.
//

#include <rviz_display_interface.h>
#include <tf/tf.h>


void DisplayInterface::displayPose(const Pose &pose) {
    //account 0.1
    geo_pose.pose.position.x = pose.x() * 0.1;
    geo_pose.pose.position.y = pose.y() * 0.1;
    geo_pose.pose.position.z = 0.0;
    geo_pose.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);
    geo_pose.header.frame_id = "map";
    int* p = new int(10);
}

void DisplayInterface::displayMap(const Map &map,const Plan &cover) {
    int width = map.width();
    int height = map.height();
    ROS_INFO("width = %d,height = %d\n,map cell size = %d",width,height,map.mapcell_size());

    occ_grid.info.resolution = 0.1;
    occ_grid.info.width = width;
    occ_grid.info.height = height;
    occ_grid.data.resize(width * height,-1);
    for (int i = 0; i < map.mapcell_size(); ++i) {
        const MapCell map_cell = map.mapcell(i);
        int x = map_cell.x();
        int y = map_cell.y();
        if(map_cell.value() == MapCell_Value_FREE){
            occ_grid.data[x + y * width] = 0;
        }else if(map_cell.value() == MapCell_Value_OBSTACLE){
            occ_grid.data[x + y * width] = 100;
        }
    }
    for (int i = 0; i < cover.point_size(); ++i) {
        int map_x = cover.point(i).x();
        int map_y = cover.point(i).y();
        ROS_INFO("covered %d ,x = %d,y = %d\n",i,map_x,map_y);
        occ_grid.data[map_x + map_y * width] = 50;
    }

}

void DisplayInterface::displayPlan(const Plan &plan) {
    nav_msgs::Path path;
    for (int i = 0; i < plan.point_size(); ++i) {
        ROS_INFO("plan %d ,x = %d,y = %d\n",i,plan.point(i).x(),plan.point(i).y());
        geometry_msgs::PoseStamped pose;
        pose.pose.position.x = plan.point(i).x() * 0.1;
        pose.pose.position.y = plan.point(i).y() * 0.1;
        pose.pose.position.z = 0.0;
        pose.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);
        pose.header.frame_id = "map";
        path.poses.push_back(pose);
    }
}

void DisplayInterface::displayPoint(const Point &point) {
    ROS_INFO("point x = %d,y = %d",point.x(),point.y());
    point_stamped.point.x = point.x();
    point_stamped.point.y = point.y();
    point_stamped.header.frame_id = "map";
}

void DisplayInterface::displayPath(const Pose& pose) {
    geometry_msgs::PoseStamped ros_pose;
    ros_pose.pose.position.x = pose.x() * 0.1;
    ros_pose.pose.position.y = pose.y() * 0.1;
    ros_pose.pose.position.z = 0.0;
    ros_pose.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);
    ros_pose.header.frame_id = "map";
    path.poses.push_back(ros_pose);
    ROS_INFO("path size = %d\n",path.poses.size());
    path.header.frame_id = "map";
}
