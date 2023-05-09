/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** OBJ
*/

#include "OBJ.hpp"
#include <iostream>
#include "AABB.hpp"
#include <cmath>

namespace Raytracer {
    OBJ::OBJ() {}

    OBJ::OBJ(const std::string &options) {
        std::string path = ParsingUtils::getString(options, "path");
        

    }

    HitRecord Raytracer::OBJ::intersection(Ray r) {
        HitRecord hitRecord;
        hitRecord.hit = false;
        return hitRecord;
    }

    AABB OBJ::getAABB() {
    return {Vec3(-1000000, -1000000, -1000000), Vec3(1000000, 1000000, 1000000)};
    }

    void OBJ::setPosition(const Vec3 &position)
    {
        this->_position = position;
    }

    std::pair<double, double> OBJ::getUV(Vec3 point) {
    }

    void OBJ::setTranslation(Vec3 translation)
    {
    }

    void OBJ::setRotation(Vec3 rotation, Vec3 center)
    {
    }
}