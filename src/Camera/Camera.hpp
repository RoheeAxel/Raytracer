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

namespace Raytracer {
    class Camera {
        public:
            Camera();
            ~Camera();
            void render(Scene &scene);
        protected:
        private:
            Vec3 _position;
            Vec3 _rotation;
            Screen _screen = Screen(Vec3(-1, -1, 0), Vec3(1, 1, 0), std::pair<int, int>(200, 200));
    };
}

#endif /* !CAMERA_HPP_ */
