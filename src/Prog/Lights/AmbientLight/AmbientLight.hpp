/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** AmbientLight
*/

#ifndef AMBIENTLIGHT_HPP_
#define AMBIENTLIGHT_HPP_

#include "ILight.hpp"
#include "Ray.hpp"
#include "Scene.hpp"

namespace Raytracer {
    class Scene;
    class Ray;
    class AmbientLight : public ILight{
        public:
            AmbientLight() = default;
            AmbientLight(const Vec3 &color, double intensity);
            ~AmbientLight() override = default;

            Raytracer::Vec3 illuminate(Raytracer::Vec3 point, Scene &scene) override;
            Raytracer::Ray getRayToLight(Raytracer::Vec3 point) override;

            void setColor(const Vec3 &color);
            void setIntensity(double intensity);
        private:
            Vec3 _color;
            double _intensity;
    };
}

#endif /* !AMBIENTLIGHT_HPP_ */
