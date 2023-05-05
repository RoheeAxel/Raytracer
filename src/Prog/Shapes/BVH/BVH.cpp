/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** BVH
*/

#include "BVH.hpp"
#include "AABB.hpp"
#include <iostream>
#include <cmath>

namespace Raytracer {
    HitRecord Raytracer::BVH::intersection(Ray r) {
        HitRecord rec;
        rec.hit = false;

        if (!_box.intersection(r).hit)
            return rec;

        HitRecord hitLeft = _left->intersection(r);
        HitRecord hitRight = _right->intersection(r);

        if (hitLeft.hit || hitRight.hit)
            return hitLeft.distance < hitRight.distance ? hitLeft : hitRight;
        return rec;
    }

    AABB BVH::getAABB()
    {
        return _box;
    }
}