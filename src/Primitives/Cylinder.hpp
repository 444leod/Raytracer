/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cylinder
*/

#pragma once

#include "APrimitive.hpp"

namespace rtx {
    class Cylinder : public APrimitive {
        public:
            Cylinder() = delete;
            Cylinder(Color color, Vector3d position, Vector3d axis, double radius);
            ~Cylinder() = default;

            double radius() const { return _radius; }
            virtual std::optional<HitResult> hits(const Ray& ray) const;

        protected:
        private:
            Vector3d _position;
            Vector3d _axis;
            double _height;
            double _radius;
    };
}
