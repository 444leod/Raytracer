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
            PointLight() = default;
            PointLight(double strength, const Vector3d& position);
            ~PointLight() = default;

            virtual const Vector3d& position() const { return this->_position; }
            virtual void setPosition(const Vector3d& position) { this->_position = position; }
            double enlightement(const HitResult& hit, bool obstructed) const;
            Vector3d lightDirection(const Vector3d& point) const;

        protected:
        private:
            Vector3d _position = Vector3d();
    };
}
