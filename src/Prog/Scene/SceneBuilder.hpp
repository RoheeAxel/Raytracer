/*
** EPITECH PROJECT, 2023
** final
** File description:
** SceneBuilder.hpp
*/

#ifndef SCENEBUILDER_HPP_
#define SCENEBUILDER_HPP_

#include "Parser.hpp"
#include "Scene.hpp"

namespace Raytracer {

    class SceneBuilder {
        public:
            SceneBuilder(Parser &parser);
            ~SceneBuilder() = default;

            void sceneInScene(std::shared_ptr<Scene> scene, Parser &parser);
            std::shared_ptr<Scene> build();
        private:
            Parser &_parser;
    };

} // Raytracer

#endif //SCENEBUILDER_HPP_
