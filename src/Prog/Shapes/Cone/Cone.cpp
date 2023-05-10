/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Cone
*/

#include "Cone.hpp"
#include "AABB.hpp"

#include <iostream>
#include <cmath>

Raytracer::Cone::Cone(const Vec3 &position, double radius)
    : _position(position), _radius(radius), _direction(Vec3(0, 1, 0)), _rotation(Vec3(0, 0, 0))
{
}

Raytracer::Cone::Cone(const std::string &options)
{
    this->_position = ParsingUtils::getVec3(options, "position");
    this->_direction = ParsingUtils::getVec3(options, "direction");
    this->_radius = ParsingUtils::getDouble(options, "radius");
    this->_rotation = ParsingUtils::getVec3(options, "rotation");
}

Raytracer::HitRecord Raytracer::Cone::intersection(Ray ray) {
    HitRecord hitRecord;
    Vec3 oc = ray.getOrigin() - _position;
    double cos2_a = pow(cos(_radius), 2);
    double sin2_a = 1 - cos2_a;
    double a = pow(ray.getDirection().x, 2) * sin2_a + pow(ray.getDirection().y, 2) * sin2_a - pow(ray.getDirection().z, 2) * cos2_a;
    double b = 2 * oc.x * sin2_a * ray.getDirection().x + 2 * oc.y * sin2_a * ray.getDirection().y - 2 * oc.z * cos2_a * ray.getDirection().z;
    double c = pow(oc.x, 2) * sin2_a + pow(oc.y, 2) * sin2_a - pow(oc.z, 2) * cos2_a;
    double discriminant = b * b - 4 * a * c;
    double t1, t2;

    if (discriminant < 0) {
        hitRecord.hit = false;
        return hitRecord;
    }
    t1 = (-b - sqrt(discriminant)) / (2 * a);
    t2 = (-b + sqrt(discriminant)) / (2 * a);
    if (t1 < 0 && t2 < 0) {
        hitRecord.hit = false;
        return hitRecord;
    }
    double t = t1 < t2 ? t1 : t2;
    Vec3 point = ray.getOrigin() + ray.getDirection() * t;
    if (point.z < _position.z) {
        double tz = (_position.z - ray.getOrigin().z) / ray.getDirection().z;
        Vec3 pointz = ray.getOrigin() + ray.getDirection() * tz;
        double dx = point.x - pointz.x;
        double dy = point.y - pointz.y;
        double dz = point.z - pointz.z;
        double d = sqrt(dx*dx + dy*dy + dz*dz);
        double cos_a = sqrt(1 - sin2_a);
        double h = d / cos_a;
        point = ray.getOrigin() + ray.getDirection() * (tz + h / ray.getDirection().Length());
    }
    hitRecord.hit = true;
    hitRecord.distance = (point - ray.getOrigin()).Length();
    hitRecord.point = point;
    hitRecord.material = this->getMaterial();
    Vec3 out_normal = Vec3(point.x - _position.x, point.y - _position.y, _radius / cos(_radius));
    hitRecord.set_face_normal(ray, out_normal);
    hitRecord.uv = this->getUV(point);
    return hitRecord;
}

Raytracer::AABB Raytracer::Cone::getAABB()
{
    return AABB(Vec3(_position.x - _radius, _position.y - _radius, _position.z - _radius),
                Vec3(_position.x + _radius, _position.y + _radius, _position.z + _radius));
}

std::pair<double, double> Raytracer::Cone::getUV(Vec3 point)
{
    double phi = atan2(point.x, point.y);
    double theta = acos(point.z / _radius);
    double u = 1 - (phi + M_PI) / (2 * M_PI);
    double v = (theta + M_PI / 2) / M_PI;
    return std::make_pair(u, v);
}

void Raytracer::Cone::setTranslation(Vec3 translation)
{
    this->_position = this->_position + translation;
}

void Raytracer::Cone::setRotation(Vec3 rotation, Vec3 center)
{
    Quaternion q(rotation);
    this->_position = q.rotate(this->_position, center);
    this->_rotation = this->_rotation + rotation;
}
