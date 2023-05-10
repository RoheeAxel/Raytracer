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
    #include "Network.hpp"

namespace Raytracer
{
    class Client : public Network {
        public:
            Client(std::vector<std::string> ips, std::vector<int> ports, std::string filename);
            ~Client();
            void run();

        protected:
        private:
            std::string _filename;
            bool _isRunning = true;
    };
};
#endif /* !CLIENT_HPP_ */
