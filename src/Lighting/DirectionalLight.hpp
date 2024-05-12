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
            DirectionalLight();
            DirectionalLight(const Vector3d& position, double strength, const Vector3d& direction);
            ~DirectionalLight() = default;

            void setDirection(const Vector3d& direction) { this->_direction = direction; }

            double enlightement(const HitResult& hit, bool obstructed) const;

        protected:
        private:
            Vector3d _direction;
    };
}
