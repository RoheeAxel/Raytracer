/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <iostream>
    #include <SFML/Network.hpp>
    #include <string>

class Client {
    public:
        Client(std::string ip, int port);
        ~Client();

    protected:
    private:
        sf::TcpSocket _socket;
        sf::Packet _packet;
        std::string _data;
};

#endif /* !CLIENT_HPP_ */
