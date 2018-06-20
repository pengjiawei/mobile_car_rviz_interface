#include <iostream>
#include <cpr/cpr.h>
#include <pose.pb.h>
int main() {
    auto response = cpr::Get(cpr::Url{"http://47.106.88.219:8080/pose"});
    Pose pose;
    pose.ParseFromString(response.text);
    printf("%d,%d\n",pose.x(),pose.y());
    std::cout << "Hello, World!" << std::endl;
    return 0;
}