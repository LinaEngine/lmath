#ifndef MATH_UTILS_H
#define MATH_UTILS_H
#include "vector2d.h"
namespace lina { namespace math { namespace utils {
    template <typename T>
    inline T transfer_range(const T& v, T&& min1, T&& max1, T&& min2, T&& max2)
    {
        return ((max2 - min2) / (max1 - min1)) * (v - min1) + min2;
    }
}}}
#endif
