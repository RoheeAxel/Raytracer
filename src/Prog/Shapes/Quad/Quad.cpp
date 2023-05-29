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

    Quad::Quad(const std::string &options) {
        this->_vertice1 = ParsingUtils::getVec3(options, "vertice1");
        this->_vertice2 = ParsingUtils::getVec3(options, "vertice2");
        this->_vertice3 = ParsingUtils::getVec3(options, "vertice3");
        this->_vertice4 = ParsingUtils::getVec3(options, "vertice4");

    }

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

        Vec3 edge3 = _vertice1 - _vertice4;
        Vec3 vp3 = P - _vertice4;
        C = edge3.Cross(vp3);
        if (N.Dot(C) < 0) return hitRecord;

        hitRecord.uv = getUV(P);
        hitRecord.hit = true;
        hitRecord.distance = t;
        hitRecord.point = P;
        hitRecord.normal = _normal * -1;
        hitRecord.material = this->getMaterial();
        return hitRecord;
    }

    AABB Quad::getAABB()
    {
        Vec3 min;
        Vec3 max;
        // Calculate the minimum and maximum x, y, and z coordinates of the triangle vertices
        min.x = std::min(_vertice1.x, _vertice2.x);
        min.y = std::min(_vertice1.y, _vertice2.y);
        min.z = std::min(_vertice1.z, _vertice2.z);
        min.x = std::min(min.x, _vertice3.x);
        min.y = std::min(min.y, _vertice3.y);
        min.z = std::min(min.z, _vertice3.z);
        min.x = std::min(min.x, _vertice4.x);
        min.y = std::min(min.y, _vertice4.y);
        min.z = std::min(min.z, _vertice4.z);

        max.x = std::max(_vertice1.x, _vertice2.x);
        max.y = std::max(_vertice1.y, _vertice2.y);
        max.z = std::max(_vertice1.z, _vertice2.z);
        max.x = std::max(max.x, _vertice3.x);
        max.y = std::max(max.y, _vertice3.y);
        max.z = std::max(max.z, _vertice3.z);
        max.x = std::max(max.x, _vertice4.x);
        max.y = std::max(max.y, _vertice4.y);
        max.z = std::max(max.z, _vertice4.z);

        AABB box(min, max);
        return box;
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

    std::pair<double, double> Quad::getUV(Vec3 point) {

        double u = fabs(double(int(point.x * 100) % 100) / 100);
        double v = fabs(double(int(point.z * 100) % 100) / 100);
        return std::make_pair(v, u);
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
    void Quad::setScale(Vec3 scale)
    {
        _vertice1 = _vertice1 * scale;
        _vertice2 = _vertice2 * scale;
        _vertice3 = _vertice3 * scale;
        _vertice4 = _vertice4 * scale;
    }
}