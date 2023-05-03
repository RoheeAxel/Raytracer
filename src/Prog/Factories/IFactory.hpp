/*
** EPITECH PROJECT, 2023
** final
** File description:
** IFactory.hpp
*/

#ifndef IFACTORY_HPP_
#define IFACTORY_HPP_

#include <memory>
#include <string>

namespace Raytracer {
    template<typename T>
    class IFactory {
        public:
            virtual ~IFactory() = 0;

            virtual std::shared_ptr<T> get(const std::string &, const std::string &) = 0;
    };
}

#endif //IFACTORY_HPP_
