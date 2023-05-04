/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Raytracer
*/

#include "Raytracer.hpp"
#include "Camera.hpp"

#include "Plastic.hpp"
#include "Normal.hpp"
#include "Glass.hpp"
#include "Lambertian.hpp"
#include "Emitive.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>

Raytracer::Raytracer::Raytracer()
{
}

void Raytracer::Raytracer::buildScene()
{
    Sphere *sphere = new Sphere(Vec3(0, 0, -3), -0.5);
    Sphere *sphere2 = new Sphere(Vec3(0, -100.5, -3), 100); // Floor
    Sphere *sphere3 = new Sphere(Vec3(1, 0, -3), 0.5); // Gold
    Sphere *sphere4 = new Sphere(Vec3(-1, 0, -3), -0.5); // Silver
    Triangle *triangle = new Triangle(Vec3(0, 0, -3), Vec3(0, 1, -2), Vec3(1, 0, -3));
    Triangle *triangle2 = new Triangle(Vec3(0, 1, -2), Vec3(1, 1, -2), Vec3(1, 0, -3));


    sphere->setMaterial(std::make_shared<Glass>());
    sphere2->setMaterial(std::make_shared<Lambertian>(Vec3(0,255,0)));
    sphere3->setMaterial(std::make_shared<Plastic>(Vec3(255 * 0.8, 255 * 0.6, 255 * 0.2), 0.5, 0.1));
    sphere4->setMaterial(std::make_shared<Emitive>(Vec3(512, 512, 512)));
    triangle->setMaterial(std::make_shared<Lambertian>(Vec3(255, 0, 0)));
    triangle2->setMaterial(std::make_shared<Lambertian>(Vec3(255, 0, 0)));


    //DirLight *light = new DirLight(Vec3(0, 0, 0), Vec3(0 ,0, -1), Vec3(255, 255, 255), 1);
    AmbientLight *ambient = new AmbientLight(Vec3(255, 255, 255), 0.7);
    _scene.addShape(sphere);
    _scene.addShape(sphere2);
    // _scene.addShape(sphere3);
    // _scene.addShape(sphere4);
    _scene.addShape(triangle);
    _scene.addShape(triangle2);
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
        }
    }
    this->renderThread(nb_threads);
    this->mergeThread(nb_threads);
}

void Raytracer::Raytracer::renderThread(size_t nb_threads)
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
