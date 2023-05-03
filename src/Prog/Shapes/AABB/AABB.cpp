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
AABB::AABB(Vec3 bot, Vec3 top) : _bot(bot), _top(top)
{
}

AABB::~AABB()
{
}

HitRecord Raytracer::AABB::intersection(Ray r)
{
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

void AABB::setMaterial(IMaterial *material)
{
    _material = material;
}

IMaterial *AABB::getMaterial()
{
    return _material;
}

AABB AABB::getAABB()
{
    return *this;
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
}