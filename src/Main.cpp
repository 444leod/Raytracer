/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Main
*/

#include <iostream>
#include "Vector.hpp"
#include "Camera.hpp"

int main(
    [[maybe_unused]] int ac,
    [[maybe_unused]] char **av,
    [[maybe_unused]] char **env
)
{
    rtx::Camera cam = rtx::Camera(72, rtx::Vector3d(), rtx::Vector3d(.0, .0, M_PI));
    std::cout << cam.forward() << std::endl;
    return 0;
}
