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
#include <vector>
#include "IFactory.hpp"
#include "LDLoader.hpp"

namespace Raytracer {
    template<typename T>
    class AFactory : public IFactory<T> {
        public:
            AFactory() = default;
            ~AFactory() {
                for (auto &loader : _loaders)
                    loader.closeLib();
            }

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

                loader.loadLib(path);
                std::shared_ptr<T> t(loader.getSymbol("create", options));
                _loaders.push_back(loader);
                return t;
            }

            virtual std::shared_ptr<T> getFromBuiltin([[maybe_unused]]const std::string &name, [[maybe_unused]]const std::string &options)
            {
                throw FactoryNotFoundException(name + " not found.");
            }

            std::string _dirName;

        private:
            std::vector<LDLoader<T>> _loaders;
    };

} // Raytracer

#endif //AFACTORY_HPP_
