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
            Camera(Vector3d position, Vector3d rotation);
            ~Camera();

            Vector3d forward() const;
            Vector3d position() const;
            Vector3d rotation() const;
            Ray ray() const;

        protected:
        private:
            Vector3d _position;
            Vector3d _rotation;
    };
}
