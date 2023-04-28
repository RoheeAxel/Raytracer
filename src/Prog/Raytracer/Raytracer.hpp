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
    #include <semaphore>

    #define THREADS 4
    #define HEIGHT 1080
    #define WIDTH 1920

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
            std::vector<std::thread> _threads;
            std::vector<Camera> _cameras;
            Scene _scene;
    };
}

#endif /* !RAYTRACER_H_ */
