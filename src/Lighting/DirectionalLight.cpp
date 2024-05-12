/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

rtx::DirectionalLight::DirectionalLight(double strength, const Vector3d& direction)
    : ALight(strength), _direction(direction)
{
}

double rtx::DirectionalLight::enlightement(const rtx::HitResult& hit, bool obstructed) const
{
    if (obstructed)
        return .0;
    return (this->_direction * -1).normalized().dot(hit.normal()) * this->_strength;
}

rtx::Vector3d rtx::DirectionalLight::lightDirection([[maybe_unused]]const rtx::Vector3d& point) const
{
    return (this->_direction * -1).normalized();
}
