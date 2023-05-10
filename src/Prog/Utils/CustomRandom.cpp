/*
** EPITECH PROJECT, 2023
** final
** File description:
** CustomRandom.cpp
*/

#include "CustomRandom.hpp"

namespace Raytracer {
    std::mt19937 CustomRandom::_gen;

    int CustomRandom::rand(int min, int max)
    {
        std::uniform_int_distribution<> dis(min, max);
        return dis(_gen);
    }

    double CustomRandom::rand(double min, double max)
    {
        std::uniform_real_distribution<> dis(min, max);
        return dis(_gen);
    }

    double CustomRandom::drand48()
    {
        return rand(0.0, 1.0);
    }

    void CustomRandom::seed() {
        std::random_device rd;
        CustomRandom::_gen = std::mt19937(rd());
    }
} // Raytracer