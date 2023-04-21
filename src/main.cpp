/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** main
*/

#include "Raytracer.hpp"
#include "Vec3.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Raytracer::Raytracer raytracer(Raytracer::Vec3(-1, -1, -1), Raytracer::Vec3(1, 1, -1), std::pair<int, int>(600, 600));
    raytracer.buildScene();
    raytracer.render();
    return 0;
}