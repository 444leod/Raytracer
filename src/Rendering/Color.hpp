/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Color
*/

#pragma once

#include <cstdint>

namespace rtx {
    class Color {
        public:
            Color() = default;
            Color(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b)
                : r(_r), g(_g), b(_b) {}
            ~Color() = default;

        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
    };
}
