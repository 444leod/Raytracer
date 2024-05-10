/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#pragma once

#include "APrimitive.hpp"

namespace rtx {
    class Plane : public APrimitive {
        public:
            Plane();
            Plane(Color color, Vector3d position, Vector3d normal);
            ~Plane() = default;

            const Vector3d& normal() const { return this->_normal; }
            void setNormal(const Vector3d& normal) { this->_normal = normal; }
            virtual std::optional<HitResult> hits(const Ray& ray) const;

        protected:
        private:
            Vector3d _normal;
    };
}
