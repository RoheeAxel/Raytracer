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

void Raytracer::Raytracer::buildScene()
{
    Sphere *sphere = new Sphere(Vec3(0, 0, 3), 1);
    sphere->setMaterial(new Plastic());
    PointLight *light = new PointLight(Vec3(0, 15, 3), Vec3(255, 255, 255), 1);
    _scene.addShape(sphere);
    _scene.addLight(light);
}

void Raytracer::Raytracer::render()
{
    _camera.render(_scene);
}
