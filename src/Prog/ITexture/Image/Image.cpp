/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Image
*/

#include "Image.hpp"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
    #include "stb_image.h"

namespace Raytracer {
    Image::Image(std::string &path)
    {
        _data = stbi_load(path.c_str(), &_size.first, &_size.second, &_channels, STBI_rgb);
        if (_data == nullptr) {
            std::cerr << "Error loading image: " << path << std::endl;
        }
    }

    Raytracer::Image::Image()
    {
    }

    Raytracer::Image::~Image()
    {
        stbi_image_free(_data);
    }

    Vec3 Raytracer::Image::getColorAt(float u, float v)
    {
        if (_data == nullptr) {
            return Vec3(0, 0, 0);
        }
        int x = u * _size.first;
        int y = v * _size.second;
        int pixel_index = (y * _size.first + x) * 3; // RGBA format
        uint8_t r_i = _data[pixel_index];
        uint8_t g_i = _data[pixel_index + 1];
        uint8_t b_i = _data[pixel_index + 2];
        double r = r_i;
        double g = g_i;
        double b = b_i;
        return Vec3(r, g, b);
    }
}