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

Raytracer::HitRecord Raytracer::Cone::intersection(Ray ray)
{
    (void)ray;
    return HitRecord();
}

Raytracer::AABB Raytracer::Cone::getAABB()
{
    return AABB();
}

std::pair<double, double> Raytracer::Cone::getUV(Vec3 point)
{
    (void)point;
    return {0, 0};
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
