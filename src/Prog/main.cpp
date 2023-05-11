/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** main
*/

#include "Raytracer.hpp"
#include "Exception.hpp"
#include <iostream>
#include <fstream>

int create_server(char **av)
{
    Raytracer::Server server(av[1], std::stoi(av[2]));
    server.run();
    return 0;
}

int create_client(char **av)
{
    std::ifstream inFile;
    std::string line;
    std::vector<std::string> ips;
    std::vector<int> ports;

    Raytracer::Client client(av[1]);
    client.run();
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 3 && std::string(av[1]) == "worker")
        return create_server(av);
    if (ac == 3 && std::string(av[2]) == "main")
        return create_client(av);
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
