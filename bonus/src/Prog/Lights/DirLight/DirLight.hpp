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
            DirLight(Vec3 position, Vec3 color, double intensity);
            ~DirLight();
            Raytracer::Vec3 illuminate(Raytracer::Vec3 point, Scene &scene) override;
            Raytracer::Ray getRayToLight(Raytracer::Vec3 point) override;
        protected:
        private:
            Vec3 _position;
            Vec3 _dir;
            Vec3 _color;
            double _intensity;
    };
}

#endif /* !DIR_LIGHT_ */
