/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** HitRecord
*/

#ifndef HITRECORD_HPP_
#define HITRECORD_HPP_
#include "Vec3.hpp"
#include "IMaterial.hpp"

namespace Raytracer {
class HitRecord {
    public:
        HitRecord() = default;
        ~HitRecord() = default;
        bool hit;
        Raytracer::Vec3 point;
        Raytracer::Vec3 light;
        Raytracer::Vec3 normal;
        Raytracer::IMaterial *material;
        double distance;
        bool front_face;

        void set_face_normal(Ray& r) {
            front_face = r.getDirection().Dot(normal) < 0;
            normal = front_face ? normal : normal * -1;
        }

    protected:
    private:
};
}

#endif /* !HITRECORD_HPP_ */
