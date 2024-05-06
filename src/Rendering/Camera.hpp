/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Camera
*/

#pragma once

#include <SFML/Window/VideoMode.hpp>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Ray.hpp"

namespace rtx
{
    class RenderSettings {
        public:
            RenderSettings(uint32_t width, uint32_t height, double fov)
                : _width(width), _height(height), _fov(fov) {};
            ~RenderSettings() = default;
            uint32_t width() const { return _width; }
            uint32_t height() const { return _height; }
            double fov() const { return _fov; }
            void setFov(double fov) { this->_fov = fov; }
            sf::VideoMode toSf() const { return sf::VideoMode(this->_width, this->_height); }
        private:
            uint32_t _width;
            uint32_t _height;
            double _fov;
    };

    class Camera {
        public:
            Camera(const RenderSettings& settings, Vector3d position, Vector3d rotation);
            ~Camera();

            Vector3d forward() const;
            const Vector3d& position() const;
            const Vector3d& rotation() const;
            const RenderSettings& settings() const;
            Ray ray(double x, double y) const;
            void rotate(const Vector3d& rotation);
            void move(const Vector3d& movement);

        protected:
        private:
            RenderSettings _settings;
            double _planeWidth = .0;
            double _planeHeight = .0;
            Vector3d _position;
            Vector3d _rotation;
    };
}
