/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Scene
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

namespace rtx {
    class Scene {
        public:
            Scene(const Camera& camera);
            ~Scene() = default;

            const Camera& camera() const { return _camera; }
            const Camera& camera() { return _camera; }

            const std::vector<Color> renderRaw(std::uint32_t width, std::uint32_t height) const;
            sf::Image renderImage(std::uint32_t width, std::uint32_t height) const;

        protected:
        private:
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
            const Camera& _camera;
    };
}
