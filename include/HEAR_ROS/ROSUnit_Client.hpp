#ifndef ROSUNIT_CLIENT_HPP
#define ROSUNIT_CLIENT_HPP

#include <ros/ros.h>
#include "HEAR_core/Block.hpp"
#include "HEAR_core/DataTypes.hpp"

namespace HEAR{

template <typename T,typename U>
class ROSUnit_Client : public Block {
private:
    AsyncInputPort<T>* async_ip;
public:
    enum IP {INPUT_ASYNC};
    ros::ServiceClient m_client;

    ROSUnit_Client(ros::NodeHandle &nh, std::string t_name){
        m_client = nh.serviceClient<U>(t_name);
        async_ip=this->createAsyncInputPort<T>(IP::INPUT_ASYNC,"INPUT_ASYNC");
    }


    void process() override{}

    void processAsync() override{
        if (async_ip->wasUpdated_AsyncIP()){
            async_ip->_was_updated=false;
            U msg;
            T data;
            async_ip->read_AsyncIP(data);
            msg.request.data = data;
            m_client.call(msg);
        }
    }

    void reset() override{}

};
}

// template <typename T>
// class ROSUnit_Client {
// public:
//     T data;
//     ros::ServiceClient m_client;
//     virtual bool process() {return true;};
// };
// }

#endif