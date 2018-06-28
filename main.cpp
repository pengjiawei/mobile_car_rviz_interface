#include <iostream>
#include <cpr/cpr.h>
#include <rviz_display_interface.h>

#ifdef DEBUG
    const std::string pose_url = "http://47.106.88.219:8080/pose";
    const std::string map_url = "http://47.106.88.219:8080/mymap";
    const std::string plan_url = "http://192.168.3.8:8080/plan";
    const std::string point_url = "http://192.168.3.8:8080/point";
#else
    const std::string pose_url = "http://192.168.3.11:8866/pose";
    const std::string map_url = "http://192.168.3.11:8866/mymap";
    const std::string plan_url = "http://192.168.3.11:8866/plan";
    const std::string point_url = "http://192.168.3.11:8866/point";
#endif

int main(int argc,char** argv) {
    std::string node_name = "display_interface";
    ros::init(argc,argv,node_name);
    DisplayInterface* displayInterface = new DisplayInterface();
    ros::Duration d(1);
    while(ros::ok()){
        auto pose_response = cpr::Get(cpr::Url{pose_url});
        Pose pose;
        pose.ParseFromString(pose_response.text);
        ROS_INFO("%d,%d\n",pose.x(),pose.y());

        auto map_response = cpr::Get(cpr::Url{map_url});
        Map map;
        map.ParseFromString(map_response.text);

        auto plan_response = cpr::Get(cpr::Url{plan_url});
        Plan plan;
        plan.ParseFromString(plan_response.text);
        ROS_INFO("plan size = %d",plan.point_size());

        auto point_response = cpr::Get(cpr::Url{point_url});
        Point point;
        point.ParseFromString(point_response.text);

        displayInterface->displayPose(pose);
        displayInterface->displayMap(map);
        displayInterface->displayPlan(plan);
        displayInterface->displayPoint(point);
        displayInterface->displayPath(pose);
        displayInterface->update();
        ros::spinOnce();
        d.sleep();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}