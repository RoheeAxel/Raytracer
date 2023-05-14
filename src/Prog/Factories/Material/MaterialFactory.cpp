/*
** EPITECH PROJECT, 2023
** final
** File description:
** MaterialFactory.cpp
*/

#include "MaterialFactory.hpp"

namespace Raytracer {
    MaterialFactory::MaterialFactory() {
        this->_dirName = "materials";
    }

    std::shared_ptr<IMaterial> MaterialFactory::getFromBuiltin(const std::string &name, const std::string &options)
    {
        if (name == "emitive")
            return std::make_shared<Emitive>(options);
        else if (name == "glass")
            return std::make_shared<Glass>(options);
        else if (name == "lambertian")
            return std::make_shared<Lambertian>(options);
        else if (name == "normal")
            return std::make_shared<Normal>(options);
        else if (name == "reflective")
            return std::make_shared<Reflective>(options);
        return AFactory::getFromBuiltin(name, options);
    }
} // Raytracer