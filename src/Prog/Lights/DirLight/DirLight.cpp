/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** DirLight
*/

#include "DirLight.hpp"
#include <iostream>
#define EPSILON -0.00001

namespace Raytracer
{
    DirLight::DirLight(const Vec3 &pos, const Vec3 &dir, const Vec3 &color, double intensity)
    : _position(pos), _dir(dir), _color(color), _intensity(intensity) {}

    DirLight::DirLight(const std::string &options) {
        Vec3 pos = ParsingUtils::getVec3(options, "position");
        Vec3 dir = ParsingUtils::getVec3(options, "direction");
        Vec3 color = ParsingUtils::getVec3(options, "color");
        auto intensity = ParsingUtils::getDouble(options, "intensity");

        _position = pos;
        _dir = dir;
        _color = color;
        _intensity = intensity;
    }

    Vec3 Raytracer::DirLight::illuminate(Raytracer::Vec3 point, Raytracer::Scene &scene) {
        Raytracer::Ray ray = getRayToLight(point);
        Raytracer::HitRecord hit;
        for (auto &shape : scene.getShapes()) {
            hit = shape->intersection(ray);
            if (!hit.hit)
                continue;
            if ((hit.distance - (point - _position).Length()) < EPSILON) {
                return {0,0,0};
            }
        }
        return _color * _intensity;
    }

    Raytracer::Ray Raytracer::DirLight::getRayToLight([[maybe_unused]]Raytracer::Vec3 point) {
        return {_position, _dir};
    }

    void DirLight::setPosition(const Vec3 &position)
    {
        this->_position = position;
    }

    void DirLight::setDir(const Vec3 &dir)
    {
        this->_dir = dir;
    }

    void DirLight::setColor(const Vec3 &color)
    {
        this->_color = color;
    }

    void DirLight::setIntensity(double intensity)
    {
        this->_intensity = intensity;
    }

}
