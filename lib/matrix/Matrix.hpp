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

    virtual ~Matrix() {};

    Matrix() :
        _data()
    {
    }

    Matrix(const Type data_[][N]) :
        _data()
    {
        memcpy(_data, data_, sizeof(_data));
    }

    Matrix(const Type *data_) :
        _data()
    {
        memcpy(_data, data_, sizeof(_data));
    }

    Matrix(const Matrix &other) :
        _data()
    {
        memcpy(_data, other._data, sizeof(_data));
    }

    /**
     * Accessors/ Assignment etc.
     */

    Type *data()
    {
        return _data[0];
    }

    inline Type operator()(size_t i, size_t j) const
    {
        return _data[i][j];
    }

    inline Type &operator()(size_t i, size_t j)
    {
        return _data[i][j];
    }

    Matrix<Type, M, N> & operator=(const Matrix<Type, M, N> &other)
    {
        if (this != &other) {
            memcpy(_data, other._data, sizeof(_data));
        }
        return (*this);
    }

    /**
     * Matrix Operations
     */

    // this might use a lot of programming memory
    // since it instantiates a class for every
    // required mult pair, but it provides
    // compile time size_t checking
    template<size_t P>
    Matrix<Type, M, P> operator*(const Matrix<Type, N, P> &other) const
    {
        const Matrix<Type, M, N> &self = *this;
        Matrix<Type, M, P> res;
        res.setZero();

        for (size_t i = 0; i < M; i++) {
            for (size_t k = 0; k < P; k++) {
                for (size_t j = 0; j < N; j++) {
                    res(i, k) += self(i, j) * other(j, k);
                }
            }
        }

        return res;
    }

    Matrix<Type, M, N> emult(const Matrix<Type, M, N> &other) const
    {
        Matrix<Type, M, N> res;
        const Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                res(i , j) = self(i, j)*other(i, j);
            }
        }

        return res;
    }

    Matrix<Type, M, N> edivide(const Matrix<Type, M, N> &other) const
    {
        Matrix<Type, M, N> res;
        const Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                res(i , j) = self(i, j)/other(i, j);
            }
        }

        return res;
    }

    Matrix<Type, M, N> operator+(const Matrix<Type, M, N> &other) const
    {
        Matrix<Type, M, N> res;
        const Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                res(i , j) = self(i, j) + other(i, j);
            }
        }

        return res;
    }

    Matrix<Type, M, N> operator-(const Matrix<Type, M, N> &other) const
    {
        Matrix<Type, M, N> res;
        const Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                res(i , j) = self(i, j) - other(i, j);
            }
        }

        return res;
    }

    // unary minus
    Matrix<Type, M, N> operator-() const
    {
        Matrix<Type, M, N> res;
        const Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                res(i , j) = -self(i, j);
            }
        }

        return res;
    }

    void operator+=(const Matrix<Type, M, N> &other)
    {
        Matrix<Type, M, N> &self = *this;
        self = self + other;
    }

    void operator-=(const Matrix<Type, M, N> &other)
    {
        Matrix<Type, M, N> &self = *this;
        self = self - other;
    }

    template<size_t P>
    void operator*=(const Matrix<Type, N, P> &other)
    {
        Matrix<Type, M, N> &self = *this;
        self = self * other;
    }

    /**
     * Scalar Operations
     */

    Matrix<Type, M, N> operator*(Type scalar) const
    {
        Matrix<Type, M, N> res;
        const Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                res(i , j) = self(i, j) * scalar;
            }
        }

        return res;
    }

    inline Matrix<Type, M, N> operator/(Type scalar) const
    {
        return (*this)*(1/scalar);
    }

    Matrix<Type, M, N> operator+(Type scalar) const
    {
        Matrix<Type, M, N> res;
        const Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                res(i , j) = self(i, j) + scalar;
            }
        }

        return res;
    }

    inline Matrix<Type, M, N> operator-(Type scalar) const
    {
        return (*this) + (-1*scalar);
    }

    void operator*=(Type scalar)
    {
        Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                self(i, j) = self(i, j) * scalar;
            }
        }
    }

    void operator/=(Type scalar)
    {
        Matrix<Type, M, N> &self = *this;
        self = self * (1.0f / scalar);
    }

    inline void operator+=(Type scalar)
    {
        *this = (*this) + scalar;
    }

    inline void operator-=(Type scalar)
    {
        *this = (*this) - scalar;
    }


    /**
     * Misc. Functions
     */

    void write_string(char * buf, size_t n) const
    {
        buf[0] = '\0'; // make an empty string to begin with (we need the '\0' for strlen to work)
        const Matrix<Type, M, N> &self = *this;
        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                snprintf(buf + strlen(buf), n - strlen(buf), "\t%g", double(self(i, j))); // directly append to the string buffer
            }
            snprintf(buf + strlen(buf), n - strlen(buf), "\n");
        }
    }

    void print() const
    {
        char buf[200];
        write_string(buf, 200);
        printf("%s\n", buf);
    }

    Matrix<Type, N, M> transpose() const
    {
        Matrix<Type, N, M> res;
        const Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                res(j, i) = self(i, j);
            }
        }

        return res;
    }

    // tranpose alias
    inline Matrix<Type, N, M> T() const
    {
        return transpose();
    }

    template<size_t P, size_t Q>
    Matrix<Type, P, Q> slice(size_t x0, size_t y0) const
    {
        Matrix<Type, P, Q> res(&(_data[x0][y0]));
        return res;
    }

    template<size_t P, size_t Q>
    void set(const Matrix<Type, P, Q> &m, size_t x0, size_t y0)
    {
        Matrix<Type, M, N> &self = *this;
        for (size_t i = 0; i < P; i++) {
            for (size_t j = 0; j < Q; j++) {
                self(i + x0, j + y0) = m(i, j);
            }
        }
    }

    void setRow(size_t i, const Matrix<Type, N, 1> &row)
    {
        Matrix<Type, M, N> &self = *this;
        for (size_t j = 0; j < N; j++) {
            self(i, j) = row(j, 0);
        }
    }

    void setCol(size_t j, const Matrix<Type, M, 1> &col)
    {
        Matrix<Type, M, N> &self = *this;
        for (size_t i = 0; i < M; i++) {
            self(i, j) = col(i, 0);
        }
    }

    void setZero()
    {
        memset(_data, 0, sizeof(_data));
    }

    inline void zero()
    {
        setZero();
    }

    void setAll(Type val)
    {
        Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                self(i, j) = val;
            }
        }
    }

    inline void setOne()
    {
        setAll(1);
    }

    void setIdentity()
    {
        setZero();
        Matrix<Type, M, N> &self = *this;

        for (size_t i = 0; i < M && i < N; i++) {
            self(i, i) = 1;
        }
    }

    inline void identity()
    {
        setIdentity();