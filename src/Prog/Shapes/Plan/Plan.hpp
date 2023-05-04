/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Plan
*/

#ifndef PLAN_HPP_
#define PLAN_HPP_

#include <string>
#include "ParsingUtils.hpp"
#include "AShape.hpp"

namespace Raytracer {
    class AABB;
    class Plan : public AShape{
        public:
            Plan(const Vec3 &position, const Vec3 &normal);
            Plan(const std::string &options);
            ~Plan() override = default;
            HitRecord intersection(Ray ray) override;
            AABB getAABB() override;

            void setPosition(const Vec3 &position);
            void setNormal(const Vec3 &normal);
            void setCenter(const Vec3 &center);

        private:
            Vec3 _position;
            Vec3 _normal;
            Vec3 _center;
};
}

#endif /* !PLAN_HPP_ */
