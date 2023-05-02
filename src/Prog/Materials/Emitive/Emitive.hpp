/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Emitive
*/

#ifndef EMITIVE_HPP_
#define EMITIVE_HPP_

#include "IMaterial.hpp"
#include "Ray.hpp"

namespace Raytracer
{
class Emitive : public IMaterial{
    public:
        Emitive();
        Emitive(Vec3 color);
        ~Emitive();
        Vec3 getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor) override;
        Vec3 getNewRay(HitRecord record, Vec3 light) override;
        double getReflectivity() override;
    protected:
    private:
        Vec3 _base_color;
};
}
#endif /* !EMITIVE_HPP_ */
