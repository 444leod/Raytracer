/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Image
*/

#pragma once

#include <optional>
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
            std::optional<uint32_t> randindex();

        protected:
        private:
            uint32_t _width = 0;
            uint32_t _height = 0;
            uint8_t *_array = nullptr;
            sf::Texture _tex;
            std::vector<uint32_t> _unrendered = {};
            uint32_t _unrendered_idx = 0;
    };
}
