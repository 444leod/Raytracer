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

/**
 * Maths be like:
 *
 *  E = {
 *      point.x = origin.x + direction.x * k
 *      point.y = origin.y + direction.y * k
 *      point.z = origin.z + direction.z * k
 *      radius² = point.x² + point.y² + point.z²
 *  }
 *
 *  radius² = (o.x + d.x * k)² + (o.y + d.y * k)² + (o.z + d.z * k)²
 *  <=> (o.x² + 2*o.x*d.x*k + (d.x*k)²) +
 *      (o.y² + 2*o.y*d.y*k + (d.y*k)²) +
 *      (o.y² + 2*o.y*d.y*k + (d.y*k)²) -
 *      radius²
 *      = 0
 *
 *  <=> (d.x² + d.y² + d.z²)k² +
 *      (o.x*d.x + o.y*d.y + o.z*d.z)2k +
 *      (o.x² + o.y² + o.z² - r²) where r = radius
 *      = 0
 *
 *  => a*k² + b*k + c = 0
 *      where   a = d.x² + d.y² + d.z²
 *              b = 2(o.x*d.x + o.y*d.y + o.z*d.z)
 *              c = o.x² + o.y² + o.z² - r²
 *
 *  It can be solved usic quadratic formula:
 *      D = b² - 4 * a * c
*/
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
