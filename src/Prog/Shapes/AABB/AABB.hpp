/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** AABB
*/

#ifndef AABB_HPP_
#define AABB_HPP_

#include "IShape.hpp"

namespace Raytracer {
class AABB : public IShape{
    public:
        AABB(Vec3 bot, Vec3 top);
        ~AABB();
        HitRecord intersection(Ray ray);
        void setMaterial(IMaterial *material);
        IMaterial *getMaterial();
        AABB getAABB();
        AABB surroundingBox(AABB box0, AABB box1);
        Vec3 getTop() {return _top;};
        Vec3 getBot() {return _bot;};
    protected:
    private:
        IMaterial *_material;
        Vec3 _position;
        Vec3 _bot;
        Vec3 _top;
};
}

#endif /* !AABB_HPP_ */
