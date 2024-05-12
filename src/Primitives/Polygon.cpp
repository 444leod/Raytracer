/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** POLYGON
*/

#include "Polygon.hpp"
#include <cmath>

rtx::Polygon::Polygon(Color color, const std::vector<Vector3d>& vertices)
    : APrimitive(Vector3d(0, 0, 0), color), _vertices(vertices)
{}

std::optional<rtx::HitResult> rtx::Polygon::hits(const rtx::Ray& ray) const
{
    double EPSILON = 1e-6;
    Vector3d normal = Vector3d(0, 0, 1);

    double dot_product = ray.direction().dot(normal);
    if (std::abs(dot_product) < EPSILON) {
        return std::nullopt;
    }

    double d = normal.dot(_vertices[0] - ray.origin()) / dot_product;
    if (d < 0) {
        return std::nullopt;
    }

    Vector3d intersection_point = ray.origin() + ray.direction() * d;

    int count = 0;
    size_t num_vertices = _vertices.size();
    for (size_t i = 0; i < num_vertices; ++i) {
        size_t j = (i + 1) % num_vertices;
        if ((_vertices[i].y() <= intersection_point.y() && intersection_point.y() < _vertices[j].y()) ||
            (_vertices[j].y() <= intersection_point.y() && intersection_point.y() < _vertices[i].y())) {
            double edge_x = (_vertices[j].x() - _vertices[i].x()) * (intersection_point.y() - _vertices[i].y()) /
                            (_vertices[j].y() - _vertices[i].y()) + _vertices[i].x();
            if (intersection_point.x() < edge_x) {
                ++count;
            }
        }
    }

    if (count % 2 == 1) {
        return HitResult(intersection_point, normal, _color);
    }

    return std::nullopt;
}
