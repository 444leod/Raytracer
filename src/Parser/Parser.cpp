/*
** EPITECH PROJECT, 2024
** Parser
** File description:
** Parser
*/

#include "Parser.hpp"

rtx::Parser::Parser()
{
}

void rtx::Parser::runParser([[maybe_unused]] std::string fileName)
{
    if (fileName.empty())
        throw ParserException("No filename set");
    std::ifstream file(fileName);
    if (!file.is_open())
        throw ParserException("Could not open file");
}

std::vector<std::shared_ptr<rtx::IPrimitive>> rtx::Parser::getPrimitives() const
{
    return this->_primitives;
}

/*
std::vector<Light> getLights() const
{
    return this->_lights;
}
*/

rtx::Camera rtx::Parser::getCamera() const
{
    return this->_camera;
}