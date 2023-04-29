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
    double t1;
    double t2;
    if(discriminant < 0){
        hitRecord.hit = false;
        return hitRecord;
    }
    else{
        hitRecord.hit = true;
        t1 = (-b - sqrt(discriminant)) / (2.0*a);
        t2 = (-b + sqrt(discriminant)) / (2.0*a);
        if (t1 < 0 && t2 < 0) {
            hitRecord.hit = false;
            return hitRecord;
        }
        hitRecord.point = r.getOrigin() + r.getDirection() * t1;
        hitRecord.normal = (hitRecord.point - _position).Normalize();
        hitRecord.distance = (hitRecord.point - r.getOrigin()).Length();
        hitRecord.material = this->getMaterial();
        hitRecord.set_face_normal(r);
        return hitRecord;
    }
}

void Sphere::setMaterial(IMaterial *material)
{
    _material = material;
}

IMaterial *Sphere::getMaterial()
{
    return _material;
}
}