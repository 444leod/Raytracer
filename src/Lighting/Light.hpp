/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Light
*/

#pragma once

#include "Vector.hpp"

namespace rtx {
    /**
     * @brief Represent a light that shines and create shadows
    */
    class Light {
        public:
            Light() = default;
            Light(Vector3d position, double strength);
            ~Light() = default;

            const Vector3d& position() const { return this->_position; }
            double strength() const { return this->_strength; }

        protected:
        private:
            Vector3d _position;
            double _strength;
    };
}
