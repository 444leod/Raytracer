/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Scene
*/

#include "Scene.hpp"

rtx::Scene::Scene(const Camera& camera)
    : _camera(camera)
{
    _primitives.push_back(std::make_shared<Sphere>(Color(100, 100, 100), Vector3d(9, 0, 2.5), 0.5));
    _primitives.push_back(std::make_shared<Sphere>(Color(100, 255, 100), Vector3d(5, -5, -1), 1.5));
    _primitives.push_back(std::make_shared<Sphere>(Color(100, 100, 255), Vector3d(11, 0, 0), 2));
    _primitives.push_back(std::make_shared<Sphere>(Color(255, 100, 100), Vector3d(7, 5, 1), 1.75));
    _primitives.push_back(std::make_shared<Sphere>(Color(100, 100, 100), Vector3d(0, 0, -100002), 100000));

    _lights.push_back(Light(Vector3d(8, 0, 8), 50.0));
}

sf::Image rtx::Scene::render(std::uint32_t width, std::uint32_t height) const
{
    auto image = sf::Image();
    image.create(width, height);

    for (std::uint32_t h = 0; h < height; h++) {
        double v = (double)h / (double)height;
        for (std::uint32_t w = 0; w < width; w++) {
            double u = (double)w / (double)width;
            const Ray& ray = this->_camera.ray(u, v);

            auto hit = this->simulateRay(ray);
            if (hit.has_value())
                image.setPixel(w, h, hit.value().color().asSf());
        }
    }
    return image;
}

std::optional<rtx::HitResult> rtx::Scene::simulateRay(const rtx::Ray& ray) const
{
    for (const auto& prim : this->_primitives) {
        auto hit = prim->hits(ray);
        if (hit.has_value())
            return hit.value();
    }
    return std::nullopt;
}
