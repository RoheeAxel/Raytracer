/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Glass
*/

#include "Glass.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

namespace Raytracer
{
    Glass::Glass(const std::string &options) {
        if (!options.empty())
            std::cerr << "Warning: Options are specified for Glass Material but not needed" << std::endl;
    }

    Vec3 Glass::refract(Vec3 uv, Vec3 n, double etai_over_etat)
    {
        auto cos_theta = fmin((uv * -1).Dot(n), 1.0);
        Vec3 r_out_perp = (uv + n * cos_theta) * etai_over_etat;
        Vec3 r_out_parallel = n * -(sqrt(fabs(1.0 - r_out_perp.Length())));
        return r_out_perp + r_out_parallel;
    }

    Vec3 Glass::getColorAt([[maybe_unused]] HitRecord record, [[maybe_unused]] Ray light, [[maybe_unused]] Vec3 lightColor)
    {
        return {255, 255, 255};
    }

    Vec3 Glass::getNewRay(HitRecord record, Vec3 light) {
        Vec3 Scattered = Vec3(0);
        double refraction_ratio = record.front_face ? (1.0/refractionIndex) : refractionIndex;
        Vec3 unit_direction = light;

        double cos_theta = fmin((unit_direction * -1).Dot(record.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta*cos_theta);
        bool cannot_refract = refraction_ratio * sin_theta > 1.0;

        double r0 = (1-refraction_ratio) / (1+refraction_ratio);
        r0 = r0*r0;
        double reflect_prob = r0 + (1-r0)*pow((1 - cos_theta),5);

        if (cannot_refract || reflect_prob > _random.drand48()) {
            Scattered = light - record.normal * 2 * record.normal.Dot(light);
        } else {
            Scattered = refract(unit_direction, record.normal, refraction_ratio);
        }

        return Scattered;
    }

    double Glass::getReflectivity() {
        return 0.67;
    }

}