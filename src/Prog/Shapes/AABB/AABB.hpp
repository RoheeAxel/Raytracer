/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** AABB
*/

#ifndef AABB_HPP_
#define AABB_HPP_

#include "AShape.hpp"

namespace Raytracer {
class AABB : public AShape{
    public:
        AABB() = default;
        AABB(const Vec3 &bot, const Vec3 &top);

        ~AABB() override = default;

        HitRecord intersection(Ray ray) override;
        AABB getAABB() override;

        void setPosition(const Vec3 &position);
        void setBot(const Vec3 &bot);
        void setTop(const Vec3 &top);
        AABB surroundingBox(AABB box0, AABB box1);
        Vec3 getTop() {return _top;};
        Vec3 getBot() {return _bot;};

    private:
        std::shared_ptr<IMaterial> _material;
        Vec3 _position;
        Vec3 _bot;
        Vec3 _top;
};
}

#endif /* !AABB_HPP_ */
