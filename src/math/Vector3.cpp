#include "Vector3.h"

USING_NS_KK_MATH;

Vector3::Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz)
{
}

Vector3::Vector3(/* args */)
{
}

Vector3::~Vector3()
{
}

float Vector3::dot(const Vector3 &v)  const
{
    float d = 0;
    d = x * v.x + y * v.y + z * v.z;
    return d;
}

void Vector3::cross(const Vector3 &v)
{
    
    float xx = (y * v.z) - (z * v.y);
    float yy = (z * v.x) - (x * v.z);
    float zz = (x * v.y) - (y * v.x);
    
    x = xx;
    y = yy;
    z = zz;

}

Vector3 Vector3::cross(const Vector3 &v) const
{
    
    float xx = (y * v.z) - (z * v.y);
    float yy = (z * v.x) - (x * v.z);
    float zz = (x * v.y) - (y * v.x);

    return Vector3(xx,yy,zz);
}


void Vector3::normalize()
{
    float n = x * x + y * y + z * z;
    // Already normalized.
    if (n == 1.0f)
        return;

    n = std::sqrt(n);
    // Too close to zero.
    if (n < MATH_TOLERANCE)
        return;

    n = 1.0f / n;
    x *= n;
    y *= n;
    z *= n;
}