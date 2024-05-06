/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Image
*/

#pragma once

#include <cstdint>
#include <cstring>
#include "Color.hpp"
#include <SFML/Graphics.hpp>

namespace rtx {
    class Image {
        public:
            Image(uint32_t width, uint32_t height);
            ~Image();
            void set(uint32_t x, uint32_t y, Color color);
            void clear(Color color = Color());
            sf::Sprite drawable();
            uint32_t width() const;
            uint32_t height() const;
            uint8_t *array() const;

        protected:
        private:
            uint32_t _width;
            uint32_t _height;
            uint8_t *_array;
            sf::Texture _tex;
    };
}
