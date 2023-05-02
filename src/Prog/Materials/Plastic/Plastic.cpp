/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Plastic
*/

#include "Plastic.hpp"
#include <iostream>

namespace Raytracer
{
Plastic::Plastic()
{
    _base_color = Vec3(255 * 0.8, 255 * 0.6, 255 * 0.2);
    _reflectivity = 0.5;
    _roughness = 0;
}

Plastic::Plastic(Vec3 color, double reflectivity, double roughness)
{
    _base_color = color;
    _reflectivity = reflectivity;
    _roughness = roughness;
}

Plastic::~Plastic()
{
}

Vec3 Plastic::getColorAt([[maybe_unused]]Vec3 point, [[maybe_unused]]Vec3 normal, [[maybe_unused]]Ray light, [[maybe_unused]]Vec3 lightColor)
{
    // double intensity = normal.Dot(light.getDirection());
    return _base_color;
}

Vec3 Plastic::getNewRay(HitRecord record, Vec3 light)
{
    Vec3 scatterdLight = light - record.normal * 2 * record.normal.Dot(light);
    scatterdLight = scatterdLight + Vec3(0).random() * _roughness;
    return scatterdLight;
}

double Plastic::getReflectivity()
{
    return _reflectivity;
}

}