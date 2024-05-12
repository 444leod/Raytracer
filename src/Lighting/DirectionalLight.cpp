/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

rtx::DirectionalLight::DirectionalLight(const Vector3d& position, double strength, const Vector3d& direction)
    : ALight(position, strength), _direction(direction)
{
}

rtx::DirectionalLight::DirectionalLight()
    : ALight(Vector3d(), .0)
{
}

double rtx::DirectionalLight::enlightement(const rtx::HitResult& hit, bool obstructed) const
{
    if (obstructed)
        return .0;
    return this->_direction.normalized().dot(hit.normal());
}
