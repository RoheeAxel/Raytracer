/*
** EPITECH PROJECT, 2023
** final
** File description:
** AFactory.cpp
*/

#include "AFactory.hpp"

namespace Raytracer {
    template<typename T>
    AFactory<T>::AFactory(const std::string &dirName) {
        this->_dirName = dirName;
    }

    template<typename T>
    std::shared_ptr<T> AFactory<T>::get(const std::string &name, const std::string &options)
    {
        try {
            return getFromPlugin(name, options);
        } catch (const InvalidPluginException &e) {
            return getFromBuiltin(name, options);
        }
    }

    template<typename T>
    std::shared_ptr<T> AFactory<T>::getFromPlugin(const std::string &name, const std::string &options)
    {
        LDLoader<T> loader;
        std::string path = _dirName + "/" + name + EXTENSION;

        loader.loadLib(path, "create", options);
        return std::shared_ptr<T>(loader.get());
    }

    template<typename T>
    std::shared_ptr<T> AFactory<T>::getFromBuiltin(const std::string &name, const std::string &options)
    {
        if (_builtins.find(name) == _builtins.end())
            throw FactoryNotFoundException("Factory not found");
        return std::shared_ptr<T>(_builtins[name].get());
    }
}