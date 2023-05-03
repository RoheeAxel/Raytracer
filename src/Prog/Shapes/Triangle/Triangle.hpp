/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "AShape.hpp"

namespace Raytracer {
    class AABB;
    class Triangle : public AShape{
        public:
            Triangle(const Vec3 &vertice1, const Vec3 &vertice2, const Vec3 &vertice3);
            ~Triangle() override = default;
            HitRecord intersection(Ray ray) override;
            AABB getAABB() override;

            void setPosition(const Vec3 &position);
            void setNormal(const Vec3 &normal);
            void setVertice1(const Vec3 &vertice1);
            void setVertice2(const Vec3 &vertice2);
            void setVertice3(const Vec3 &vertice3);

        private:
            Vec3 _position;
            Vec3 _normal;
            Vec3 _vertice1 = Vec3(0, 0, 0);
            Vec3 _vertice2 = Vec3(0, 0, 0);
            Vec3 _vertice3 = Vec3(0, 0, 0);
};
}

#endif /* !TRIANGLE_HPP_ */
