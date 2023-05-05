/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(std::string ip, int port)
{
    _socket.connect(ip, port);
    _packet << "Hello server!";
    _socket.send(_packet);
}

Client::~Client()
{
}
