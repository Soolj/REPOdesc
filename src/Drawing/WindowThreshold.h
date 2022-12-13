#pragma once

// "Absolute threshold" trigger/detector
// Detects if the absolute value of a signal goes below a certain threshold for at least a given time
// and plots the detection point (different color if quiet time met) 

#include "BaseAnalyzer.h"

class WindowThreshold : public BaseAnalyzer
{
public:
  WindowThreshold(string var, float thresh, float minWindow)
  {
    _var = var;
    _thresh = thresh;
    _minWindow = minWindow;
    _lastTime = 0;
    Reset();
  }

  void Reset()
  {
    if (_lastTime != 0)
    {
      if (_active)
      {
 