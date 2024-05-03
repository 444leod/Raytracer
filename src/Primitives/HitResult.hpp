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
            HitResult(const Vector3d& point, const Vector3d& bounce, const Color& color) :
                _point(point), _bounce(bounce), _color(color) {};
            HitResult(const HitResult& source) :
                _point(source.point()), _bounce(source.bounce()), _color(source.color()) {};
            ~HitResult() = default;

            const Vector3d& point() const { return this->_point; }
            const Vector3d& bounce() const { return this->_bounce; }
            const Color& color() const { return this->_color; }
            const HitResult& operator=(const HitResult& other) {
                this->_point = other.point();
                this->_color = other.color();
                this->_bounce = other.bounce();
                return *this;
            }

        protected:
        private:
            Vector3d _point;
            Vector3d _bounce;
            Color _color;
    };
}
