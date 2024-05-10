/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Camera
*/

#pragma once

#include <SFML/Window/VideoMode.hpp>
#include <cstdint>

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Ray.hpp"

namespace rtx
{
    class RenderSettings {
        public:
            RenderSettings(std::uint32_t width, std::uint32_t height, double fov)
                : _width(width), _height(height), _fov(fov) {};
            ~RenderSettings() = default;
            std::uint32_t width() const { return _width; }
            std::uint32_t height() const { return _height; }
            void setResolution(std::uint32_t width, std::uint32_t height) { this->_width = width; this->_height = height; }
            double fov() const { return _fov; }
            void setFov(double fov) { this->_fov = fov; }
            sf::VideoMode toSf() const { return sf::VideoMode(this->_width, this->_height); }
        private:
            std::uint32_t _width;
            std::uint32_t _height;
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
            void setPosition(const Vector3d& position) { this->_position = position; }
            void setRotation(const Vector3d& rotation) { this->_rotation = rotation; }
            void setFov(double fov) { _settings.setFov(fov); }
            void setResolution(std::uint32_t width, std::uint32_t height) { _settings.setResolution(width, height); }
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
