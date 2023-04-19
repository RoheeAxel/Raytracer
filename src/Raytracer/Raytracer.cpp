/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Raytracer
*/

#include "Raytracer.hpp"
#include "Camera.hpp"
#include <iostream>

Raytracer::Raytracer::Raytracer()
{
}

void Raytracer::Raytracer::buildScene()
{
    Sphere *sphere = new Sphere(Vec3(-2, 0, 3), 1);
    _scene.addShape(sphere2);
}

void Raytracer::Raytracer::render()
{
    _camera.render(_scene);
}
