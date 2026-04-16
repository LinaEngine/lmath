#ifndef VECTOR_2D_H
#define VECTOR_2D_H
#include "types.h"
#include <algorithm>
#include <cmath>
#include <ostream>
namespace lina { namespace math{
    class vector2d
    {
        public:
            vector2d(): x(0), y(0){}
            vector2d(f64 x, f64 y): x(x), y(y){}
            f64 x;
            f64 y;
        public:
            // vec operations
            inline f64 norm() const;
            inline f64 sq_norm() const;
            inline f64 dot(const vector2d& other) const;
            inline f64 cross(const vector2d& other) const;
            inline vector2d normalized() const;
            inline void normalize();
            //math operations
            inline void operator/=(f64 s);
            inline void operator*=(f64 s);
            inline void operator-=(f64 s);
            inline void operator+=(f64 s);

            inline friend vector2d operator/(const vector2d& v, f64 s);
            inline friend vector2d operator*(const vector2d& v, f64 s);
            inline friend vector2d operator-(const vector2d& v, f64 s);
            inline friend vector2d operator+(const vector2d& v, f64 s);

            inline void operator/=(const vector2d& v);
            inline void operator*=(const vector2d& v);
            inline void operator-=(const vector2d& v);
            inline void operator+=(const vector2d& v);

            inline friend vector2d operator/(const vector2d& v, const vector2d& v2);
            inline friend vector2d operator*(const vector2d& v, const vector2d& v2);
            inline friend vector2d operator+(const vector2d& v, const vector2d& v2);
            inline friend vector2d operator-(const vector2d& v, const vector2d& v2);

            static inline vector2d max(const vector2d& v, const vector2d& v2);
            static inline vector2d min(const vector2d& v, const vector2d& v2);

            inline friend std::ostream& operator<<(const std::ostream& os, const vector2d& v);
    };
    inline f64 vector2d::norm() const
    {
        return std::sqrt(x * x + y * y);
    }
    inline f64 vector2d::sq_norm() const
    {
        return x * x + y * y;
    }
    inline f64 vector2d::dot(const vector2d& other) const 
    {
        return x * other.x + y * other.y;
    }
    inline f64 vector2d::cross(const vector2d& other) const
    {
        return x * other.y  - y * other.x;
    }
    inline vector2d operator/(const vector2d& v, f64 s)
    {
        return vector2d(v.x/s, v.y/s);
    }
    inline vector2d operator*(const vector2d& v, f64 s)
    {
        return vector2d(v.x*s, v.y*s);
    }
    inline vector2d operator+(const vector2d& v, f64 s)
    {
        return vector2d(v.x+s, v.y+s);
    }
    inline vector2d operator-(const vector2d& v, f64 s)
    {
        return vector2d(v.x-s, v.y-s);
    }
    inline vector2d operator/(const vector2d& v, const vector2d& v2)
    {
        return vector2d(v.x / v2.x, v.y / v2.y);
    }
    inline vector2d operator*(const vector2d& v, const vector2d& v2)
    {
        return vector2d(v.x * v2.x, v.y * v2.y);
    }
    inline vector2d operator+(const vector2d& v, const vector2d& v2)
    {
        return vector2d(v.x + v2.x, v.y + v2.y);
    }
    inline vector2d operator-(const vector2d& v, const vector2d& v2)
    {
        return vector2d(v.x - v2.x, v.y - v2.y);
    }

    inline void vector2d::operator/=(f64 s)
    {
        x /= s;
        y /= s;
    }
    inline void vector2d::operator*=(f64 s)
    {
        x *= s;
        y *= s;
    }
    inline void vector2d::operator-=(f64 s)
    {
        x -= s;
        y -= s;
    }
    inline void vector2d::operator+=(f64 s)
    {
        x += s;
        y += s;
    }

    inline void vector2d::operator/=(const vector2d& v)
    {
        x /= v.x;
        y /= v.y;
    }
    inline void vector2d::operator*=(const vector2d& v)
    {
        x *= v.x;
        y *= v.y;
    }
    inline void vector2d::operator-=(const vector2d& v)
    {
        x -= v.x;
        y -= v.y;
    }
    inline void vector2d::operator+=(const vector2d& v)
    {
        x += v.x;
        y += v.y;
    }
    inline vector2d vector2d::normalized() const
    {
       return *this / norm();
    }
    inline void vector2d::normalize()
    {
       *this = *this / norm();
    }

    inline vector2d vector2d::max(const vector2d& v, const vector2d& v2)
    {
        return vector2d(std::max(v.x, v2.x), std::max(v.y, v2.y));
    }

    inline vector2d vector2d::min(const vector2d& v, const vector2d& v2)
    {
        return vector2d(std::min(v.x, v2.x), std::min(v.y, v2.y));
    }

    inline std::ostream& operator<<(std::ostream& os, const vector2d& v)
    {
        os << "(" << v.x  << ", " << v.y << ")";
        return os;
    }

}}
#endif
