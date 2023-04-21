/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** DirLight
*/

#include "DirLight.hpp"
#include <iostream>

namespace Raytracer
{
DirLight::DirLight(Vec3 dir, Vec3 color, double intensity)
    : _dir(_dir), _color(color), _intensity(intensity)
{
}

DirLight::~DirLight()
{
}

Vec3 Raytracer::DirLight::illuminate(Raytracer::Vec3 point, Raytracer::Scene &scene)
{
    return Raytracer::Vec3(255,255,255);
}

Raytracer::Ray Raytracer::DirLight::getRayToLight(Raytracer::Vec3 point)
{
    return Raytracer::Ray(Vec3(0, 0, 0), point);
}
}