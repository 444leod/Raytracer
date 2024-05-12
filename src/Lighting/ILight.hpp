/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILight
*/

#pragma once

#include "HitResult.hpp"
#include "Color.hpp"
#include "Vector.hpp"

namespace rtx {
    class ILight {
        public:
            virtual ~ILight() = default;

            virtual const Vector3d& position() const = 0;
            virtual double strength() const = 0;
            virtual void setPosition(const Vector3d& position) = 0;
            virtual void setStrength(double strength) = 0;

            /**
             * @brief Computes the resulted color of a `HitResult` enlighted
             * (or not) by this `ILight`.
             *
             * @param hit The `HitResult` from a `Ray` simulation.
             * @param obstructed Wether there are obstacles between this light and given `HitResult` point.
            */
            virtual double enlightement(const HitResult& hit, bool obstructed) const = 0;

        protected:
        private:
    };
}
