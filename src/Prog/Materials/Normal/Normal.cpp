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
    Normal::Normal(const std::string &options) {
        if (!options.empty()) {
            std::cerr << "Normal does not take any options" << std::endl;
        }
    }

    Vec3 Normal::getColorAt([[maybe_unused]]Vec3 point, Vec3 normal, [[maybe_unused]]Ray light, [[maybe_unused]]Vec3 lightColor) {
        // double intensity = normal.Dot(light.getDirection());
        Vec3 normalized = (normal+Vec3(1))* 0.5;
        return (normal+Vec3(1))* 0.5 * 255;
        //return Vec3(255, 25, 255) * intensity;
    }

    Vec3 Normal::getNewRay([[maybe_unused]]HitRecord record, [[maybe_unused]]Vec3 light) {
        return {0,0,0};
    }

    double Normal::getReflectivity() {
        return 0;
    }
}