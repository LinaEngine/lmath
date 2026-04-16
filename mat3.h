#ifndef MAT_3_H
#define MAT_3_H
#include "vector3d.h"
#include "vector4d.h"
#include <array>
namespace lina { namespace math { 
    class mat3 
    {
        public:
            mat3(): rs({(std::array<f64, 3>){1.0, 0., 0.}, {0., 1., 0.}, {0., 0., 1.}}){}
            mat3(vector3d&& ro1, vector3d&& ro2, vector3d&& ro3): 
                rs({(std::array<f64, 3>){ro1.x, ro1.y, ro1.z}, {ro2.x, ro2.y, ro2.z}, {ro3.x, ro3.y, ro3.z}}){}
        public:
            static inline mat3 get_identity();
            static inline mat3 get_zero();

            inline vector3d row(i32 i) const;
            inline vector3d col(i32 i) const;
            inline f64 det() const;

            inline mat3 get_inverse() const;
            inline void transpose();
            inline mat3 get_transpose() const;
            inline void zero();
            inline void identity();

            inline friend mat3 operator/(const mat3& m, f64 s);
            inline friend mat3 operator*(const mat3& m, f64 s);
            inline friend mat3 operator*(const mat3& m, const mat3& m2);
            inline friend vector3d operator*(const mat3& m, const vector3d& v);
            inline friend std::ostream& operator<<(std::ostream& os, const mat3& v);
            inline f64& operator()(i32 row, i32 col) {return rs[row][col];}
        private:
            inline f64& at_pos(i32 row, i32 col) {return rs[row][col];}
        private:
            std::array<std::array<f64, 3>, 3> rs;
    };
    inline vector3d mat3::row(i32 i) const
    {
        return vector3d(rs[i][0], rs[i][1], rs[i][2]);
    }
    inline vector3d mat3::col(i32 i) const
    {
        return vector3d(rs[0][i], rs[1][i], rs[2][i]);
    }

    inline f64 mat3::det() const
    {
        return rs[0][0] * (rs[1][1] * rs[2][2] - rs[1][2] * rs[2][1])
		+ rs[0][1] * (rs[1][2] * rs[2][0] - rs[1][0] * rs[2][2])
		+ rs[0][2] * (rs[1][0] * rs[2][1] - rs[1][1] * rs[2][0]);
    }
    inline void mat3::transpose()
    {
        *this = get_transpose();
    }
    inline mat3 mat3::get_transpose() const
    {
        return mat3(col(0), col(1), col(2));
    }
    inline mat3 mat3::get_inverse() const
    {
        const vector3d& v0 = row(0);
        const vector3d& v1 = row(1);
        const vector3d& v2 = row(2);
        vector3d r0 = v2.cross(v1);
        vector3d r1 = v0.cross(v2);
        vector3d r2 = v1.cross(v0);
        f64 inv_det = 1 / r2.dot(v2);
        return mat3(
                vector3d(r0.x *inv_det, r1.x * inv_det, r2.x * inv_det),
                vector3d(r0.y *inv_det, r1.y * inv_det, r2.y * inv_det),
                vector3d(r0.z *inv_det, r1.z * inv_det, r2.z * inv_det)
                );
    }
    inline void mat3::zero()
    {
        rs.fill({0, 0, 0});
    }
    inline void mat3::identity()
    {
        rs[0] = {1., 0., 0.};
        rs[1] = {0., 1., 0.};
        rs[2] = {0., 0., 1.};
    }
    inline mat3 mat3::get_identity()
    {
        return mat3(vector3d(1., 0., 0.), vector3d(0., 1., 0.), vector3d(0., 0., 1.));
    }
    inline mat3 mat3::get_zero()
    {
        return mat3(vector3d(0., 0., 0.), vector3d(0., 0., 0.), vector3d(0., 0., 0.));
    }
    inline mat3 operator/(const mat3& m, f64 s)
    {
        return mat3(m.row(0)/s, m.row(1)/s, m.row(2)/s);
    }
    inline mat3 operator*(const mat3& m, f64 s)
    {
        return mat3(m.row(0)*s, m.row(1)*s, m.row(2) * s);
    }
    inline vector3d operator*(const mat3& m, const vector3d& v)
    {
        return vector3d(m.row(0).dot(v), m.row(1).dot(v), m.row(2).dot(v));
    }
    inline mat3 operator*(const mat3& m, const mat3& m2)
    {
        return mat3(
                vector3d(
                    m.row(0).dot(m2.col(0)),
                    m.row(0).dot(m2.col(1)),
                    m.row(0).dot(m2.col(2))
                    ),
                vector3d(
                    m.row(1).dot(m2.col(0)),
                    m.row(1).dot(m2.col(1)),
                    m.row(1).dot(m2.col(2))
                    ),
                vector3d(
                    m.row(2).dot(m2.col(0)),
                    m.row(2).dot(m2.col(1)),
                    m.row(2).dot(m2.col(2))
                    ));
    }
    inline std::ostream& operator<<(std::ostream& os, const mat3& m)
    {
        os << "{\n" << m.row(0) << '\n' << m.row(1) << '\n' << m.row(2) << "\n}";
        return os;
    }
}}
#endif
