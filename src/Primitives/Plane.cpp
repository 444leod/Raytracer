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
    float denom = this->_normal.dot(ray.direction());
    if (std::abs(denom) > 0.0001f)
    {
        float k = (this->_position - ray.origin()).dot(this->normal()) / denom;
        if (k < 0) return std::nullopt;
        auto p = ray.origin() + ray.direction() * k;
        return HitResult(p, this->_normal, this->_color);
    }
    return std::nullopt;
}
