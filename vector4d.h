#ifndef VECTOR_4D_H
#define VECTOR_4D_H
#include "types.h"
#include <algorithm>
#include <cmath>
#include <ostream>
namespace lina { namespace math{
    class vector4d
    {
        public:
            vector4d(f64 x, f64 y, f64 z, f64 w): x(x), y(y), z(z), w(w){}
            vector4d(): x(0), y(0), z(0), w(0){}
            f64 x;
            f64 y;
            f64 z;
            f64 w;
        public:
            // vec operations
            inline f64 norm() const;
            inline f64 sq_norm() const;
            inline f64 dot(const vector4d& other) const;
            inline vector4d cross(const vector4d& other) const;
            inline vector4d normalized() const;
            inline void normalize();
            //math operations
            inline void operator/=(f64 s);
            inline void operator*=(f64 s);
            inline void operator-=(f64 s);
            inline void operator+=(f64 s);

            inline friend vector4d operator/(const vector4d& v, f64 s);
            inline friend vector4d operator*(const vector4d& v, f64 s);
            inline friend vector4d operator-(const vector4d& v, f64 s);
            inline friend vector4d operator+(const vector4d& v, f64 s);

            inline void operator/=(const vector4d& v);
            inline void operator*=(const vector4d& v);
            inline void operator-=(const vector4d& v);
            inline void operator+=(const vector4d& v);

            inline friend vector4d operator/(const vector4d& v, const vector4d& v4);
            inline friend vector4d operator*(const vector4d& v, const vector4d& v4);
            inline friend vector4d operator+(const vector4d& v, const vector4d& v4);
            inline friend vector4d operator-(const vector4d& v, const vector4d& v4);

            static inline vector4d max(const vector4d& v, const vector4d& v4);
            static inline vector4d min(const vector4d& v, const vector4d& v4);

            inline friend std::ostream& operator<<(const std::ostream& os, const vector4d& v);
    };
    inline f64 vector4d::norm() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }
    inline f64 vector4d::sq_norm() const
    {
        return x * x + y * y + z * z;
    }
    inline f64 vector4d::dot(const vector4d& other) const 
    {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }
    inline vector4d vector4d::cross(const vector4d& other) const
    {
        return vector4d(y * other.z  - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 1.);
    }
    inline vector4d operator/(const vector4d& v, f64 s)
    {
        return vector4d(v.x/s, v.y/s, v.z/s, v.w/s);
    }
    inline vector4d operator*(const vector4d& v, f64 s)
    {
        return vector4d(v.x*s, v.y*s, v.z * s, v.w * s);
    }
    inline vector4d operator+(const vector4d& v, f64 s)
    {
        return vector4d(v.x+s, v.y+s, v.z + s, v.w + s);
    }
    inline vector4d operator-(const vector4d& v, f64 s)
    {
        return vector4d(v.x-s, v.y-s, v.z - s, v.w - s);
    }
    inline vector4d operator/(const vector4d& v, const vector4d& v4)
    {
        return vector4d(v.x / v4.x, v.y / v4.y, v.z / v4.z, v.w / v4.w);
    }
    inline vector4d operator*(const vector4d& v, const vector4d& v4)
    {
        return vector4d(v.x * v4.x, v.y * v4.y, v.z * v4.z, v.w * v4.w);
    }
    inline vector4d operator+(const vector4d& v, const vector4d& v4)
    {
        return vector4d(v.x + v4.x, v.y + v4.y, v.z + v4.z, v.w + v4.w);
    }
    inline vector4d operator-(const vector4d& v, const vector4d& v4)
    {
        return vector4d(v.x - v4.x, v.y - v4.y, v.z - v4.z, v.w - v4.w);
    }

    inline void vector4d::operator/=(f64 s)
    {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
    }
    inline void vector4d::operator*=(f64 s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    inline void vector4d::operator-=(f64 s)
    {
        x -= s;
        y -= s;
        z -= s;
        w -= s;
    }
    inline void vector4d::operator+=(f64 s)
    {
        x += s;
        y += s;
        z += s;
        w += s;
    }

    inline void vector4d::operator/=(const vector4d& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        w /= v.w;
    }
    inline void vector4d::operator*=(const vector4d& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        w *= v.w;
    }
    inline void vector4d::operator-=(const vector4d& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
    }
    inline void vector4d::operator+=(const vector4d& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }
    inline vector4d vector4d::normalized() const
    {
       return *this / norm();
    }
    inline void vector4d::normalize()
    {
       *this = *this / norm();
    }

    inline vector4d vector4d::max(const vector4d& v, const vector4d& v4)
    {
        return vector4d(std::max(v.x, v4.x), std::max(v.y, v4.y), std::max(v.z, v4.z), std::max(v.w, v4.w));
    }

    inline vector4d vector4d::min(const vector4d& v, const vector4d& v4)
    {
        return vector4d(std::min(v.x, v4.x), std::min(v.y, v4.y), std::min(v.z, v4.z), std::min(v.w, v4.w));
    }

    inline std::ostream& operator<<(std::ostream& os, const vector4d& v)
    {
        os << "(" << v.x  << ", " << v.y  << ", " << v.z << ", " << v.w << ")";
        return os;
    }

}}
#endif
