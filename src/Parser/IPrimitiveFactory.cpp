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

void rtx::IPrimitiveFactory::createIPrimitive(rtx::PARSABLE type, std::vector<std::shared_ptr<rtx::IPrimitive>>& primitives)
{
    if (_primitiveFactory.find(type) == _primitiveFactory.end())
        return;
    std::cout << _primitiveFactory[type]()->position() << std::endl;
    primitives.push_back(_primitiveFactory[type]());
}
