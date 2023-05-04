/*
** EPITECH PROJECT, 2023
** final
** File description:
** LightFactory.cpp
*/

#include "LightFactory.hpp"

namespace Raytracer {
    LightFactory::LightFactory() {
        this->_dirName = "lights";
    }

    std::shared_ptr<ILight> LightFactory::getFromBuiltin(const std::string &name, const std::string &options) {
        if (name == "point")
            return std::make_shared<PointLight>(options);
        else if (name == "directional")
            return std::make_shared<DirLight>(options);
        else if (name == "ambient")
            return std::make_shared<AmbientLight>(options);
        return AFactory::getFromBuiltin(name, options);
    }
} // Raytracer