/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <iostream>
    #include <string>
    #include "Scene.hpp"
    #include "Network.hpp"

namespace Raytracer {
    class Server : public Network {
        public:
            Server(std::string ip, int port);
            ~Server();
            void run();
        protected:
        private:
            sf::TcpListener _listener;
            Raytracer::Scene _scene;
    };
};

#endif /* !SERVER_HPP_ */
