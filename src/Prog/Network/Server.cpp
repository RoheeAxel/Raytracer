/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(std::string ip, int port)
{
    _listener.listen(port);
    _listener.accept(_socket);
    _socket.receive(_packet);
    _packet >> _data;
    std::cout << _data << std::endl;
}

Server::~Server()
{
    //this->socket.disconnect();
    //this->listener.close();
}
