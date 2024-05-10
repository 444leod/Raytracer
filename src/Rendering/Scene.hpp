/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Scene
*/

#pragma once

#include <vector>
#include <memory>

#include "Image.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Light.hpp"

namespace rtx {
    class Scene {
        public:
            Scene(Camera& camera);
            ~Scene() = default;

            const Camera& camera() const { return _camera; }
            Camera& camera() { return _camera; }

            Image render() const;
            Image& render(Image& image, std::uint32_t batch_size) const;
            Color hitcolor(const rtx::HitResult& hit) const;
            std::optional<HitResult> hitresult(const rtx::Ray& ray) const;
            Vector3d enlightment(const Vector3d& point) const;

        protected:
        private:
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
            std::vector<Light> _lights;
            Camera& _camera;
    };
}
