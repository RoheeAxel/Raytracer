/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** BVH
*/

#ifndef BVH_HPP_
#define BVH_HPP_

#include "AShape.hpp"
#include "AABB.hpp"

namespace Raytracer {
class AABB;
class BVH : public AShape{
    public:
        BVH() = default;

        ~BVH() override = default;

        HitRecord intersection(Ray ray) override;
        AABB getAABB() override;
        void setTranslation(Vec3 translation) override;
    private:
        std::shared_ptr<IMaterial> _material;
        std::shared_ptr<AShape> _left;
        std::shared_ptr<AShape> _right;
        AABB _box;
};
}

#endif /* !BVH_HPP_ */
