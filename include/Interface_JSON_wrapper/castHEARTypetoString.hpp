#pragma once

#include "HEAR_core/DataTypes.hpp"
#include "HEAR_core/Vector3D.hpp"

namespace HEAR {


template <typename T> std::string castHEARTypetoString() 
{ 
    throw std::runtime_error("Invalid castHEARTypetoString function signature");
}

template <> std::string castHEARTypetoString<PID_parameters>() 
{ 
    return "PID_parameters";
}

template <> std::string castHEARTypetoString<MRFT_parameters>() 
{ 
    return "MRFT_parameters";
}

template <> std::string castHEARTypetoString<BoundingCtrl_parameters>() 
{ 
    return "BoundingCtrl_parameters";
}

template <> std::string castHEARTypetoString<Trajectory_parameters>() 
{ 
    return "Trajectory_parameters";
}

template <> std::string castHEARTypetoString<float>() 
{ 
    return "float";
}

template <> std::string castHEARTypetoString<int>() 
{ 
    return "int";
}

template <> std::string castHEARTypetoString<bool>() 
{ 
    return "bool";
}

template <> std::string castHEARTypetoString<std::vector<float>>() 
{ 
    return "std::vector<float>";
}

template <> std::string castHEARTypetoString<Vector3D<float>>() 
{ 
    return "Vector3D<float>";
}

}
