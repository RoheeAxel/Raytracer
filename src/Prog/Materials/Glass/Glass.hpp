/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Glass
*/

#ifndef GLASS_HPP_
#define GLASS_HPP_

#include "IMaterial.hpp"
#include "Ray.hpp"

namespace Raytracer
{
    class Glass : public IMaterial{
        public:
            Glass() = default;
            Glass(const std::string &options);
            ~Glass() override = default;

            Vec3 refract(Vec3 uv, Vec3 n, double etai_over_etat);
            Vec3 getColorAt(HitRecord record, Ray light, Vec3 lightColor) override;
            Vec3 getNewRay(HitRecord record, Vec3 light) override;
            double getReflectivity() override;
        private:
            double refractionIndex = 1.5;
            CustomRandom _random;
};
}
#endif /* !GLASS_HPP_ */
