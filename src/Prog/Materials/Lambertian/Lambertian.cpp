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
        Vec3 color = ParsingUtils::getVec3(options, "color");
        this->_base_color = color;
    }

    Vec3 Lambertian::getColorAt(HitRecord record, Ray light, [[maybe_unused]]Vec3 lightColor) {
        double intensity;
        Vec3 unit_light;
        if (light.getDirection() == Vec3(0))
            intensity = 1;
        else
            intensity = -record.normal.Dot(light.getDirection());

        unit_light = lightColor / 255;
        Vec3 color_at_point = _base_color;
        Raytracer::Dammier dam;
        color_at_point = dam.getColorAt(record.uv.first, record.uv.second);

        return (color_at_point  * intensity * unit_light).Clamp(0, 255);
    }

    Vec3 Lambertian::getNewRay(HitRecord record, [[maybe_unused]]Vec3 light) {
        Vec3 p = Vec3(drand48() * 2 - 1, drand48() * 2 - 1, drand48() * 2 - 1);
        Vec3 inSphere = (record.normal + p).Normalize();

        if (inSphere.Dot(record.normal) > 0.0)
            return inSphere;
        else
            return inSphere * -1;
    }

    double Lambertian::getReflectivity() {
        return 0.5;
    }
}