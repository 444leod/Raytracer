/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Color
*/

#pragma once

#include <cstdint>
#include <algorithm>
#include <SFML/Graphics/Color.hpp>

namespace rtx {
    class Color {
        public:
            Color() = default;
            Color(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b)
                :   r(std::clamp<std::uint8_t>(_r, 0, 255)),
                    g(std::clamp<std::uint8_t>(_g, 0, 255)),
                    b(std::clamp<std::uint8_t>(_b, 0, 255)) {}
            ~Color() = default;

            Color operator*(double factor) const { return Color(this->r * factor, this->g * factor, this->b * factor); }
            Color operator+(const Color& o) const { return Color(this->r + o.r, this->g + o.g, this->b + o.b); }
            sf::Color asSf() const { return sf::Color(this->r, this->g, this->b); }

            std::uint8_t r = 0;
            std::uint8_t g = 0;
            std::uint8_t b = 0;
    };
}

inline std::ostream& operator<<(std::ostream& stream, const rtx::Color& color)
{
    stream << "{" << color.r << ", " << color.g << ", " << color.b << "}";
    return stream;
}
