/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Transparent
*/

#ifndef TRANSPARENT_HPP_
#define TRANSPARENT_HPP_

#include "IMaterial.hpp"
#include "ParsingUtils.hpp"
#include "Ray.hpp"

namespace Raytracer
{
    class Transparent : public IMaterial{
        public:
            Transparent() = default;
            Transparent(const std::string &options);
            ~Transparent() override = default;

            Vec3 getColorAt(HitRecord record, Ray light, Vec3 lightColor) override;
            Vec3 getNewRay(HitRecord record, Vec3 light) override;
            double getReflectivity() override;
        private:
            double _opacity = 0.5;
            CustomRandom _random;
};
}
#endif /* !TRANSPARENT_HPP_ */
