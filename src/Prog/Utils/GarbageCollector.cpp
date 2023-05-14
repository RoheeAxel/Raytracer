/*
** EPITECH PROJECT, 2023
** final
** File description:
** GarbageCollector.cpp
*/

#include "GarbageCollector.hpp"

namespace Raytracer {
    std::vector<std::shared_ptr<void>> GarbageCollector::_ptrs;

    void GarbageCollector::add(std::shared_ptr<void> ptr)
    {
        _ptrs.push_back(ptr);
    }

    void GarbageCollector::clear()
    {
        _ptrs.clear();
    }
}