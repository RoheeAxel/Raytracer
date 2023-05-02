/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Plastic
*/

#ifndef PLASTIC_HPP_
#define PLASTIC_HPP_

#include "IMaterial.hpp"
#include "Ray.hpp"

namespace Raytracer
{
class Plastic : public IMaterial{
    public:
        Plastic();
        Plastic(Vec3 color, double reflectivity, double roughness);
        ~Plastic();
        Vec3 getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor) override;
        Vec3 getNewRay(HitRecord record, Vec3 light) override;
        double getReflectivity() override;
    protected:
    private:
        Vec3 _base_color;
        double _reflectivity;
        double _roughness;
};
}
#endif /* !PLASTIC_HPP_ */
