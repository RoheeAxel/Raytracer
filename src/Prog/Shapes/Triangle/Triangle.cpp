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
    Triangle::Triangle(const Vec3 &vertice1, const Vec3 &vertice2, const Vec3 &vertice3)
    : _vertice1(vertice1), _vertice2(vertice2), _vertice3(vertice3) {}

    Triangle::Triangle(const std::string &options) {
        this->_vertice1 = ParsingUtils::getVec3(options, "vertice1");
        this->_vertice2 = ParsingUtils::getVec3(options, "vertice2");
        this->_vertice3 = ParsingUtils::getVec3(options, "vertice3");
    }

    HitRecord Raytracer::Triangle::intersection(Ray r) {
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
        hitRecord.normal = N;
        hitRecord.material = this->getMaterial();
        hitRecord.uv = this->getUV(P);
        return hitRecord;
    }

    AABB Triangle::getAABB() {
    return {Vec3(-1000000, -1000000, -1000000), Vec3(1000000, 1000000, 1000000)};
    }

    std::pair<double, double> Triangle::getUV(Vec3 point)
    {
        Vec3 v0 = _vertice2 - _vertice1;
        Vec3 v1 = _vertice3 - _vertice1;
        Vec3 v2 = point - _vertice1;

        double d00 = v0.Dot(v0);
        double d01 = v0.Dot(v1);
        double d11 = v1.Dot(v1);
        double d20 = v2.Dot(v0);
        double d21 = v2.Dot(v1);
        double denom = d00 * d11 - d01 * d01;
        double v = (d11 * d20 - d01 * d21) / denom;
        double w = (d00 * d21 - d01 * d20) / denom;
        double u = 1.0f - v - w;
        return {u, v};
    }

    void Triangle::setTranslation(Vec3 translation) {
        this->_vertice1 += translation;
        this->_vertice2 += translation;
        this->_vertice3 += translation;
    }
    void Triangle::setRotation(Vec3 rotation, Vec3 center)
    {
        Quaternion q(rotation);
        _vertice1 = q.rotate(this->_vertice1, center);
        _vertice2 = q.rotate(this->_vertice2, center);
        _vertice3 = q.rotate(this->_vertice3, center);

    }
}