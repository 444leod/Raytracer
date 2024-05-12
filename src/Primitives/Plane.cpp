/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"

rtx::Plane::Plane(Color color, Vector3d position, Vector3d normal)
    : APrimitive(position, color), _normal(normal.normalized())
{
}

/**
 * Maths be like:
 *  dot = the dot between the ray dir and plane's normal
 *        if dot >= 0, then ray won't hit.
 *
 *  k = is the parameter that will be used to get the point.
 *  do some in between magic found online...
*/
std::optional<rtx::HitResult> rtx::Plane::hits(const Ray& ray) const
{
    double dot = ray.direction().dot(this->_normal);
    if (std::abs(dot) < 1e-6)
        return std::nullopt;
    Vector3d planeToRay = this->_position - ray.origin();
    double k = planeToRay.dot(this->_normal) / dot;
    if (k < 0.0001)
        return std::nullopt;

    Vector3d point = ray.origin() + ray.direction() * k;
    return HitResult(point, this->_normal, this->_color);
}
