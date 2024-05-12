/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Polygon
*/

#pragma once

#include "APrimitive.hpp"
#include <vector>

namespace rtx {
    class Polygon : public APrimitive {
    public:
        Polygon() = delete;
        Polygon(Color color, const std::vector<Vector3d>& vertices);
        ~Polygon() = default;

        virtual std::optional<HitResult> hits(const Ray& ray) const override;

    private:
        std::vector<Vector3d> _vertices;
    };
}
