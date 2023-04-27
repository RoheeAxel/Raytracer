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
    _scene.addShape(sphere);
    _scene.addShape(sphere2);
    _scene.addLight(light);
}

void Raytracer::Raytracer::render()
{
    float value = -1;
    std::ofstream myfile("result.ppm");

    std::cout << "Rendering..." << std::endl;
    for (size_t i = 0; i < THREADS; i++) {
        _cameras.push_back(Camera(Vec3(0, 0, 0), Vec3(0, 0, 0), Screen(Vec3(-1, value, -1), Vec3(1, value + (2 / THREADS), -1), std::pair<int, int>(WIDTH, HEIGHT / THREADS)), "test" + std::to_string(i) + ".ppm"));
        _threads.push_back(std::thread(&Camera::render, &_cameras[i], std::ref(this->_scene)));
        value += (2 / THREADS);
    }
    for (size_t i = 0; i < THREADS; i++) {
        _threads[i].join();
    }
    std::cout << "Done!" << std::endl;
    std::cout << "Merging files..." << std::endl;
    myfile << "P3" << std::endl << WIDTH << " " << HEIGHT << std::endl << "255" << std::endl;
    for (size_t i = 0; i < THREADS; i++) {
        std::ifstream file("test" + std::to_string(i) + ".ppm");
        if (!file.is_open()) {
            std::cout << "Error while opening file" << std::endl;
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            myfile << line << std::endl;
        }
        file.close();
    }
    myfile.close();
    std::cout << "Done!" << std::endl;
}
