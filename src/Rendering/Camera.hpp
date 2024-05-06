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
            RenderSettings(double width, double height, double fov)
                : _width(width), _height(height), _fov(fov) {};
            ~RenderSettings() = default;
            double width() const { return _width; }
            double height() const { return _height; }
            double fov() const { return _fov; }
            void setFov(double fov) { this->_fov = fov; }
            sf::VideoMode toSf() const { return sf::VideoMode(this->_width, this->_height); }
        private:
            double _width;
            double _height;
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

        protected:
        private:
            RenderSettings _settings;
            double _planeWidth = .0;
            double _planeHeight = .0;
            Vector3d _position;
            Vector3d _rotation;
    };
}
