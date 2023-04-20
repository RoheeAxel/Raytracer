/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Raytracer
*/

#ifndef RAYTRACER_H_
    #define RAYTRACER_H_
    #include "Scene.hpp"
    #include "Camera.hpp"
    #include "Sphere.hpp"
    #include "PointLight.hpp"

namespace Raytracer {
    class Raytracer {
        public:
            Raytracer();
            ~Raytracer() = default;
            void buildScene();
            void render();
        private:
            Camera _camera;
            Scene _scene;
    };
}

#endif /* !RAYTRACER_H_ */
