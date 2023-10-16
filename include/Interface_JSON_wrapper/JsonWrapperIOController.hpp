#pragma once
#include <tuple>
#include <string>

#include "Interface_core/InterfaceController.hpp"
#include "HEAR_core/CallbackG.hpp"
#include "HEAR_core/CallerKeyed.hpp"
#include "sync_io_drivers/IOWriter.hpp"

namespace HEAR{
class JsonWrapperIOController: public InterfaceController, public CallbackG<std::tuple<size_t,char*>> {
private:
IOWriter* io_writer;
JsonWrapperIOController() {}
public:

void Update() override {

}

void callbackPerform(const std::tuple<size_t,char*> data_received) override{
    //Implement
    // auto json_data=convertToJson(std::get<0>(data_received),std::get<1>(data_received)); 

}

void writeJsonToIO(std::string json_payload){
    io_writer->writeData(json_payload.size(),json_payload.c_str());
}

JsonWrapperIOController(IOWriter* io_writer_para) : io_writer(io_writer_para) {}

~JsonWrapperIOController(){}

};
}