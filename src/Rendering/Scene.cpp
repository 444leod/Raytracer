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
    _primitives.push_back(std::make_shared<Sphere>(Color(100, 255, 100), Vector3d(7, 10, 0), 3));
    _primitives.push_back(std::make_shared<Sphere>(Color(255, 100, 100), Vector3d(10, 0, 0), 4));
    _primitives.push_back(std::make_shared<Sphere>(Color(100, 100, 255), Vector3d(12, -5, 0), 5));
    _primitives.push_back(std::make_shared<Plane>(Color(100, 100, 100), Vector3d(0, 0, -2), Vector3d(0, 0, -1)));
}

const std::vector<rtx::Color> rtx::Scene::renderRaw(std::uint32_t width, std::uint32_t height) const
{
    std::vector<rtx::Color> image;

    for (std::uint32_t h = 0; h < height; h++) {
        double v = (double)h / (double)height;
        for (std::uint32_t w = 0; w < width; w++) {
            double u = (double)w / (double)width;
            const Ray& ray = this->_camera.ray(u, v);
            for (auto s : this->_primitives) {
                if (!s->hits(ray)) continue;
                image.push_back(s->color());
                break;
            }
        }
    }
    return image;
}

sf::Image rtx::Scene::renderImage(std::uint32_t width, std::uint32_t height) const
{
    auto image = sf::Image();
    image.create(width, height);

    for (std::uint32_t h = 0; h < height; h++) {
        double v = (double)h / (double)height;
        for (std::uint32_t w = 0; w < width; w++) {
            double u = (double)w / (double)width;
            const Ray& ray = this->_camera.ray(u, v);
            for (auto s : this->_primitives) {
                if (!s->hits(ray)) continue;
                sf::Color c = {s->color().r, s->color().g, s->color().b};
                image.setPixel(w, h, c);
                break;
            }
        }
    }
    return image;
}
