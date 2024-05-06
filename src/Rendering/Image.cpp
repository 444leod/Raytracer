/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Image
*/

#include <iostream>
#include "Image.hpp"

rtx::Image::Image(u_int32_t width, u_int32_t height)
    : _width(width), _height(height)
{
    this->_array = static_cast<uint8_t *>(std::malloc(width * height * 4));
    if (this->_array == NULL)
        throw std::runtime_error("Memory error. Could not create pixel array for rtx::Image");
}

rtx::Image::~Image()
{
}

void rtx::Image::set(uint32_t x, uint32_t y, Color color)
{
    auto i = this->_width * 4 * y + x * 4;

    this->_array[i + 0] = color.r;
    this->_array[i + 1] = color.g;
    this->_array[i + 2] = color.b;
    this->_array[i + 3] = 255;
}

void rtx::Image::clear(Color color)
{
    for (uint32_t i = 0; i < this->_width * this->_height * 4; i += 4) {
        this->_array[i + 0] = color.r;
        this->_array[i + 1] = color.g;
        this->_array[i + 2] = color.b;
        this->_array[i + 3] = 255;
    }
}

sf::Sprite rtx::Image::drawable()
{
    auto img = sf::Image();

    img.create(this->_width, this->_height, this->_array);
    this->_tex.loadFromImage(img);
    return sf::Sprite(this->_tex);
}

uint32_t rtx::Image::width() const
{
    return this->_width;
}

uint32_t rtx::Image::height() const
{
    return this->_height;
}

uint8_t *rtx::Image::array() const
{
    return this->_array;
}
