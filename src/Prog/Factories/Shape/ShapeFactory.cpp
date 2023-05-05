/*
** EPITECH PROJECT, 2023
** final
** File description:
** ShapeFactory.cpp
*/

#include "ShapeFactory.hpp"

namespace Raytracer {
    ShapeFactory::ShapeFactory() {
        this->_dirName = "shapes";
    }

    std::shared_ptr<IShape> ShapeFactory::getFromBuiltin(const std::string &name, const std::string &options) {
        if (name == "aabb")
            return std::make_shared<AABB>(options);
        else if (name == "plan")
            return std::make_shared<Plan>(options);
        else if (name == "sphere")
            return std::make_shared<Sphere>(options);
        else if (name == "triangle")
            return std::make_shared<Triangle>(options);
        return AFactory::getFromBuiltin(name, options);
    }

} // Raytracer