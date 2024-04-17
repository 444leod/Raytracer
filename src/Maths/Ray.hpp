/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Ray
*/

#pragma once

#include "Vector.hpp"

namespace rtx {
    class Ray {
        public:
            Ray();
            Ray(Vector3d origin, Vector3d direction);
            Ray(const Ray& source);
            Ray(const Ray&& source);
            ~Ray();
            Vector3d origin() const;
            Vector3d direction() const;

        protected:
        private:
            Vector3d _origin;
            Vector3d _direction;
    };
}
