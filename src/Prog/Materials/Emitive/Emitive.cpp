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

Vec3 Emitive::getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor)
{
    return _base_color;
}

Vec3 Emitive::getNewRay(HitRecord record, Vec3 light)
{
    return Vec3(0, 0, 0);
}

double Emitive::getReflectivity()
{
    return 0;
}
}