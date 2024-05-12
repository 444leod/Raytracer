/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** LimitedCone
*/

#include "LimitedCone.hpp"
#include "Delta.hpp"

rtx::LimitedCone::LimitedCone()
    : APrimitive(Vector3d(0, 0, 0), Color(0, 0, 0)), _apex(Vector3d(0, 0, 0)), _axis((Vector3d(1, 0, 0)).normalized()), _theta(0), _height(0)
{
}

rtx::LimitedCone::LimitedCone(Color color, Vector3d apex, Vector3d axis, double theta, double height)
    : APrimitive(apex, color), _apex(apex), _axis(axis.normalized()), _theta(theta), _height(height)
{
}

/**
 * Maths be like:
 *
 *  => a*k² + b*k + c = 0
 *      where   a = d.v² - cos²(θ)
 *              b = 2 * (d.v * o.v - d.o * cos²(θ))
 *              c = o.v² - o.o * cos²(θ)
 *
 *  It can be solved usic quadratic formula:
 *      D = b² - 4 * a * c
*/

std::optional<rtx::HitResult> rtx::LimitedCone::hits(const rtx::Ray& ray) const
{
    auto theta = this->_theta;
    auto o = ray.origin() - this->_position;
    auto d = ray.direction();

    double dv = d.dot(this->_axis);
    Vector3d co = o - this->_apex;
    double cov = co.dot(this->_axis);
    double theta_squared = std::pow(std::cos(theta), 2);

    double a = std::pow(dv, 2) - theta_squared;
    double b = 2.0 * (dv * cov - d.dot(co) * theta_squared);
    double c = std::pow(cov, 2) - co.dot(co) * theta_squared;

    std::optional<std::pair<double, double>> k_pair = Delta(a, b, c).solve();
    if (!k_pair.has_value())
        return std::nullopt;

    double k;
    if (_is_not_shadow(k_pair.value().first, ray))
        k = k_pair.value().first;
    else
        return std::nullopt;
    if (k < 0.01)
        return std::nullopt;
    auto p = ray.origin() + ray.direction().normalized() * k;
    Vector3d v = p - this->_apex;
    double projection = v.dot(this->_axis);
    if (projection > this->_height)
        return std::nullopt;

    Vector3d proj_axis = _axis * projection;
    Vector3d normal = (v - proj_axis) / (v - proj_axis).size();

    return HitResult(p, normal, this->_color);
}

bool rtx::LimitedCone::_is_not_shadow(double k, const rtx::Ray& ray) const
{
    auto p = ray.origin() + ray.direction().normalized() * k;
    if (_theta < M_PI_2) {
        if ((p - _position).dot(_axis) < 0)
            return false;
    } else {
        if (((p - _position) / (p - _position).size()).dot(_axis) - std::cos(_theta) > 0.01)
            return false;
    }
    return true;
}
