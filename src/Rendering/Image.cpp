/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Image
*/

#include "Image.hpp"
#include <mutex>
#include <iostream>
#include <sstream>
#include <fstream>

rtx::Image::Image(std::uint32_t width, std::uint32_t height)
    : _width(width), _height(height)
{
    for (std::uint32_t i = 0; i < width * height; i++)
        this->_unrendered.push_back(i);
    auto rng = std::default_random_engine();
    std::shuffle(this->_unrendered.begin(), this->_unrendered.end(), rng);
    this->_array = static_cast<uint8_t *>(std::malloc(width * height * 4));
    if (this->_array == NULL)
        throw std::runtime_error("Memory error. Could not create pixel array for rtx::Image");
}

rtx::Image::~Image()
{
    //std::free(this->_array);
}

void rtx::Image::set(std::uint32_t x, std::uint32_t y, Color color)
{
    static std::mutex mtx;
    auto i = this->_width * 4 * y + x * 4;

    mtx.lock();
    this->_array[i + 0] = color.r;
    this->_array[i + 1] = color.g;
    this->_array[i + 2] = color.b;
    this->_array[i + 3] = 255;
    mtx.unlock();
}

void rtx::Image::clear(Color color)
{
    this->_unrendered_idx = 0;
    for (std::uint32_t i = 0; i < this->_width * this->_height * 4; i += 4) {
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

std::uint32_t rtx::Image::width() const
{
    return this->_width;
}

std::uint32_t rtx::Image::height() const
{
    return this->_height;
}

uint8_t *rtx::Image::array() const
{
    return this->_array;
}

std::optional<std::uint32_t> rtx::Image::randindex()
{
    if (this->_unrendered_idx >= this->_unrendered.size())
        return std::nullopt;
    this->_unrendered_idx++;
    return this->_unrendered.at(this->_unrendered_idx - 1);
}

void rtx::Image::trySave()
{
    if (this->_unrendered_idx != this->width() * this->height())
        return;
    auto img = sf::Image();
    std::string filename;

    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::stringstream ss;
    ss << filename << ".ppm";

    std::ofstream file(ss.str());
    if (!file) {
        std::cerr << "Cannot open file for writing\n";
        throw(std::runtime_error("Cannot open file for writing"));
    }

    file << "P3\n" << this->width() << " " << this->height() << "\n255\n";
    for (uint32_t i = 0; i < this->width() * this->height(); i++)
    {
        file << static_cast<int>(this->_array[i * 4 + 0]) << " ";
        file << static_cast<int>(this->_array[i * 4 + 1]) << " ";
        file << static_cast<int>(this->_array[i * 4 + 2]) << " ";
    }

    file.close();
    std::cout << "Image saved as " << ss.str() << std::endl;
}
