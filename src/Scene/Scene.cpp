/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Scene
*/

#include "Scene.hpp"
#include <iostream>

namespace Raytracer {
Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::addLight(ILight *light)
{
    _lights.push_back(light);
}

void Scene::addShape(IShape *shape)
{
    _shapes.push_back(shape);
}

std::vector<ILight *> &Scene::getLights()
{
    return _lights;
}

std::vector<IShape *> &Scene::getShapes()
{
    return _shapes;
}

void Scene::throwRay(Ray ray, int depth)
{
    HitRecord to_return;
    to_return.hit = false;

    HitRecord hit;
    for (auto &shape : _shapes) {
        hit = shape->intersection(ray);
        if (hit.hit) {
            for (auto &light : _lights) {
                hit.color = light->illuminate(hit.point);
            }
            to_return = hit;
        }
    }
    if (to_return.hit) {
        std::cout << to_return.color.x << " " << to_return.color.y << " " << to_return.color.z << std::endl;
        return;
    } else {
        std::cout << "0 0 0" << std::endl;
    }
}
}