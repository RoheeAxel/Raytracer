/*
** EPITECH PROJECT, 2023
** final
** File description:
** AFactory.hpp
*/

#ifndef AFACTORY_HPP_
#define AFACTORY_HPP_

#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include "IFactory.hpp"
#include "LDLoader.hpp"

namespace Raytracer {
    template<typename T>
    class AFactory : public IFactory<T> {
        public:
            AFactory() = default;
            ~AFactory() override = default;

            std::shared_ptr<T> get(const std::string &name, const std::string &options) override
            {
                try {
                    return getFromPlugin(name, options);
                } catch (const InvalidPluginException &e) {
                    return getFromBuiltin(name, options);
                }
            }

        protected:
            std::shared_ptr<T> getFromPlugin(const std::string &name, const std::string &options)
            {
                LDLoader<T> loader;
                std::string path = "./plugins/" + _dirName + "/" + name + EXTENSION;

                loader.loadLib(path, "create", options);
                std::shared_ptr<T> t(loader.get(), [&]([[maybe_unused]] T *ptr) {
                    loader.closeLib();
                });
                return t;
            }

            virtual std::shared_ptr<T> getFromBuiltin([[maybe_unused]]const std::string &name, [[maybe_unused]]const std::string &options)
            {
                throw FactoryNotFoundException(name + " not found.");
            }

            std::string _dirName;
    };

} // Raytracer

#endif //AFACTORY_HPP_
