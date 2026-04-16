#include "tests.h"
#include "utils.h"
#include "vector2d.h"
#include "vector3d.h"
#include "vector4d.h"
#include <cassert>
namespace lina { namespace math { namespace tests{
    void v2d_tests()
    {
        BEGIN_TEST("vec2");
        vector2d v1(0., 2.);

        assert(utils::f64_eq(v1.x, 0.));
        assert(utils::f64_eq(v1.y, 2.));

        v1.x = 5;
        v1.y = 5;

        vector2d v2(3., 4.);

        f64 d = v1.dot(v2);
        f64 c = v1.cross(v2);

        assert(utils::f64_eq(d, 35.));
        assert(utils::f64_eq(c, 5.));
        assert(utils::f64_eq(v1.sq_norm(), 50));
        assert(utils::f64_eq(v1.norm(), std::sqrt(50)));

        v1 += 2;
        assert(utils::f64_eq(v1.x, 7.));
        assert(utils::f64_eq(v1.y, 7.));

        auto v = v1 / v2;

        assert(utils::f64_eq(v.x, 7./3.));
        assert(utils::f64_eq(v.y, 7./4.));

        v2.x = 10.;

        v = vector2d::max(v1, v2);
        assert(utils::f64_eq(v.x, 10.));
        assert(utils::f64_eq(v.y, 7.));
        v = vector2d::min(v1, v2);
        assert(utils::f64_eq(v.x, 7.));
        assert(utils::f64_eq(v.y, 4.));

        v = v1.normalized();
        assert(utils::f64_eq(v.x, 1./sqrt(2)));
        assert(utils::f64_eq(v.y, 1./sqrt(2)));

        v1.normalize();
        assert(utils::f64_eq(v1.x, 1./sqrt(2)));
        assert(utils::f64_eq(v1.y, 1./sqrt(2)));
        END_TEST("vec2");
    }
    void v3d_tests()
    {
        BEGIN_TEST("vec3");
        vector3d v1(0., 2., 3.);

        assert(utils::f64_eq(v1.x, 0.));
        assert(utils::f64_eq(v1.y, 2.));
        assert(utils::f64_eq(v1.z, 3.));

        v1.x = 5;
        v1.y = 5;
        v1.z = 5;

        vector3d v2(3., 4., 5.);

        f64 d = v1.dot(v2);

        assert(utils::f64_eq(d, 60.));
        assert(utils::f64_eq(v1.sq_norm(), 75));
        assert(utils::f64_eq(v1.norm(), std::sqrt(75)));

        v1 += 2;
        assert(utils::f64_eq(v1.x, 7.));
        assert(utils::f64_eq(v1.y, 7.));
        assert(utils::f64_eq(v1.z, 7.));

        auto v = v1 / v2;

        assert(utils::f64_eq(v.x, 7./3.));
        assert(utils::f64_eq(v.y, 7./4.));
        assert(utils::f64_eq(v.z, 7./5.));

        v2.x = 10.;

        v = vector3d::max(v1, v2);
        assert(utils::f64_eq(v.x, 10.));
        assert(utils::f64_eq(v.y, 7.));
        assert(utils::f64_eq(v.z, 7.));

        v = vector3d::min(v1, v2);
        assert(utils::f64_eq(v.x, 7.));
        assert(utils::f64_eq(v.y, 4.));
        assert(utils::f64_eq(v.z, 5.));

        v = v1.normalized();
        assert(utils::f64_eq(v.x, 1./sqrt(3)));
        assert(utils::f64_eq(v.y, 1./sqrt(3)));
        assert(utils::f64_eq(v.z, 1./sqrt(3)));

        v1.normalize();
        assert(utils::f64_eq(v1.x, 1./sqrt(3)));
        assert(utils::f64_eq(v1.y, 1./sqrt(3)));
        assert(utils::f64_eq(v1.z, 1./sqrt(3)));

        v1 = vector3d(1., 0., 0.);
        v2 = vector3d(0., 1., 0.);
        auto v3 = v1.cross(v2);
        auto v4 = v2.cross(v1);

        assert(utils::f64_eq(v3.x, 0.));
        assert(utils::f64_eq(v3.y, 0.));
        assert(utils::f64_eq(v3.z, 1.));

        assert(utils::f64_eq(v4.x, 0.));
        assert(utils::f64_eq(v4.y, 0.));
        assert(utils::f64_eq(v4.z, -1.));

        END_TEST("vec3");
    }

    void mat2_tests()
    {
        BEGIN_TEST("mat2");
        using namespace math::utils;
        mat2 m;

        mat2 minv = m.get_inverse();

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                assert(f64_eq(m(i, j), minv(i, j)));
            }
        }


        auto det = m.det();
        assert(f64_eq(det, 1.));

        m = m * 2.;

        assert(f64_eq(m(0, 0), 2.));
        assert(f64_eq(m(1, 1), 2.));

        det = m.det();
        assert(f64_eq(det, 4.));

        m(0, 0) = 2.;
        m(1, 1) = 3.;
        m(0, 1) = 1.;
        m(1, 0) = 1.;

        minv = m.get_inverse();

        assert(f64_eq(minv(0, 0), 0.6));
        assert(f64_eq(minv(0, 1), -0.2));
        assert(f64_eq(minv(1, 0), -0.2));
        assert(f64_eq(minv(1, 1), 0.4));

        vector2d v(2, 3);

        v = minv * v;

        assert(f64_eq(v.x, 0.6));
        assert(f64_eq(v.y, 0.8));

        END_TEST("mat2");
    }
    void mat3_tests()
    {
        BEGIN_TEST("mat3");
        using namespace math::utils;
        mat3 m;
        mat3 minv = m.get_inverse();


        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                assert(f64_eq(m(i, j), minv(i, j)));
            }
        }


        auto det = m.det();
        assert(f64_eq(det, 1.));

        m = m * 2.;

        assert(f64_eq(m(0, 0), 2.));
        assert(f64_eq(m(1, 1), 2.));
        assert(f64_eq(m(2, 2), 2.));

        det = m.det();
        assert(f64_eq(det, 8.));

        m = mat3(vector3d(2, 1, 11), vector3d(1, 3, 13), vector3d(4, 7, 15));

        assert(f64_eq(m.det(), -110));
        minv = m.get_inverse();

        assert(f64_eq(minv(0, 0), 23./55.));
        assert(f64_eq(minv(0, 1), -31./55.));
        assert(f64_eq(minv(0, 2), 2./11.));

        assert(f64_eq(minv(1, 0), -37./110));
        assert(f64_eq(minv(1, 1), 7./55.));
        assert(f64_eq(minv(1, 2), 3./22.));

        assert(f64_eq(minv(2, 0), 1./22.));
        assert(f64_eq(minv(2, 1), 1./11.));
        assert(f64_eq(minv(2, 2), -1./22.));

        vector3d v(2, 3, 5);

        mat3 seq(vector3d(1, 2, 3), vector3d(4, 5, 6), vector3d(7, 8, 9));

        v = seq * v;

        assert(f64_eq(v.x, 23.));
        assert(f64_eq(v.y, 53.));
        assert(f64_eq(v.z, 83.));

        END_TEST("mat3");
    }

    void mat4_tests()
    {
        BEGIN_TEST("mat4");
        using namespace math::utils;
        mat4 m;
        mat4 minv = m.get_inverse();


        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                assert(f64_eq(m(i, j), minv(i, j)));
            }
        }


        auto det = m.det();
        assert(f64_eq(det, 1.));

        m = m * 2.;

        assert(f64_eq(m(0, 0), 2.));
        assert(f64_eq(m(1, 1), 2.));
        assert(f64_eq(m(2, 2), 2.));
        assert(f64_eq(m(3, 3), 2.));

        det = m.det();
        assert(f64_eq(det, 16.));

        m = mat4(
                vector4d(2, 1, 11, 4),
                vector4d(1, 3, 13, 2),
                vector4d(4, 7, 15, 1),
                vector4d(1, 2, 3, 4));

        assert(f64_eq(m.det(), -465));
        minv = m.get_inverse();

        assert(f64_eq(minv(0, 0), 37./93.));
        assert(f64_eq(minv(0, 1), -53./93.));
        assert(f64_eq(minv(0, 2), 22./93.));
        assert(f64_eq(minv(0, 3), -16./93.));

        assert(f64_eq(minv(1, 0), -48./155.));
        assert(f64_eq(minv(1, 1), 21./155.));
        assert(f64_eq(minv(1, 2), 2./31.));
        assert(f64_eq(minv(1, 3), 7./31.));

        assert(f64_eq(minv(2, 0), 17./465.));
        assert(f64_eq(minv(2, 1), 41./465.));
        assert(f64_eq(minv(2, 2), -2./93.));
        assert(f64_eq(minv(2, 3), -7./93.));

        assert(f64_eq(minv(3, 0), 13./465.));
        assert(f64_eq(minv(3, 1), 4./465.));
        assert(f64_eq(minv(3, 2), -7./93.));
        assert(f64_eq(minv(3, 3), 22./93.));

        vector4d v(2, 3, 5, -7);

        mat4 seq(vector4d(1, 2, 3, 4), 
                vector4d(5, 6, 7, 8),
                vector4d(9, 10, 11, 12),
                vector4d(13, 14, 15, 16)
                );

        v = seq * v;

        assert(f64_eq(v.x, -5.));
        assert(f64_eq(v.y, 7.));
        assert(f64_eq(v.z, 19.));
        assert(f64_eq(v.w, 31.));

        END_TEST("mat4");
    }

    void all()
    {
        v2d_tests();
        v3d_tests();
        mat2_tests();
        mat3_tests();
        mat4_tests();
    }
}}}
