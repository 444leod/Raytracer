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

rtx::Ray::Ray(const Vector3d& origin, const Vector3d& direction)
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

rtx::Vector3d rtx::Ray::origin() const
{
    return this->_origin;
}

rtx::Vector3d rtx::Ray::direction() const
{
    return this->_direction;
}
