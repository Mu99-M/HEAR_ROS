#include "Interface_motive_natnet/NatNetMotiveController.hpp"

namespace HEAR{


NatNetMotiveController::NatNetMotiveController(){
    
}


void NatNetMotiveController::Update() { //Process the data received from the callback and give it to corresponding subscriber
    for (auto it : *rigid_bodies_shmem.getSharedData()){
        this->callCallbackByKey(it.id,it);
    }
}

void NatNetMotiveController::callbackPerform(char* data){
    std::vector<OptiTrackRigidBodyData> rigid_bodies;
    Unpack((char*)data,rigid_bodies);
    rigid_bodies_shmem.writeSharedData(rigid_bodies);
}

NatNetMotiveController::~NatNetMotiveController(){
}
    

}