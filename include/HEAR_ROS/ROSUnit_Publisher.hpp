#pragma once

#include <ros/ros.h>
#include "HEAR_core/DataTypes.hpp"
#include "HEAR_core/Port.hpp"

namespace HEAR{

template <typename T, typename U>
class ROSUnit_Publisher : public Block {
protected:
    int id_; 
    ros::Publisher pub_;
    InputPort<T>* _input_port;

public:
    enum IP {INPUT};
    ROSUnit_Publisher(ros::NodeHandle& nh, const std::string& topic_name, int idx) {
        pub_ = nh.advertise<U>(topic_name, 10);
        _input_port=this->createInputPort<T>(IP::INPUT,"INPUT");
        id_ = idx; 
    }
    void process() override{
        U msg;
        ((InputPort<float>*)_input_port)->read(msg.data);
        pub_.publish(msg);
    }

    void processAsync() override{}

    void reset() override{}


};
}