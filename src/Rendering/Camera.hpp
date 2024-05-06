/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Camera
*/

#pragma once

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Ray.hpp"

namespace rtx
{
    class Camera {
        public:
            Camera();
            Camera(double fov, Vector3d position, Vector3d rotation);
            ~Camera();

            Vector3d forward() const;
            const Vector3d& position() const;
            const Vector3d& rotation() const;
            Ray ray(double x, double y) const;

        protected:
        private:
            double _fov = 72.f;
            double _planeWidth = .0;
            double _planeHeight = .0;
            Vector3d _position;
            Vector3d _rotation;
    };
}
