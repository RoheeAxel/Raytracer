/*
** EPITECH PROJECT, 2023
** final
** File description:
** SceneBuilder.cpp
*/

#include "SceneBuilder.hpp"

namespace Raytracer {
    SceneBuilder::SceneBuilder(Parser &parser) : _parser(parser) {}

    void SceneBuilder::sceneInScene(std::shared_ptr<Scene> scene, Parser &parser) {
        if (parser._cfg.exists("scenes")) {
            libconfig::Setting &scenesGroup = parser._cfg.lookup("scenes");
            for (int i = 0; i < scenesGroup.getLength(); i++) {
                std::string name = scenesGroup[i];
                try {
                    Parser tmp(scenesGroup[i]);

                    for (auto &shape : tmp.parsePrimitives())
                        scene->addShape(shape);

                    for (auto &light : tmp.parseLights())
                        scene->addLight(light);
                    sceneInScene(scene, tmp);
                } catch (Exception &e) {
                    std::cerr << "Invalid scene " << name << ": " << e.what() << std::endl;
                }
            }
        }
    }

    std::shared_ptr<Scene> SceneBuilder::build()
    {
        auto scene = std::make_shared<Scene>();

        for (auto &shape : _parser.parsePrimitives())
            scene->addShape(shape);

        for (auto &light : _parser.parseLights())
            scene->addLight(light);

        scene->setMaxDepth(_max_depth);

        sceneInScene(scene, _parser);
        return scene;
    }
} // Raytracer