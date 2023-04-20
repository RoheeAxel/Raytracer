/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** PointLight
*/

#include "PointLight.hpp"
#include <iostream>

namespace Raytracer
{
PointLight::PointLight(Vec3 position, Vec3 color, double intensity)
    : _position(position), _color(color), _intensity(intensity)
{
}

PointLight::~PointLight()
{
}

Vec3 Raytracer::PointLight::illuminate(Raytracer::Vec3 point, Raytracer::Scene &scene)
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

Raytracer::Ray Raytracer::PointLight::getRayToLight(Raytracer::Vec3 point)
{
    Vec3 direction = point;
    direction -= _position;
    direction.x *= -1;
    direction.y *= -1;
    Raytracer::Ray ray(_position, direction.Normalize());
    return ray;
}
}