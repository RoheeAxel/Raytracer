/*
** EPITECH PROJECT, 2023
** final
** File description:
** ParsingUtils.hpp
*/

#ifndef PARSINGUTILS_HPP_
#define PARSINGUTILS_HPP_

#include <string>
#include "Exception.hpp"
#include "FromString.hpp"
#include "Vec3.hpp"

namespace Raytracer {

    class ParsingUtils {
        public:
            ParsingUtils() = default;
            ~ParsingUtils() = default;

//            template<typename T>
//            T getOption(const std::string &, const std::string &);

            static double getDouble(const std::string &, const std::string &);
            static Vec3 getVec3(const std::string &, const std::string &);
    };

} // Raytracer

#endif //PARSINGUTILS_HPP_
