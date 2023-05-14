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
        else if (name == "cylinder")
            return std::make_shared<Cylinder>(options);
        else if (name == "cone")
            return std::make_shared<Cone>(options);
        else if (name == "quad")
            return std::make_shared<Quad>(options);
        else if (name == "obj")
            return std::make_shared<OBJ>(options);
        else if (name == "lcylinder")
            return std::make_shared<LCylinder>(options);
        else if (name == "lcone")
            return std::make_shared<lCone>(options);
        return AFactory::getFromBuiltin(name, options);
    }

    std::shared_ptr<IShape> ShapeFactory::get(const std::string &name, const std::string &options) {
        std::shared_ptr<IShape> shape = AFactory::get(name, options);
        try {
            Vec3 translation = ParsingUtils::getVec3(options, "translation");
            shape->setTranslation(translation);
        } catch (Exception &e) {}
        try {
            Vec3 rotation = ParsingUtils::getVec3(options, "rotation");
            Vec3 center = ParsingUtils::getVec3(options, "rotation_center");
            shape->setRotation(rotation, center);
        } catch (Exception &e) {}
        try {
            Vec3 scale = ParsingUtils::getVec3(options, "scale");
            shape->setScale(scale);
        } catch (Exception &e) {}
        return shape;
    }

} // Raytracer