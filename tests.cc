#include "tests.h"
#include "vector2d.h"
#include "../core/utils.h"
#include <cassert>
namespace lina { namespace math { namespace tests{
    void v2d_tests()
    {
        BEGIN_TEST("vec2");
        using namespace core::util;
        vector2d v1(0., 2.);

        assert(f64_eq(v1.x, 0.));
        assert(f64_eq(v1.y, 2.));

        v1.x = 5;
        v1.y = 5;

        vector2d v2(3., 4.);

        f64 d = v1.dot(v2);
        f64 c = v1.cross(v2);

        assert(f64_eq(d, 35.));
        assert(f64_eq(c, 5.));
        assert(f64_eq(v1.sq_norm(), 50));
        assert(f64_eq(v1.norm(), std::sqrt(50)));

        v1 += 2;
        assert(f64_eq(v1.x, 7.));
        assert(f64_eq(v1.y, 7.));

        auto v = v1 / v2;

        assert(f64_eq(v.x, 7./3.));
        assert(f64_eq(v.y, 7./4.));

        v2.x = 10.;

        v = vector2d::max(v1, v2);
        assert(f64_eq(v.x, 10.));
        assert(f64_eq(v.y, 7.));
        v = vector2d::min(v1, v2);
        assert(f64_eq(v.x, 7.));
        assert(f64_eq(v.y, 4.));

        v = v1.normalized();
        assert(f64_eq(v.x, 1./sqrt(2)));
        assert(f64_eq(v.y, 1./sqrt(2)));

        v1.normalize();
        assert(f64_eq(v1.x, 1./sqrt(2)));
        assert(f64_eq(v1.y, 1./sqrt(2)));
        END_TEST("vec2");
    }
    void v3d_tests()
    {
        BEGIN_TEST("vec3");
        using namespace core::util;
        vector3d v1(0., 2., 3.);

        assert(f64_eq(v1.x, 0.));
        assert(f64_eq(v1.y, 2.));
        assert(f64_eq(v1.z, 3.));

        v1.x = 5;
        v1.y = 5;
        v1.z = 5;

        vector3d v2(3., 4., 5.);

        f64 d = v1.dot(v2);

        assert(f64_eq(d, 60.));
        assert(f64_eq(v1.sq_norm(), 75));
        assert(f64_eq(v1.norm(), std::sqrt(75)));

        v1 += 2;
        assert(f64_eq(v1.x, 7.));
        assert(f64_eq(v1.y, 7.));
        assert(f64_eq(v1.z, 7.));

        auto v = v1 / v2;

        assert(f64_eq(v.x, 7./3.));
        assert(f64_eq(v.y, 7./4.));
        assert(f64_eq(v.z, 7./5.));

        v2.x = 10.;

        v = vector3d::max(v1, v2);
        assert(f64_eq(v.x, 10.));
        assert(f64_eq(v.y, 7.));
        assert(f64_eq(v.z, 7.));

        v = vector3d::min(v1, v2);
        assert(f64_eq(v.x, 7.));
        assert(f64_eq(v.y, 4.));
        assert(f64_eq(v.z, 5.));

        v = v1.normalized();
        assert(f64_eq(v.x, 1./sqrt(3)));
        assert(f64_eq(v.y, 1./sqrt(3)));
        assert(f64_eq(v.z, 1./sqrt(3)));

        v1.normalize();
        assert(f64_eq(v1.x, 1./sqrt(3)));
        assert(f64_eq(v1.y, 1./sqrt(3)));
        assert(f64_eq(v1.z, 1./sqrt(3)));

        v1 = vector3d(1., 0., 0.);
        v2 = vector3d(0., 1., 0.);
        auto v3 = v1.cross(v2);
        auto v4 = v2.cross(v1);

        assert(f64_eq(v3.x, 0.));
        assert(f64_eq(v3.y, 0.));
        assert(f64_eq(v3.z, -1.));

        assert(f64_eq(v4.x, 0.));
        assert(f64_eq(v4.y, 0.));
        assert(f64_eq(v4.z, 1.));

        END_TEST("vec3");
    }

    void all()
    {
        v2d_tests();
        v3d_tests();
    }
}}}
