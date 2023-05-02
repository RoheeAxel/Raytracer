/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** IMaterial
*/

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

#include "Vec3.hpp"
#include "HitRecord.hpp"

namespace Raytracer {
class Ray;
class IMaterial {
    public:
        virtual ~IMaterial() = default;
        virtual Vec3 getColorAt(Vec3 point, Vec3 normal, Ray light, Vec3 lightColor) = 0;
        virtual Vec3 getNewRay(HitRecord record, Vec3 light) = 0;
        virtual double getReflectivity() = 0;

    protected:
    private:
};
}

#endif /* !IMATERIAL_HPP_ */
