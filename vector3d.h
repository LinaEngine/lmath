#ifndef VECTOR_3D_H
#define VECTOR_3D_H
#include "types.h"
#include <algorithm>
#include <cmath>
#include <ostream>
namespace lina { namespace math{
    class vector3d
    {
        public:
            vector3d(f64 x, f64 y, f64 z): x(x), y(y), z(z){}
            vector3d(): x(0), y(0), z(0){}
            f64 x;
            f64 y;
            f64 z;
        public:
            // vec operations
            inline f64 norm() const;
            inline f64 sq_norm() const;
            inline f64 dot(const vector3d& other) const;
            inline vector3d cross(const vector3d& other) const;
            inline vector3d normalized() const;
            inline bool same_direction(const vector3d& other) const;
            inline bool same_direction(vector3d&& other) const;
            inline void normalize();
            //math operations
            inline void operator/=(f64 s);
            inline void operator*=(f64 s);
            inline void operator-=(f64 s);
            inline void operator+=(f64 s);
            inline vector3d operator-() const;

            inline friend vector3d operator/(const vector3d& v, f64 s);
            inline friend vector3d operator*(const vector3d& v, f64 s);
            inline friend vector3d operator-(const vector3d& v, f64 s);
            inline friend vector3d operator+(const vector3d& v, f64 s);

            inline void operator/=(const vector3d& v);
            inline void operator*=(const vector3d& v);
            inline void operator-=(const vector3d& v);
            inline void operator+=(const vector3d& v);

            inline friend vector3d operator/(const vector3d& v, const vector3d& v3);
            inline friend vector3d operator*(const vector3d& v, const vector3d& v3);
            inline friend vector3d operator+(const vector3d& v, const vector3d& v3);
            inline friend vector3d operator-(const vector3d& v, const vector3d& v3);

            static inline vector3d max(const vector3d& v, const vector3d& v3);
            static inline vector3d min(const vector3d& v, const vector3d& v3);

            inline friend std::ostream& operator<<(const std::ostream& os, const vector3d& v);
    };
    inline vector3d vector3d::operator-() const
    {
        return *this * -1;
    }
    inline bool vector3d::same_direction(vector3d&& other) const
    {
        return dot(other) > 0;
    }
    inline bool vector3d::same_direction(const vector3d& other) const
    {
        return dot(other) > 0;
    }
    inline f64 vector3d::norm() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }
    inline f64 vector3d::sq_norm() const
    {
        return x * x + y * y + z * z;
    }
    inline f64 vector3d::dot(const vector3d& other) const 
    {
        return x * other.x + y * other.y + z * other.z;
    }
    inline vector3d vector3d::cross(const vector3d& other) const
    {
        return vector3d(y * other.z  - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
    inline vector3d operator/(const vector3d& v, f64 s)
    {
        return vector3d(v.x/s, v.y/s, v.z/s);
    }
    inline vector3d operator*(const vector3d& v, f64 s)
    {
        return vector3d(v.x*s, v.y*s, v.z * s);
    }
    inline vector3d operator+(const vector3d& v, f64 s)
    {
        return vector3d(v.x+s, v.y+s, v.z + s);
    }
    inline vector3d operator-(const vector3d& v, f64 s)
    {
        return vector3d(v.x-s, v.y-s, v.z - s);
    }
    inline vector3d operator/(const vector3d& v, const vector3d& v3)
    {
        return vector3d(v.x / v3.x, v.y / v3.y, v.z / v3.z);
    }
    inline vector3d operator*(const vector3d& v, const vector3d& v3)
    {
        return vector3d(v.x * v3.x, v.y * v3.y, v.z * v3.z);
    }
    inline vector3d operator+(const vector3d& v, const vector3d& v3)
    {
        return vector3d(v.x + v3.x, v.y + v3.y, v.z + v3.z);
    }
    inline vector3d operator-(const vector3d& v, const vector3d& v3)
    {
        return vector3d(v.x - v3.x, v.y - v3.y, v.z - v3.z);
    }

    inline void vector3d::operator/=(f64 s)
    {
        x /= s;
        y /= s;
        z /= s;
    }
    inline void vector3d::operator*=(f64 s)
    {
        x *= s;
        y *= s;
        z *= s;
    }
    inline void vector3d::operator-=(f64 s)
    {
        x -= s;
        y -= s;
        z -= s;
    }
    inline void vector3d::operator+=(f64 s)
    {
        x += s;
        y += s;
        z += s;
    }

    inline void vector3d::operator/=(const vector3d& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
    }
    inline void vector3d::operator*=(const vector3d& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
    }
    inline void vector3d::operator-=(const vector3d& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }
    inline void vector3d::operator+=(const vector3d& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }
    inline vector3d vector3d::normalized() const
    {
       return *this / norm();
    }
    inline void vector3d::normalize()
    {
       *this = *this / norm();
    }

    inline vector3d vector3d::max(const vector3d& v, const vector3d& v3)
    {
        return vector3d(std::max(v.x, v3.x), std::max(v.y, v3.y), std::max(v.z, v3.z));
    }

    inline vector3d vector3d::min(const vector3d& v, const vector3d& v3)
    {
        return vector3d(std::min(v.x, v3.x), std::min(v.y, v3.y), std::min(v.z, v3.z));
    }

    inline std::ostream& operator<<(std::ostream& os, const vector3d& v)
    {
        os << "(" << v.x  << ", " << v.y  << ", " << v.z<< ")";
        return os;
    }

}}
#endif
