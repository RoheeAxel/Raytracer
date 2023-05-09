/*
** EPITECH PROJECT, 2023
** final
** File description:
** CameraBuilder.cpp
*/

#include "CameraBuilder.hpp"

namespace Raytracer {
    CameraBuilder &CameraBuilder::setPosition(const Vec3 &position)
    {
        _position = position;
        return *this;
    }

    CameraBuilder &CameraBuilder::setRotation(const Vec3 &rotation)
    {
        _rotation = rotation;
        return *this;
    }

    CameraBuilder &CameraBuilder::setScreen(const Screen &screen)
    {
        _screen = screen;
        return *this;
    }

    CameraBuilder &CameraBuilder::setId(size_t id)
    {
        _id = id;
        return *this;
    }

    CameraBuilder &CameraBuilder::setSamplePerPixel(int sample_per_pixel)
    {
        _sample_per_pixel = sample_per_pixel;
        return *this;
    }

    Camera CameraBuilder::build()
    {
        return Camera(_position, _rotation, _screen, _id, _sample_per_pixel);
    }
} // Raytracer