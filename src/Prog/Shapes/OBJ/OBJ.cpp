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
#include "Emitive.hpp"
#include "Glass.hpp"

namespace Raytracer {
    OBJ::OBJ() {}

    OBJ::OBJ(const std::string &options) {
        _path = ParsingUtils::getString(options, "path");
        _position = ParsingUtils::getVec3(options, "position");
        _rotation = ParsingUtils::getVec3(options, "rotation");
        _scale = ParsingUtils::getVec3(options, "scale");
        _material = std::make_shared<Lambertian>(Vec3(255, 0, 255));
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

                    _faces.push_back(std::make_shared<Triangle>(vertices[std::stoi(vertex[0]) - 1] * _scale, vertices[std::stoi(vertex[1]) - 1] * _scale, vertices[std::stoi(vertex[2]) - 1] * _scale));
                    _faces[_faces.size() - 1]->setTranslation(_position);
                    _faces[_faces.size() - 1]->setRotation(_rotation, _position);
                    _faces[_faces.size() - 1]->setMaterial(this->getMaterial());
                } else if (split.size() == 5) {
                    std::vector<std::string> vertex;
                    for (std::size_t i = 1; i < split.size(); i++) {
                        vertex.push_back(ParsingUtils::split(split[i], '/')[0]);
                    }
                    _faces.push_back(std::make_shared<Quad>(vertices[std::stoi(vertex[0]) - 1] * _scale, vertices[std::stoi(vertex[1]) - 1] * _scale, vertices[std::stoi(vertex[2]) - 1] * _scale, vertices[std::stoi(vertex[3]) - 1] * _scale));
                    _faces[_faces.size() - 1]->setTranslation(_position);
                    _faces[_faces.size() - 1]->setRotation(_rotation, _position);
                    _faces[_faces.size() - 1]->setMaterial(this->getMaterial());
                }
            }
        }
        createAABB();
    }

    HitRecord Raytracer::OBJ::intersection(Ray r) {
        HitRecord hitRecord;
        hitRecord.hit = false;
        HitRecord isHit = getAABB().intersection(r);
        if (!isHit.hit) {
            return hitRecord;
        }
        for (std::size_t i = 0; i < _faces.size(); i++) {
            HitRecord hit = _faces[i]->intersection(r);
            if (hit.hit && (!hitRecord.hit || hit.distance < hitRecord.distance)) {
                hitRecord = hit;
            }
        }
        return hitRecord;
    }

    AABB OBJ::getAABB()
    {
        return AABB(_aabbBot, _aabbTop);
    }

    void OBJ::createAABB() {

        if (_faces.empty()) {
            return;
        }
        Vec3 minPoint = _faces[0]->getAABB().getBot();
        Vec3 maxPoint = _faces[0]->getAABB().getTop();

        for (const auto& face : _faces) {
            Vec3 triMin = face->getAABB().getBot();
            Vec3 triMax = face->getAABB().getTop();
            minPoint = Vec3(std::min(minPoint.x, triMin.x), std::min(minPoint.y, triMin.y), std::min(minPoint.z, triMin.z));
            maxPoint = Vec3(std::max(maxPoint.x, triMax.x), std::max(maxPoint.y, triMax.y), std::max(maxPoint.z, triMax.z));
        }

        _aabbBot = minPoint;
        _aabbTop = maxPoint;
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
    void OBJ::setScale(Vec3 scale)
    {
    }
}