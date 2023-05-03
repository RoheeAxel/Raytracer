/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Normal
*/

#ifndef NORMA_HPP_
#define NORMA_HPP_

#include "IMaterial.hpp"
#include "Ray.hpp"

namespace Raytracer
{
class Normal : public IMaterial{
    public:
        Normal() = default;
        Normal(const std::string &);
        ~Normal() override = default;

        Vec3 getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor) override;
        Vec3 getNewRay(HitRecord record, Vec3 light) override;
        double getReflectivity() override;
};
}
#endif /* !NORMA_HPP_ */
