/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Scene
*/

#ifndef SCENE_H_
#define SCENE_H_

#include "ILight.hpp"
#include "IShape.hpp"
#include "GarbageCollector.hpp"
#include <memory>
#include <vector>

namespace Raytracer {
    class Scene {
        public:
            Scene() = default;
            ~Scene() {
                _lights.clear();
                _shapes.clear();
                GarbageCollector::clear();
            };

            void addLight(std::shared_ptr<ILight> light);
            void addShape(std::shared_ptr<IShape> shape);
            void setMaxDepth(int max_depth);

            std::vector<std::shared_ptr<ILight>> &getLights();
            std::vector<std::shared_ptr<IShape>> &getShapes();
            int getMaxDepth() const;

            Vec3 throwRay(Ray ray, int depth);
        private:
            std::vector<std::shared_ptr<ILight>> _lights;
            std::vector<std::shared_ptr<IShape>> _shapes;
            int _max_depth;
    };
}

#endif /* !SCENE_H_ */
