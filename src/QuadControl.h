#pragma once


#include "Utility/StringUtils.h"
#include "Trajectory.h"
#include "BaseController.h"

class QuadControl : public BaseController
{
public:
  QuadControl(string config) : BaseController(config) { Init(); };

  virtual void Init();

  // returns a desired acceleration in global frame
  V3F LateralPositionControl(V3F posCmd, V3F velCmd, V3F pos, V3F vel, V3F accelC