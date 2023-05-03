/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** PointLight
*/

#ifndef POINTLIGHT_HPP_
#define POINTLIGHT_HPP_

#include "ILight.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
#include "ParsingUtils.hpp"

namespace Raytracer {
    class Scene;
    class Ray;
    class PointLight : public ILight{
        public:
            PointLight() = default;
            PointLight(const Vec3 &position, const Vec3 &color, double intensity);
            explicit PointLight(const std::string &options);
            ~PointLight() override = default;
            Raytracer::Vec3 illuminate(Raytracer::Vec3 point, Scene &scene) override;
            Raytracer::Ray getRayToLight(Raytracer::Vec3 point) override;

            void setPosition(const Vec3 &position);
            void setColor(const Vec3 &color);
            void setIntensity(double intensity);
        protected:
        private:
            Vec3 _position;
            Vec3 _color;
            double _intensity;
    };
}

#endif /* !POINTLIGHT_HPP_ */
