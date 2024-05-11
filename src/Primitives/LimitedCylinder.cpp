/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** LimitedCylinder
*/

#include "LimitedCylinder.hpp"
#include "Delta.hpp"

rtx::LimitedCylinder::LimitedCylinder()
    : APrimitive(Vector3d(0, 0, 0), Color(0, 0, 0)), _position(Vector3d(0, 0, 0)), _axis(Vector3d(0, 0, 0)), _radius(0), _height(0)
{
}

rtx::LimitedCylinder::LimitedCylinder(Color color, Vector3d position, Vector3d axis, double radius, double height)
    : APrimitive(position, color), _position(position), _axis(axis.normalized()), _radius(radius), _height(height)
{
}

/**
 * Maths be like:
 *
 *  => a*k² + b*k + c = 0
 *      where   a = 1 - (d dot x)²
 *              b = 2 * (d dot (o - p) - (d dot x) * (o - p) dot x)
 *              c = (o - p) dot (o - p) - ((o - p) dot x)² - r²
 *
 *  It can be solved usic quadratic formula:
 *      D = b² - 4 * a * c
 * 
 * Then we check if the intersection point is inside the cylinder
 * by checking if the projection of the intersection point on the axis
 * is between 0 and the height of the cylinder.
 * we calculate the projection with the formula:
 * projection = x * v.dot(x) where x is the axis of the cylinder
 * and v is the vector from the apex of the cylinder to the intersection point
*/

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
    
    double projection_length = projection.dot(x);
    
    if (projection_length < 0 || projection_length > h)
        return std::nullopt;

    auto n = v - projection;

    return HitResult(p, n.normalized(), this->_color);
}

