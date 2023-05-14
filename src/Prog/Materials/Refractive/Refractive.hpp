/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Refractive
*/

#ifndef REFRACTIVE_HPP_
#define REFRACTIVE_HPP_

#include "IMaterial.hpp"
#include "ParsingUtils.hpp"
#include "Ray.hpp"

namespace Raytracer
{
    class Refractive : public IMaterial{
        public:
            Refractive() = default;
            Refractive(const std::string &options);
            ~Refractive() override = default;

            Vec3 refract(Vec3 uv, Vec3 n, double etai_over_etat);
            Vec3 getColorAt(HitRecord record, Ray light, Vec3 lightColor) override;
            Vec3 getNewRay(HitRecord record, Vec3 light) override;
            double getReflectivity() override;
        private:
            double _refractionIndex = 1.5;
            CustomRandom _random;
};
}
#endif /* !REFRACTIVE_HPP_ */
