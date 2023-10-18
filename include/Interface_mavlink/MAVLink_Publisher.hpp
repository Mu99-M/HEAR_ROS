#pragma once

#include <sstream>
#include "HEAR_core/DataTypes.hpp"
#include "HEAR_core/Port.hpp"

#include "Interface_mavlink/MAVLinkController.hpp"

namespace HEAR{

template <typename T>
class MAVLink_Publisher : public Block {
private:
    MAVLinkController* if_ctrl;
    uint8_t system_id,component_id;
protected:
    InputPort<T>* _input_port;

public:
    enum IP {INPUT};
    MAVLink_Publisher(MAVLinkController* if_ctrl_para,std::string uri ,uint8_t system_id_para,uint8_t component_id_para) {
        if_ctrl=if_ctrl_para;
        std::stringstream string_inst;
        string_inst << uri <<", Sys id: "<<system_id_para <<", Comp id:" << component_id_para; 
        this->updateInstanceDescription(string_inst.str());
        _input_port=this->createInputPort<T>(IP::INPUT,"INPUT");
        this->block_att->block_func=BlockNodeAttributes::Sink;
    }
    void process() override{
        mavlink_message_t msg;
        T buff;
        ((InputPort<T>*)_input_port)->read(buff);
        serializeMessage(buff,system_id, component_id, msg);
        if_ctrl->writeMAVLinkMsgToIO(msg);
    }

    void processAsync() override{}

    void reset() override{}

    std::string getTypeDescription(){
        return "MAVLink_Publisher";
    }


};

}