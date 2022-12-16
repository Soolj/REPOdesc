// Vector, 3-Doubles, super-lightweight-robotics library
// 2003-2018 sergei lupashin
// License: BSD-3-clause

#pragma once

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>
#include "MathUtils.h"
#include <limits>
#include <string>
using namespace std;

#define NULL_VECTOR_D V3D(0.0,0.0,0.0)

inline void normalize_3(double* v){
  double mag = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
  v[0] /= mag;
  v[1] /= mag;
  v[2] /= mag;
}

#pragma pack(push,1)

class V3D{
public:
  double x,y,z;
  V3D():x(0),y(0),z(0){};
	V3D(const int v):x(v),y(v),z(v){};
	V3D(const double v):x(v),y(v),z(v){};
  V3D(const double X, const double Y, const double Z):x(X),y(Y),z(Z){};
	V3D(const double* d):x(d[0]),y(d[1]),z(d[2]){};
  V3D(const float* d):x(d[0]),y(d[1]),z(d[2]){};
#ifdef BOOST_MSVC
	V3D(const boost::numeric::ublas::bounded_vector<double,3>& d):x(d(0)),y(d(1)),z(d(2)){};
	V3D(const boost::numeric::ublas::bounded_vector<float,3>& d):x(d(0)),y(d(1)),z(d(2)){};
#endif
  
  inline V3D operator+(const V3D b) const{    return V3D(x+b.x,y+b.y,z+b.z);  };
  inline V3D operator*(const V3D b) const{    return V3D(x*b.x,y*b.y,z*b.z);  };
  inline V3D operator/(const V3D b) const{    return V3D(x/b.x,y/b.y,z/b.z);  };
  inline V3D operator-(const V3D b) const{    return V3D(x-b.x,y-b.y,z-b.z);  };
  
  inline V3D operator+(const double b) const{    return V3D(x+b,y+b,z+b);  };
  inline V3D operator*(const double b) const{    return V3D(x*b,y*b,z*b);  };
  inline V3D operator/(const double b) const{    return V3D(x/b,y/b,z/b);  };
  inline V3D operator-(const double b) const{    return V3D(x-b,y-b,z-b);  };

  inline bool operator==(const V3D& b) const{ return (b.x==x && b.y==y && b.z==z);}
  inline bool operator!=(const V3D& b) const{ return (b.x!=x || b.y!=y || b.z!=z);}
	inline bool operator>(const V3D& b) const{ return (b.x>x || b.y>y || b.z>z);}
	inline bool operator<(const V3D& b) const{ return (b.x<x || b.y<y || b.z<z);}

  inline V3D operator/=(const V3D b){ *this = *this / b; return *this;}
  inline V3D operator*=(const V3D b){ *this = *this * b; return *this;}
  inline V3D operator+=(const V3D b){ *this = *this + b; return *this;}
  inline V3D operator-=(const V