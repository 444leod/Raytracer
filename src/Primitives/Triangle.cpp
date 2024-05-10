#include "Triangle.hpp"
#include <cmath>

rtx::Triangle::Triangle(Color color, Vector3d p1, Vector3d p2, Vector3d p3)
    : APrimitive((p1 + p2 + p3) / 3.0, color), _p1(p1), _p2(p2), _p3(p3)
{}

std::optional<rtx::HitResult> rtx::Triangle::hits(const rtx::Ray& ray) const
{
    double EPSILON = 1e-6;
    Vector3d e1 = _p2 - _p1;
    Vector3d e2 = _p3 - _p1;
    Vector3d h = ray.direction().cross(e2);
    double a = e1.dot(h);

    if (std::abs(a) < EPSILON)
        return std::nullopt;

    double f = 1.0 / a;
    Vector3d s = ray.origin() - _p1;
    double u = f * s.dot(h);

    if (u < 0.0 || u > 1.0)
        return std::nullopt;

    Vector3d q = s.cross(e1);
    double v = f * ray.direction().dot(q);

    if (v < 0.0 || u + v > 1.0)
        return std::nullopt;

    double t = f * e2.dot(q);

    if (t < EPSILON) {
        return std::nullopt;
    }
    Vector3d hit_point = ray.origin() + ray.direction() * t;
    Vector3d normal = e1.cross(e2).normalized();
    return HitResult(hit_point, normal, _color);

}
