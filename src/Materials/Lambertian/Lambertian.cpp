/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Lambertian
*/

#include "Lambertian.hpp"
#include <iostream>

namespace Raytracer
{
Lambertian::Lambertian()
{
    _base_color = Vec3(255, 255, 255);
}

Lambertian::Lambertian(Vec3 color)
{
    _base_color = color;
}

Lambertian::~Lambertian()
{
}

Vec3 Lambertian::getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor)
{
    double intensity = normal.Dot(light.getDirection());
    return _base_color * intensity;
    //return Vec3(255, 25, 255) * intensity;
}

Vec3 Lambertian::getNewRay(Vec3 point, Vec3 normal, Vec3 light)
{
    Vec3 p = Vec3(rand() / (RAND_MAX + 1.0) * 2 - 1, rand() / (RAND_MAX + 1.0) * 2 - 1, rand() / (RAND_MAX + 1.0) * 2 - 1);

    return light - normal * 2 * normal.Dot(light) + p * 0.8;
    while (true) {
        Vec3 p = Vec3(rand() / (RAND_MAX + 1.0) * 2 - 1, rand() / (RAND_MAX + 1.0) * 2 - 1, rand() / (RAND_MAX + 1.0) * 2 - 1);
        if (p.Length() >= 1)
            continue;
        return p;
    }
}
}