#pragma once
#include "Interface_core/InterfaceController.hpp"
#include "HEAR_core/Threaded.hpp"

#include <string>

namespace HEAR{
template <typename T>
class WebSocketController: public InterfaceController, public Threaded {
    const int polling_period_us_default=100000;//Poll once every 100 ms by default
    int polling_period_us=polling_period_us_default; 
public:
void Update() override {
    
}

void WritePayload(T data){
    
}

WebSocketController(int polling_period_us_para=polling_period_us_default){ // <- add WebSocket parameters here and store them as local variables
    this->spawn();
    polling_period_us=polling_period_us_para;
    this->startPeriodicRun(polling_period_us);
}


void initLogic() override{
    // implement the code that starts the WebSocket here
}

void runOnceLogic() override{ // implement the WebSocket read/write logic here

}

~WebSocketController(){}

};
}