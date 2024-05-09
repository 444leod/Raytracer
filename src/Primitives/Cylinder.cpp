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
*/
std::optional<rtx::HitResult> rtx::Cylinder::hits(const rtx::Ray& ray) const
{
}
