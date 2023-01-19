#ifndef MAGNETOMETER_H
#define MAGNETOMETER_H

#include <math.h>
#include "Common.h"
#include "Math/Random.h"
#include "Math/Quaternion.h"
#include "matrix/math.hpp"
#include <random>

class magnetometer
{
public:
  V3F mag;
  float fx_std