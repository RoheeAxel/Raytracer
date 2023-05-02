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
        Glass();
        ~Glass();
        Vec3 getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor) override;
        Vec3 getNewRay(Vec3 point, Vec3 normal, Vec3 light) override;
        double getReflectivity() override;
    protected:
    private:
        double refractionIndex = 1.5;
};
}
#endif /* !GLASS_HPP_ */
