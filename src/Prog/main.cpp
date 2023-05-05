/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** main
*/

#include "Raytracer.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./raytracer [scene file]" << std::endl;
        return 84;
    }
    try {
        Raytracer::Raytracer raytracer(av[1]);
        raytracer.render();
    } catch (Raytracer::Exception &e) {
        std::cerr << "Unexcepted error! " << e.what() << std::endl;
        return 84;
    }
    return 0;
}
