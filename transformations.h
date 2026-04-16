#ifndef MATH_TRANSFORMATIONS_H
#define MATH_TRANSFORMATIONS_H
#include "vector3d.h"
#include "all.h"
#include "vector4d.h"
namespace lina { namespace math { namespace transformations {
    inline mat4 translate_matrix(vector3d&& v)
    {
        mat4 m;
        m(0, 3) = v.x;
        m(1, 3) = v.y;
        m(2, 3) = v.z;
        return m;
    }
    inline mat4 scale_matrix(vector3d&& v)
    {
        mat4 m;
        m(0, 0) = v.x;
        m(1, 1) = v.y;
        m(2, 2) = v.z;
        return m;
    }
    inline mat4 rot_matrix(vector3d&& axis, f64 theta)
    {
        f64 c = cos(theta);
        f64 s = sin(theta);
        f64 d = 1 - c;
        vector3d a = axis.normalized();
        return mat4(
                vector4d(c + d * a.x * a.x, d * a.x * a.y - s * a.z, d * a.x * a.z + s * a.y, 0),
                vector4d(d * a.x * a.y + s * a.z, c + d * a.y * a.y, d * a.y * a.z - s * a.x, 0),
                vector4d(d * a.x * a.z - s * a.y, d * a.y * a.z + s * a.x, c + d * a.z * a.z, 0),
                vector4d(0, 0, 0, 1)
                );
    }
    inline mat4 rot_matrix(vector3d&& angles)
    {
        return 
            rot_matrix(vector3d(1, 0, 0), angles.x) * 
            rot_matrix(vector3d(0, 1, 0), angles.y) *
            rot_matrix(vector3d(0, 0, 1), angles.z);
    }
    inline mat4 projMatrix(f64 fov, f64 ar, f64 nearf = 0., f64 farf =1e3)
    {
        f64 rad = fov * 3.1415 / 180.0;
        f64 tanHalfFov = tan(rad * 0.5);
        f64 f = 1 / tanHalfFov;
        f64 range = farf-nearf;
        f64 A = (-farf - nearf) / range;
        f64 B = 2.0f * farf * nearf / range;
        return mat4(
                vector4d(f / ar, 0, 0, 0),
                vector4d(0, f, 0, 0),
                vector4d(0, 0, A, B),
                vector4d(0, 0, 1, 0));
    }
}}}
#endif
