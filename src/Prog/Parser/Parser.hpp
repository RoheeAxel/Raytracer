/*
** EPITECH PROJECT, 2023
** final
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <libconfig.h++>
#include <string>
#include <sstream>
#include <vector>
#include "Scene.hpp"
#include "LightFactory.hpp"
#include "MaterialFactory.hpp"
#include "ShapeFactory.hpp"
#include "Exception.hpp"

namespace Raytracer {
    class Parser {
        public:
            Parser(const std::string &file);
            ~Parser() = default;

            std::vector<std::shared_ptr<IShape>> parsePrimitives();
            std::vector<std::shared_ptr<ILight>> parseLights();
            std::string convertGroup(libconfig::Setting &array, bool isGroup = false);

            libconfig::Config _cfg;
            MaterialFactory _materialFactory;
            LightFactory _lightFactory;
            ShapeFactory _shapeFactory;
    };
} // Raytracer

#endif //PARSER_HPP_