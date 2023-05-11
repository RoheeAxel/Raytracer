/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Client
*/

#include "Client.hpp"
#include "Network.hpp"
#include "Raytracer.hpp"
#include <fstream>
#include <thread>
#include <iostream>

namespace Raytracer {

    Client::Client(std::vector<std::string> ips, std::vector<int> ports, std::string filename)
    {
        if (ips.size() != ports.size())
            throw NetworkException::InvalidClusterException();
        for (size_t i = 0; i < ips.size(); i++) {
            this->newSocket();
            connect(i, ips[i], ports[i]);
        }
        _filename = filename;
    }

    Client::~Client()
    {
        for (size_t i = 0; i < getSockets().size(); i++)
            disconnect(i);
    }

    void Client::run()
    {
        std::ifstream inFile;
        std::string line;
        std::string fullfile;
        std::vector<std::string> _mypixels;
        std::string outfile;
        std::vector<std::string> tmp;
        std::string test;
        std::pair <float, float> _cam_pos = std::pair<float, float>(-1, 1);
        float value = _cam_pos.first;
        float divider = _cam_pos.second - _cam_pos.first;

        inFile.open(_filename);
        if (!inFile) {
            throw Config::FileNotFoundException(_filename);
        }
        while (getline(inFile, line) && _isRunning) {
            fullfile += line + "\n";
        }
        inFile.close();
        std::cout << "Scene loaded" << std::endl;
        for (size_t i = 0; i < CLUSTERS - 1; i++) {
            send(i, fullfile);
            if (receive(i) == "OK")
                std::cout << "Scene sent successfully" << std::endl;
            else
                throw NetworkException::SendFailedException("Scene");
        }
        Raytracer raytracer(_filename);
        raytracer._cam_pos = std::pair<float, float>(value, value + (divider / CLUSTERS));
        value = value + (divider / CLUSTERS);
        for (size_t i = 0; i < CLUSTERS - 1; i++) {
            std::string cam_str = std::to_string(value) + " " +std::to_string(value + (divider / CLUSTERS));
            send(i, cam_str);
            if (receive(i) == "OK")
                std::cout << "Camera position sent successfully" << std::endl;
            else
                throw NetworkException::SendFailedException("Camera position");
            value = value + (divider / CLUSTERS);
        }
        raytracer.render();
        for (size_t i = 0; i < CLUSTERS - 1; i++) {
            test = receive(i);
            send(i, "OK");
            tmp.push_back(test);
        }
        _mypixels.push_back(raytracer._pixels);
        for (size_t i = 0; i < CLUSTERS - 1; i++) {
            _mypixels.push_back(tmp[i]);
        }
        raytracer.mergeCluster(_mypixels, CLUSTERS);
        outfile = raytracer.getOutpoutFilename();
        raytracer.create_file(raytracer._pixels, outfile);
    }
};
