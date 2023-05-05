/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Quad
*/

#ifndef Quad_HPP
#define Quad_HPP

#include "AShape.hpp"

namespace Raytracer {
    class AABB;
    class Quad : public AShape{
        public:
            Quad(const Vec3 &vertice1, const Vec3 &vertice2, const Vec3 &vertice3, const Vec3 &vertice4);
            ~Quad() override = default;
            HitRecord intersection(Ray ray) override;
            AABB getAABB() override;

            void setPosition(const Vec3 &position);
            void setNormal(const Vec3 &normal);
            void setVertice1(const Vec3 &vertice1);
            void setVertice2(const Vec3 &vertice2);
            void setVertice3(const Vec3 &vertice3);
            void setVertice4(const Vec3 &vertice4);
            void setTranslation(Vec3 translation) override;
            virtual void setRotation(Vec3 rotation, Vec3 center) override;


        private:
            Vec3 _position;
            Vec3 _normal;
            Vec3 _vertice1 = Vec3(0, 0, 0);
            Vec3 _vertice2 = Vec3(0, 0, 0);
            Vec3 _vertice3 = Vec3(0, 0, 0);
            Vec3 _vertice4 = Vec3(0, 0, 0);
};
}

#endif /* !Quad_HPP */
