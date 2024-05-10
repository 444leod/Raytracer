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
        sf::Event e;

        while (win.pollEvent(e))
            if (e.type == sf::Event::Closed) win.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            image.clear(); scene.camera().rotate(rtx::Vector3d(.0, .0, .1)); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            image.clear(); scene.camera().rotate(rtx::Vector3d(.0, .0, -.1)); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            image.clear(); scene.camera().move(rtx::Vector3d(.1, .0, .0)); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            image.clear(); scene.camera().move(rtx::Vector3d(-.1, -.0, .0)); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            image.clear(); scene.camera().move(rtx::Vector3d(.0, -.1, .0)); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            image.clear(); scene.camera().move(rtx::Vector3d(.0, .1, .0)); }

        scene.render(image, 20000);
        win.clear();
        win.draw(image.drawable());
        win.display();
    }

    return 0;
}
