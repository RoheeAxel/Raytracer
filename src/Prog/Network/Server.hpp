/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <iostream>
    #include <SFML/Network.hpp>
    #include <string>

class Server {
    public:
        Server(std::string ip, int port);
        ~Server();

    protected:
    private:
        sf::TcpListener _listener;
        sf::TcpSocket _socket;
        sf::Packet _packet;
        std::string _data;
};

#endif /* !SERVER_HPP_ */
