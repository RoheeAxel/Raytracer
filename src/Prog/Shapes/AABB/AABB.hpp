/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** AABB
*/

#ifndef AABB_HPP_
#define AABB_HPP_

#include <string>
#include "ParsingUtils.hpp"
#include "AShape.hpp"

namespace Raytracer {
class AABB : public AShape{
    public:
        AABB() = default;
        AABB(const Vec3 &bot, const Vec3 &top);
        AABB(const std::string &options);
        ~AABB() override = default;

        HitRecord intersection(Ray ray) override;
        AABB getAABB() override;
        AABB surroundingBox(AABB box0, AABB box1);

    private:
        Vec3 _bot;
        Vec3 _top;
};
}

#endif /* !AABB_HPP_ */
