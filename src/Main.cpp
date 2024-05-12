/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Main
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <list>
#include "Camera.hpp"
#include "Scene.hpp"
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

    rtx::Camera cam = parser.getCamera();
    rtx::RenderSettings settings = cam.settings();
    rtx::Scene scene(cam, parser.getPrimitives(), parser.getLights());

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            image.trySave();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            image.clear(); scene.camera().move(rtx::Vector3d(.0, .0, .1)); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            image.clear(); scene.camera().move(rtx::Vector3d(.0, .0, -.1)); }

        scene.render(image, 20000);
        win.clear();
        win.draw(image.drawable());
        win.display();
    }

    return 0;
}
