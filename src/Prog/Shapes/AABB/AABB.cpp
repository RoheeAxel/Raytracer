/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** AABB
*/

#include "AABB.hpp"
#include <iostream>
#include "Quaternion.hpp"
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

    AABB AABB::surroundingBox(AABB box0, AABB box1)
    {
        Vec3 small(fmin(box0.getBot().x, box1.getBot().x),
                    fmin(box0.getBot().y, box1.getBot().y),
                    fmin(box0.getBot().z, box1.getBot().z));

        Vec3 big(fmax(box0.getTop().x, box1.getTop().x),
                fmax(box0.getTop().y, box1.getTop().y),
                fmax(box0.getTop().z, box1.getTop().z));
        return AABB(small,big);
    }

    AABB AABB::getAABB()
    {
        return *this;
    }

    std::pair<double, double> AABB::getUV(Vec3 point)
    {
        return std::make_pair(0, 0);
    }

    Vec3 AABB::getBot() const
    {
        return this->_bot;
    }

    Vec3 AABB::getTop() const {
        return this->_top;
    }

    void AABB::setTranslation(Vec3 translation)
    {
        this->_bot += translation;
        this->_top += translation;
    }

    void AABB::setRotation(Vec3 rotation, Vec3 center)
    {
        Quaternion q(rotation);
        _bot = q.rotate(this->_bot, center);
        _top = q.rotate(this->_top, center);
    }
    void AABB::setScale(Vec3 scale)
    {
        this->_bot *= scale;
        this->_top *= scale;
    }
}