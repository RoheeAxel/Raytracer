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

        try {
            std::string path = ParsingUtils::getString(options, "path");
            _tex = std::make_shared<Image>(path);
        } catch (Exception &e) {}
        try {
            std::string path = ParsingUtils::getString(options, "normal_map");
            _normalMap = std::make_shared<Image>(path);
            double intensity = ParsingUtils::getDouble(options, "normal_intensity");
            _normalIntensity = intensity;
        } catch (Exception &e) {}
    }

    Vec3 Reflective::getColorAt(HitRecord record, Ray light, [[maybe_unused]]Vec3 lightColor) {
        double intensity;
        if (light.getDirection() == Vec3(0))
            intensity = 1;
        else
            intensity = -record.normal.Dot(light.getDirection());

        Vec3 color_at_point = _base_color;
        if (_tex != nullptr)
            color_at_point = _tex->getColorAt(record.uv.first, record.uv.second);
        return (color_at_point * intensity).Clamp(0, 255);
    }

    Vec3 Reflective::getNewRay(HitRecord record, Vec3 light) {
        Vec3 normalAtPoint = record.normal;
        if (_normalMap != nullptr) {
            normalAtPoint = (record.normal + (_normalMap->getColorAt(record.uv.first, record.uv.second) / 255 * 2 - 1) * _normalIntensity).Normalize();
        }

        Vec3 scatterdLight = light - normalAtPoint * 2 * record.normal.Dot(light);
        scatterdLight = scatterdLight + Vec3(0).random() * _roughness;
        return scatterdLight;
    }

    double Reflective::getReflectivity() {
        return 1;
    }

}
