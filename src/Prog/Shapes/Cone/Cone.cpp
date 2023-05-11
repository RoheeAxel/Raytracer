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
    this->_angle = ParsingUtils::getDouble(options, "angle");
}

Raytracer::HitRecord Raytracer::Cone::intersection(Ray r) {
    HitRecord hitRecord;
        hitRecord.hit = false;

        Vec3 newPos = _position * -1;
        Quaternion q(_rotation);
        Vec3 newDir = q.rotate(r.getDirection(), _position);

        float a = newDir.x * newDir.x + newDir.z * newDir.z - newDir.y * newDir.y * tan(_angle) * tan(_angle);
        float b = 2.0 * (newPos.x * newDir.x + newPos.z * newDir.z - newPos.y * newDir.y * tan(_angle) * tan(_angle));
        float c = newPos.x * newPos.x + newPos.z * newPos.z - newPos.y * newPos.y * tan(_angle) * tan(_angle);
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

        hitRecord.point = r.getOrigin() + newDir * hitRecord.distance;
        hitRecord.distance = (hitRecord.point - r.getOrigin()).Length();
        hitRecord.material = this->getMaterial();
        Vec3 c_to_p = hitRecord.point - _position;
        Vec3 u = _direction.Cross(c_to_p.Cross(_direction));
        Vec3 out_normal = (c_to_p - u) / _radius;
        hitRecord.set_face_normal(r, out_normal);
        hitRecord.normal = out_normal;
        hitRecord.uv = this->getUV(out_normal);
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
