/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <iostream>
#include "AABB.hpp"
#include <cmath>

namespace Raytracer {
    Sphere::Sphere(const Vec3 &position, double radius) : _position(position), _radius(radius) {}

    Sphere::Sphere(const std::string &options) {
        this->_position = ParsingUtils::getVec3(options, "position");
        this->_radius = ParsingUtils::getDouble(options, "radius");
    }

    HitRecord Raytracer::Sphere::intersection(Ray r) {
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
        } else {
            hitRecord.hit = true;
            t1 = (-b - sqrt(discriminant)) / (2.0*a);
            t2 = (-b + sqrt(discriminant)) / (2.0*a);
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
            hitRecord.distance = (hitRecord.point - r.getOrigin()).Length();
            hitRecord.material = this->getMaterial();
            Vec3 out_normal = (hitRecord.point - _position) / _radius;
            hitRecord.set_face_normal(r, out_normal);
            hitRecord.uv = this->getUV(out_normal);
            return hitRecord;
        }
    }

    AABB Sphere::getAABB() {
        Vec3 bot = _position - Vec3(_radius, _radius, _radius);
        Vec3 top = _position + Vec3(_radius, _radius, _radius);
        return {bot, top};
    }

    std::pair<double, double> Sphere::getUV(Vec3 point) {
        double theta = acos(-point.y);
        double phi = atan2(-point.z, point.x) + M_PI;
        double u = phi / (2 * M_PI);
        double v = theta / M_PI;
        return {u, v};
    }

    void Sphere::setTranslation(Vec3 translation) {
        _position = translation;
    }
    void Sphere::setRotation(Vec3 rotation, Vec3 center)
    {
        Quaternion q(rotation);
        _position = q.rotate(this->_position, center);
        
    }
}