//
// Created by root on 18-6-20.
//

#include <rviz_display_interface.h>
#include <tf/tf.h>


void DisplayInterface::displayPose(const Pose &pose) {
    geo_pose.pose.position.x = pose.x();
    geo_pose.pose.position.y = pose.y();
    geo_pose.pose.position.z = 0.0;
    geo_pose.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);
    geo_pose.header.frame_id = "map";
}

void DisplayInterface::displayMap(const Map &map) {
    int width = map.width();
    int height = map.height();
    ROS_INFO("width = %d,height = %d\n,map cell size = %d",width,height,map.mapcell_size());

    occ_grid.info.resolution = 1;
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
}
