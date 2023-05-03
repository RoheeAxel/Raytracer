/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** DirLight
*/

#ifndef DIR_LIGHT_
#define DIR_LIGHT_

#include "ILight.hpp"
#include "Ray.hpp"
#include "Scene.hpp"

namespace Raytracer {
    class Scene;
    class Ray;
    class DirLight : public ILight{
        public:
            DirLight() = default;
            DirLight(const Vec3 &position, const Vec3 &dir, const Vec3 &color, double intensity);
            ~DirLight() override = default;
            Raytracer::Vec3 illuminate(Raytracer::Vec3 point, Scene &scene) override;
            Raytracer::Ray getRayToLight(Raytracer::Vec3 point) override;

            void setPosition(const Vec3 &position);
            void setDir(const Vec3 &dir);
            void setColor(const Vec3 &color);
            void setIntensity(double intensity);

        private:
            Vec3 _position;
            Vec3 _dir;
            Vec3 _color;
            double _intensity;
    };
}

#endif /* !DIR_LIGHT_ */
