#pragma once

#include "HEAR_core/DataTypes.hpp"
#include "HEAR_core/Vector3D.hpp"
#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include <std_srvs/SetBool.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Point.h>
#include <hear_msgs/set_bool.h>
#include <hear_msgs/set_int.h>
#include <hear_msgs/set_float.h>
#include <hear_msgs/set_point.h>
#include <hear_msgs/Update_Controller_Bounding.h>
#include <hear_msgs/Update_Controller_MRFT.h>
#include <hear_msgs/PID_param.h>
#include <hear_msgs/Update_Controller_PID.h>
#include <hear_msgs/Update_Trajectory.h>

namespace HEAR {

template <typename T,typename U> void castMsgToROS(T& data_from,U& data_to) 
{ 
    throw std::runtime_error("Invalid castMsgToROS function signature in ROSUnit_Client");
}

template <> void castMsgToROS<int,std_srvs::Empty>(int& data_from,std_srvs::Empty& data_to);

template <> void castMsgToROS<bool,hear_msgs::set_bool>(bool& data_from,hear_msgs::set_bool& data_to);

template <> void castMsgToROS<int,hear_msgs::set_int>(int& data_from,hear_msgs::set_int& data_to);

template <> void castMsgToROS<float,hear_msgs::set_float>(float& data_from,hear_msgs::set_float& data_to);

template <> void castMsgToROS<float,std_msgs::Float32>(float& data_from,std_msgs::Float32& data_to);

template <> void castMsgToROS<Vector3D<float>,hear_msgs::set_point>(Vector3D<float>& data_from,hear_msgs::set_point& data_to);

template <> void castMsgToROS<Vector3D<float>,geometry_msgs::Point>(Vector3D<float>& data_from,geometry_msgs::Point& data_to);

template <> void castMsgToROS<std::vector<float>,std_msgs::Float32MultiArray>(std::vector<float>& data_from,std_msgs::Float32MultiArray& data_to);

template <> void castMsgToROS<BoundingCtrl_parameters,hear_msgs::Update_Controller_Bounding>(BoundingCtrl_parameters& data_from,hear_msgs::Update_Controller_Bounding& data_to);

template <> void castMsgToROS<MRFT_parameters,hear_msgs::Update_Controller_MRFT>(MRFT_parameters& data_from,hear_msgs::Update_Controller_MRFT& data_to);

template <> void castMsgToROS<PID_parameters,hear_msgs::Update_Controller_PID>(PID_parameters& data_from,hear_msgs::Update_Controller_PID& data_to) ;

template <> void castMsgToROS<Trajectory_parameters,hear_msgs::Update_Trajectory>(Trajectory_parameters& data_from,hear_msgs::Update_Trajectory& data_to) ;




template <typename T,typename U> void castMsgFromROS(T& data_from,U& data_to) 
{ 
    throw std::runtime_error("Invalid castMsgFromROS function signature in ROSUnit_Client");
}

}
// template <typename T> 
// void castMsgToROS(T& data_from) 
// { 
//     throw std::runtime_error("Invalid castMsgToROS function signature in ROSUnit_Client");
//     }
// template <> std_srvs::Empty castMsgToROS<void>(void& data_from) 
// { 
//     std_srvs::Empty msg;
//     return msg;
// }

// template <> hear_msgs::set_bool castMsgToROS<bool>(bool& data_from) 
// { 
//     hear_msgs::set_bool msg;
//     msg.request.data = data_from; 
//     return msg;
// }

