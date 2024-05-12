/*
** EPITECH PROJECT, 2024
** Parser
** File description:
** ILightFactory
*/

#include "Parsable.hpp"
#include "PointLight.hpp"
#include "DirectionalLight.hpp"
#include "AmbiantLight.hpp"

#include <memory>
#include <map>
#include <functional>
#include <vector>

#pragma once
namespace rtx {
    class ILightFactory {
        public:
            ILightFactory();
            ~ILightFactory() = default;
            void tryCreateILight(std::string key, rtx::PARSABLE& type, std::vector<std::shared_ptr<rtx::ILight>>& lights);

        private:
            std::map<std::string, rtx::PARSABLE> _lightMap {
                {"pointLight:", rtx::PARSABLE::POINTLIGHT},
                {"directionalLight:", rtx::PARSABLE::DIRLIGHT},
                {"ambiantLight:", rtx::PARSABLE::AMBLIGHT},
            };
            std::map<rtx::PARSABLE, std::function<std::shared_ptr<ILight>()>> _lightFactory {
                {rtx::PARSABLE::POINTLIGHT, []() { return std::make_shared<PointLight>(); }},
                {rtx::PARSABLE::DIRLIGHT, []() { return std::make_shared<DirectionalLight>(); }},
                {rtx::PARSABLE::AMBLIGHT, []() { return std::make_shared<AmbiantLight>(); }},
            };
    };
}
