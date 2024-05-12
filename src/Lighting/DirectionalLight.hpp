/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DirectionalLight
*/

#pragma once

#include "ALight.hpp"

namespace rtx {
    class DirectionalLight : public ALight {
        public:
            DirectionalLight() = default;
            DirectionalLight(double strength, const Vector3d& direction);
            ~DirectionalLight() = default;

            const Vector3d& direction() const { return this->_direction; }
            void setDirection(const Vector3d& direction) { this->_direction = direction; }

            double enlightement(const HitResult& hit, bool obstructed) const;
            Vector3d lightDirection(const Vector3d& point) const;

        protected:
        private:
            Vector3d _direction;
    };
}
