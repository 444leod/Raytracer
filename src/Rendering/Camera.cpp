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
    _planeWidth = tan(this->_fov / 2.0) * 2.0;
    _planeHeight = tan(this->_fov / 2.0) * 2.0;
}

rtx::Camera::~Camera()
{
}

rtx::Camera::Camera(double fov, Vector3d position, Vector3d rotation = Vector3d())
    : _fov(fov), _position(position), _rotation(rotation)
{
    _planeWidth = tan(this->_fov / 2.0);
    _planeHeight = tan(this->_fov / 2.0);
}

const rtx::Vector3d& rtx::Camera::position() const
{
    return this->_position;
}

const rtx::Vector3d&  rtx::Camera::rotation() const
{
    return this->_rotation;
}

rtx::Vector3d  rtx::Camera::forward() const
{
    return Vector3d(1.0, .0, .0).rotate(this->_rotation);
}

rtx::Ray rtx::Camera::ray(double x, double y) const
{
    double u = (x - 0.5) * 2.0 * _planeWidth;
    double v = (y - 0.5) * 2.0 * _planeHeight;
    Vector3d dir = Vector3d(1.0,  u, v).normalized().rotate(this->_rotation);
    Ray ret(this->_position, dir);
    return ret;
}
