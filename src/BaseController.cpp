#include "Common.h"
#include "BaseController.h"
#ifndef __PX4_NUTTX
#include "Utility/SimpleConfig.h"
#endif
#include "Utility/StringUtils.h"
using namespace SLR;

BaseController::BaseController(string config)
{
  _config = config;
  Init();
}

void BaseController::Init()
{
#ifndef __PX4_NUTTX
  ParamsHandle config = SimpleConfig::GetInstance();

  optFlowX = 0;
  optFlowY = 0;
  mass = config->Get(_config+".Mass", 1.f);
  L = config->Get(_config+".L", 0.1f);
  Ixx = config->Get(_config+".Ixx", 0.001f);
  Iyy = config->Get(_config + ".Iyy", 0.001f);
  Izz = config->Get(_config + ".Izz", 0.002f);
  kappa = config->Get(_config + ".kappa", 0.01f);

  trajectory.Clear();
  string trajFile = config->Get(_config + ".Trajectory","");
  if (!trajectory.ReadFile(string("../config/")+trajFile))
  {
    TrajectoryPoint tmp;
    tmp.position = config->Get(_config + ".Trajectory", V3F());
    trajectory.AddTrajectoryPoint(tmp);
  }
#else


#endif
}

void BaseController::Reset()
{
  // Reinitialise the physical parameters
  Init();
}

void BaseController::OnSensor_IMU(V3F accel, V3F gyros)
{
  // todo
}

void BaseController::OnSensor_OpticalFlow(float x, float y)
{
  optFlowX = x;
  optFlowY = y;
}

void BaseController::OnSensor_Range(float z)
{
  range = z;
}

// Allows the simulator to provid