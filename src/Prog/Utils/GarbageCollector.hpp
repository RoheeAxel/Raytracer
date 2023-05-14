/*
** EPITECH PROJECT, 2023
** final
** File description:
** GarbageCollector.hpp
*/

#ifndef GARBAGECOLLECTOR_HPP_
#define GARBAGECOLLECTOR_HPP_

#include <vector>
#include <memory>

namespace Raytracer {
    class GarbageCollector {
        public:
            GarbageCollector() = default;
            ~GarbageCollector() = default;

            static void add(std::shared_ptr<void> ptr);
            static void clear();
        private:
            static std::vector<std::shared_ptr<void>> _ptrs;
    };
}

#endif //GARBAGECOLLECTOR_HPP_
