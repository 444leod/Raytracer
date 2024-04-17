/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Ray
*/

#include "Ray.hpp"

rtx::Ray::Ray()
{
}

rtx::Ray::Ray(Vector3d origin, Vector3d direction)
    : _origin(origin), _direction(direction)
{
}

rtx::Ray::Ray(const Ray& source)
    : _origin(source.origin()), _direction(source.direction())
{
}

rtx::Ray::Ray(const Ray&& source)
    : _origin(source.origin()), _direction(source.direction())
{
}

rtx::Ray::~Ray()
{
}
