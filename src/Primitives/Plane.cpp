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
bool rtx::Plane::hits(const Ray& ray) const
{
    double k = 0;
    Vector3d origin = this->_position - ray.origin();
    double dot = this->_normal.dot(ray.direction().normalized());

    if (dot >= 0)
        return false;
    k = origin.dot(this->_normal) / dot;
    return k <= 0;
}
