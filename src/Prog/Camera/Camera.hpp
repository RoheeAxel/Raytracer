/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#define SAMPLE_PER_PIXEL 10

#include "Scene.hpp"
#include "Screen.hpp"
#include "Vec3.hpp"
#include "Ray.hpp"
#include <string>

namespace Raytracer {
    class Camera {
        public:
            Camera();
            Camera(Vec3 position, Vec3 rotation, Screen screen, std::string file, size_t test);
            ~Camera();
            void render(Scene &scene);
        protected:
        private:
            Vec3 randomSuperSampling(Scene &scene, int i, int j);
            Vec3 regularSuperSampling(Scene &scene, int i, int j);
            Vec3 (*samplingFunction)(Scene &scene, int i, int j);
            int _sample_per_pixel = 1000;
            Vec3 _position;
            Vec3 _rotation;
            Screen _screen = Screen(Vec3(-1, -1, 1), Vec3(1, 1, 1), std::pair<int, int>(200, 200));
            std::string _file;
            size_t test;
    };
}

#endif /* !CAMERA_HPP_ */
