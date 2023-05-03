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
    std::unique_ptr<T> AFactory<T>::get(const std::string &name)
    {
        try {
            return getFromPlugin(name);
        } catch (const InvalidPluginException &e) {
            return getFromBuiltin(name);
        }
    }

    template<typename T>
    std::unique_ptr<T> AFactory<T>::getFromPlugin(const std::string &name)
    {
        LDLoader<T> loader;
        std::string path = _dirName + "/" + name + EXTENSION;

        loader.loadLib(path, "create");
        return std::unique_ptr<T>(loader.get());
    }

    template<typename T>
    std::unique_ptr<T> AFactory<T>::getFromBuiltin(const std::string &name)
    {
        if (_builtins.find(name) == _builtins.end())
            throw FactoryNotFoundException("Factory not found");
        return std::unique_ptr<T>(_builtins[name].get());
    }
}