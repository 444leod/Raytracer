/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** APrimitive
*/

#pragma once

#include "IPrimitive.hpp"

namespace rtx {
    class APrimitive : public IPrimitive {
        public:
            APrimitive() = default;
            APrimitive(Vector3d position, Color color) : _position(position), _color(color) {};
            ~APrimitive() = default;

            virtual const Color& color() const override { return this->_color; }
            virtual const Vector3d& position() const override { return this->_position; }
            virtual void setColor(const Color color) override { this->_color = color; }
            virtual void setPosition(const Vector3d& position) override { this->_position = position; }

        protected:
            Vector3d _position;
            Color _color;
        private:
    };
}
