#include "Interface_JSON_wrapper/castHEARtoJson.hpp"

namespace HEAR{

template <> void castHEARtoJson<PID_parameters>(json& j,PID_parameters& data) 
{ 
    std::tie(j["id"], j["kp"], j["ki"], j["kd"], j["kdd"], j["anti_windup"], j["dt"], j["en_pv_derivation"]) = 
    std::make_tuple(data.id,data.kp,data.ki,data.kd,data.kdd,data.anti_windup,data.dt,(int)data.en_pv_derivation);
}
template <> void castHEARtoJson<BoundingCtrl_parameters>(json& j,BoundingCtrl_parameters& data) 
{ 
    std::tie(j["id"], j["eps_1"], j["eps_2"], j["h_o1"], j["h_o2"]) = 
    std::make_tuple(data.id,data.eps_1,data.eps_2,data.h_o1,data.h_o2);
}

template <> void castHEARtoJson<MRFT_parameters>(json& j,MRFT_parameters& data) 
{
    std::tie(j["id"], j["beta"], j["relay_amp"], j["no_switch_delay_in_ms"], j["num_of_peak_conf_samples"]) = 
    std::make_tuple(data.id,data.beta,data.relay_amp,data.no_switch_delay_in_ms,data.num_of_peak_conf_samples);
}

template <> void castHEARtoJson<Trajectory_parameters>(json& j,Trajectory_parameters& data) 
{
    std::tie(j["_trajectoryType"], j["_samplingType"], j["_transformationType"], j["scale"], j["rot"], j["trans"], j["TotalExecutionTime"], j["Velocity"],j["ClearQ"]) = 
    std::make_tuple(data._trajectoryType,data._samplingType,data._transformationType,
    data.scale,data.rot,data.trans,
    data.TotalExecutionTime,data.Velocity,data.ClearQ);
}

}