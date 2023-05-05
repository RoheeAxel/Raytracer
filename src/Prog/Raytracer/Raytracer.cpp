/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Raytracer
*/

#include "Raytracer.hpp"
#include "Camera.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <algorithm>

namespace Raytracer {
    Raytracer::Raytracer(const std::string &file_path) {
        try {
            Parser parser(file_path);
            SceneBuilder builder(parser);
            this->_scene = builder.build();
            this->_settings = parser.parseSettings();
        } catch (libconfig::ParseException &e) {
            throw Exception("Parsing error: " + std::string(e.what()));
        }
    }

    void Raytracer::render()
    {
        size_t nb_threads = this->_settings->getThreads();

        for (size_t i = nb_threads; i > 0; i--) {
            if (this->_settings->getWidth() % i == 0 && this->_settings->getHeight() % i == 0) {
                nb_threads = i;
                break;
            }
        }
        this->renderThread(nb_threads);
        this->mergeThread(nb_threads);
    }

    void Raytracer::renderThread(size_t nb_threads)
    {
        float value = -1;

        auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Rendering..." << std::endl;
        for (size_t i = 0; i < nb_threads; i++) {
            Camera cam(this->_settings->getPosition(), this->_settings->getRotation(), Screen(Vec3(value, -1, -1), Vec3(value + (2.0 / nb_threads), 1, -1), std::pair<int, int>(this->_settings->getWidth() / nb_threads, this->_settings->getHeight())), i, this->_settings->getSamples());
            _cameras.push_back(cam);
            value = value + (2.0 / nb_threads);
        }
        for (size_t i = 0; i < nb_threads; i++) {
            _threads.push_back(std::thread(&Camera::render, &_cameras[i], std::ref(*this->_scene)));
        }
        for (size_t i = 0; i < nb_threads; i++) {
            _threads[i].join();
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time taken for generation: " << duration.count() << " microseconds" << std::endl;
        std::cout << "Done!" << std::endl;
    }

    void Raytracer::mergeThread(size_t nb_threads)
    {
        std::ofstream myfile("result.ppm", std::ios::out | std::ios::binary);
        size_t index = 0;
        size_t pos = 0;
        size_t divider = this->_settings->getWidth() / nb_threads;
        std::vector<std::vector<Vec3>> pixels;

        auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Merging files..." << std::endl;
        for (size_t i = 0; i < nb_threads; i++) {
            pixels.push_back(_cameras[i].getPixels());
        }
        myfile << "P6\n" << this->_settings->getWidth() << " " << this->_settings->getHeight() << "\n255\n";
        for (size_t j = 0; j < this->_settings->getHeight(); j++) {
            for (size_t i = 0; i < this->_settings->getWidth(); i++) {
                index = (i) / (divider);
                pos = (divider * j) + i - (index * divider);
                int r = _cameras[index].getPixels()[pos].x > 255 ? 255 : _cameras[index].getPixels()[pos].x;
                int g = _cameras[index].getPixels()[pos].y > 255 ? 255 : _cameras[index].getPixels()[pos].y;
                int b = _cameras[index].getPixels()[pos].z > 255 ? 255 : _cameras[index].getPixels()[pos].z;
                myfile.put(r);
                myfile.put(g);
                myfile.put(b);
            }
        }
        myfile.close();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time taken for merge: " << duration.count() << " microseconds" << std::endl;
        std::cout << "Done!" << std::endl;
    }

}
