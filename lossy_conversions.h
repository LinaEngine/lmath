#ifndef MATH_LOSSY_COVNERSIONS_H
#define MATH_LOSSY_COVNERSIONS_H
#include "vector2d.h"
#include "vector3d.h"
#include "vector4d.h"
#include "mat4.h"
#include "mat3.h"
#include "mat2.h"
namespace lina { namespace math { namespace conversions {
    inline vector3d drop_last(vector4d&& v)
    {
        return vector3d(v.x, v.y, v.z);
    }
    inline vector2d drop_last(vector3d&& v)
    {
        return vector2d(v.x, v.y);
    }
    inline f64 drop_last(vector2d&& v)
    {
        return v.x;
    }
    inline vector4d extend(vector3d&& v, f64 w = 0.)
    {
        return vector4d(v.x, v.y, v.z, w);
    }
    inline vector3d extend(vector2d&& v, f64 z = 0.)
    {
        return vector3d(v.x, v.y,z);
    }
}}}
#endif
