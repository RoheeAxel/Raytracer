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
    #include "Parser.hpp"
    #include "SceneBuilder.hpp"
    #include "Network.hpp"
    #include "Client.hpp"
    #include "Server.hpp"
    #include "Vec3.hpp"
    #include "Settings.hpp"
    #include "CameraBuilder.hpp"

    #include <thread>
    #include <array>
    #include <list>
    #include <vector>
    #include <semaphore>
    #include <memory>

namespace Raytracer {
    class Raytracer {
        public:
            Raytracer(const std::string &file_path);
            ~Raytracer() = default;

            void render();
            void mergeCluster(std::vector<std::string> &pixels, size_t nb_clusters);
            void create_file(std::string &pixels, std::string &file_path);

            size_t networkMode = NetworkType::CLIENT;
            std::pair<float, float> _cam_pos = std::pair<float, float>(-1, 1);
            std::string _pixels = "";
        private:
            void renderThread(size_t nb_threads);
            void mergeThread(size_t nb_threads);
            std::vector<std::thread> _threads;
            std::vector<Camera> _cameras;

            std::shared_ptr<Settings> _settings;
            std::shared_ptr<Scene> _scene;
            std::string _output_file_name;
    };
}

#endif /* !RAYTRACER_H_ */
