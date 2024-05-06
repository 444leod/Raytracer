/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Main
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Camera.hpp"
#include "Scene.hpp"

int main(
    [[maybe_unused]] int ac,
    [[maybe_unused]] char **av,
    [[maybe_unused]] char **env
)
{
    rtx::RenderSettings settings = rtx::RenderSettings(1080, 720, M_PI_2);
    rtx::Camera cam = rtx::Camera(settings, rtx::Vector3d(), rtx::Vector3d(.0, .0, .0));
    rtx::Scene scene(cam);

    sf::RenderWindow win(settings.toSf(), "Window");
    rtx::Image image = rtx::Image(settings.width(), settings.height());

    while (win.isOpen()) {
        scene.render(image, 1000);
        sf::Event e;

        while (win.pollEvent(e)) {
            if (e.type == sf::Event::Closed) win.close();
            if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::A) image.clear();
        }
        win.clear();
        win.draw(image.drawable());
        win.display();
    }

    return 0;
}
