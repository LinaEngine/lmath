#ifndef MAT_4_H
#define MAT_4_H
#include "vector3d.h"
#include "vector4d.h"
#include <array>
namespace lina { namespace math { 
    class mat4 
    {
        public:
            mat4(): rs({(std::array<f64, 4>){1.0, 0., 0., 0.}, {0., 1., 0., 0.}, {0., 0., 1., 0.}, {0., 0., 0., 1.}}){}
            mat4(vector4d&& ro1, vector4d&& ro2, vector4d&& ro3, vector4d&& ro4): 
                rs({(std::array<f64, 4>)
                        {ro1.x, ro1.y, ro1.z, ro1.w}, 
                        {ro2.x, ro2.y, ro2.z, ro2.w},
                        {ro3.x, ro3.y, ro3.z, ro3.w},
                        {ro4.x, ro4.y, ro4.z, ro4.w},
                        }){}
        public:
            static inline mat4 get_identity();
            static inline mat4 get_zero();

            inline vector4d row(i32 i) const;
            inline vector4d col(i32 i) const;
            inline f64 det() const;

            inline mat4 get_inverse() const;
            inline void transpose();
            inline mat4 get_transpose() const;
            inline void zero();
            inline void identity();

            inline friend mat4 operator/(const mat4& m, f64 s);
            inline friend mat4 operator*(const mat4& m, f64 s);
            inline friend mat4 operator*(const mat4& m, const mat4& m2);
            inline friend vector4d operator*(const mat4& m, const vector4d& v);
            inline friend std::ostream& operator<<(std::ostream& os, const mat4& v);
            inline f64& operator()(i32 row, i32 col) {return rs[row][col];}
        private:
            inline f64& at_pos(i32 row, i32 col) {return rs[row][col];}
        private:
            std::array<std::array<f64, 4>, 4> rs;
    };
    inline vector4d mat4::row(i32 i) const
    {
        return vector4d(rs[i][0], rs[i][1], rs[i][2], rs[i][3]);
    }
    inline vector4d mat4::col(i32 i) const
    {
        return vector4d(rs[0][i], rs[1][i], rs[2][i], rs[3][i]);
    }

    inline f64 mat4::det() const
    {
        vector4d temp = col(0);
        const vector3d v0(temp.x, temp.y, temp.z);

        temp = col(1);
        const vector3d v1(temp.x, temp.y, temp.z);
        
        temp = col(2);
        const vector3d v2(temp.x, temp.y, temp.z);

        temp = col(3);
        const vector3d v3(temp.x, temp.y, temp.z);

        const vector4d v4 = vector4d(rs[3][0], rs[3][1], rs[3][2], rs[3][3]);

        vector3d s = v0.cross(v1);
        vector3d t = v2.cross(v3);
        vector3d u = v0 * v4.y - v1 * v4.x;
        vector3d v = v2 * v4.w - v3 * v4.z;
        return (s.dot(v) + t.dot(u));
    }
    inline void mat4::transpose()
    {
        *this = get_transpose();
    }
    inline mat4 mat4::get_transpose() const
    {
        return mat4(col(0), col(1), col(2), col(3));
    }
    inline mat4 mat4::get_inverse() const
    {
        vector4d temp = col(0);
        const vector3d v0(temp.x, temp.y, temp.z);

        temp = col(1);
        const vector3d v1(temp.x, temp.y, temp.z);
        
        temp = col(2);
        const vector3d v2(temp.x, temp.y, temp.z);

        temp = col(3);
        const vector3d v3(temp.x, temp.y, temp.z);

        const vector4d v4 = vector4d(rs[3][0], rs[3][1], rs[3][2], rs[3][3]);

        vector3d s = v0.cross(v1);
        vector3d t = v2.cross(v3);
        vector3d u = v0 * v4.y - v1 * v4.x;
        vector3d v = v2 * v4.w - v3 * v4.z;
        f64 inv_det = 1 / (s.dot(v) + t.dot(u));
        s = s * inv_det;
        u = u * inv_det;
        v = v * inv_det;
        t = t * inv_det;

        vector3d r0 = v1.cross(v) + t * v4.y;
        vector3d r1 = v.cross(v0) - t * v4.x;
        vector3d r2 = v3.cross(u) + s * v4.w;
        vector3d r3 = u.cross(v2) - s * v4.z;

        return mat4 (
                vector4d(
                    r0.x, r0.y, r0.z, - v1.dot(t)
                    ),
                vector4d(
                    r1.x, r1.y, r1.z, v0.dot(t)
                    ),
                vector4d(
                    r2.x, r2.y, r2.z, - v3.dot(s)
                    ),
                vector4d(
                    r3.x, r3.y, r3.z, v2.dot(s)
                    )
                );
    }
    inline void mat4::zero()
    {
        rs.fill({0, 0, 0, 0});
    }
    inline void mat4::identity()
    {
        rs[0] = {1., 0., 0., 0.};
        rs[1] = {0., 1., 0., 0.};
        rs[2] = {0., 0., 1., 0.};
        rs[3] = {0., 0., 0., 1.};
    }
    inline mat4 mat4::get_identity()
    {
        return mat4(
                vector4d(1., 0., 0., 0.), 
                vector4d(0., 1., 0., 0.), 
                vector4d(0., 0., 1., 0.),
                vector4d(0., 0., 0., 1.)
                );
    }
    inline mat4 mat4::get_zero()
    {
        return mat4(
                vector4d(0., 0., 0., 0.), 
                vector4d(0., 0., 0., 0.),
                vector4d(0., 0., 0., 0.),
                vector4d(0., 0., 0., 0.)
                );
    }
    inline mat4 operator/(const mat4& m, f64 s)
    {
        return mat4(m.row(0)/s, m.row(1)/s, m.row(2)/s, m.row(3)/s);
    }
    inline mat4 operator*(const mat4& m, f64 s)
    {
        return mat4(m.row(0)*s, m.row(1)*s, m.row(2) * s, m.row(3) * s);
    }
    inline vector4d operator*(const mat4& m, const vector4d& v)
    {
        return vector4d(m.row(0).dot(v), m.row(1).dot(v), m.row(2).dot(v), m.row(3).dot(v));
    }
    inline mat4 operator*(const mat4& m, const mat4& m2)
    {
        return mat4(
                vector4d(
                    m.row(0).dot(m2.col(0)),
                    m.row(0).dot(m2.col(1)),
                    m.row(0).dot(m2.col(2)),
                    m.row(0).dot(m2.col(3))
                    ),
                vector4d(
                    m.row(1).dot(m2.col(0)),
                    m.row(1).dot(m2.col(1)),
                    m.row(1).dot(m2.col(2)),
                    m.row(1).dot(m2.col(3))
                    ),
                vector4d(
                    m.row(2).dot(m2.col(0)),
                    m.row(2).dot(m2.col(1)),
                    m.row(2).dot(m2.col(2)),
                    m.row(2).dot(m2.col(3))
                    ),
                vector4d(
                    m.row(3).dot(m2.col(0)),
                    m.row(3).dot(m2.col(1)),
                    m.row(3).dot(m2.col(2)),
                    m.row(4).dot(m2.col(3))
                    )
                );
    }
    inline std::ostream& operator<<(std::ostream& os, const mat4& m)
    {
        os << "{\n" << m.row(0) << '\n' << m.row(1) << '\n' << m.row(2) << '\n' << m.row(3)<< "\n}";
        return os;
    }
}}
#endif
