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
    #define CLUSTERS 2

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
            void send(std::string data);
            std::string receive();
            void connect(std::string ip, int port);
            void disconnect();
            void setBlocking(bool blocking);

            sf::TcpSocket &getSocket();

        protected:
        private:
            sf::TcpSocket _socket;
            sf::Packet _packet;
            std::string _data;
    };
};

#endif /* !NETWORK_HPP_ */
