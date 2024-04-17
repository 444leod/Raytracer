/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Camera
*/

#include "Camera.hpp"

rtx::Camera::Camera()
    : _position(Vector3d()), _rotation(Vector3d())
{
}

rtx::Camera::~Camera()
{
}

rtx::Camera::Camera(Vector3d position, Vector3d rotation = Vector3d())
    : _position(position), _rotation(rotation)
{
}

rtx::Vector3d rtx::Camera::position() const
{
    return this->_position;
}

rtx::Vector3d rtx::Camera::rotation() const
{
    return this->_rotation;
}

rtx::Vector3d rtx::Camera::forward() const
{
    return Vector3d(1.0, .0, .0).rotate(this->_rotation);
}

rtx::Ray rtx::Camera::ray() const
{
    Ray ret(this->_position, this->forward());
    return ret;
}
