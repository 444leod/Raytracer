/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Camera
*/

#include "Camera.hpp"

rtx::Camera::Camera(const RenderSettings& settings, Vector3d position, Vector3d rotation = Vector3d())
    : _settings(settings), _position(position), _rotation(rotation)
{
    double ratio = this->_settings.width() / this->_settings.height();
    _planeWidth = tan(this->_settings.fov() / 2.0) * ratio;
    _planeHeight = tan(this->_settings.fov() / 2.0);
}

rtx::Camera::~Camera()
{
}

const rtx::Vector3d& rtx::Camera::position() const
{
    return this->_position;
}

const rtx::Vector3d&  rtx::Camera::rotation() const
{
    return this->_rotation;
}

const rtx::RenderSettings& rtx::Camera::settings() const
{
    return this->_settings;
}

rtx::Vector3d  rtx::Camera::forward() const
{
    return Vector3d(1.0, .0, .0).rotate(this->_rotation);
}

rtx::Ray rtx::Camera::ray(double x, double y) const
{
    double u = (x - 0.5) * 2.0 * _planeWidth;
    double v = (y - 0.5) * 2.0 * _planeHeight;
    Vector3d dir = Vector3d(1.0,  u, -v).normalized().rotate(this->_rotation);
    Ray ret(this->_position, dir);
    return ret;
}
