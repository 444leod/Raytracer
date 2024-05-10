/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Main
*/

#include <iostream>
#include <string>

#include "Vector.hpp"
#include "Camera.hpp"
#include "Parser.hpp"

int main(
    [[maybe_unused]] int ac,
    char **av,
    [[maybe_unused]] char **env
)
{
    if (av[1] == nullptr || !std::string(av[1]).compare("--help")) {
        std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration" << std::endl;
        return 84;
    }
    rtx::Parser parser = rtx::Parser();
    try {
        parser.runParser(std::string(av[1]));
    } catch (rtx::Parser::ParserException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    std::cout << parser.getCamera()->position() << " " << parser.getCamera()->rotation() << std::endl;
    std::cout << parser.getCamera()->forward() << std::endl;
    for (auto &primitive : parser.getPrimitives()) {
        std::cout << primitive->position() << std::endl;
    }
    return 0;
}
