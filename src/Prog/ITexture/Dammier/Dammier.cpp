/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Dammier
*/

#include "Dammier.hpp"
#include <iostream>

namespace Raytracer {
    Raytracer::Dammier::Dammier()
    {
    }

    Raytracer::Dammier::~Dammier()
    {
    }

    Vec3 Raytracer::Dammier::getColorAt(float x, float y)
    {
        int real_x = int(x * 100) % 8;
        int real_y = int(y * 100) % 8;
        if ((real_x) > 5 && (real_y) <= 5 || (real_x) <= 5 && (real_y) > 5)
            return Vec3(0, 0, 0);
        else
            return Vec3(255, 255, 255);
    }
}