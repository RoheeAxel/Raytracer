/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Plan
*/

#include "Plan.hpp"
#include <iostream>
#include <cmath>

namespace Raytracer {
Plan::Plan(Vec3 position) : _position(position)
{
}

Plan::~Plan()
{
}

HitRecord Raytracer::Plan::intersection(Ray r)
{
    HitRecord hitRecord;
    Vec3 planeNormal = _normal.Normalize();
    float denom = r.getDirection().Dot(planeNormal);
    if (abs(denom) > 1e-6) {
        Vec3 p0ToPoint = _center - r.getOrigin();
        float t = p0ToPoint.Dot(planeNormal) / denom;
        if (t > 0) {
            hitRecord.hit = true;
            hitRecord.distance = t;
            hitRecord.point = r.getDirection() + r.getOrigin() * t;
            hitRecord.normal = planeNormal;
            hitRecord.material = this->getMaterial();
            return hitRecord;
        }
    }
    hitRecord.hit = false;
    return hitRecord;
}

void Plan::setMaterial(IMaterial *material)
{
    _material = material;
}

IMaterial *Plan::getMaterial()
{
    return _material;
}
}