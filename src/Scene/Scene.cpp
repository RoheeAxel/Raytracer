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

Vec3 Scene::throwRay(Ray ray, int depth)
{
    Vec3 final_color;

    HitRecord hit;
    for (auto &shape : _shapes) {
        hit = shape->intersection(ray);
        if (hit.hit) {
            for (auto &light : _lights) {
                hit.light = light->illuminate(hit.point, *this);
                Ray light_dir = light->getRayToLight(hit.point);
                final_color= hit.material->getColorAt(hit.point, hit.normal, light_dir, hit.light);
            }
        }
    }
    return final_color;
}
}