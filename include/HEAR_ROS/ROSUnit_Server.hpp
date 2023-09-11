#pragma once

#include "HEAR_core/ExternalConnector.hpp"
#include "HEAR_core/castMsgHelperG.hpp"

namespace HEAR{

template <typename T, typename U>
class ROSUnit_Server : public Block{
private:
std::string topic_name;
ros::ServiceServer m_server;
AsyncOutputPort<T>* async_op;
public:
enum OP {OUTPUT_ASYNC};
ROSUnit_Server(ros::NodeHandle& nh_, std::string topic){
    this->setTopic(topic);
    m_server = nh_.advertiseService(topic, &ROSUnit_Server::callback, this);
    async_op=this->createAsyncOutputPort<T>(OP::OUTPUT_ASYNC,"OUTPUT_ASYNC");
}

typedef typename U::Request Request_para;
typedef typename U::Response Response_para;
bool callback(Request_para& req,Response_para& res)
{
    T data_to;
    castMsgHelper<Request_para,T>(req,data_to);
    async_op->write_AsyncOP(data_to);
    return true;
}

void setTopic(std::string topic){
    this->topic_name = topic;
}

void process() override{

}

void processAsync() override{

}

void reset() override{

}

};


}