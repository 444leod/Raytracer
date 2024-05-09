/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/

#pragma once

#include "APrimitive.hpp"

namespace rtx {
    class Cone : public APrimitive {
        public:
            Cone() = delete;
            Cone(Color color, Vector3d apex, Vector3d axis, double theta);
            ~Cone() = default;

            virtual std::optional<HitResult> hits(const Ray& ray) const;
            bool _is_not_shadow(double k, const rtx::Ray& ray) const;

        protected:
        private:
            Vector3d _apex;
            Vector3d _axis;
            double _height;
            double _theta;
    };
}
