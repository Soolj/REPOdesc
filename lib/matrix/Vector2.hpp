/**
 * @file Vector2.hpp
 *
 * 2D vector class.
 *
 * @author James Goppert <james.goppert@gmail.com>
 */

#pragma once

#include "math.hpp"

namespace matrix
{

template <typename Type, size_t M>
class Vector;

template<typename Type>
class Vector2 : public Vector<Type, 2>
{
public:

    typedef Matrix<Type, 2, 1> Matrix21;

    virtual ~Vector2() {};

    Vector2() :
        Vector<Type, 2>()
    {
    }

    Vector2(const Matrix21 & other) :
        Vector<Type, 2>(other)
    {
    }

    Vector2(const Type *data_) :
        Vector<Type, 2>(data_)
    {
    }

    Vector2(Type x, Type y) : Vector<Type, 2>()
    {
        Vector2 &v(*this);
