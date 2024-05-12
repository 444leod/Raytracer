/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AmbiantLight
*/

#pragma once

#include "ILight.hpp"

namespace rtx {
    class AmbiantLight : public ILight {
        public:
            AmbiantLight() = default;
            AmbiantLight(double strength);
            ~AmbiantLight() = default;

            double strength() const { return this->_strength; }
            void setStrength(const double strength) { this->_strength = strength; }

            double enlightement(const HitResult& hit, bool obstructed) const;
            Vector3d lightDirection(const Vector3d& point) const;

        protected:
        private:
            double _strength;
    };
}
