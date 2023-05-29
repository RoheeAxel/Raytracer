/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Lambertian
*/

#include "Lambertian.hpp"
#include <iostream>

namespace Raytracer
{
    Lambertian::Lambertian() {
        _base_color = Vec3(255, 255, 255);
    }

    Lambertian::Lambertian(const Vec3& color) {
        _base_color = color;
    }

    Lambertian::Lambertian(const std::string &options) {
        try {
            std::string path = ParsingUtils::getString(options, "path");
            _tex = std::make_shared<Image>(path);
        } catch (Exception &e) {}
        try {
            std::string path = ParsingUtils::getString(options, "dammier");
            _tex = std::make_shared<Dammier>();
        } catch (Exception &e) {}
        try {
            std::string path = ParsingUtils::getString(options, "normal_map");
            _normalMap = std::make_shared<Image>(path);
            double intensity = ParsingUtils::getDouble(options, "normal_intensity");
            _normalIntensity = intensity;
        } catch (Exception &e) {}
        Vec3 color = ParsingUtils::getVec3(options, "color");
        this->_base_color = color;
    }

    Vec3 Lambertian::getColorAt(HitRecord record, Ray light, Vec3 lightColor) {
        double intensity;
        Vec3 unit_light;
        if (light.getDirection() == Vec3(0))
            intensity = 1;
        else
            intensity = -record.normal.Dot(light.getDirection());

        unit_light = lightColor / 255;
        Vec3 color_at_point = _base_color;
        if (_tex != nullptr)
            color_at_point = _tex->getColorAt(record.uv.first, record.uv.second);
        return (color_at_point  * intensity * unit_light).Clamp(0, 255);
    }

    Vec3 Lambertian::getNewRay(HitRecord record, [[maybe_unused]]Vec3 light) {
        Vec3 normalAtPoint = record.normal;
        if (_normalMap != nullptr) {
            normalAtPoint = (record.normal + (_normalMap->getColorAt(record.uv.first, record.uv.second) / 255 * 2 - 1) * _normalIntensity).Normalize();
        }
        Vec3 p = Vec3(_random.drand48() * 2 - 1, _random.drand48() * 2 - 1, _random.drand48() * 2 - 1);
        Vec3 inSphere = (normalAtPoint + p).Normalize();

        if (inSphere.Dot(normalAtPoint) > 0.0)
            return inSphere;
        else
            return inSphere * -1;
    }

    double Lambertian::getReflectivity() {
        return 0.2;
    }
}