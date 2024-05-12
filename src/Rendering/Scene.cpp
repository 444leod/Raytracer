/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Scene
*/

#include "Scene.hpp"
#include <thread>

rtx::Scene::Scene(Camera& camera, std::vector<std::shared_ptr<IPrimitive>> primitives, std::vector<Light> lights)
    : _camera(camera)
{
    _primitives = primitives;
    _lights = lights;
}

rtx::Image rtx::Scene::render() const
{
    auto width = this->_camera.settings().width();
    auto height = this->_camera.settings().height();
    auto image = Image(width, height);

    for (std::uint32_t h = 0; h < height; h++) {
        double v = h / static_cast <double>(height);
        for (std::uint32_t w = 0; w < width; w++) {
            double u = w / static_cast <double>(width);
            const Ray& ray = this->_camera.ray(u, v);

            auto hit = this->hitresult(ray);
            if (!hit.has_value())
                continue;
            auto color = this->hitcolor(hit.value());
            image.set(w, h, color);
        }
    }
    return image;
}

rtx::Image& rtx::Scene::render(Image& image, std::uint32_t batch_size) const
{
    auto width = this->_camera.settings().width();
    auto height = this->_camera.settings().height();

    std::vector<std::thread> threads;
    int num_threads = std::thread::hardware_concurrency();

    for (int t = 0; t < num_threads; ++t) {
        threads.emplace_back([&, t]() {
            for (std::uint32_t i = t; i < batch_size - 1; i += num_threads) {
                auto idx = image.randindex();
                if (!idx.has_value()) return;
                double w = idx.value() % width;
                double h = idx.value() / width;
                double u = w / static_cast <double>(width);
                double v = h / static_cast <double>(height);
                const Ray& ray = this->_camera.ray(u, v);

                auto hit = this->hitresult(ray);
                if (!hit.has_value())
                    continue;
                auto color = this->hitcolor(hit.value());
                image.set(w, h, color);
            }
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return image;
}

rtx::Color rtx::Scene::hitcolor(const rtx::HitResult& hit) const
{
    auto color = hit.color();
    auto light_dir = this->enlightment(hit.point());
    auto light_force = light_dir.dot(hit.normal());
    return color * light_force;
}

std::optional<rtx::HitResult> rtx::Scene::hitresult(const rtx::Ray& ray) const
{
    std::vector<HitResult> hits;
    for (const auto& prim : this->_primitives) {
        auto hit = prim->hits(ray);
        if (hit.has_value())
            hits.push_back(hit.value());
    }
    if (hits.empty())
        return std::nullopt;
    std::pair<double, HitResult> min_hit = {std::numeric_limits<double>::max(), HitResult()};
    for (const auto& hit : hits) {
        double dist = (hit.point() - ray.origin()).size();
        if (dist < min_hit.first)
            min_hit = {dist, hit};
    }
    return min_hit.second;
}

rtx::Vector3d rtx::Scene::enlightment(const Vector3d& point) const
{
    for (const auto& light : this->_lights) {
        Vector3d dir = (light.position() - point).normalized();
        bool obstructed = false;
        std::optional<HitResult> result;

        for (const auto& prim : this->_primitives) {
            auto ray = Ray(point, dir);
            auto hit = prim->hits(ray);
            if (!hit.has_value())
                continue;
            obstructed = true;
            break;
        }
        if (!obstructed)
            return dir;
    }
    return Vector3d();
}
