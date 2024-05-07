/*
** EPITECH PROJECT, 2024
** Parser
** File description:
** Parser
*/

#include <vector>
#include <memory>

#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
// #include "Light.hpp"

#pragma once

namespace rtx {
    class Parser {
        public:
            Parser();
            ~Parser() = default;
            void runParser(std::string file);
            std::vector<std::shared_ptr<rtx::IPrimitive>> getPrimitives() const;
            // std::vector<Light> getLights() const;
            rtx::Camera getCamera() const;

        private:
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
            // std::vector<Light> _lights;
            rtx::Camera _camera = rtx::Camera();
    };
}