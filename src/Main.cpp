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
    sf::Image img; img.create(settings.width(), settings.height());

    while (win.isOpen()) {
        scene.render(img, 1000);
        sf::Texture tex; tex.loadFromImage(img);
        sf::Sprite sprite(tex);
        sf::Event e;

        while (win.pollEvent(e))
            if (e.type == sf::Event::Closed)
                win.close();
        win.clear();
        win.draw(sprite);
        win.display();
    }

    return 0;
}
