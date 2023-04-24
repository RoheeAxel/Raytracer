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
    #include "DirLight.hpp"
    #include "Vec3.hpp"
    #include <thread>
    #include <array>
    #include <vector>

    #define THREADS 1
    #define HEIGHT 200
    #define WIDTH 200

namespace Raytracer {
    class Raytracer {
        public:
            Raytracer();
            ~Raytracer() = default;
            void buildScene();
            void render();
        private:
            void renderThread(size_t nb_threads);
            void mergeThread();
            std::array<std::array<Vec3, WIDTH>, HEIGHT> _pixels;
            std::vector<std::thread> _threads;
            std::vector<Camera> _cameras;
            Scene _scene;
    };
}

#endif /* !RAYTRACER_H_ */
