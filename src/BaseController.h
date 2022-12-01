#pragma once

#include <vector>
#include "DataSource.h"
#include "VehicleDatatypes.h"
#include "Trajectory.h"
using namespace SLR;
using namespace std;

#ifndef __PX4_NUTTX
class BaseController;
typedef shared_ptr<BaseController> ControllerHandle;
#endif

class BaseController : public DataSource
{
public:
  BaseController(string c