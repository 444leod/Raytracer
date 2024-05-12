/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AmbiantLight
*/

#pragma once

#include "ALight.hpp"

namespace rtx {
    class AmbiantLight : public ALight {
        public:
            AmbiantLight() = default;
            AmbiantLight(double strength);
            ~AmbiantLight() = default;

            double enlightement(const HitResult& hit, bool obstructed) const;
            Vector3d lightDirection(const Vector3d& point) const;

        protected:
        private:
    };
}
