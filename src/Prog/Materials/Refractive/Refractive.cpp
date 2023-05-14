/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Refractive
*/

#include "Refractive.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

namespace Raytracer
{
    Refractive::Refractive(const std::string &options) {
       double refractionIndex = ParsingUtils::getDouble(options, "refractionIndex");
        this->_refractionIndex = refractionIndex;
    }

    Vec3 Refractive::refract(Vec3 uv, Vec3 n, double etai_over_etat)
    {
        auto cos_theta = fmin((uv * -1).Dot(n), 1.0);
        Vec3 r_out_perp = (uv + n * cos_theta) * etai_over_etat;
        Vec3 r_out_parallel = n * -(sqrt(fabs(1.0 - r_out_perp.Length())));
        return r_out_perp + r_out_parallel;
    }

    Vec3 Refractive::getColorAt([[maybe_unused]] HitRecord record, [[maybe_unused]] Ray light, [[maybe_unused]] Vec3 lightColor)
    {
        return {255, 255, 255};
    }

    Vec3 Refractive::getNewRay(HitRecord record, Vec3 light) {
        Vec3 Scattered = Vec3(0);
        double refraction_ratio = record.front_face ? (1.0/_refractionIndex) : _refractionIndex;
        Vec3 unit_direction = light;
        Scattered = refract(unit_direction, record.normal, refraction_ratio);

        return Scattered;
    }

    double Refractive::getReflectivity() {
        return 1;
    }

}