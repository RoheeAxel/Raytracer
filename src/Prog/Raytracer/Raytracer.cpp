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

<<<<<<< HEAD
Raytracer::Raytracer::Raytracer()
{
}

void Raytracer::Raytracer::buildScene()
{
    Quad *wall1 = new Quad(Vec3(-1, -1, -3), Vec3(-1, 1, -3), Vec3(-1, 1, 1), Vec3(-1, -1, 1));
    Quad *ceil = new Quad(Vec3(-1, 1, -3), Vec3(1, 1, -3), Vec3(1, 1, 1), Vec3(-1, 1, 1));
    Quad *lamp = new Quad (Vec3(0, 0.99, -2), Vec3(0.1, 0.99, -2), Vec3(0.1, 0.99, -1), Vec3(0, 0.99, -1));
    Quad *wall2 = new Quad(Vec3(1, 1, -3), Vec3(1, -1, -3), Vec3(1, -1, 1), Vec3(1, 1, 1));
    Quad *floor = new Quad(Vec3(-1, -1, -3), Vec3(1, -1, -3), Vec3(1, -1, 1), Vec3(-1, -1, 1));
    Quad *wall3 = new Quad(Vec3(-1, -1, -3), Vec3(1, -1, -3.001), Vec3(1, 1, -3.001), Vec3(-1, 1, -3));
    Sphere *sphere3 = new Sphere(Vec3(0, -100, -40), 100);

    wall1->setMaterial(std::make_shared<Lambertian>(Vec3(0,255,0)));
    ceil->setMaterial(std::make_shared<Lambertian>(Vec3(255,255,255)));
    wall2->setMaterial(std::make_shared<Lambertian>(Vec3(255,0,0)));
    floor->setMaterial(std::make_shared<Lambertian>(Vec3(255,255,255)));
    wall3->setMaterial(std::make_shared<Lambertian>(Vec3(255,255,255)));
    lamp->setMaterial(std::make_shared<Emitive>(Vec3(4000,4000,4000)));

    sphere3->setMaterial(std::make_shared<Lambertian>(Vec3(255,255,255)));

    //DirLight *light = new DirLight(Vec3(0, 0, 0), Vec3(0 ,0, -1), Vec3(255, 255, 255), 1);
    //PointLight *light = new PointLight(Vec3(0, 0, -1.5), Vec3(255 ,255, 255), 1);
    AmbientLight *ambient = new AmbientLight(Vec3(255, 255, 255), 0.4);
    // _scene.addShape(wall1);
    // _scene.addShape(ceil);
    // _scene.addShape(wall2);
    // _scene.addShape(floor);
    // _scene.addShape(wall3);
    _scene.addShape(sphere3);
    // _scene.addShape(sphere4);
    // _scene.addShape(wall1);
    // _scene.addShape(lamp);
    //_scene.addLight(light);
    _scene.addLight(ambient);
}

void Raytracer::Raytracer::render()
{
    size_t nb_threads = THREADS;

    for (size_t i = THREADS; i > 0; i--) {
        if (WIDTH % i == 0 && HEIGHT % i == 0) {
            nb_threads = i;
            break;
=======
namespace Raytracer {
    Raytracer::Raytracer(const std::string &file_path) {
        try {
            Parser parser(file_path);
            SceneBuilder builder(parser);
            this->_scene = builder.build();
        } catch (libconfig::ParseException &e) {
            throw Exception("Parsing error: " + std::string(e.what()));
>>>>>>> refs/remotes/origin/main
        }
    }

    void Raytracer::render()
    {
        size_t nb_threads = THREADS;

<<<<<<< HEAD
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Rendering..." << std::endl;
    for (size_t i = 0; i < nb_threads; i++) {
        Camera cam(Vec3(0, 0, 0), Vec3(0, 0, 0), Screen(Vec3(value, -1, -1), Vec3(value + (2.0 / nb_threads), 1, -1), std::pair<int, int>(WIDTH / nb_threads, HEIGHT)), i);
        _cameras.push_back(cam);
        value = value + (2.0 / nb_threads);
    }
    for (size_t i = 0; i < nb_threads; i++) {
        _threads.push_back(std::thread(&Camera::render, &_cameras[i], std::ref(this->_scene)));
    }
    for (size_t i = 0; i < nb_threads; i++) {
        _threads[i].join();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken for generation: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Done!" << std::endl;
}

void Raytracer::Raytracer::mergeThread(size_t nb_threads)
{
    std::ofstream myfile("result.ppm", std::ios::out | std::ios::binary);
    size_t index = 0;
    size_t pos = 0;
    size_t divider = WIDTH / nb_threads;
    std::vector<std::vector<Vec3>> pixels;

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Merging files..." << std::endl;
    for (size_t i = 0; i < nb_threads; i++) {
        pixels.push_back(_cameras[i].getPixels());
    }
    myfile << "P6\n" << WIDTH << " " << HEIGHT << "\n255\n";
    for (size_t j = 0; j < HEIGHT; j++) {
        for (size_t i = 0; i < WIDTH; i++) {
            index = (i) / (divider);
            pos = (divider * j) + i - (index * divider);
            myfile.put(std::min(_cameras[index].getPixels()[pos].x, 255.0));
            myfile.put(std::min(_cameras[index].getPixels()[pos].y, 255.0));
            myfile.put(std::min(_cameras[index].getPixels()[pos].z, 255.0));
=======
        for (size_t i = THREADS; i > 0; i--) {
            if (WIDTH % i == 0 && HEIGHT % i == 0) {
                nb_threads = i;
                break;
            }
>>>>>>> refs/remotes/origin/main
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
            Camera cam(Vec3(0, 0, 0), Vec3(0, 0, 0), Screen(Vec3(value, -1, -1), Vec3(value + (2.0 / nb_threads), 1, -1), std::pair<int, int>(WIDTH / nb_threads, HEIGHT)), i);
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
        size_t divider = WIDTH / nb_threads;
        std::vector<std::vector<Vec3>> pixels;

        auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Merging files..." << std::endl;
        for (size_t i = 0; i < nb_threads; i++) {
            pixels.push_back(_cameras[i].getPixels());
        }
        myfile << "P6\n" << WIDTH << " " << HEIGHT << "\n255\n";
        for (size_t j = 0; j < HEIGHT; j++) {
            for (size_t i = 0; i < WIDTH; i++) {
                index = (i) / (divider);
                pos = (divider * j) + i - (index * divider);
                myfile.put(_cameras[index].getPixels()[pos].x);
                myfile.put(_cameras[index].getPixels()[pos].y);
                myfile.put(_cameras[index].getPixels()[pos].z);
            }
        }
        myfile.close();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time taken for merge: " << duration.count() << " microseconds" << std::endl;
        std::cout << "Done!" << std::endl;
    }

}
