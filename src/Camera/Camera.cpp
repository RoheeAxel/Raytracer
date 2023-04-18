/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Camera
*/

#include "Camera.hpp"
#include <iostream>

namespace Raytracer {
Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::render(Scene &scene)
{
    Vec3 dir;
    Vec3 screenDiagonal = _screen.getBotRight() - _screen.getTopLeft();
    screenDiagonal = screenDiagonal.abs();

    std::cout << "Rendering scene" << std::endl;
    for (int i = 0; i < _screen.getResolution().first; i++) {
        for (int j = 0; j < _screen.getResolution().second; j++) {
            dir.x = _screen.getTopLeft().x + i * screenDiagonal.x / _screen.getResolution().first;
            dir.y = _screen.getTopLeft().y + j * screenDiagonal.y / _screen.getResolution().second;
            dir.z = _screen.getTopLeft().z;
            Ray ray(_position, dir);
        }
        //std::cout << "Line " << i << " done" << std::endl;
    }
}

}
