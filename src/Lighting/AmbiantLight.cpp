/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AmbiantLight
*/

#include "AmbiantLight.hpp"

rtx::AmbiantLight::AmbiantLight(const double strength)
    : ALight(strength)
{
}

double rtx::AmbiantLight::enlightement(
    [[maybe_unused]]const rtx::HitResult& hit,
    [[maybe_unused]]bool obstructed) const
{
    return this->_strength;
}

rtx::Vector3d rtx::AmbiantLight::lightDirection(
    [[maybe_unused]]const rtx::Vector3d& point) const
{
    return Vector3d();
}
