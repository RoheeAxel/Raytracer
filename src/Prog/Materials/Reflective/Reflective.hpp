/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Reflective
*/

#ifndef REFLECTIVE_HPP_
#define REFLECTIVE_HPP_

#include "IMaterial.hpp"
#include "Ray.hpp"
#include "ParsingUtils.hpp"

namespace Raytracer
{
class Reflective : public IMaterial{
    public:
        Reflective();
        Reflective(const Vec3& color, double reflectivity, double roughness);
        Reflective(const std::string &);
        ~Reflective() override = default;

        Vec3 getColorAt(HitRecord record, Ray light, Vec3 lightColor) override;
        Vec3 getNewRay(HitRecord record, Vec3 light) override;
        double getReflectivity() override;

    private:
        Vec3 _base_color;
        double _reflectivity;
        double _roughness;
};
}
#endif /* !REFLECTIVE_HPP_ */
