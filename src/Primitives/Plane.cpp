/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"

rtx::Plane::Plane(Color color, Vector3d position, Vector3d normal)
    : APrimitive(position, color), _normal(normal)
{
}

/**
 * Maths be like:
 *  dot product. :)
*/
bool rtx::Plane::hits(const Ray& ray) const
{
    return this->_normal.dot(ray.direction()) < 0;
}
