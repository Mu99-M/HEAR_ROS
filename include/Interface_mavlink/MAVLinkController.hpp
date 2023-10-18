#pragma once
#include <tuple>
#include <string>

#include "Interface_core/InterfaceController.hpp"
#include "HEAR_core/CallbackG.hpp"
#include "HEAR_core/CallerKeyed.hpp"
#include "sync_io_drivers/IOWriter.hpp"

#include "mavlink.h"

namespace HEAR{
class MAVLinkController: public InterfaceController, public CallbackG<std::tuple<size_t,char*>> {
private:
IOWriter* io_writer;
MAVLinkController() {}
public:

void Update() override {

}

void callbackPerform(const std::tuple<size_t,char*> data_received) override{
    //Implement
    // auto json_data=convertToJson(std::get<0>(data_received),std::get<1>(data_received)); 

}

void writeMAVLinkMsgToIO(mavlink_message_t& msg){
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    int len = mavlink_msg_to_send_buffer(buffer, &msg);
    io_writer->writeData(len,(char*)buffer);
}

MAVLinkController(IOWriter* io_writer_para) : io_writer(io_writer_para) {}

~MAVLinkController(){}

};
}