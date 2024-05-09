/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/

#include "Cone.hpp"
#include "Delta.hpp"

rtx::Cone::Cone(Color color, Vector3d apex, Vector3d axis, double theta)
    : APrimitive(apex, color), _apex(apex), _axis(axis.normalized()), _theta(theta)
{
}

/**
 * Maths be like:
 *
 *  => a*k² + b*k + c = 0
 *      where   a = d.v² - cos²(θ)
 *              b = 2 * (d.v * o.v - d.o * cos²(θ))
 *              c = o.v² - o.o * cos²(θ)
 *
 *  It can be solved usic quadratic formula:
 *      D = b² - 4 * a * c
*/
std::optional<rtx::HitResult> rtx::Cone::hits(const rtx::Ray& ray) const
{
}
