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
#include <iostream>


Raytracer::Raytracer::Raytracer()
{
}

Raytracer::Raytracer::Raytracer(Vec3 top_left, Vec3 bot_right, std::pair<int, int> resolution)
{
    Camera camera(top_left, bot_right, resolution);
    _camera = camera;
}

void Raytracer::Raytracer::buildScene()
{
    Sphere *sphere = new Sphere(Vec3(0, 0, -3), 1);
    Sphere *sphere3 = new Sphere(Vec3(0, -101, -5), 100);
    sphere->setMaterial(new Normal());
    sphere3->setMaterial(new Plastic());
    PointLight *light = new PointLight(Vec3(2, 0, -1), Vec3(255, 255, 255), 1);
    _scene.addShape(sphere);
    _scene.addShape(sphere3);
    _scene.addLight(light);
}

void Raytracer::Raytracer::render()
{
    _camera.render(_scene);
}
