/**
 * @file Quaternion.hpp
 *
 * All rotations and axis systems follow the right-hand rule.
 *
 * In order to rotate a vector v by a righthand rotation defined by the quaternion q
 * one can use the following operation:
 * v_rotated = q^(-1) * [0;v] * q
 * where q^(-1) represents the inverse of the quaternion q.
 * The product z of two quaternions z = q1 * q2 represents an intrinsic rotation
 * in the order of first q1 followed by q2.
 * The first element of the quaternion
 * represents the real part, thus, a quaternion representing a zero-rotation
 * is defined as (1,0,0,0).
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
 * Quaternion class
 *
 * The rotation between two coordinate frames is
 * described by this class.
 */
template<typename Type>
class Quaternion : public Vector<Type, 4>
{
public:
    virtual ~Quaternion() {};

    typedef Matrix<Type, 4, 1> Matrix41;
    typedef Matrix<Type, 3, 1> Matrix31;

    /**
     * Constructor from array
     *
     * @param data_ array
     */
    Quaternion(const Type *data_) :
        Vector<Type, 4>(data_)
    {
    }

    /**
     * Standard constructor
     */
    Quaternion() :
        Vector<Type, 4>()
    {
        Q