/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Triangle
*/

#include "Triangle.hpp"
#include <iostream>
#include "AABB.hpp"
#include <cmath>

namespace Raytracer {
Triangle::Triangle(Vec3 vertice1, Vec3 vertice2, Vec3 vertice3)
    : _vertice1(vertice1), _vertice2(vertice2), _vertice3(vertice3)
{
}

Triangle::~Triangle()
{
}

HitRecord Raytracer::Triangle::intersection(Ray r)
{
    HitRecord hitRecord;
    hitRecord.hit = false;

    double kEpsilon = 0.0001f;
    Vec3 v0v1 = _vertice2 - _vertice1;
    Vec3 v0v2 = _vertice3 - _vertice1;
    Vec3 N = v0v1.Cross(v0v2); // N
    float NdotRayDirection = N.Dot(r.getDirection());
    if (fabs(NdotRayDirection) < kEpsilon)
        return hitRecord;
    float d = -N.Dot(_vertice1);
    double t;

    t = -(N.Dot(r.getOrigin()) + d) / NdotRayDirection;
    
    if (t < 0) return hitRecord;
    Vec3 P = r.getOrigin() + r.getDirection() * t;
    Vec3 C;
    Vec3 edge0 = _vertice2 - _vertice1;
    Vec3 vp0 = P - _vertice1;
    C = edge0.Cross(vp0);
    if (N.Dot(C) < 0) return hitRecord;
    Vec3 edge1 = _vertice3 - _vertice2;
    Vec3 vp1 = P - _vertice2;
    C = edge1.Cross(vp1);
    if (N.Dot(C) < 0)  return hitRecord;
    // edge 2
    Vec3 edge2 = _vertice1 - _vertice3;
    Vec3 vp2 = P - _vertice3;
    C = edge2.Cross(vp2);
    if (N.Dot(C) < 0) return hitRecord;
    hitRecord.hit = true;
    hitRecord.distance = t;
    hitRecord.point = P;
    hitRecord.normal = _normal;
    hitRecord.material = this->getMaterial();
    return hitRecord;
}

void Triangle::setMaterial(IMaterial *material)
{
    _material = material;
}

IMaterial *Triangle::getMaterial()
{
    return _material;
}

AABB Triangle::getAABB()
{
    return AABB(Vec3(-1000000, -1000000, -1000000), Vec3(1000000, 1000000, 1000000));
}
}