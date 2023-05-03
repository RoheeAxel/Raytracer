/*
** EPITECH PROJECT, 2023
** final
** File description:
** AShape.cpp
*/

#include "AShape.hpp"

namespace Raytracer {
    void AShape::setMaterial(std::shared_ptr<IMaterial> material)
    {
        this->_material = material;
    }

    std::shared_ptr<IMaterial> AShape::getMaterial()
    {
        return this->_material;
    }
} // Raytracer