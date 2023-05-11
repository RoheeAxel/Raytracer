/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Network
*/

#ifndef NETWORK_HPP_
    #define NETWORK_HPP_

    #include <SFML/Network.hpp>
    #include "Exception.hpp"
    #include <iostream>
    #include <map>
    #include <memory>
    #include <list>
    #include <array>
    #define CLUSTERS 1

namespace Raytracer {

    enum NetworkType
    {
        CLIENT,
        SERVER
    };

    class Network {
        public:
            Network();
            ~Network();
            void send(size_t id, std::string data);
            std::string receive(size_t id);
            void connect(size_t id, std::string ip, int port);
            void disconnect(size_t id);
            void setBlocking(size_t id, bool blocking);

            void newSocket();
            std::array<sf::TcpSocket, CLUSTERS> &getSockets();

        protected:
        private:
            std::array<sf::TcpSocket, CLUSTERS> _sockets;
            std::array<sf::Packet, CLUSTERS> _packets;
            std::vector<std::string> _datas;
    };
};

#endif /* !NETWORK_HPP_ */
