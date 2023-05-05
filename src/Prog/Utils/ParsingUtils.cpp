/*
** EPITECH PROJECT, 2023
** final
** File description:
** ParsingUtils.cpp
*/

#include <iostream>
#include "ParsingUtils.hpp"

namespace Raytracer {

//    template<typename T>
//    T ParsingUtils::getOption(const std::string &option, const std::string &str) {
//        size_t optionPos = str.find(option);
//        if (optionPos == std::string::npos)
//            throw Exception("ParsingUtils::getOption: option not found");
//        size_t nextCommaPos = str.find(',', optionPos);
//        std::string value = str.substr(optionPos + option.size() + 1, nextCommaPos - optionPos - option.size() - 1);
//
//        if (std::is_base_of<FromString, T>::value)
//            return T(value);
//        else if (std::is_same<T, double>::value) {
//            try {
//                return std::stod(value);
//            } catch (std::exception &e) {
//                throw Exception("ParsingUtils::getOption: T cannot be converted from string");
//            }
//        } else
//            throw Exception("ParsingUtils::getOption: T cannot be converted from string");
//    }

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
        } catch (std::invalid_argument &e) {
            throw Exception("ParsingUtils::getOption: vec3 for " + option + " cannot be converted from string\nDebug: " + str);
        }
    }

} // Raytracer