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

    Client::Client(std::string ip, int port, std::string filename)
    {
        connect(ip, port);
        _filename = filename;
    }

    Client::~Client()
    {
        disconnect();
    }

    void Client::run()
    {
        std::ifstream inFile;
        std::string line;
        std::string fullfile;
        std::vector<std::string> _mypixels;
        std::string result_path = "result.ppm";
        // start chrono
        auto start = std::chrono::high_resolution_clock::now();

        inFile.open(_filename);
        if (!inFile) {
            throw Config::FileNotFoundException(_filename);
        }
        while (getline(inFile, line) && _isRunning) {
            fullfile += line + "\n";
        }
        inFile.close();
        send(fullfile);
        if (receive() == "OK")
            std::cout << "Scene sent successfully" << std::endl;
        else
            throw NetworkException::SendFailedException("Scene");
        send("0 1");
        if (receive() == "OK")
            std::cout << "Camera position sent successfully" << std::endl;
        else
            throw NetworkException::SendFailedException("Camera position");
        Raytracer raytracer(_filename);
        raytracer._cam_pos = std::pair<float, float>(-1, 0);
        raytracer.render();
        std::string tmp = receive();
        _mypixels.push_back(raytracer._pixels);
        _mypixels.push_back(tmp);
        send("OK");
        raytracer.mergeCluster(_mypixels, CLUSTERS);
        raytracer.create_file(raytracer._pixels, result_path);
        // stop chrono
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Raytracing took " << duration.count() << " milliseconds" << std::endl;
    }
};
