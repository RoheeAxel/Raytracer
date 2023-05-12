/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Camera
*/

#include <iostream>
#include <cmath>
#include "Camera.hpp"

namespace Raytracer {

    Camera::Camera(const Vec3& position, const Vec3& rotation, Screen& screen, size_t id, int sample_per_pixel)
    {
        _position = position;
        _rotation = _rotation + rotation;

        _screen = screen;
        _id = id;
        _sample_per_pixel = sample_per_pixel;
        _angle = 90;
        double angle_rad = _angle * M_PI / 180;

        _longueur = (1 / sin(angle_rad / 2) / (Vec3(-1,1,-1) - _position).Length());
    }

    void Camera::render(Scene &scene)
    {
        std::cout << "Thread " << _id << " starting" << std::endl;
        std::pair<int, int> resolution = _screen.getResolution();
        for (int j = resolution.second; j > 0; j--) {
            for (int i = 0; i < resolution.first; i++) {
                Vec3 finalColor = randomSuperSampling(scene, i, j);
                _pixels.push_back(finalColor);
            }
        }
        std::cout << "Thread " << _id << " ending" << std::endl;
    }

    Vec3 Camera::randomSuperSampling(Scene &scene, int i, int j)
    {
        Vec3 screenDiagonal = _screen.getBotRight() - _screen.getTopLeft();
        screenDiagonal = screenDiagonal.abs();
        Vec3 finalColor;

        for (int k = 0; k < _sample_per_pixel; k++) {
            Vec3 dir (
                _screen.getTopLeft().x + (i + _rand.rand(0, RAND_MAX) / (RAND_MAX + 1.0)) * screenDiagonal.x / _screen.getResolution().first,
                _screen.getTopLeft().y + (j + _rand.rand(0, RAND_MAX) / (RAND_MAX + 1.0)) * screenDiagonal.y / _screen.getResolution().second,
                _screen.getTopLeft().z * _longueur
            );
            Quaternion q(_rotation);
            dir = q.rotate(dir, _position);
            Ray ray(_position, dir);
            Vec3 color = scene.throwRay(ray, 0);
            finalColor += color;
        }
        double scale = 1.0 / _sample_per_pixel;
        finalColor /= 255;
        finalColor = Vec3(sqrt(finalColor.x * scale), sqrt(finalColor.y * scale), sqrt(finalColor.z * scale));
        finalColor *= 255;
        return finalColor;
    }

    Vec3 Camera::regularSuperSampling(Scene &scene, int i, int j)
    {
        Vec3 dir;
        Vec3 screenDiagonal = _screen.getBotRight() - _screen.getTopLeft();
        screenDiagonal = screenDiagonal.abs();
        Vec3 finalColor;

        for (int k = 0; k < 9; k++) {
            dir.x = _screen.getTopLeft().x + (i + double(k % 3 - 1) / 4) * screenDiagonal.x / _screen.getResolution().first;
            dir.y = _screen.getTopLeft().y + (j + double(k / 3 - 1) / 4) * screenDiagonal.y / _screen.getResolution().second;
            dir.z = _screen.getTopLeft().z;
            Ray ray(_position, dir);
            Vec3 color = scene.throwRay(ray, 0);
            finalColor += color;
        }
        return finalColor / 9;
    }
}