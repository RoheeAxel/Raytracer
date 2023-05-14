/*
** EPITECH PROJECT, 2023
** final
** File description:
** LDLoader.hpp
*/

#ifndef LDLOADER_HPP_
#define LDLOADER_HPP_

/*
** EPITECH PROJECT, 2023
** B_OOP_400_REN_4_1_arcade_jason_lagoute
** File description:
** DLLoader.hpp
*/
#ifndef DLLoader_HPP_
#define DLLoader_HPP_

#include <dlfcn.h>
#include <iostream>
#include "Exception.hpp"

#if __APPLE__
#define EXTENSION ".dylib"
#elif _WIN32 || _WIN64
#define EXTENSION ".dll"
#else
#define EXTENSION ".so"
#endif

template<typename T>
class LDLoader {
public:
    LDLoader() {
        this->_handle = nullptr;
        this->_instance = nullptr;
    };
    ~LDLoader() {
        this->closeLib();
    };

    /**
     * @brief Load a library and get the entry point
     * @param path Path to the library
     * @param entryPoint Name of the entry point
     */
    void loadLib(const std::string &path)
    {
        this->_handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!this->_handle)
            throw Raytracer::InvalidPluginException("Failed to load plugin " + path + ": " + dlerror());
    }

    T *getSymbol(const std::string &symbol, const std::string &options)
    {
        void *entry = dlsym(this->_handle, symbol.c_str());
        if (!entry)
            throw Raytracer::InvalidPluginException("Failed to load plugin: " + std::string(dlerror()));
        return reinterpret_cast<T *(*)(const std::string &)> (entry)(options);
    }

    /**
     * @brief Close the library and delete the instance
     */
    void closeLib()
    {
        if (this->_handle)
            dlclose(this->_handle);
        this->_handle = nullptr;
    }

private:
    void *_handle;
    T *_instance;
};

#endif /*DLLoader_HPP_*/

#endif //LDLOADER_HPP_
