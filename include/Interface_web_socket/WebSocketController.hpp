#pragma once
#include "Interface_core/InterfaceController.hpp"

#include <string>

namespace HEAR{
class WebSocketController: public InterfaceController {
public:
void Update() override {

}

void WriteString(std::string data){
    
}

WebSocketController(){

}

~WebSocketController(){}

};
}