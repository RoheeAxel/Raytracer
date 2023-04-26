/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_

#include "Vec3.hpp"

namespace Raytracer {
class Scene;
class Ray;
class ILight {
    public:
        virtual ~ILight() = default;
        virtual Raytracer::Vec3 illuminate(Raytracer::Vec3 point, Scene &scene) = 0;
        virtual Raytracer::Ray getRayToLight(Raytracer::Vec3 point) = 0;
    protected:
    private:
};
}

#endif /* !ILIGHT_HPP_ */
