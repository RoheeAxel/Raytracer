/*
** EPITECH PROJECT, 2023
** final
** File description:
** CameraBuilder.hpp
*/

#ifndef CAMERABUILDER_HPP_
#define CAMERABUILDER_HPP_

#include "Vec3.hpp"
#include "Camera.hpp"

namespace Raytracer {

    class CameraBuilder {
        public:
            CameraBuilder() = default;
            ~CameraBuilder() = default;

            CameraBuilder &setPosition(const Vec3 &position);
            CameraBuilder &setRotation(const Vec3 &rotation);
            CameraBuilder &setScreen(const Screen &screen);
            CameraBuilder &setId(size_t id);
            CameraBuilder &setSamplePerPixel(int sample_per_pixel);
            CameraBuilder &setFov(int fov);
            Camera build();
        private:
            Vec3 _position;
            Vec3 _rotation;
            Screen _screen;
            size_t _id;
            int _sample_per_pixel;
            int _fov;
    };

} // Raytracer

#endif //CAMERABUILDER_HPP_
