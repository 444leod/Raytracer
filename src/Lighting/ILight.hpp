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

            /**
             * @brief Gets the direction at which a point was enligted.
             * @param point The enlighted point.
            */
            virtual Vector3d lightDirection(const Vector3d& point) const = 0;

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
