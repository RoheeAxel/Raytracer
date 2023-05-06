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
    }

    HitRecord Raytracer::Cylinder::intersection(Ray r) {
    //     HitRecord hitRecord;d
    //     hitRecord.hit = false;
    //    // transform the ray into the local space of the cylinder
    //     Vec3 local_origin = r.getOrigin() - _position;
    //     Vec3 local_direction = r.getDirection();

    //     // rotate the ray direction and origin
    //     Quaternion q = Quaternion::fromTwoVectors(Vec3(0, 1, 0), _direction);
    //     local_origin = q * local_origin;
    //     local_direction = q * local_direction;

    //     float a = local_direction.x * local_direction.x + local_direction.z * local_direction.z;
    //     float b = 2.0f * (local_origin.x * local_direction.x + local_origin.z * local_direction.z);
    //     float c = local_origin.x * local_origin.x + local_origin.z * local_origin.z - _radius * _radius;
    //     float discriminant = b * b - 4.0f * a * c;

    //     if (discriminant < 0.0f) {
    //         return false;
    //     }

    //     float sqrt_d = sqrt(discriminant);
    //     double t1 = (-b - sqrt_d) / (2.0f * a);
    //     double t2 = (-b + sqrt_d) / (2.0f * a);

    //     if (t1 < t_min && t2 < t_min) {
    //         return false;
    //     }

    //     double hit_t;
    //     Vec3 hit_point;
    //     Vec3 hit_normal;

    //     if (t1 >= t_min && t1 <= t_max) {
    //         hit_t = t1;
    //         hit_point = local_origin + hit_t * local_direction;
    //         hit_normal = Vec3(hit_point.x, 0.0f, hit_point.z).normalize();
    //     } else if (t2 >= t_min && t2 <= t_max) {
    //         hit_t = t2;
    //         hit_point = local_origin + hit_t * local_direction;
    //         hit_normal = Vec3(hit_point.x, 0.0f, hit_point.z).normalize();
    //     } else {
    //         return false;
    //     }

    //     // rotate the hit point and normal back to world space
    //     hit_point = q.conjugate() * hit_point + _position;
    //     hit_normal = q.conjugate() * hit_normal;

    //     // set the hit record
    //     hitRecord.hit = true;
    //     hitRecord.distance = hit_t;
    //     hitRecord.point = hit_point;
    //     hitRecord.normal = hit_normal;
    //     hitRecord.material = _material;

    //     return true;
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
        double theta = acos(-pointRotate.y);
        double phi = atan2(-pointRotate.z, pointRotate.x) + M_PI;
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