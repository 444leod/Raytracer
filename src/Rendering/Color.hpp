/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Color
*/

#pragma once

#include <cstdint>
#include <algorithm>
#include <ostream>
#include <SFML/Graphics/Color.hpp>

namespace rtx {
    class Color {
        public:
            Color() = default;
            Color(int _r, int _g, int _b)
                :   r(std::clamp<int>(_r, 0, 255)),
                    g(std::clamp<int>(_g, 0, 255)),
                    b(std::clamp<int>(_b, 0, 255)) {}
            ~Color() = default;

            Color operator*(double factor) const { return Color(this->r * factor, this->g * factor, this->b * factor); }
            Color operator+(const Color& o) const { return Color(this->r + o.r, this->g + o.g, this->b + o.b); }
            sf::Color asSf() const { return sf::Color(this->r, this->g, this->b); }

            int r = 0;
            int g = 0;
            int b = 0;
    };
}

inline std::ostream& operator<<(std::ostream& stream, const rtx::Color& color)
{
    stream << "{" << static_cast<std::uint32_t>(color.r) << ", " << static_cast<std::uint32_t>(color.g) << ", " << static_cast<std::uint32_t>(color.b) << "}";
    return stream;
}
