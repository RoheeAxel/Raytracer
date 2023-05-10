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
        size_t pos2 = this->_output_file_name.find_last_of("/");
        if (pos2 != std::string::npos)
            this->_output_file_name = this->_output_file_name.substr(pos2 + 1);
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
        if (this->networkMode == NetworkType::CLIENT && CLUSTERS < 2) {
            this->create_file(this->_pixels, this->_output_file_name);
        }
    }

    void Raytracer::renderThread(size_t nb_threads)
    {
        float value = _cam_pos.first;
        float divider = _cam_pos.second - _cam_pos.first;
        std::pair<int, int> screenSize((this->_settings->getWidth() / nb_threads / CLUSTERS), this->_settings->getHeight());

        auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Rendering..." << std::endl;
        for (size_t i = 0; i < nb_threads; i++) {
            CameraBuilder builder;
            builder.setPosition(this->_settings->getPosition());
            builder.setRotation(this->_settings->getRotation());
            builder.setScreen(Screen(Vec3(value, -1, -1), Vec3(value + (divider / nb_threads), 1, -1), screenSize));
            builder.setId(i);
            builder.setSamplePerPixel(this->_settings->getSamples());
            _cameras.push_back(builder.build());
            value = value + (divider / nb_threads);
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
        size_t divider = this->_settings->getWidth() / nb_threads / CLUSTERS;
        std::vector<std::vector<Vec3>> pixels;

        for (size_t i = 0; i < nb_threads; i++) {
            pixels.push_back(_cameras[i].getPixels());
        }
        for (int j = 0; j < this->_settings->getHeight(); j++) {
            for (int i = 0; i < (this->_settings->getWidth() / CLUSTERS); i++) {
                index = (i) / (divider);
                pos = (divider * j) + i - (index * divider);
                char r = _cameras[index].getPixels()[pos].x > 255 ? 255 : _cameras[index].getPixels()[pos].x;
                char g = _cameras[index].getPixels()[pos].y > 255 ? 255 : _cameras[index].getPixels()[pos].y;
                char b = _cameras[index].getPixels()[pos].z > 255 ? 255 : _cameras[index].getPixels()[pos].z;
                std::string rgb = std::string(1, r) + std::string(1, g) + std::string(1, b);
                _pixels.append(rgb);
            }
        }
    }

    void Raytracer::mergeCluster(std::vector<std::string> &pixels, size_t nb_clusters)
    {
        size_t index = 0;
        size_t pos = 0;
        size_t divider = this->_settings->getWidth() / nb_clusters;
        std::string new_pixels = "";
        size_t width = this->_settings->getWidth();
        size_t height = this->_settings->getHeight();

        for (size_t j = 0; j < height; j++) {
            for (size_t i = 0; i < width; i++) {
                index = (i) / (divider);
                pos = (divider * j) + i - (index * divider);
                char r = pixels[index][pos * 3];
                char g = pixels[index][pos * 3 + 1];
                char b = pixels[index][pos * 3 + 2];
                std::string rgb = std::string(1, r) + std::string(1, g) + std::string(1, b);
                new_pixels.append(rgb);
            }
        }
        this->_pixels = new_pixels;
    }

    void Raytracer::create_file(std::string &pixels, std::string &file_path)
    {
        std::ofstream myfile(file_path, std::ios::out | std::ios::binary);
        if (!myfile.is_open())
            throw FileCreationException(file_path);
        myfile << "P6\n" << this->_settings->getWidth() << " " << this->_settings->getHeight() << "\n255\n";
        myfile << pixels;
        myfile.close();
    }
}
