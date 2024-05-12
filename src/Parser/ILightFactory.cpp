/*
** EPITECH PROJECT, 2024
** Parser
** File description:
** ILightFactory
*/

#include "ILightFactory.hpp"

rtx::ILightFactory::ILightFactory()
{
}

void rtx::ILightFactory::tryCreateILight(std::string key, rtx::PARSABLE& type, std::vector<std::shared_ptr<rtx::ILight>>& lights)
{
    if (_lightMap.find(key) == _lightMap.end())
        return;
    type = _lightMap[key];
    if (_lightFactory.find(type) == _lightFactory.end())
        return;
    lights.push_back(_lightFactory[type]());
}
