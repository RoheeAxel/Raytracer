/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Emitive
*/

#include "Emitive.hpp"
#include <iostream>

namespace Raytracer
{
    Emitive::Emitive() {
    _base_color = Vec3(500, 500, 500);
    }

    Emitive::Emitive(const Vec3 &color) {
        _base_color = color;
    }

    Emitive::Emitive(const std::string &options) {
        try {
            std::string path = ParsingUtils::getString(options, "path");
            _tex = std::make_shared<Image>(path);
        } catch (Exception &e) {}
        Vec3 color = ParsingUtils::getVec3(options, "color");
        double intensity = ParsingUtils::getDouble(options, "intensity");
        this->_base_color = color;
        this->_intensity = intensity;
    }

    Vec3 Emitive::getColorAt([[maybe_unused]]HitRecord record, [[maybe_unused]]Ray light, [[maybe_unused]]Vec3 lightColor) {
        Vec3 color_at_point = _base_color;
        if (_tex != nullptr)
            color_at_point = _tex->getColorAt(record.uv.first, record.uv.second);
        return color_at_point * _intensity;
    }

    Vec3 Emitive::getNewRay([[maybe_unused]] HitRecord record, [[maybe_unused]] Vec3 light)
    {
        return {0, 0, 0};
    }

    double Emitive::getReflectivity() {
        return 0;
    }
}