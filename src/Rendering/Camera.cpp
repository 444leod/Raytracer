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

rtx::Camera::Camera(double fov, Vector3d position, Vector3d rotation = Vector3d())
    : _fov(fov), _position(position), _rotation(rotation)
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

rtx::Ray rtx::Camera::ray(double x, double y) const
{
    double u = (x - 0.5) * this->_fov * (180.0 / M_PI);
    double v = (y - 0.5) * this->_fov * (180.0 / M_PI);
    Vector3d rotation = Vector3d(.0, v, u);

    Ray ret(this->_position, this->forward().rotate(rotation));
    return ret;
}
