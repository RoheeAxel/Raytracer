/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <iostream>
#include <cmath>

namespace Raytracer {
Sphere::Sphere(Vec3 position, double radius) : _position(position), _radius(radius)
{
}

Sphere::~Sphere()
{
}

HitRecord Raytracer::Sphere::intersection(Ray r)
{
    HitRecord hitRecord;
    Vec3 oc = r.getOrigin() - _position;
    float a = r.getDirection().Dot(r.getDirection());
    float b = 2.0 * oc.Dot(r.getDirection());
    float c = oc.Dot(oc) - _radius * _radius;
    float discriminant = b * b - 4 * a * c;
    if(discriminant < 0){
        hitRecord.hit = false;
        return hitRecord;
    }
    else{
        hitRecord.hit = true;
        hitRecord.point = r.getOrigin() + r.getDirection() * (-b - sqrt(discriminant)) / (2.0*a);
        hitRecord.color = Vec3(255, 0, 0);
        hitRecord.newRay = Vec3(0, 0, 0);
        return hitRecord;
    }
}
}