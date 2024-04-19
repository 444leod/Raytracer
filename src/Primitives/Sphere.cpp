/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

rtx::Sphere::Sphere(Color color, Vector3d position, double radius)
    : APrimitive(position, color), _radius(radius)
{
}

bool rtx::Sphere::hits(const rtx::Ray& ray) const
{
    auto r = this->_radius;
    auto o = ray.origin() - this->_position;
    auto d = ray.direction();

    double a = d.x() *d.x() + d.y() * d.y() + d.z() * d.z();
    double b = 2.0 * (o.x() * d.x() + o.y() * d.y() + o.z() * d.z());
    double c = o.x() * o.x() + o.y() * o.y() + o.z() * o.z() - r * r;

    return b * b - 4.0 * a * c >= 0;
}
