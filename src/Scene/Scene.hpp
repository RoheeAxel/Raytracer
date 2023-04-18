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
#include <vector>

namespace Raytracer {
    class Scene {
        public:
            Scene();
            ~Scene();
            std::vector<ILight *> &getLights();
            std::vector<IShape *> &getShapes();
        private:
            std::vector<ILight *> _lights;
            std::vector<IShape *> _shapes;
    };
}

#endif /* !SCENE_H_ */
