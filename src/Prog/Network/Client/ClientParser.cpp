/*
** EPITECH PROJECT, 2023
** final
** File description:
** ClientParser.cpp
*/

#include "ClientParser.hpp"

namespace Raytracer {
    int ClientParser::_nb_clusters = 1;

    int ClientParser::getNbClusters() {
        return _nb_clusters;
    }

    ClientParser::ClientParser() {
        try {
            this->_cfg.readFile("cluster.cfg");
        } catch (libconfig::FileIOException &e) {
            throw Config::FileNotFoundException("config.cfg");
        }
        this->parse();
    }

    std::vector<std::string> ClientParser::getIps() {
        return _ips;
    }


    std::vector<int> ClientParser::getPorts() {
        return _ports;
    }

    void ClientParser::parse() {
        if (!this->_cfg.exists("workers")) {
            throw Config::MissingGroupException("workers");
        }

        libconfig::Setting &workersGroup = this->_cfg.lookup("workers");
        for (int i = 0; i < workersGroup.getLength(); i++) {
            libconfig::Setting &worker = workersGroup[i];
            if (!worker.exists("ip") || !worker.exists("port")) {
                throw Config::MissingGroupException("ip or port");
            }
            std::string ip = worker.lookup("ip");
            int port = worker.lookup("port");
            _ips.push_back(ip);
            _ports.push_back(port);
            this->_nb_clusters++;
        }
        std::cout << "Number of clusters: " << this->_nb_clusters << std::endl;
    }
} // Raytracer