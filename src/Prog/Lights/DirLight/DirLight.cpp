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
DirLight::DirLight(Vec3 pos, Vec3 dir, Vec3 color, double intensity)
    : _position(pos), _dir(dir), _color(color), _intensity(intensity)
{
}

DirLight::~DirLight()
{
}

Vec3 Raytracer::DirLight::illuminate(Raytracer::Vec3 point, Raytracer::Scene &scene)
{
    Raytracer::Ray ray = getRayToLight(point);
    Raytracer::HitRecord hit;
    for (auto &shape : scene.getShapes()) {
        hit = shape->intersection(ray);
        if (hit.hit == false)
            continue;
        if (hit.point != point) {
            return Raytracer::Vec3(0,0,0);
        }
    }
    return Raytracer::Vec3(255,255,255);
}

Raytracer::Ray Raytracer::DirLight::getRayToLight(Raytracer::Vec3 point)
{
    return Raytracer::Ray(_position, _dir);
}
}