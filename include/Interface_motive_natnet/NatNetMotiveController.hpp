#pragma once
#include "Interface_core/InterfaceController.hpp"
#include "natnet/natnet_optitrack.hpp"
#include "HEAR_core/SharedMemory.hpp"
#include "HEAR_core/Threaded.hpp"
#include "HEAR_core/CallbackG.hpp"
#include "Interface_motive_natnet/NatNetMotive_Subscriber.hpp"

#include <string>
#include <vector>
#include <unordered_map>

namespace HEAR{

class NatNetMotiveController: public InterfaceController , public CallbackG<char*> {
private:
SharedMemory<std::vector<OptiTrackRigidBodyData>> rigid_bodies_shmem;
std::unordered_map<int,CallbackG<OptiTrackRigidBodyData>*> list_of_subscribers; //the key is the rigid_body id


public:

NatNetMotiveController();

void Update() override; //Process the data received from the callback and give it to corresponding subscriber


void registerSubscriber(int id,CallbackG<OptiTrackRigidBodyData>* subscriber);

void callbackPerform(char* data) override;

~NatNetMotiveController();
    
};
}