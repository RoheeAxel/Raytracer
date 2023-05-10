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
            CustomRandom() = default;
            ~CustomRandom() = default;

            int rand(int min, int max);
            double rand(double min, double max);

            double drand48();

            static void seed();
        private:
            static std::mt19937 _gen;
    };
} // Raytracer

#endif //CUSTOMRANDOM_HPP_
