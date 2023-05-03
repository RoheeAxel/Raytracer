/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** PointLight
*/

#include "PointLight.hpp"
#include <iostream>
#include <iomanip>

#define EPSILON -0.0001

namespace Raytracer
{
    PointLight::PointLight(const Vec3 &position, const Vec3 &color, double intensity)
    : _position(position), _color(color), _intensity(intensity) {}

    PointLight::PointLight(const std::string &options) {
        Vec3 position = ParsingUtils::getVec3(options, "position");
        Vec3 color = ParsingUtils::getVec3(options, "color");
        auto intensity = ParsingUtils::getDouble(options, "intensity");

        _position = position;
        _color = color;
        _intensity = intensity;
    }

    Vec3 Raytracer::PointLight::illuminate(Raytracer::Vec3 point, Raytracer::Scene &scene) {
        Raytracer::Ray ray = getRayToLight(point);
        Raytracer::HitRecord hit;
        for (auto &shape : scene.getShapes()) {
            hit = shape->intersection(ray);
            if (hit.hit && (hit.distance - (point - _position).Length()) < EPSILON) {
                return {0, 0, 0};
            }
        }
        return _color;
    }

    Raytracer::Ray Raytracer::PointLight::getRayToLight(Raytracer::Vec3 point)
    {
        Vec3 direction = point;
        direction -= _position;
        Raytracer::Ray ray(_position, direction.Normalize());
        return ray;
    }

    void PointLight::setPosition(const Vec3 &position) {
        this->_position = position;
    }

    void PointLight::setColor(const Vec3 &color) {
        this->_color = color;
    }

    void PointLight::setIntensity(double intensity) {
        this->_intensity = intensity;
    }

}