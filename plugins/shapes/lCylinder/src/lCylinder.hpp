/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** LCylinder
*/

#ifndef LLCylinder_HPP
    #define LLCylinder_HPP

    #include <string>
    #include "ParsingUtils.hpp"
    #include "AShape.hpp"

namespace Raytracer {
    class LCylinder : public AShape{
        public:
            LCylinder(const Vec3 &position, double radius);
            LCylinder(const std::string &options);
            ~LCylinder() override = default;
            HitRecord intersection(Ray ray) override;
            AABB getAABB() override;
            std::pair<double, double> getUV(Vec3 point) override;
            void setTranslation(Vec3 translation) override;
            void setRotation(Vec3 rotation, Vec3 center) override;
            void setScale(Vec3 scale) override;

        private:
            Vec3 _position;
            double _radius;
            Vec3 _direction;
            Vec3 _rotation;
            double _height;
            Vec3 _scale;
    };
}

extern "C" Raytracer::LCylinder *create(const std::string &options);

#endif /* !LLCylinder_HPP */
