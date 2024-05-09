/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Delta
*/

#include "Delta.hpp"

#include <cmath>

rtx::Delta::Delta(double a, double b, double c)
    : _a(a), _b(b), _c(c)
{
}

std::optional<std::pair<double, double>> rtx::Delta::solve() const
{
    double D = (this->_b * this->_b) - (4.0 * this->_a * this->_c);

    if (D < .0)
        return std::nullopt;

    double k1 = (-_b - std::sqrt(D)) / (2 * _a);
    double k2 = (-_b + std::sqrt(D)) / (2 * _a);
    double nearest = std::min(k1, k2);
    double furthest = std::max(k1, k2);

    if (nearest < .001 && furthest < .001)
        return std::nullopt;
    return std::make_pair(nearest, furthest);
}
