/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Emitive
*/

#include "Emitive.hpp"
#include <iostream>

namespace Raytracer
{
Emitive::Emitive()
{
    _base_color = Vec3(500, 500, 500);
}

Emitive::Emitive(Vec3 color)
{
    _base_color = color;
}

Emitive::~Emitive()
{
}

Vec3 Emitive::getColorAt([[maybe_unused]]Vec3 point, [[maybe_unused]]Vec3 normal, [[maybe_unused]]Ray light, [[maybe_unused]]Vec3 lightColor)
{
    return _base_color;
}

Vec3 Emitive::getNewRay([[maybe_unused]]HitRecord record, [[maybe_unused]]Vec3 light)
{
    return Vec3(0, 0, 0);
}

double Emitive::getReflectivity()
{
    return 0;
}
}