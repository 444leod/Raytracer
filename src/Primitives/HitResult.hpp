/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** HitResult
*/

#pragma once

#include "Vector.hpp"
#include "Color.hpp"

namespace rtx {
    class HitResult {
        public:
            HitResult() = default;
            HitResult(const Vector3d& point, const Vector3d& normal, const Color& color) :
                _point(point), _normal(normal), _color(color) {};
            HitResult(const HitResult& source) :
                _point(source.point()), _normal(source.normal()), _color(source.color()) {};
            ~HitResult() = default;

            const Vector3d& point() const { return this->_point; }
            const Vector3d& normal() const { return this->_normal; }
            const Color& color() const { return this->_color; }
            const HitResult& operator=(const HitResult& other) {
                this->_point = other.point();
                this->_color = other.color();
                this->_normal = other.normal();
                return *this;
            }

        protected:
        private:
            Vector3d _point;
            Vector3d _normal;
            Color _color;
    };
}
