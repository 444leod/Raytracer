/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Vector
*/

#include "Vector.hpp"

rtx::Vector3d::Vector3d(double x, double y, double z)
    : _x(x), _y(y), _z(z)
{
}

rtx::Vector3d::Vector3d(const Vector3d& source)
    : _x(source.x()), _y(source.y()), _z(source.z())
{
}

rtx::Vector3d::Vector3d(const Vector3d&& source)
    : _x(source.x()), _y(source.y()), _z(source.z())
{
}
