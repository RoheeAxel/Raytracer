/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** AABB
*/

#include "AABB.hpp"
#include <iostream>
#include <cmath>

namespace Raytracer {
    AABB::AABB(const Vec3 &bot, const Vec3 &top) : _bot(bot), _top(top) {}

    AABB::AABB(const std::string &options) {
        this->_top = ParsingUtils::getVec3(options, "top");
        this->_bot = ParsingUtils::getVec3(options, "bot");
    }

    HitRecord Raytracer::AABB::intersection(Ray r) {
        double t_min = 0.0;
        double t_max = 100000.0;
        HitRecord hit;
        for (int a = 0; a < 3; a++) {
            double t1 = fmin((_bot[a] - r.getOrigin()[a]) / r.getDirection()[a],
                        (_top[a] - r.getOrigin()[a]) / r.getDirection()[a]);
            double t2 = fmax((_bot[a] - r.getOrigin()[a]) / r.getDirection()[a],
                        (_top[a] - r.getOrigin()[a]) / r.getDirection()[a]);
            t_min = fmax(t1, t_min);
            t_max = fmin(t2, t_max);
            if (t_max <= t_min)
                hit.hit = false;
        }
        hit.hit = true;
        return hit;
    }

    AABB AABB::getAABB()
    {
        return *this;
    }

}