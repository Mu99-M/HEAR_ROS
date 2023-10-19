#include "Interface_JSON_wrapper/castJsonToHEAR.hpp"

namespace HEAR{

// template <> void castJsonToHEAR<PID_parameters>(json& j,PID_parameters& data) 
// { 
//     data.id=j["id"];
//     data.kp=j["kp"];
//     data.ki=j["ki"];
//     data.kd=j["kd"];
//     data.kdd=j["kdd"];
//     data.anti_windup=j["anti_windup"];
//     data.en_pv_derivation=j["en_pv_derivation"];
//     data.dt=j["dt"];
// }
// template <> void castJsonToHEAR<BoundingCtrl_parameters>(json& j,BoundingCtrl_parameters& data) 
// { 
//     data.id=j["id"];
//     data.eps_1=j["eps_1"];
//     data.eps_2=j["eps_2"];
//     data.h_o1=j["h_o1"];
//     data.h_o2=j["h_o2"];

// }

// template <> void castJsonToHEAR<MRFT_parameters>(json& j,MRFT_parameters& data) 
// { 
//     data.id=j["id"];
//     data.beta=j["beta"];
//     data.relay_amp=j["relay_amp"];
//     data.no_switch_delay_in_ms=j["no_switch_delay_in_ms"];
//     data.num_of_peak_conf_samples=j["num_of_peak_conf_samples"];
// }

// template <> void castJsonToHEAR<Trajectory_parameters>(json& j,Trajectory_parameters& data) 
// { 
//     data._trajectoryType=j["_trajectoryType"];
//     data._samplingType=j["_samplingType"];
//     data._transformationType=j["_transformationType"];
//     data.scale=j["scale"].get<std::vector<float>>();
//     data.rot=j["rot"].get<std::vector<float>>();
//     data.trans=j["trans"].get<std::vector<float>>();
//     data.TotalExecutionTime=j["TotalExecutionTime"];
//     data.Velocity=j["Velocity"];
//     data.ClearQ=j["ClearQ"];

// }


// template <> void castJsonToHEAR<float>(json& j,float& data,std::string _field_name) 
// { 
//     data=j[_field_name];
// }

// template <> void castJsonToHEAR<std::vector<float>>(json& j,std::vector<float>& data,std::string _field_name) 
// { 
//     data=j[_field_name].get<std::vector<float>>();
// }

}