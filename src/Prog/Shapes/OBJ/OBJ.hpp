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

            std::pair<double, double> getUV(Vec3 point) override;
            void setPosition(const Vec3 &position);
            void setTranslation(Vec3 translation) override;
            virtual void setRotation(Vec3 rotation, Vec3 center) override;


        private:
            Vec3 _position;
            Vec3 _rotation;
            std::string _path;
            std::vector<std::shared_ptr<IShape>> _faces;
};
}

#endif /* !OBJ_HPP_ */
