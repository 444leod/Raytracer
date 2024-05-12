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
    updatePlane();
}

rtx::Camera::~Camera()
{
}

void rtx::Camera::updatePlane()
{
    double ratio = this->_settings.width() / static_cast <double>(this->_settings.height());
    _planeWidth = tan(this->_settings.fov() / 2.0) * ratio;
    _planeHeight = tan(this->_settings.fov() / 2.0);
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

rtx::Vector3d rtx::Camera::forward() const
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

void rtx::Camera::rotate(const Vector3d& rotation)
{
    this->_rotation += rotation;
}

void rtx::Camera::move(const Vector3d& movement)
{
    this->_position += movement.rotate(this->_rotation);
}

void rtx::Camera::setFov(double fov)
{
    _settings.setFov(fov);
    updatePlane();
}

void rtx::Camera::setResolution(std::uint32_t width, std::uint32_t height)
{
    _settings.setResolution(width, height);
    updatePlane();    
}
