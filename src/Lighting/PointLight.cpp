/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** PointLight
*/

#include "PointLight.hpp"

rtx::PointLight::PointLight(const Vector3d& position)
    : _position(position)
{
}

rtx::PointLight::PointLight()
{
}

double rtx::PointLight::enlightement(const rtx::HitResult& hit, bool obstructed) const
{
    if (obstructed)
        return .0;
    const Vector3d dir = this->_position - hit.point();
    return dir.normalized().dot(hit.normal());
}

rtx::Vector3d rtx::PointLight::lightDirection(const rtx::Vector3d& point) const
{
    return (this->_position - point).normalized();
}
