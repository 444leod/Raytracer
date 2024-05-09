/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** LimitedCylinder
*/

#include "LimitedCylinder.hpp"
#include "Delta.hpp"

rtx::LimitedCylinder::LimitedCylinder(Color color, Vector3d position, Vector3d axis, double radius, double height)
    : APrimitive(position, color), _position(position), _axis(axis.normalized()), _radius(radius), _height(height)
{
}

std::optional<rtx::HitResult> rtx::LimitedCylinder::hits(const rtx::Ray& ray) const
{
    auto o = ray.origin() - this->_position;
    auto d = ray.direction();

    auto x = _axis;
    auto p = _position;
    auto r = _radius;
    auto h = _height;

    Vector3d op = o - p;
    double a1 = d.dot(x);
    double a2 = op.dot(x);

    double a = 1 - std::pow(a1, 2);
    double b = 2 * (d.dot(op) - a1 * a2);
    double c = op.dot(op) - std::pow(a2, 2) - std::pow(r, 2);

    auto delta = Delta(a, b, c).solve();
    if (!delta.has_value())
        return std::nullopt;
    if (delta.value().first < 0.01 && delta.value().second < 0.01)
        return std::nullopt;
    double k = delta.value().first;
    auto i = ray.origin() + ray.direction().normalized() * k;

    auto v = i - p;
    auto projection = x * v.dot(x);
    
    // Calculate the projection length
    double projection_length = projection.dot(x);
    
    // Check if the projection length is within the height of the cylinder
    if (projection_length < 0 || projection_length > h)
        return std::nullopt;

    auto n = v - projection;

    return HitResult(p, n.normalized(), this->_color);
}

