/*
** EPITECH PROJECT, 2023
** final
** File description:
** AShape.hpp
*/

#ifndef ASHAPE_HPP_
#define ASHAPE_HPP_

#include "IShape.hpp"

namespace Raytracer {
    class AShape : public IShape {
        public:
            AShape() = default;
            ~AShape() override = default;

            virtual HitRecord intersection(Ray ray) = 0;
            void setMaterial(std::shared_ptr<IMaterial> material) override;
            std::shared_ptr<IMaterial> getMaterial() override;
            virtual AABB getAABB() = 0;
            virtual std::pair<double, double> getUV(Vec3 point) = 0;
        protected:
            std::shared_ptr<IMaterial> _material;
    };
}

#endif //ASHAPE_HPP_
