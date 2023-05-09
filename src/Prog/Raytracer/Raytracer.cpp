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

        size_t pos = file_path.find(".");
        if (pos != std::string::npos)
            this->_output_file_name = file_path.substr(0, pos);
        else
            this->_output_file_name = file_path;
        this->_output_file_name += ".ppm";
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
            CameraBuilder builder;
            builder.setPosition(this->_settings->getPosition());
            builder.setRotation(this->_settings->getRotation());
            builder.setScreen(Screen(Vec3(value, -1, -1), Vec3(value + (2.0 / nb_threads), 1, -1),
                std::pair<int, int>(this->_settings->getWidth() / nb_threads, this->_settings->getHeight())));
            builder.setId(i);
            builder.setSamplePerPixel(this->_settings->getSamples());
            _cameras.push_back(builder.build());
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
        std::cout << "Time taken for generation: " << duration.count() / 1000000 << " second(s)" << std::endl;
        std::cout << "Done!" << std::endl;
    }

    void Raytracer::mergeThread(size_t nb_threads)
    {
        std::ofstream myfile(this->_output_file_name, std::ios::out | std::ios::binary);
        size_t index = 0;
        size_t pos = 0;
        size_t divider = this->_settings->getWidth() / nb_threads;
        std::vector<std::vector<Vec3>> pixels;

        auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Merging files..." << std::endl;
        for (size_t i = 0; i < nb_threads; i++) {
            pixels.push_back(_cameras[i].getPixels());
        }

        size_t width = this->_settings->getWidth();
        size_t height = this->_settings->getHeight();
        myfile << "P6\n" << width << " " << height << "\n255\n";
        for (size_t j = 0; j < height; j++) {
            for (size_t i = 0; i < width; i++) {
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
        std::cout << "Time taken for merge: " << duration.count() / 1000000 << " second(s)" << std::endl;
        std::cout << "Done!" << std::endl;
    }

}
