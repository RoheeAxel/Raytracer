/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Raytracer
*/

#ifndef RAYTRACER_H_
    #define RAYTRACER_H_

    #include <SFML/Graphics.hpp>

    #include "Scene.hpp"
    #include "Camera.hpp"
    #include "Parser.hpp"
    #include "SceneBuilder.hpp"
    #include "Vec3.hpp"

    #include <thread>
    #include <array>
    #include <list>
    #include <vector>
    #include <semaphore>
    #include <memory>

    #define THREADS 8
    #define HEIGHT 400
    #define WIDTH 400

namespace Raytracer {
    class Raytracer {
        public:
            Raytracer();
            ~Raytracer() = default;

            void run(const std::string &file_path);

            sf::Image render();

        private:
            void renderThread(size_t nb_threads);
            sf::Image mergeThread(size_t nb_threads);
            std::vector<std::thread> _threads;
            std::vector<Camera> _cameras;

            //Screen _screen;
            std::shared_ptr<Scene> _scene;
    };
}

#endif /* !RAYTRACER_H_ */
