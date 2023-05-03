/*
** EPITECH PROJECT, 2023
** final
** File description:
** AFactory.hpp
*/

#ifndef AFACTORY_HPP_
#define AFACTORY_HPP_

#include <unordered_map>
#include "IFactory.hpp"
#include "LDLoader.hpp"

namespace Raytracer {
    template<typename T>
    class AFactory : public IFactory<T> {
        public:
            AFactory() = default;
            explicit AFactory(const std::string &dirName);
            ~AFactory() override = default;

            std::unique_ptr<T> get(const std::string &name) override;

        protected:
            std::unique_ptr<T> getFromPlugin(const std::string &name);
            std::unique_ptr<T> getFromBuiltin(const std::string &name);

            std::string _dirName;
            std::unordered_map<std::string, std::unique_ptr<T>> _builtins;
    };

} // Raytracer

#endif //AFACTORY_HPP_
