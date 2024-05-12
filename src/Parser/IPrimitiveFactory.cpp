/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IPrimitiveFactory
*/

#include "IPrimitiveFactory.hpp"

rtx::IPrimitiveFactory::IPrimitiveFactory()
{
}

void rtx::IPrimitiveFactory::tryCreateIPrimitive(std::string key, rtx::PARSABLE& type, std::vector<std::shared_ptr<rtx::IPrimitive>>& primitives)
{
    if (_primitiveMap.find(key) == _primitiveMap.end())
        return;
    type = _primitiveMap[key];
    if (_primitiveFactory.find(type) == _primitiveFactory.end())
        return;
    primitives.push_back(_primitiveFactory[type]());
}
