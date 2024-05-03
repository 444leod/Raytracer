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
    rtx::Camera cam = rtx::Camera(M_PI_2, rtx::Vector3d(), rtx::Vector3d(.0, .0, .0));
    rtx::Scene scene(cam);

    sf::RenderWindow win(sf::VideoMode(600, 600), "Window");
    sf::Image img = scene.render(600, 600);
    sf::Texture tex; tex.loadFromImage(img);
    sf::Sprite sprite(tex);

    while (win.isOpen()) {
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
