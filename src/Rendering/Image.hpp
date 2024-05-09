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
            Image(std::uint32_t width, std::uint32_t height);
            ~Image();
            void set(std::uint32_t x, std::uint32_t y, Color color);
            void clear(Color color = Color());
            sf::Sprite drawable();
            std::uint32_t width() const;
            std::uint32_t height() const;
            uint8_t *array() const;
            std::optional<std::uint32_t> randindex();

        protected:
        private:
            std::uint32_t _width = 0;
            std::uint32_t _height = 0;
            uint8_t *_array = nullptr;
            sf::Texture _tex;
            std::vector<std::uint32_t> _unrendered = {};
            std::uint32_t _unrendered_idx = 0;
    };
}
