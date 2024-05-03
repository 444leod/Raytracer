/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Light
*/

#include "Light.hpp"

rtx::Light::Light(Vector3d position, double strength)
    : _position(position), _strength(strength)
{
}
