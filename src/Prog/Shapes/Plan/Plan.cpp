/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Plan
*/

#include "Plan.hpp"
#include <iostream>
#include "AABB.hpp"
#include <cmath>

namespace Raytracer {
    Plan::Plan(const Vec3 &position, const Vec3 &normal) : _position(position) , _normal(normal) {}

    Plan::Plan(const std::string &options) {
        this->_position = ParsingUtils::getVec3(options, "position");
        this->_normal = ParsingUtils::getVec3(options, "normal");
    }

    HitRecord Raytracer::Plan::intersection(Ray r) {
        HitRecord hitRecord;
        float epsilon = 0.0001f;
        float ndotu = r.getDirection().Dot( _normal);

        if (fabs(ndotu) < epsilon) {
            // The ray is parallel to the plan, there is no intersection
            hitRecord.hit = false;
            return hitRecord;
        }

        float t = (_position - r.getOrigin()).Dot(_normal) / ndotu;

        if (t < 0) {
            // The intersection point is behind the ray's origin, there is no intersection
            hitRecord.hit = false;
            return hitRecord;
        }

        hitRecord.hit = true;
        hitRecord.distance = t;
        hitRecord.point = r.getOrigin() + r.getDirection() * t;
        hitRecord.normal = _normal;
        hitRecord.material = this->getMaterial();
        return hitRecord;
    }

    AABB Plan::getAABB() {
        return {Vec3(-1000000, -1000000, -1000000), Vec3(1000000, 1000000, 1000000)};
    }

    void Plan::setPosition(const Vec3 &position)
    {
        this->_position = position;
    }

    void Plan::setNormal(const Vec3 &normal)
    {
        this->_normal = normal;
    }

    void Plan::setCenter(const Vec3 &center)
    {
        this->_center = center;
    }

}