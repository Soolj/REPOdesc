/**
 * @file AxisAngle.hpp
 *
 * @author James Goppert <james.goppert@gmail.com>
 */

#pragma once

#include "math.hpp"
#include "helper_functions.hpp"

namespace matrix
{

template <typename Type>
class Dcm;

template <typename Type>
class Euler;

template <typename Type>
class AxisAngle;

/**
 * AxisAngle class
 *
 * The rotation between two coordinate frames is
 * described by this class.
 */
template<typename Type>
class AxisAngle : public Vector<Type, 3>
{
public:
    virtual ~AxisAngle() {};

    typedef Matrix<Type, 3, 1> Matrix31;

    /**
     * Constructor from array
     *
     * @param data_ array
     */
    AxisAngle(const Type *data_) :
        Vector<Type, 3>(data_)
    {
    }

    /**
     * Standard constructor
     */
    AxisAngle() :
        Vector<Type, 3>()
    {
    }

    /**
     * Constructor from Matrix31
     *
     * @param other Matrix31 to copy
     */
    AxisAngle(const Matrix31 &other) :
        Vector<Type, 3>(other)
    {
    }

    /**
     * Constructor from quaternion
     *
     * This sets the instance from a quaternion representing coordinate transformation from
     * frame 2 to frame 1 where the rotation from frame 1 to frame 2 is described
     * by a 3-2-1 intrinsic Tait-Bryan rotation sequence.
     *
     * @param q quaternion
     */
    AxisAngle(const Quaternion<Type> &q) :
        Vector<Type, 3>()
    {
        AxisAngle &v = *this;
        Type ang = (Type)2.0f*acosf(q(0));
        Type mag = sinf(a