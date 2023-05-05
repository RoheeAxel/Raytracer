/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include <string>
#include "ParsingUtils.hpp"
#include "AShape.hpp"

namespace Raytracer {
    class AABB;
    class Triangle : public AShape{
        public:
            Triangle(const Vec3 &vertice1, const Vec3 &vertice2, const Vec3 &vertice3);
            Triangle(const std::string &options);
            ~Triangle() override = default;
            HitRecord intersection(Ray ray) override;
            AABB getAABB() override;
            std::pair<double, double> getUV(Vec3 point) override;

        private:
            Vec3 _normal;
            Vec3 _vertice1;
            Vec3 _vertice2;
            Vec3 _vertice3;
};
}

#endif /* !TRIANGLE_HPP_ */
