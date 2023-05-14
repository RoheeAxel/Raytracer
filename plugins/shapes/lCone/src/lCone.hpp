/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** lCone
*/

#ifndef LCone_HPP_
    #define LCone_HPP_

    #include <string>
    #include "ParsingUtils.hpp"
    #include "AShape.hpp"

namespace Raytracer {
    class lCone : public AShape{
        public:
            lCone(const Vec3 &position, double radius);
            lCone(const std::string &options);
            ~lCone() override = default;
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
            double _angle;
            double _height;
    };
}

#endif /* !LCone_HPP_ */
