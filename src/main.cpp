/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** main
*/

#include "Raytracer.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Raytracer::Raytracer raytracer;
    raytracer.buildScene();
    raytracer.render();
    return 0;
}