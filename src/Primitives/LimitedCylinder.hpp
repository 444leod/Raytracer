/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** LimitedCylinder
*/

#pragma once

#include "APrimitive.hpp"

namespace rtx {
    class LimitedCylinder : public APrimitive {
        public:
            LimitedCylinder();
            LimitedCylinder(Color color, Vector3d position, Vector3d axis, double radius, double height);
            ~LimitedCylinder() = default;

            double radius() const { return _radius; }
            double height() const { return _height; }
            virtual std::optional<HitResult> hits(const Ray& ray) const;

        protected:
        private:
            Vector3d _position;
            Vector3d _axis;
            double _radius;
            double _height;
    };
}
