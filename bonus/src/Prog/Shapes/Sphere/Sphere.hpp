/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "IShape.hpp"

namespace Raytracer {
class Sphere : public IShape{
    public:
        Sphere(Vec3 position, double radius);
        ~Sphere();
        HitRecord intersection(Ray ray);
        void setMaterial(IMaterial *material);
        IMaterial *getMaterial();
    protected:
    private:
        IMaterial *_material;
        Vec3 _position;
        double _radius;
};
}

#endif /* !SPHERE_HPP_ */
