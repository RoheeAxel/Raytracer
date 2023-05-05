/*
** EPITECH PROJECT, 2023
** final
** File description:
** SceneBuilder.cpp
*/

#include "SceneBuilder.hpp"

namespace Raytracer {
    SceneBuilder::SceneBuilder(Parser &parser) : _parser(parser) {}

    std::shared_ptr<Scene> SceneBuilder::build()
    {
        auto scene = std::make_shared<Scene>();

        for (auto &shape : _parser.parsePrimitives())
            scene->addShape(shape);

        for (auto &light : _parser.parseLights())
            scene->addLight(light);

        return scene;
    }
} // Raytracer