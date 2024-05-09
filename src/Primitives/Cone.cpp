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

std::optional<rtx::HitResult> rtx::Cone::hits(const rtx::Ray& ray) const
{
}
