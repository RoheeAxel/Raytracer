/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Camera
*/

#include "Camera.hpp"
#include <iostream>
#include <fstream>

namespace Raytracer {

Camera::Camera()
{
}

Camera::Camera(Vec3 position, Vec3 rotation, Screen screen, std::string file)
{
    _position = position;
    _rotation = rotation;
    _screen = screen;
    _file = file;
}

Camera::~Camera()
{
}

void Camera::render(Scene &scene)
{
    Vec3 dir;
    Vec3 screenDiagonal = _screen.getBotRight() - _screen.getTopLeft();
    screenDiagonal = screenDiagonal.abs();
    std::ofstream myfile(this->_file);

    for (int j = 0; j < _screen.getResolution().second; j++) {
        for (int i = 0; i < _screen.getResolution().first; i++) {
            dir.x = _screen.getTopLeft().x + i * screenDiagonal.x / _screen.getResolution().first;
            dir.y = _screen.getTopLeft().y + j * screenDiagonal.y / _screen.getResolution().second;
            dir.z = _screen.getTopLeft().z;
            Ray ray(_position, dir);
            Vec3 color = scene.throwRay(ray, 0);
            myfile << color.x << " " << color.y << " " << color.z << std::endl;
        }
    }
    myfile.close();
}

}
