/*
** EPITECH PROJECT, 2023
** final
** File description:
** CustomRandom.hpp
*/

#ifndef CUSTOMRANDOM_HPP_
#define CUSTOMRANDOM_HPP_

#include <random>

#define RAND_MAX 2147483647

namespace Raytracer {
    class CustomRandom {
        public:
            CustomRandom();
            ~CustomRandom() = default;

            int rand(int min, int max);
            double rand(double min, double max);

            double drand48();
        private:
            std::mt19937 _gen;
    };
} // Raytracer

#endif //CUSTOMRANDOM_HPP_
