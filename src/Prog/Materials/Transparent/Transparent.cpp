/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Transparent
*/

#include "Transparent.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

namespace Raytracer
{
    Transparent::Transparent(const std::string &options) {
        double opacity = ParsingUtils::getDouble(options, "opacity");
        this->_opacity = opacity;
    }

    Vec3 Transparent::getColorAt([[maybe_unused]] HitRecord record, [[maybe_unused]] Ray light, [[maybe_unused]] Vec3 lightColor)
    {
        return {255, 255, 255};
    }

    Vec3 Transparent::getNewRay([[maybe_unused]]HitRecord record, Vec3 light) {
        return light.Normalize();
    }

    double Transparent::getReflectivity() {
        return 1 - _opacity;
    }

}