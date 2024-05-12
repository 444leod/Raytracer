/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ALight
*/

#pragma once

#include "ILight.hpp"

namespace rtx
{
    class ALight : public ILight {
        public:
            ALight() = default;
            ALight(double strength) : _strength(strength) {}
            ~ALight() = default;

            double strength() const { return this->_strength; }
            void setStrength(double strength) { this->_strength = strength; }

        protected:
            double _strength = 1.0;
        private:
    };
}
