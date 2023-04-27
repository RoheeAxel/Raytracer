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

namespace Raytracer
{
class Lambertian : public IMaterial{
    public:
        Lambertian();
        Lambertian(Vec3 color);
        ~Lambertian();
        Vec3 getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor) override;
        Vec3 getNewRay(Vec3 point, Vec3 normal, Vec3 light) override;
        double getReflectivity() override;
    protected:
    private:
        Vec3 _base_color;
};
}
#endif /* !LAMBERTIAN_HPP_ */
