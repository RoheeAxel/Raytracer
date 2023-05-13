/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include <iostream>
#include "AABB.hpp"
#include <cmath>

namespace Raytracer {
    Cylinder::Cylinder(const Vec3 &position, double radius) : _position(position), _radius(radius) {}

    Cylinder::Cylinder(const std::string &options) {
        this->_position = ParsingUtils::getVec3(options, "position");
        this->_direction = ParsingUtils::getVec3(options, "direction");
        this->_radius = ParsingUtils::getDouble(options, "radius");
        this->_rotation = ParsingUtils::getVec3(options, "rotation");
    }

    HitRecord Raytracer::Cylinder::intersection(Ray r) {
        HitRecord hitRecord;
        hitRecord.hit = false;

        Vec3 newPos = _position * -1;
        Quaternion q(_rotation);
        Vec3 newDir = q.rotate(r.getDirection(), _position);

        float a = newDir.x * newDir.x + newDir.z * newDir.z;
        float b = 2.0 * (newPos.x * newDir.x + newPos.z * newDir.z);
        float c = newPos.x * newPos.x + newPos.z * newPos.z - _radius * _radius;
        float discriminant = b * b - 4.0 * a * c;

        if (discriminant < 0.0) return hitRecord;

        float sqrt_d = sqrt(discriminant);
        hitRecord.hit = true;
        double t1 = (-b - sqrt_d) / (2.0*a);
        double t2 = (-b + sqrt_d) / (2.0*a);
        if (t1 < 0 && t2 < 0) {
            hitRecord.hit = false;
            return hitRecord;
        }
        if (t1 < 0)
            hitRecord.distance = t2;
        else if (t2 < 0)
            hitRecord.distance = t1;
        else
            hitRecord.distance = t1 < t2 ? t1 : t2;

        hitRecord.point = r.getOrigin() + r.getDirection() * hitRecord.distance;
        hitRecord.material = this->getMaterial();
        Vec3 c_to_p = hitRecord.point - _position;
        Vec3 u = _direction.Cross(c_to_p.Cross(_direction));
        Vec3 out_normal = (c_to_p) / _radius;
        hitRecord.set_face_normal(r, out_normal);
        hitRecord.normal = out_normal;
        hitRecord.normal = q.rotate(hitRecord.normal, _position);
        hitRecord.uv = this->getUV(out_normal);
        return hitRecord;
    }

    AABB Cylinder::getAABB() {
        Vec3 bot = _position - Vec3(_radius, _radius, _radius);
        Vec3 top = _position + Vec3(_radius, _radius, _radius);
        return {bot, top};
    }

    std::pair<double, double> Cylinder::getUV(Vec3 point) {
        Quaternion q(_rotation);
        Vec3 pointRotate;
        pointRotate = q.rotate(point, _position);
        double theta = std::acos(-pointRotate.y);
        double phi = std::atan2(-pointRotate.z, pointRotate.x) + M_PI;
        double u = phi / (2 * M_PI);
        double v = theta / M_PI;
        return {u, 1 - v};
    }

    void Cylinder::setTranslation(Vec3 translation) {
        _position = _position + translation;
    }
    void Cylinder::setRotation(Vec3 rotation, Vec3 center)
    {
        Quaternion q(rotation);
        _position = q.rotate(this->_position, center);
        _rotation = _rotation + rotation;
    }
}