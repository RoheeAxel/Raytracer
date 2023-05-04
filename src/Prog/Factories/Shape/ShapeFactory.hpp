/*
** EPITECH PROJECT, 2023
** final
** File description:
** ShapeFactory.hpp
*/

#ifndef SHAPEFACTORY_HPP_
#define SHAPEFACTORY_HPP_

#include "AFactory.hpp"
#include "IShape.hpp"

#include "AABB.hpp"
#include "Plan.hpp"
#include "Sphere.hpp"
#include "Triangle.hpp"

namespace Raytracer {
    class ShapeFactory : public AFactory<IShape> {
        public:
            ShapeFactory();
            ~ShapeFactory() override = default;

        protected:
            std::shared_ptr<IShape> getFromBuiltin(const std::string &name, const std::string &options) override;
    };
} // Raytracer

#endif //SHAPEFACTORY_HPP_
