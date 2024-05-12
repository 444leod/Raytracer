/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IPrimitiveFactory
*/

#pragma once

#include "Parsable.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Light.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "LimitedCone.hpp"
#include "LimitedCylinder.hpp"
#include "Triangle.hpp"

#include <memory>
#include <map>
#include <functional>

namespace rtx {
    class IPrimitiveFactory {
        public:
            IPrimitiveFactory();
            ~IPrimitiveFactory() = default;
            void tryCreateIPrimitive(std::string key, rtx::PARSABLE& type, std::vector<std::shared_ptr<rtx::IPrimitive>>& primitives);

        private:
            std::map<std::string, rtx::PARSABLE> _primitiveMap {
                {"sphere:", rtx::PARSABLE::SPHERE},
                {"plane:", rtx::PARSABLE::PLANE},
                {"light:", rtx::PARSABLE::LIGHT},
                {"camera:", rtx::PARSABLE::CAMERA},
                {"cone:", rtx::PARSABLE::CONE},
                {"cylinder:", rtx::PARSABLE::CYLINDER},
                {"limitedCone:", rtx::PARSABLE::LIMITEDCONE},
                {"limitedCylinder:", rtx::PARSABLE::LIMITEDCYLINDER},
                {"triangle:", rtx::PARSABLE::TRIANGLE},
            };
            std::map<rtx::PARSABLE, std::function<std::shared_ptr<IPrimitive>()>> _primitiveFactory {
                {rtx::PARSABLE::SPHERE, []() { return std::make_shared<Sphere>(); }},
                {rtx::PARSABLE::PLANE, []() { return std::make_shared<Plane>(); }},
                {rtx::PARSABLE::CONE, []() { return std::make_shared<Cone>(); }},
                {rtx::PARSABLE::CYLINDER, []() { return std::make_shared<Cylinder>(); }},
                {rtx::PARSABLE::LIMITEDCONE, []() { return std::make_shared<LimitedCone>(); }},
                {rtx::PARSABLE::LIMITEDCYLINDER, []() { return std::make_shared<LimitedCylinder>(); }},
                {rtx::PARSABLE::TRIANGLE, []() { return std::make_shared<Triangle>(); }},
            };
    };
}
