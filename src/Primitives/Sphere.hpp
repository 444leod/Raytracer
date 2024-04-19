/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Sphere
*/

#pragma once

#include "APrimitive.hpp"

namespace rtx {
    class Sphere : public APrimitive {
        public:
            Sphere() = default;
            Sphere(Color color, Vector3d position, double radius);
            ~Sphere() = default;

            double radius() const { return this->_radius; }

            bool hits(const Ray& ray) const;

        protected:
        private:
            double _radius = 1.0;
    };
}
