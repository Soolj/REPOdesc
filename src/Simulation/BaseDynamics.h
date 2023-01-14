#pragma once

#include "Common.h"
#include "Math/Quaternion.h"
#include "VehicleDatatypes.h"
#include "DataSource.h"

#define VEHICLE_TYPE_QUAD              0

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4100) // unreferenced formal parameter
#endif

using SLR::Quaternion;
class Trajectory;

class BaseDynamics : public DataSource
{
public:
	BaseDynamics(string name="");
	virtual ~BaseDynamics() {}; // destructor

	virtual int Initialize();

  virtual void Run(float dt, float simulationTime, int &idum,  // updates the simula