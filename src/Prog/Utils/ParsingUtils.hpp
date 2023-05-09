/*
** EPITECH PROJECT, 2023
** final
** File description:
** ParsingUtils.hpp
*/

#ifndef PARSINGUTILS_HPP_
#define PARSINGUTILS_HPP_

#include <string>
#include <sstream>
#include "Exception.hpp"
#include "FromString.hpp"
#include "Vec3.hpp"

namespace Raytracer {

    class ParsingUtils {
        public:
            ParsingUtils() = default;
            ~ParsingUtils() = default;

            static double getDouble(const std::string &, const std::string &);
            static Vec3 getVec3(const std::string &, const std::string &);
            static std::string getString(const std::string &, const std::string &);

            static std::vector<std::string> split(const std::string &str, char delim);
    };

} // Raytracer

#endif //PARSINGUTILS_HPP_
