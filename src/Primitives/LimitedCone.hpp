/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** LimitedCone
*/

#pragma once

#include "APrimitive.hpp"

namespace rtx {
    class LimitedCone : public APrimitive {
        public:
            LimitedCone();
            LimitedCone(Color color, Vector3d apex, Vector3d axis, double theta, double height);
            ~LimitedCone() = default;

            virtual std::optional<HitResult> hits(const Ray& ray) const;
            bool _is_not_shadow(double k, const rtx::Ray& ray) const;

        protected:
        private:
            Vector3d _apex;
            Vector3d _axis;
            double _theta;
            double _height;
    };
}
