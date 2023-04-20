/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Raytracer
*/

#include "Raytracer.hpp"
#include "Camera.hpp"
#include "Plastic.hpp"
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
    Sphere *sphere = new Sphere(Vec3(-1, 0, 3), 0.5);
    Sphere *sphere2 = new Sphere(Vec3(1, 0, 3), 0.5);
    sphere->setMaterial(new Plastic());
    sphere2->setMaterial(new Plastic());
    PointLight *light = new PointLight(Vec3(3, 0, 2), Vec3(255, 255, 255), 1);
    _scene.addShape(sphere);
    _scene.addShape(sphere2);
    _scene.addLight(light);
}

void Raytracer::Raytracer::render()
{
    _camera.render(_scene);
}
