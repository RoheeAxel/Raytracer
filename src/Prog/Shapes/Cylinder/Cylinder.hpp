/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP
    #define CYLINDER_HPP

    #include <string>
    #include "ParsingUtils.hpp"
    #include "AShape.hpp"

namespace Raytracer {
    class Cylinder : public AShape{
        public:
            Cylinder(const Vec3 &position, double radius);
            Cylinder(const std::string &options);
            ~Cylinder() override = default;
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
    };
}

#endif /* !CYLINDER_HPP */
