/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** PointLight
*/

#include "PointLight.hpp"

rtx::PointLight::PointLight(const Vector3d& position, double strength)
    : ALight(position, strength)
{
}

rtx::PointLight::PointLight()
    : ALight(Vector3d(), .0)
{
}

double rtx::PointLight::enlightement(const rtx::HitResult& hit, bool obstructed) const
{
    if (obstructed)
        return .0;
    const Vector3d dir = this->_position - hit.point();
    return dir.normalized().dot(hit.normal());
}
