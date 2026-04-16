#ifndef MAT_2_H
#define MAT_2_H
#include "vector2d.h"
#include "vector4d.h"
#include <array>
namespace lina { namespace math { 
    class mat2 
    {
        public:
            mat2(): rs({(std::array<f64, 2>){1.0, 0.}, {0., 1.}}){}
            mat2(vector2d&& ro1, vector2d&& ro2): 
                rs({(std::array<f64, 2>){ro1.x, ro1.y}, {ro2.x, ro2.y}}){}
        public:
            static inline mat2 get_identity();
            static inline mat2 get_zero();

            inline vector2d row(i32 i) const;
            inline vector2d col(i32 i) const;
            inline f64 det() const;

            inline mat2 get_inverse() const;
            inline void transpose();
            inline mat2 get_transpose() const;
            inline void zero();
            inline void identity();

            inline friend mat2 operator/(const mat2& m, f64 s);
            inline friend mat2 operator*(const mat2& m, f64 s);
            inline friend mat2 operator*(const mat2& m, const mat2& m2);
            inline friend vector2d operator*(const mat2& m, const vector2d& v);
            inline friend std::ostream& operator<<(std::ostream& os, const mat2& v);
        private:
            std::array<std::array<f64, 2>, 2> rs;
    };
    inline vector2d mat2::row(i32 i) const
    {
        return vector2d(rs[i][0], rs[i][1]);
    }
    inline vector2d mat2::col(i32 i) const
    {
        return vector2d(rs[0][i], rs[1][i]);
    }

    inline f64 mat2::det() const
    {
        return row(1).x * row(2).y - row(1).y * row(2).x;
    }
    inline void mat2::transpose()
    {

    }
    inline mat2 mat2::get_transpose() const
    {
        return mat2(vector2d(row(1).x, row(2).x), vector2d(row(1).y, row(2).y));
    }
    inline mat2 mat2::get_inverse() const
    {
    }
    inline void mat2::zero()
    {

    }
    inline void mat2::identity()
    {

    }
    inline mat2 mat2::get_identity()
    {
        return mat2(vector2d(1., 0.), vector2d(0., 1.));
    }
    inline mat2 mat2::get_zero()
    {
        return mat2(vector2d(0., 0.), vector2d(0., 0.));
    }
    inline mat2 operator/(const mat2& m, f64 s)
    {
        return mat2(m.row(1)/s, m.row(2)/s);
    }
    inline mat2 operator*(const mat2& m, f64 s)
    {
        return mat2(m.row(1)*s, m.row(2)*s);
    }
    inline vector2d operator*(const mat2& m, const vector2d& v)
    {
        return vector2d(m.row(1).dot(v), m.row(2).dot(v));
    }
    inline mat2 operator*(const mat2& m, const mat2& m2)
    {
        return mat2(
                vector2d(
                    m.row(1).x * m2.row(1).x + m.row(1).y * m2.row(2).x,
                    m.row(1).x * m2.row(1).y + m.row(1).y * m2.row(2).y
                    ), 
                vector2d(
                    m.row(2).x * m2.row(1).x + m.row(2).y * m2.row(2).x,
                    m.row(2).x * m2.row(1).y + m.row(2).y * m2.row(2).y
                    ));
    }
    inline std::ostream& operator<<(std::ostream& os, const mat2& m)
    {
        os << "{\n" << m.row(1) << '\n' << m.row(2) << "\n}";
        return os;
    }
}}
#endif
