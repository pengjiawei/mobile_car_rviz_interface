#include <iostream>
#include <cpr/cpr.h>
#include <rviz_display_interface.h>
int main(int argc,char** argv) {
    std::string node_name = "display_interface";
    ros::init(argc,argv,node_name);
    DisplayInterface* displayInterface = new DisplayInterface();
    ros::Duration d(1);
    while(ros::ok()) {
        auto pose_response = cpr::Get(cpr::Url{"http://47.106.88.219:8080/pose"});
        Pose pose;
        pose.ParseFromString(pose_response.text);
        ROS_INFO("%d,%d\n",pose.x(),pose.y());
        auto map_response = cpr::Get(cpr::Url{"http://47.106.88.219:8080/mymap"});
        Map map;
        map.ParseFromString(map_response.text);

        displayInterface->displayPose(pose);
        displayInterface->displayMap(map);
        displayInterface->update();
        ros::spinOnce();
        d.sleep();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}