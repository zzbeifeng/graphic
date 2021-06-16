#ifndef MATH_VEC3_H
#define MATH_VEC3_H

#include <cmath>
#include "kkMathBase.h"

NS_KK_MATH_BEGIN

class Vector3
{
private:
    /* data */

public:
    /**
     * The x-coordinate.
     */
    float x;

    /**
     * The y-coordinate.
     */
    float y;

    /**
     * The z-coordinate.
     */
    float z;

public:
    Vector3(/* args */);
    Vector3(float xx, float yy, float zz);

    ~Vector3();

    static Vector3 fromColor(unsigned int color);

    inline bool isZero() const { return x == 0.0f && y == 0.0f && z == 0.0f; }

    inline bool isOne() const { return x == 1.0f && y == 1.0f && z == 1.0f; }

    inline float length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    inline void add(const Vector3 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    inline void subtract(const Vector3 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    void normalize();

    float dot(const Vector3 &v) const;

    void cross(const Vector3 &v);

    Vector3 cross(const Vector3 &v) const;
};

NS_KK_MATH_END

#endif