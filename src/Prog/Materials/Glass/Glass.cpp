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
Glass::Glass()
{
}

Glass::~Glass()
{
}

Vec3 Glass::getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor)
{
    double intensity = normal.Dot(light.getDirection());
    return Vec3(255, 255, 255) * intensity;
}

Vec3 Glass::getNewRay(Vec3 point, Vec3 normal, Vec3 light)
{

    double refraction_ratio = refractionIndex;//rec.front_face ? (1.0/refractionIndex) : refractionIndex;
    Vec3 p = Vec3(drand48() * 2 - 1, drand48() * 2 - 1, drand48() * 2 - 1);

    double cos_theta = fmin((p * -1).Dot(normal), 1.0);
    Vec3 r_out_perp =  (p + normal * cos_theta) * refraction_ratio;
    Vec3 r_out_parallel = normal * -(sqrt(fabs(1.0 - r_out_perp.Length())));
    return r_out_perp + r_out_parallel;
}

double Glass::getReflectivity()
{
    return 0.67;
}

}