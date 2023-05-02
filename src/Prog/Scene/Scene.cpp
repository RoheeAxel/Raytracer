/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Scene
*/

#include "Scene.hpp"
#include <iostream>
#include <cmath>

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
    double reflect = 0;
    HitRecord hit;
    bool has_hit = false;
    for (auto &shape : _shapes) {
        hit = shape->intersection(ray);
        if (hit.hit && (hit.distance < last_distance || last_distance == -1)) {
            has_hit = true;
            for (auto &light : _lights) {
                hit.light = light->illuminate(hit.point, *this);
                Ray light_dir = light->getRayToLight(hit.point);
                current_color = hit.material->getColorAt(hit.point, hit.normal, light_dir, hit.light);
                if (depth < 8) {
                    reflect = hit.material->getReflectivity();

                    Ray new_ray = Ray(hit.point, hit.material->getNewRay(hit, ray.getDirection()));
                    if (new_ray.getDirection() != Vec3(0, 0, 0)) {
                        current_color = (current_color / 255) * throwRay(new_ray, depth + 1); //* reflect; //  current_color * (1 - reflect)
                    }
                }
                final_color = current_color;
                last_distance = hit.distance;
            }
        }
    }
    if (has_hit == false)
        return Vec3(255, 255, 255) * (1.0- 0.5*(ray.getDirection().y + 1.0)) + Vec3(127, 178, 255) * (0.5*(ray.getDirection().y + 1.0));
    return final_color;
}
}