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
        } catch (libconfig::ParseException &e) {
            throw Exception("Parsing error: " + std::string(e.what()));
        }
    }

    void Raytracer::render()
    {
        size_t nb_threads = THREADS;
        std::string result_file = "result.ppm";

        for (size_t i = THREADS; i > 0; i--) {
            if (WIDTH % i == 0 && HEIGHT % i == 0) {
                nb_threads = i;
                break;
            }
        }
        this->renderThread(nb_threads);
        this->mergeThread(nb_threads);
        if (this->networkMode == NetworkType::CLIENT && CLUSTERS < 2) {
            this->create_file(this->_pixels, result_file);
        }
    }

    void Raytracer::renderThread(size_t nb_threads)
    {
        float value = _cam_pos.first;
        float divider = _cam_pos.second - _cam_pos.first;

        auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Rendering..." << std::endl;
        for (size_t i = 0; i < nb_threads; i++) {
            Camera cam(Vec3(0, 0, 0), Vec3(0, 0, 0), Screen(Vec3(value, -1, -1), Vec3(value + (divider / nb_threads), 1, -1), std::pair<int, int>(WIDTH / CLUSTERS / nb_threads, HEIGHT)), i);
            _cameras.push_back(cam);
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
        std::cout << "Time taken for generation: " << duration.count() << " microseconds" << std::endl;
        std::cout << "Done!" << std::endl;
    }

    void Raytracer::mergeThread(size_t nb_threads)
    {
        size_t index = 0;
        size_t pos = 0;
        size_t divider = WIDTH / CLUSTERS / nb_threads;
        std::vector<std::vector<Vec3>> pixels;

        for (size_t i = 0; i < nb_threads; i++) {
            pixels.push_back(_cameras[i].getPixels());
        }
        for (size_t j = 0; j < HEIGHT; j++) {
            for (size_t i = 0; i < (WIDTH / CLUSTERS); i++) {
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
        size_t divider = WIDTH / nb_clusters;
        std::string new_pixels = "";
        for (size_t j = 0; j < HEIGHT; j++) {
            for (size_t i = 0; i < WIDTH; i++) {
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
        myfile << "P6\n" << WIDTH << " " << HEIGHT << "\n255\n";
        myfile << pixels;
        myfile.close();
    }
}
