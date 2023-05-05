/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Lambertian
*/

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

#include "IMaterial.hpp"
#include "Ray.hpp"
#include "ParsingUtils.hpp"
#include "Dammier.hpp"

namespace Raytracer
{
    class Lambertian : public IMaterial{
        public:
            Lambertian();
            Lambertian(const Vec3& color);
            Lambertian(const std::string &options);
            ~Lambertian() override = default;

            Vec3 getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor) override;
            Vec3 getNewRay(HitRecord record, Vec3 light) override;
            double getReflectivity() override;
        private:
            Vec3 _base_color;
};
}
#endif /* !LAMBERTIAN_HPP_ */
