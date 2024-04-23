/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Main
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Camera.hpp"
#include "Scene.hpp"

int main(
    [[maybe_unused]] int ac,
    [[maybe_unused]] char **av,
    [[maybe_unused]] char **env
)
{
    rtx::Camera cam = rtx::Camera(72, rtx::Vector3d(), rtx::Vector3d(.0, .0, M_PI));
    rtx::Scene scene(cam);

    scene.renderImage(600, 600);
    return 0;
}
