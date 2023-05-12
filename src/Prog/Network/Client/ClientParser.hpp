/*
** EPITECH PROJECT, 2023
** final
** File description:
** ClientParser.hpp
*/

#ifndef CLIENTPARSER_HPP_
#define CLIENTPARSER_HPP_

#include <libconfig.h++>
#include <vector>
#include <string>
#include <iostream>
#include "Exception.hpp"

namespace Raytracer {

    class ClientParser {
        public:
            ClientParser();
            ~ClientParser() = default;

            std::vector<std::string> getIps();
            std::vector<int> getPorts();

            static std::size_t getNbClusters();
            static void setNbClusters(std::size_t nbClusters);
        private:
            libconfig::Config _cfg;
            std::vector<std::string> _ips;
            std::vector<int> _ports;

            static std::size_t _nb_clusters;

            void parse();
    };

} // Raytracer

#endif //CLIENTPARSER_HPP_
