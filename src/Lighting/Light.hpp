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
            Light() { this->_position = Vector3d(0, 0, 0); this->_strength = 1; };
            Light(Vector3d position, double strength);
            ~Light() = default;

            const Vector3d& position() const { return this->_position; }
            double strength() const { return this->_strength; }
            void setPosition(const Vector3d& position) { this->_position = position; }
            void setStrength(double strength) { this->_strength = strength; }

        protected:
        private:
            Vector3d _position;
            double _strength;
    };
}
