/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Vec3.hpp"
#include "IMaterial.hpp"

namespace Raytracer {
struct HitRecord
{
    bool hit;
    Raytracer::Vec3 point;
    Raytracer::Vec3 light;
    Raytracer::Vec3 normal;
    Raytracer::IMaterial *material;
};
class Ray {
    public:
        Ray(Vec3 origin, Vec3 direction) : _origin(origin), _direction(direction) {};
        ~Ray();

        Raytracer::Vec3 getOrigin();
        Raytracer::Vec3 getDirection();

    protected:
    private:
        Raytracer::Vec3 _origin;
        Raytracer::Vec3 _direction;
};
}

#endif /* !RAY_HPP_ */
