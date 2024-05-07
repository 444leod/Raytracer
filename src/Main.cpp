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
    [[maybe_unused]] char **av,
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
    // rtx::Camera cam = rtx::Camera(72, rtx::Vector3d(), rtx::Vector3d(.0, .0, M_PI));
    rtx::Camera cam = rtx::Camera();
    std::cout << cam.position() << " " << cam.rotation() << std::endl;
    std::cout << cam.forward() << std::endl;
    return 0;
}
