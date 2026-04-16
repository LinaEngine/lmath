#include "common_parametric_curves.h"
#include "vector2d.h"
namespace lina { namespace math{ namespace parametric{

    vector2d circle::eval(f64 t)
    {
        return vector2d(std::cos(t), std::sin(t)) * r;
    }
    vector2d circle::grad(f64 t)
    {
        return vector2d(-std::sin(t), std::cos(t));
    }

    vector2d descartes_follium::eval(f64 t)
    {
        f64 den = (1 + t * t * t);
        return vector2d(3. * a * t / den, 3. * a * t * t / den);
    }
    vector2d descartes_follium::grad(f64 t)
    {
        f64 den = (1 + t * t * t);
        return vector2d(
                3 * a * (1 - 2 * t * t * t) / (den * den), 
                3 * a * (2 * t - t * t * t * t) / (den * den));
    }
}}}
