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
    }

    Network::~Network()
    {
    }

    void Network::send(size_t id, std::string data)
    {
        _datas[id] = data;
        _packets[id].clear();
        _packets[id] << _datas[id];
        _sockets[id].send(_packets[id]);
    }

    std::string Network::receive(size_t id)
    {
        _packets[id].clear();
        _sockets[id].receive(_packets[id]);
        _packets[id] >> _datas[id];
        return _datas[id];
    }

    void Network::connect(size_t id, std::string ip, int port)
    {
        if (_sockets[id].connect(ip, port) != sf::Socket::Done)
            throw NetworkException::ConnectionFailedException(ip, port);
    }

    void Network::disconnect(size_t id)
    {
        _sockets[id].disconnect();
    }

    void Network::setBlocking(size_t id, bool blocking)
    {
        _sockets[id].setBlocking(blocking);
    }

    void Network::newSocket()
    {
        std::string data = "";
        _datas.push_back(data);
    }

    std::array<sf::TcpSocket, CLUSTERS> &Network::getSockets()
    {
        return _sockets;
    }
};
