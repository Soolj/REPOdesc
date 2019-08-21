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
        Quaternion &q = *this;
        q(0) = 1;
        q(1) = 0;
        q(2) = 0;
        q(3) = 0;
    }

    /**
     * Constructor from Matrix41
     *
     * @param other Matrix41 to copy
     */
    Quaternion(const Matrix41 &other) :
        Vector<Type, 4>(other)
    {
    }

    /**
     * Constructor from dcm
     *
     * Instance is initialized from a dcm representing coordinate transformation
     * from frame 2 to frame 1.
     *
     * @param dcm dcm to set quaternion to
     */
    Quaternion(const Dcm<Type> &dcm) :
        Vector<Type, 4>()
    {
        Quaternion &q = *this;
        q(0) = Type(0.5) * Type(sqrt(Type(1) + dcm(0, 0) +
                                     dcm(1, 1) + dcm(2, 2)));
        q(1) = Type((dcm(2, 1) - dcm(1, 2)) /
                    (Type(4) * q(0)));
        q(2) = Type((dcm(0, 2) - dcm(2, 0)) /
                    (Type(4) * q(0)));
        q(3) = Type((dcm(1, 0) - dcm(0, 1)) /
                    (Type(4) * q(0)));
    }

    /**
     * Constructor from euler angles
     *
     * This sets the instance to a quaternion representing coordinate transformation from
     * frame 2 to frame 1 where the rotation from frame 1 to frame 2 is described
     * by a 3-2-1 intrinsic Tait-Bryan rotation sequence.
     *
     * @param euler euler angle instance
     */
    Quaternion(const Euler<Type> &euler) :
        Vector<Type, 4>()
    {
        Quaternion &q = *this;
        Type cosPhi_2 = Type(cos(euler.phi() / (Type)2.0));
        Type cosTheta_2 = Type(