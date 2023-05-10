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
#include <fstream>
#include "Lambertian.hpp"
#include "Glass.hpp"

namespace Raytracer {
    OBJ::OBJ() {}

    OBJ::OBJ(const std::string &options) {
        _path = ParsingUtils::getString(options, "path");
        _position = ParsingUtils::getVec3(options, "position");
        _rotation = ParsingUtils::getVec3(options, "rotation");
        _material = std::make_shared<Glass>();
        load();
    }

    void OBJ::load()
    {
        std::fstream my_file;
	    my_file.open(_path);
        std::string line;
        std::vector<Vec3> vertices;

        while (getline(my_file, line)) {
            if (line.find("v ") == 0) {
                std::vector<std::string> split = ParsingUtils::split(line, ' ');
                vertices.push_back(Vec3(std::stod(split[1]), std::stod(split[2]), std::stod(split[3])));
            }
            if (line.find("f ") == 0) {
                std::vector<std::string> split = ParsingUtils::split(line, ' ');
                if (split.size() == 4) {
                     std::vector<std::string> vertex;
                    for (std::size_t i = 1; i < split.size(); i++) {
                        vertex.push_back(ParsingUtils::split(split[i], '/')[0]);
                    }
                    _faces.push_back(std::make_shared<Triangle>(vertices[std::stoi(vertex[0]) - 1], vertices[std::stoi(vertex[1]) - 1], vertices[std::stoi(vertex[2]) - 1]));
                    _faces[_faces.size() - 1]->setTranslation(_position);
                    _faces[_faces.size() - 1]->setRotation(_rotation, _position);
                    _faces[_faces.size() - 1]->setMaterial(this->getMaterial());
                } else if (split.size() == 5) {
                    std::vector<std::string> vertex;
                    for (std::size_t i = 1; i < split.size(); i++) {
                        vertex.push_back(ParsingUtils::split(split[i], '/')[0]);
                    }
                    _faces.push_back(std::make_shared<Quad>(vertices[std::stoi(vertex[0]) - 1], vertices[std::stoi(vertex[1]) - 1], vertices[std::stoi(vertex[2]) - 1], vertices[std::stoi(vertex[3]) - 1]));
                    _faces[_faces.size() - 1]->setTranslation(_position);
                    _faces[_faces.size() - 1]->setRotation(_rotation, _position);
                    _faces[_faces.size() - 1]->setMaterial(this->getMaterial());
                }
            }
        }
    }

    HitRecord Raytracer::OBJ::intersection(Ray r) {
        HitRecord hitRecord;
        hitRecord.hit = false;
        for (std::size_t i = 0; i < _faces.size(); i++) {
            HitRecord hit = _faces[i]->intersection(r);
            if (hit.hit && (!hitRecord.hit || hit.distance < hitRecord.distance)) {
                hitRecord = hit;
            }
        }
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