/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include "Delta.hpp"

rtx::Cylinder::Cylinder(Color color, Vector3d position, Vector3d axis, double radius)
    : APrimitive(position, color), _position(position), _axis(axis.normalized()), _radius(radius)
{
}

std::optional<rtx::HitResult> rtx::Cylinder::hits(const rtx::Ray& ray) const
{
}
