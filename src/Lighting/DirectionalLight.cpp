/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

rtx::DirectionalLight::DirectionalLight(const Vector3d& direction)
    : _direction(direction)
{
}

double rtx::DirectionalLight::enlightement(const rtx::HitResult& hit, bool obstructed) const
{
    if (obstructed)
        return .0;
    return (this->_direction * -1).normalized().dot(hit.normal());
}

rtx::Vector3d rtx::DirectionalLight::lightDirection([[maybe_unused]]const rtx::Vector3d& point) const
{
    return (this->_direction * -1).normalized();
}
