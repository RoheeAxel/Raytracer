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
#include "Lambertian.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>

Raytracer::Raytracer::Raytracer()
{
}

void Raytracer::Raytracer::buildScene()
{
    Sphere *sphere = new Sphere(Vec3(0, 0, -3), 0.5);
    Sphere *sphere2 = new Sphere(Vec3(0, -100.5, -3), 100);
    sphere->setMaterial(new Lambertian(Vec3(255, 0, 0)));
    sphere2->setMaterial(new Lambertian(Vec3(255, 255, 255)));
    PointLight *light = new PointLight(Vec3(8, 3, -3), Vec3(255, 255, 255), 1);
    AmbientLight *ambient = new AmbientLight(Vec3(255, 255, 255), 0.3);
    _scene.addShape(sphere);
    _scene.addShape(sphere2);
    _scene.addLight(light);
    _scene.addLight(ambient);
}

void Raytracer::Raytracer::render()
{
    this->renderThread(THREADS);
    this->mergeThread();
}

void Raytracer::Raytracer::renderThread(size_t nb_threads)
{
    float value = -1;
    std::ofstream myfile("result.ppm");

    std::cout << "Rendering..." << std::endl;
    for (size_t i = 0; i < nb_threads; i++) {
        Camera cam(Vec3(0, 0, 0), Vec3(0, 0, 0), Screen(Vec3(value, -1, -1), Vec3(value + (2.0 / nb_threads), 1, -1), std::pair<int, int>(WIDTH / THREADS, HEIGHT)), i);
        _cameras.push_back(cam);
        value = value + (2.0 / nb_threads);
    }
    for (size_t i = 0; i < nb_threads; i++) {
        _threads.push_back(std::thread(&Camera::render, &_cameras[i], std::ref(this->_scene)));
    }
    for (size_t i = 0; i < nb_threads; i++) {
        _threads[i].join();
    }
    std::cout << "Done!" << std::endl;
}

void Raytracer::Raytracer::mergeThread()
{
    std::ofstream myfile("result.ppm");
    size_t index = 0;
    size_t pos = 0;
    size_t divider = WIDTH / THREADS;
    std::vector<std::vector<Vec3>> pixels;

    std::cout << "Merging files..." << std::endl;
    for (size_t i = 0; i < THREADS; i++) {
        pixels.push_back(_cameras[i].getPixels());
    }
    myfile << "P3" << std::endl << WIDTH << " " << HEIGHT << std::endl << "255" << std::endl;
    for (size_t j = 0; j < HEIGHT; j++) {
        for (size_t i = 0; i < WIDTH; i++) {
            index = (i) / (divider);
            pos = (divider * j) + i - (index * divider);
            myfile << _cameras[index].getPixels()[pos].x << " " << _cameras[index].getPixels()[pos].y << " " <<_cameras[index].getPixels()[pos].z << std::endl;
        }
    }
    myfile.close();
    std::cout << "Done!" << std::endl;
}
