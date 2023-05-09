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

        if (_parser._cfg.exists("scenes")) {
            libconfig::Setting &scenesGroup = _parser._cfg.lookup("scenes");
            for (int i = 0; i < scenesGroup.getLength(); i++) {
                std::string name = scenesGroup[i];
                try {
                    Parser tmp(scenesGroup[i]);

                    for (auto &shape : tmp.parsePrimitives())
                        scene->addShape(shape);

                    for (auto &light : tmp.parseLights())
                        scene->addLight(light);
                } catch (Exception &e) {
                    std::cerr << "Invalid scene " << name << ": " << e.what() << std::endl;
                }
            }
        }

        return scene;
    }
} // Raytracer