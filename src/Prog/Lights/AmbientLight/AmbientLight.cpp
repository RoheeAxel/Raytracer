/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** AmbientLight
*/

#include "AmbientLight.hpp"
#include <iostream>
#include <iomanip>

#define EPSILON -0.0001

namespace Raytracer
{
    AmbientLight::AmbientLight(const Vec3 &color, double intensity)
    : _color(color), _intensity(intensity) {}

    Vec3 Raytracer::AmbientLight::illuminate([[maybe_unused]]Raytracer::Vec3 point, [[maybe_unused]]Raytracer::Scene &scene) {
        return _color * _intensity;
    }

    Raytracer::Ray Raytracer::AmbientLight::getRayToLight(Raytracer::Vec3 point) {
        return {point, Vec3(0)};
    }

    void AmbientLight::setColor(const Vec3 &color) {
        this->_color = color;
    }

    void AmbientLight::setIntensity(double intensity) {
        this->_intensity = intensity;
    }

}