/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "IShape.hpp"

namespace Raytracer {
class AABB;
class Triangle : public IShape{
    public:
        Triangle(Vec3 vertice1, Vec3 vertice2, Vec3 vertice3);
        ~Triangle();
        HitRecord intersection(Ray ray);
        void setMaterial(IMaterial *material);
        IMaterial *getMaterial();
        AABB getAABB();
    protected:
    private:
        IMaterial *_material;
        Vec3 _position;
        Vec3 _normal;
        Vec3 _vertice1 = Vec3(0, 0, 0);
        Vec3 _vertice2 = Vec3(0, 0, 0);
        Vec3 _vertice3 = Vec3(0, 0, 0);
};
}

#endif /* !TRIANGLE_HPP_ */
