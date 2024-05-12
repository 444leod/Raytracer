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
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "ILight.hpp"

namespace rtx {
    class Scene {
        public:
            Scene(Camera& camera, std::vector<std::shared_ptr<IPrimitive>> primitives, std::vector<std::shared_ptr<ILight>> lights);
            ~Scene() = default;

            const Camera& camera() const { return _camera; }
            Camera& camera() { return _camera; }

            Image render() const;
            Image& render(Image& image, std::uint32_t batch_size) const;
            Color hitcolor(const HitResult& hit) const;
            std::optional<HitResult> hitresult(const rtx::Ray& ray) const;
            double enlightment(const HitResult& point) const;

        protected:
        private:
            Camera& _camera;
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
            std::vector<std::shared_ptr<ILight>> _lights;
    };
}
