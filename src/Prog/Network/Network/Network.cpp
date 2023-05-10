/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Network
*/

#include "Network.hpp"

namespace Raytracer {

    Network::Network()
    {
        std::cout << "Network created" << std::endl;
    }

    Network::~Network()
    {
    }

    void Network::send(std::string data)
    {
        _packet.clear();
        _packet << data;
        _socket.send(_packet);
    }

    std::string Network::receive()
    {
        _packet.clear();
        _socket.receive(_packet);
        _packet >> _data;
        return _data;
    }

    void Network::connect(std::string ip, int port)
    {
        _socket.setBlocking(true);
        if (_socket.connect(ip, port) != sf::Socket::Done)
            throw NetworkException::ConnectionFailedException(ip, port);
    }

    void Network::disconnect()
    {
        _socket.disconnect();
    }

    void Network::setBlocking(bool blocking)
    {
        _socket.setBlocking(blocking);
    }

    sf::TcpSocket &Network::getSocket()
    {
        return this->_socket;
    }
};
