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
        Type cosTheta_2 = Type(cos(euler.theta() / (Type)2.0));
        Type cosPsi_2 = Type(cos(euler.psi() / (Type)2.0));
        Type sinPhi_2 = Type(sin(euler.phi() / (Type)2.0));
        Type sinTheta_2 = Type(sin(euler.theta() / (Type)2.0));
        Type sinPsi_2 = Type(sin(euler.psi() / (Type)2.0));
        q(0) = cosPhi_2 * cosTheta_2 * cosPsi_2 +
               sinPhi_2 * sinTheta_2 * sinPsi_2;
        q(1) = sinPhi_2 * cosTheta_2 * cosPsi_2 -
               cosPhi_2 * sinTheta_2 * sinPsi_2;
        q(2) = cosPhi_2 * sinTheta_2 * cosPsi_2 +
               sinPhi_2 * cosTheta_2 * sinPsi_2;
        q(3) = cosPhi_2 * cosTheta_2 * sinPsi_2 -
               sinPhi_2 * sinTheta_2 * cosPsi_2;
    }

    /**
     * Quaternion from AxisAngle
     *
     * @param aa axis-angle vector
     */
    Quaternion(const AxisAngle<Type> &aa) :
        Vector<Type, 4>()
    {
        Quaternion &q = *this;
        Type angle = aa.norm();
        Vector<Type, 3> axis = aa.unit();
        if (angle < (Type)1e-10) {
            q(0) = (Type)1.0;
            q(1) = q(2) = q(3) = 0;
        } else {
            Type magnitude = sinf(angle / 2.0f);
            q(0) = cosf(angle / 2.0f);
            q(1) = axis(0) * magnitude;
            q(2) = axis(1) * magnitude;
            q(3) = axis(2) * magnitude;
        }
    }


    /**
     * Constructor from quaternion values
     *
     * Instance is initialized from quaternion values representing coordinate
     * transformation from frame 2 to frame 1.
     * A zero-rotation quaternion is represented by (1,0,0,0).
     *
     * @param a set quaternion value 0
     * @param b set quaternion value 1
     * @param c set quaternion value 2
     * @param d set quaternion value 3
     */
    Quaternion(Type a, Type b, Type c, Type d) :
        Vector<Type, 4>()
    {
        Quaternion &q = *this;
        q(0) = a;
        q(1) = b;
        q(2) = c;
        q(3) = d;
    }

    /**
     * Quaternion multiplication operator
     *
     * @param q quaternion to multiply with
     * @return product
     */
    Quaternion operator*(const Quaternion &q) const
    {
        const Quaternion &p = *this;
        Quaternion r;
        r(0) = p(0) * q(0) - p(1) * q(1) - p(2) * q(2) - p(3) * q(3);
        r(1) = p(0) * q(1) + p(1) * q(0) - p(2) * q(3) + p(3) * q(2);
        r(2) = p(0) * q(2) + p(1) * q(3) + p(2) * q(0) - p(3) * q(1);
        r(3) = p(0) * q(3) - p(1) * q(2) + p(2) * q(1) + p(3) * q(0);
        return r;
    }

    /**
     * Self-multiplication operator
     *
     * @param other quaternion to multiply with
     */
    void operator*=(const Quaternion &other)
    {
        Quaternion &self = *this;
        self = self * other;
    }

    /**
     * Scalar multiplication operator
     *
     * @param scalar scalar to multiply with
     * @return product
     */
    Quaternion operator*(Type scalar) const
    {
        const Quaternion &q = *this;
        return scalar * q;
    }

    /**
     * Scalar self-multiplication operator
     *
     * @param scalar scalar to multiply with
     */
    void operator*=(Type scalar)
    {
        Quaternion &q = *this;
        q = q * 