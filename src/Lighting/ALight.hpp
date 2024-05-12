/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ALight
*/

#pragma once

#include "ILight.hpp"

namespace rtx {
    class ALight : public ILight {
        public:
            ALight() = default;
            ALight(Vector3d position, double strength) : _position(position), _strength(strength) {};
            ~ALight() = default;

            virtual const Vector3d& position() const { return this->_position; }
            virtual double strength() const { return this->_strength; }
            virtual void setPosition(const Vector3d& position) { this->_position = position; }
            virtual void setStrength(double strength) { this->_strength = strength; }

        protected:
            Vector3d _position = Vector3d();
            double _strength = .0;
        private:
    };
}
