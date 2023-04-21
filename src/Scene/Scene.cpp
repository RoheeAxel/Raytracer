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
    Vec3 current_color;
    double last_distance = -1;

    HitRecord hit;
    for (auto &shape : _shapes) {
        hit = shape->intersection(ray);
        if (hit.hit && (hit.distance < last_distance || last_distance == -1)) {
            for (auto &light : _lights) {
                hit.light = light->illuminate(hit.point, *this);
                Ray light_dir = light->getRayToLight(hit.point);
                current_color = hit.material->getColorAt(hit.point, hit.normal, light_dir, hit.light);
                if (depth < 5) {
                    Ray new_ray = Ray(hit.point, hit.material->getNewRay(hit.point, hit.normal, ray.getDirection()));
                    if (new_ray.getDirection() != Vec3(0, 0, 0)) {
                        current_color += throwRay(new_ray, depth + 1);
                        current_color /= 2;
                    }
                }
                final_color = final_color.Max(current_color);
                last_distance = hit.distance;
            }
        }
    }
    return final_color;
}
}