#pragma once

#include "HEAR_core/Block.hpp"
#include <string>

namespace HEAR {
template <typename T>
class JsonWrapperClient : public Block {
    AsyncInputPort<T>* inp;
    std::string name;
    WebSocketController* web_sckt; //TODO: remove JsonWrapperClient dependency on websocket
public:
    enum IP{INPUT_ASYNC};

    JsonWrapperClient(std::string _name,InterfaceController* io_ctrl){
        web_sckt=io_ctrl;
        this->updateInstanceDescription(_name);
        name=_name;
        inp=createAsyncInputPort<T>(IP::INPUT_ASYNC, "Input");
    }
    
    void process() override {

    }
    void processAsync() override {
        if (inp->wasUpdated_AsyncIP()){
            // One: cast data to json
            // Two: Wrap json with address
            // Three: write to controller
            T data;
            inp->read_AsyncIP(data);
        }
    }

    std::string getTypeDescription(){
        return "JsonWrapperClient";
    }


};

}