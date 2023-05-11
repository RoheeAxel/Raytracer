/*
** EPITECH PROJECT, 2023
** final
** File description:
** ParsingUtils.cpp
*/

#include <iostream>
#include "ParsingUtils.hpp"

namespace Raytracer {

    double ParsingUtils::getDouble(const std::string &str, const std::string &option) {
        size_t optionPos = str.find(option);
        if (optionPos == std::string::npos)
            throw Exception("ParsingUtils::getOption: option " + option + " not found\nDebug: " + str);
        size_t nextCommaPos = str.find(';', optionPos);
        std::string value = str.substr(optionPos + option.size() + 1, nextCommaPos - optionPos - option.size() - 1);
        try {
            return std::stod(value);
        } catch (std::invalid_argument &e) {
            throw Exception("ParsingUtils::getOption: double for " + option + " cannot be converted from string\nDebug: " + str);
        }
    }

    Vec3 ParsingUtils::getVec3(const std::string &str, const std::string &option) {
        size_t optionPos = str.find(option);
        if (optionPos == std::string::npos)
            throw Exception("ParsingUtils::getOption: option " + option + " not found\nDebug: " + str);
        size_t nextCommaPos = str.find(';', optionPos);
        std::string value = str.substr(optionPos + option.size() + 1, nextCommaPos - optionPos - option.size() - 1);
        try {
            return {value};
        } catch (Exception &e) {
            throw Exception("ParsingUtils::getOption: vec3 for " + option + " cannot be converted from string\nDebug: " + str);
        }
    }

    std::string ParsingUtils::getString(const std::string &str, const std::string &option) {
        size_t optionPos = str.find(option);
        if (optionPos == std::string::npos)
            throw Exception("ParsingUtils::getOption: option " + option + " not found\nDebug: " + str);
        size_t nextCommaPos = str.find(';', optionPos);
        std::string value = str.substr(optionPos + option.size() + 1, nextCommaPos - optionPos - option.size() - 1);
        return value;
    }

    std::vector<std::string> ParsingUtils::split(const std::string &str, char delim) {
        std::vector<std::string> elems;
        std::stringstream ss(str);
        std::string item;

        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

} // Raytracer