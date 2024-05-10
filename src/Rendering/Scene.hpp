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
#include "Light.hpp"

namespace rtx {
    class Scene {
        public:
            Scene(const Camera& camera);
            ~Scene() = default;

            const Camera& camera() const { return _camera; }
            const Camera& camera() { return _camera; }

            sf::Image render() const;
            std::optional<HitResult> simulateRay(const rtx::Ray& ray) const;
            Vector3d enlightment(const Vector3d& point) const;

        protected:
        private:
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
            std::vector<Light> _lights;
            const Camera& _camera;
    };
}
