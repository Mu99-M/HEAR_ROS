#pragma once

#include <ros/ros.h>
#include "HEAR_core/DataTypes.hpp"
#include "HEAR_core/Port.hpp"

namespace HEAR{

template <typename T, typename U>
class ROSUnit_Subscriber : public Block {
protected:
    int id_; 
    ros::Subscriber sub_;
    OutputPort<T>* _output_port;
public:
    enum OP {OUTPUT};

    // OutputPort<T>* getOutputPort() { return (OutputPort<T>*)_output_port;}


    ROSUnit_Subscriber(ros::NodeHandle& nh, const std::string& topic, int idx){
    sub_ = nh.subscribe<U>(topic, 10, &ROSUnit_Subscriber::callback, this);
    _output_port=this->createOutputPort<T>(OP::OUTPUT,"OUTPUT");
    id_ = idx;
    }

    typedef typename U::ConstPtr Sub_para;
    void callback(const Sub_para& msg){
        _output_port->write(msg->data);
    }

    void process() override{}

    void processAsync() override{}

    void reset() override{}


};
}

