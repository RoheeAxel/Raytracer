/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** IShape
*/

#ifndef IShape_HPP_
#define IShape_HPP_

#include "Vec3.hpp"
#include "Ray.hpp"
#include "HitRecord.hpp"

namespace Raytracer {
class IShape {
    public:
        virtual ~IShape() = default;
        virtual HitRecord intersection(Ray ray) = 0;
        virtual void setMaterial(IMaterial *material) = 0;
        virtual IMaterial *getMaterial() = 0;
    protected:
    private:
};

}

#endif /* !IShape_HPP_ */
