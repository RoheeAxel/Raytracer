/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** lCone
*/

#include "lCone.hpp"
#include <iostream>
#include "AABB.hpp"
#include <cmath>

namespace Raytracer {
    lCone::lCone(const Vec3 &position, double radius) : _position(position), _radius(radius) {}

    lCone::lCone(const std::string &options) {
        this->_position = ParsingUtils::getVec3(options, "position");
        this->_direction = ParsingUtils::getVec3(options, "direction");
        this->_radius = ParsingUtils::getDouble(options, "radius");
        this->_rotation = ParsingUtils::getVec3(options, "rotation");
        this->_angle = ParsingUtils::getDouble(options, "angle");
        this->_height = ParsingUtils::getDouble(options, "height");
    }

    HitRecord Raytracer::lCone::intersection(Ray r) {
        HitRecord hitRecord;
        hitRecord.hit = false;
        double other;
        Vec3 newPos = _position * -1;
        Quaternion q(_rotation);
        Vec3 newDir = q.rotate(r.getDirection(), _position);

        float a = newDir.x * newDir.x + newDir.z * newDir.z - newDir.y * newDir.y * std::tan(_angle) * std::tan(_angle);
        float b = 2.0 * (newPos.x * newDir.x + newPos.z * newDir.z - newPos.y * newDir.y * std::tan(_angle) * std::tan(_angle));
        float c = newPos.x * newPos.x + newPos.z * newPos.z - newPos.y * newPos.y * std::tan(_angle) * std::tan(_angle);
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
        if (t1 < 0) {
            hitRecord.distance = t2;
            other = t1;
        } else if (t2 < 0) {
            hitRecord.distance = t1;
            other = t2;
        } else {
            if (t1 < t2) {
                hitRecord.distance = t1;
                other = t2;
            }
            else {
                hitRecord.distance = t2;
                other = t1;
            }
        }

        hitRecord.point = r.getOrigin() + r.getDirection() * hitRecord.distance;
        if (q.rotate(hitRecord.point, _position).y < _position.y || q.rotate(hitRecord.point, _position).y > _position.y + _height) {
            hitRecord.point = r.getOrigin() + r.getDirection() * other;
            if (q.rotate(hitRecord.point, _position).y < _position.y || q.rotate(hitRecord.point, _position).y > _position.y + _height) {
                HitRecord hitRecord2;
                hitRecord2.hit = false;
                return hitRecord2;
            }
            hitRecord.distance = other;
        }
        hitRecord.material = this->getMaterial();
        Vec3 c_to_p = hitRecord.point - _position;
        double slope = 1.0 / std::tan(_angle);
        Vec3 projection = c_to_p - _direction * (c_to_p.Dot(_direction));
        double h = projection.Length() * slope;
        Vec3 normal = (c_to_p - _direction * h).Normalize();
        hitRecord.set_face_normal(r, normal);
        hitRecord.normal = normal;
        hitRecord.uv = this->getUV(normal);
        return hitRecord;
    }

    AABB lCone::getAABB() {
        Vec3 bot = _position - Vec3(_radius, _radius, _radius);
        Vec3 top = _position + Vec3(_radius, _radius, _radius);
        return {bot, top};
    }

    std::pair<double, double> lCone::getUV(Vec3 point) {
        Quaternion q(_rotation);
        Vec3 pointRotate;
        pointRotate = q.rotate(point, _position);
        double theta = std::acos(-pointRotate.y);
        double phi = std::atan2(-pointRotate.z, pointRotate.x) + M_PI;
        double u = phi / (2 * M_PI);
        double v = theta / M_PI;
        return {u, 1 - v};
    }

    void lCone::setTranslation(Vec3 translation) {
        _position = _position + translation;
    }
    void lCone::setRotation(Vec3 rotation, Vec3 center)
    {
        Quaternion q(rotation);
        _position = q.rotate(this->_position, center);
        _rotation = _rotation + rotation;
    }
    void lCone::setScale(Vec3 scale)
    {
        _radius = _radius * scale.x;
        _height = _height * scale.y;
    }
}

extern "C" Raytracer::lCone *create(const std::string &options) {
    return new Raytracer::lCone(options);
}