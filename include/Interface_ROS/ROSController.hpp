#pragma once
#include "ros/ros.h"
#include "Interface_core/InterfaceController.hpp"

namespace HEAR{
class ROSController: public InterfaceController {
public:
ros::NodeHandle nh;
ros::NodeHandle pnh;
bool en_ros_nodelet=false;
void Update() override {
    if (!en_ros_nodelet){
        ros::spinOnce();
    }
}

ROSController(ros::NodeHandle &_nh,ros::NodeHandle &_pnh) : nh(_nh), pnh(_pnh){}

~ROSController(){}

};
}