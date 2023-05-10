/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Server
*/

#include "Server.hpp"
#include "Scene.hpp"
#include <fstream>
#include "Client.hpp"
#include "Raytracer.hpp"

namespace Raytracer {

    Server::Server(std::string ip, int port) : Network()
    {
        _listener.listen(port);
        if (_listener.accept(Network::getSocket()) != sf::Socket::Done)
            throw NetworkException::ConnectionFailedException(ip, port);
    }

    Server::~Server()
    {
        Network::disconnect();
        _listener.close();
    }

    void Server::run()
    {
        std::ofstream myfile("tmpscene.cfg");
        std::string cam_pos;

        if (!myfile.is_open())
            throw FileCreationException("tmpscene.cfg");
        myfile << receive();
        myfile.close();
        Network::send("OK");
        cam_pos = Network::receive();
        Network::send("OK");
        Raytracer raytracer("tmpscene.cfg");
        raytracer._cam_pos = std::pair<float, float>(std::stof(cam_pos.substr(0, cam_pos.find(" "))), std::stof(cam_pos.substr(cam_pos.find(" ") + 1)));
        raytracer.render();
        std::cout << "Image rendered with a size of " << raytracer._pixels.length() << std::endl;
        Network::send(raytracer._pixels);
        if (Network::receive() == "OK")
            std::cout << "Image sent successfully" << std::endl;
        else
            throw NetworkException::SendFailedException("Image");
    }
}