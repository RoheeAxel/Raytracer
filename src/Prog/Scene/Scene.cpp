/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Scene
*/

#include "Scene.hpp"

namespace Raytracer {

    Vec3 Scene::throwRay(Ray ray, int depth)
    {
        Vec3 final_color;
        Vec3 current_color;
        double last_distance = -1;
        HitRecord hit;
        bool has_hit = false;

        for (auto &shape : _shapes) {
            hit = shape->intersection(ray);
            if (hit.hit && (hit.distance < last_distance || last_distance == -1)) {
                has_hit = true;
                for (auto &light : _lights) {
                    hit.light = light->illuminate(hit.point, *this);
                    Ray light_dir = light->getRayToLight(hit.point);
                    current_color = hit.material->getColorAt(hit, light_dir, hit.light);
                    if (depth < this->getMaxDepth()) {
                        Ray new_ray = Ray(hit.point, hit.material->getNewRay(hit, ray.getDirection()));
                        if (new_ray.getDirection() != Vec3(0, 0, 0)) {
                            current_color = (current_color / 255) * throwRay(new_ray, depth + 1);
                        }
                    }
                    final_color = current_color;
                    last_distance = hit.distance;
                }
            }
        }
        if (!has_hit)
            return Vec3(255, 255, 255) * (1.0- 0.5*(ray.getDirection().y + 1.0)) + Vec3(127, 178, 255) * (0.5*(ray.getDirection().y + 1.0));
        return final_color;
    }

    void Scene::addLight(std::shared_ptr<ILight> light) {
        this->_lights.push_back(light);
    }

    void Scene::addShape(std::shared_ptr<IShape> shape) {
        this->_shapes.push_back(shape);
    }

    void Scene::setMaxDepth(int max_depth) {
        this->_max_depth = max_depth;
    }

    std::vector<std::shared_ptr<ILight>> &Scene::getLights() {
        return this->_lights;
    }

    std::vector<std::shared_ptr<IShape>> &Scene::getShapes() {
        return this->_shapes;
    }

    int Scene::getMaxDepth() const {
        return this->_max_depth;
    }

}
