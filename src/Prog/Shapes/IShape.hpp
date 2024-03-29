/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** IShape
*/

#ifndef IShape_HPP_
#define IShape_HPP_

#include <memory>
#include "Vec3.hpp"
#include "HitRecord.hpp"
#include "Quaternion.hpp"
#include "IMaterial.hpp"

namespace Raytracer {
class Ray;
class AABB;
class IShape {
    public:
        virtual ~IShape() = default;
        virtual HitRecord intersection(Ray ray) = 0;
        virtual void setMaterial(std::shared_ptr<IMaterial> material) = 0;
        virtual std::shared_ptr<IMaterial> getMaterial() = 0;
        virtual AABB getAABB() = 0;
        virtual std::pair<double, double> getUV(Vec3 point) = 0;
        virtual void setTranslation(Vec3 translation) = 0;
        virtual void setRotation(Vec3 rotation, Vec3 center) = 0;
        virtual void setScale(Vec3 scale) = 0;
    protected:
    private:
};

}

#endif /* !IShape_HPP_ */
