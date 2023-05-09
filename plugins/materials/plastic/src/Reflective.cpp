/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Reflective
*/

#include "Reflective.hpp"
#include <iostream>

namespace Raytracer
{
    Reflective::Reflective() {
        _base_color = Vec3(255 * 0.8, 255 * 0.6, 255 * 0.2);
        _reflectivity = 0.5;
        _roughness = 0;
    }

    Reflective::Reflective(const Vec3& color, double reflectivity, double roughness) {
        _base_color = color;
        _reflectivity = reflectivity;
        _roughness = roughness;
    }

    Reflective::Reflective(const std::string &options) {
        Vec3 color = ParsingUtils::getVec3(options, "color");
        _base_color = color;

        auto reflectivity = ParsingUtils::getDouble(options, "reflectivity");
        _reflectivity = reflectivity;

        auto roughness = ParsingUtils::getDouble(options, "roughness");
        _roughness = roughness;
    }

    Vec3 Reflective::getColorAt([[maybe_unused]]HitRecord record, [[maybe_unused]]Ray light, [[maybe_unused]]Vec3 lightColor) {
        // double intensity = normal.Dot(light.getDirection());
        return _base_color;
    }

    Vec3 Reflective::getNewRay(HitRecord record, Vec3 light) {
        Vec3 scatterdLight = light - record.normal * 2 * record.normal.Dot(light);
        scatterdLight = scatterdLight + Vec3(0).random() * _roughness;
        return scatterdLight;
    }

    double Reflective::getReflectivity() {
        return _reflectivity;
    }

}

extern "C" Raytracer::Reflective *create(const std::string &options) {
    return new Raytracer::Reflective(options);
}