/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include <string>
#include "ParsingUtils.hpp"
#include "AShape.hpp"

namespace Raytracer {
    class Sphere : public AShape{
        public:
            Sphere(const Vec3 &position, double radius);
            Sphere(const std::string &options);
            ~Sphere() override = default;
            HitRecord intersection(Ray ray) override;
            AABB getAABB() override;

        private:
            Vec3 _position;
            double _radius;
    };
}

#endif /* !SPHERE_HPP_ */
