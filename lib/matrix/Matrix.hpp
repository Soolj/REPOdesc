/**
 * @file Matrix.hpp
 *
 * A simple matrix template library.
 *
 * @author James Goppert <james.goppert@gmail.com>
 */

#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#if defined(SUPPORT_STDIOSTREAM)
#include <iostream>
#include <iomanip>
#endif // defined(SUPPORT_STDIOSTREAM)

#include "math.hpp"

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

namespace matrix
{

template <typename Type, size_t M>
class Vector;

template<typename Type, size_t  M, size_t N>
class Matrix
{

public:

    Type _data[M][N];

    vir