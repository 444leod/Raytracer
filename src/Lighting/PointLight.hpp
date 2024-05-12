/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** PointLight
*/

#pragma once

#include "ALight.hpp"

namespace rtx {
    class PointLight : public ALight {
        public:
            PointLight();
            PointLight(const Vector3d& position, double strength);
            ~PointLight() = default;

            double enlightement(const HitResult& hit, bool obstructed) const;

        protected:
        private:
    };
}
