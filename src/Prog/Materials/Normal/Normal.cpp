/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Normal
*/

#include "Normal.hpp"
#include <iostream>

namespace Raytracer
{
Normal::Normal()
{
}

Normal::~Normal()
{
}

Vec3 Normal::getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor)
{
    // double intensity = normal.Dot(light.getDirection());
    Vec3 normalized = (normal+Vec3(1))* 0.5;
    return (normal+Vec3(1))* 0.5 * 255;
    //return Vec3(255, 25, 255) * intensity;
}

Vec3 Normal::getNewRay(HitRecord record, Vec3 light)
{
    return Vec3(0,0,0);
}

double Normal::getReflectivity()
{
    return 0;
}
}