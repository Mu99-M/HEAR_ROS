#pragma once

#include <ros/ros.h>
#include "HEAR_core/DataTypes.hpp"
#include "HEAR_core/Port.hpp"
#include "Interface_ROS/castMsgROSG.hpp"
#include "Interface_ROS/ROSController.hpp"

namespace HEAR{

template <typename T>
class MAVLink_Publisher : public Block {
protected:
    InputPort<T>* _input_port;

public:
    enum IP {INPUT};
    ROSUnit_Publisher(InterfaceController* if_ctrl, const std::string& topic_name) {
        this->updateInstanceDescription(topic_name);
        using ROS_type=typename ROSTopicTypeTranslator<T>::ROSType;
        ROSController* ros_ctrl = (ROSController*)if_ctrl;
        pub_ = ros_ctrl->nh.advertise<ROS_type>(topic_name, 10);
        _input_port=this->createInputPort<T>(IP::INPUT,"INPUT");
        this->block_att->block_func=BlockNodeAttributes::Sink;
    }
    void process() override{
        using ROS_type=typename ROSTopicTypeTranslator<T>::ROSType;
        ROS_type msg;
        T buff;
        ((InputPort<T>*)_input_port)->read(buff);
        castMsgToROS<T,ROS_type>(buff,msg);
        pub_.publish(msg);
    }

    void processAsync() override{}

    void reset() override{}

    std::string getTypeDescription(){
        return "ROSUnit_Publisher";
    }


};

}