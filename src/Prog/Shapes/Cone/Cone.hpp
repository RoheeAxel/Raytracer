/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Cone
*/

#ifndef CONE_HPP_
    #define CONE_HPP_

    #include <string>
    #include "ParsingUtils.hpp"
    #include "AShape.hpp"

namespace Raytracer {
    class Cone : public AShape {
        public:
            Cone(const Vec3 &position, double radius);
            Cone(const std::string &options);
            ~Cone() override = default;

            HitRecord intersection(Ray ray) override;
            AABB getAABB() override;
            std::pair<double, double> getUV(Vec3 point) override;
            void setTranslation(Vec3 translation) override;
            virtual void setRotation(Vec3 rotation, Vec3 center) override;

        private:
            Vec3 _position;
            double _radius;
            Vec3 _direction;
            Vec3 _rotation;
    };
}

#endif /* !CONE_HPP_ */
