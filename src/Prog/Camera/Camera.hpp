/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Scene.hpp"
#include "Screen.hpp"
#include "Vec3.hpp"
#include "Ray.hpp"
#include <string>
#include <array>
#include <list>
#include "CustomRandom.hpp"

namespace Raytracer {
    class Camera {
        public:
            Camera() = default;
            Camera(const Vec3& position, const Vec3& rotation, Screen& screen, size_t id, int _sample_per_pixel = 10);
            ~Camera() = default;

            void render(Scene &scene);
            Vec3 getPixel(size_t index) { return _pixels[index]; };
            std::vector<Vec3> &getPixels() { return _pixels; };
        protected:
        private:
            Vec3 randomSuperSampling(Scene &scene, int i, int j);
            Vec3 regularSuperSampling(Scene &scene, int i, int j);
            Vec3 (*samplingFunction)(Scene &scene, int i, int j);
            int _sample_per_pixel;
            Vec3 _position;
            Vec3 _rotation;
            Screen _screen = Screen(Vec3(-1, -1, 1), Vec3(1, 1, 1), std::pair<int, int>(200, 200));
            std::vector<Vec3> _pixels;
            size_t _id;
            CustomRandom _rand;
    };
}

#endif /* !CAMERA_HPP_ */
