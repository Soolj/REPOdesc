#pragma once

#include "BaseDynamics.h"
#include "Math/V4D.h"
#include "BaseController.h"
#include <matrix/math.hpp>
#include "Math/LowPassFilter.h"
#include "Drawing/ColorUtils.h"
#include "Utility/FastDelegate.h"
using namespace fastdelegate;

class QuadDynamics;
typedef shared_ptr<QuadDynamics> QuadcopterHandle;

class QuadDynamics : public BaseDynamics
{
public:
	static QuadcopterHandle Create(string name, int cnt=0)
	{
		QuadcopterHandle ret(new QuadDynamics(name));
    float hue = (float)cnt*30.f;
    ret->color = HSVtoRGB(hue + 15.f, 1, 1);
		return ret;
	}

  QuadDynamics(string name="");
	virtual ~QuadDynamics() {}; // destructor
	virtual int Initialize();

  virtual void Run(float dt, float simulationTime