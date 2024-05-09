/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IPrimitive
*/

#pragma once

#include "Vector.hpp"
#include "Ray.hpp"
#include "Color.hpp"

namespace rtx {
    class IPrimitive {
        public:
            virtual ~IPrimitive() = default;

            virtual const Color& color() const = 0;
            virtual const Vector3d& position() const = 0;
            virtual void setColor(const Color& color) = 0;
            virtual void setPosition(const Vector3d& position) = 0;
            virtual bool hits(const Ray& ray) const = 0;
        protected:
        private:
    };
}
