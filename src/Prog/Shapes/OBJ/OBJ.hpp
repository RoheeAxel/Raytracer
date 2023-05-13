/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** OBJ
*/

#ifndef OBJ_HPP_
#define OBJ_HPP_

#include "AShape.hpp"
#include "Triangle.hpp"
#include "Quad.hpp"

namespace Raytracer {
    class AABB;
    class OBJ : public AShape{
        public:
            OBJ();
            OBJ(const std::string &options);
            void load();
            ~OBJ() override = default;
            HitRecord intersection(Ray ray) override;
            AABB getAABB() override;
            void createAABB();

            std::pair<double, double> getUV(Vec3 point) override;
            void setPosition(const Vec3 &position);
            void setTranslation(Vec3 translation) override;
            void setRotation(Vec3 rotation, Vec3 center) override;
            void setScale(Vec3 scale) override;


        private:
            Vec3 _aabbBot;
            Vec3 _aabbTop;
            Vec3 _position;
            Vec3 _rotation;
            Vec3 _scale;
            std::string _path;
            std::vector<std::shared_ptr<IShape>> _faces;
};
}

#endif /* !OBJ_HPP_ */
