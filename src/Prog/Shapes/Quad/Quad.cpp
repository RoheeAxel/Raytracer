/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Quad
*/

#include "Quad.hpp"
#include <iostream>
#include "AABB.hpp"
#include <cmath>

namespace Raytracer {
    Quad::Quad(const Vec3 &vertice1, const Vec3 &vertice2, const Vec3 &vertice3, const Vec3 &vertice4)
    : _vertice1(vertice1), _vertice2(vertice2), _vertice3(vertice3), _vertice4(vertice4) {}

    HitRecord Raytracer::Quad::intersection(Ray r) {
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
        Vec3 edge2 = _vertice4 - _vertice3;
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

    AABB Quad::getAABB() {
    return {Vec3(-1000000, -1000000, -1000000), Vec3(1000000, 1000000, 1000000)};
    }

    void Quad::setPosition(const Vec3 &position)
    {
        this->_position = position;
    }

    void Quad::setNormal(const Vec3 &normal) {
        this->_normal = normal;
    }

    void Quad::setVertice1(const Vec3 &vertice1) {
        this->_vertice1 = vertice1;
    }

    void Quad::setVertice2(const Vec3 &vertice2) {
        this->_vertice2 = vertice2;
    }

    void Quad::setVertice3(const Vec3 &vertice3) {
        this->_vertice3 = vertice3;
    }

    void Quad::setVertice4(const Vec3 &vertice4) {
        this->_vertice4 = vertice4;
    }

    void Quad::setTranslation(Vec3 translation)
    {
        this->_position = this->_position + translation;
        this->_vertice1 = this->_vertice1 + translation;
        this->_vertice2 = this->_vertice2 + translation;
        this->_vertice3 = this->_vertice3 + translation;
        this->_vertice4 = this->_vertice4 + translation;
    }

    void Quad::setRotation(Vec3 rotation, Vec3 center)
    {
        Quaternion q(rotation);
        _vertice1 = q.rotate(_vertice1, center);
        _vertice2 = q.rotate(_vertice2, center);
        _vertice3 = q.rotate(_vertice3, center);
        _vertice4 = q.rotate(_vertice4, center);
    }
}