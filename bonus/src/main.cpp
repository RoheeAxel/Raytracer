/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** main
*/

#include "ViewerPpm.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./raytracer [file]" << std::endl;
        return 84;
    } else if (ac == 2 && std::string(av[1]) == "-h") {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t./raytracer [file]" << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\t[file]\t\tfile describing the scene to render, in PPM format" << std::endl;
        return 0;
    }
    try {
        Viewer::ViewerPpm viewer(av[1]);
        viewer.run();
    } catch (std::exception &e) {
        return 84;
    }
    return 0;
}
