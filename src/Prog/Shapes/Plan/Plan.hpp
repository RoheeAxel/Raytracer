/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Plan
*/

#ifndef PLAN_HPP_
#define PLAN_HPP_

#include "IShape.hpp"

namespace Raytracer {
class Plan : public IShape{
    public:
        Plan(Vec3 position);
        ~Plan();
        HitRecord intersection(Ray ray);
        void setMaterial(IMaterial *material);
        IMaterial *getMaterial();
    protected:
    private:
        IMaterial *_material;
        Vec3 _position;
        Vec3 _normal;
        Vec3 _center;
};
}

#endif /* !PLAN_HPP_ */
