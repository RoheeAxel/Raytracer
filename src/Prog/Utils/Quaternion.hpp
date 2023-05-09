/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Quaternion
*/

#ifndef QUATERNION_HPP_
#define QUATERNION_HPP_

#include <cmath>
#include "Vec3.hpp"

namespace Raytracer {
class Quaternion {
public:
    double w, x, y, z;

    Quaternion() : w(1), x(0), y(0), z(0) {}

    Quaternion(Vec3 euler)
    {
        Vec3 eulerInRadian = euler * M_PI / 180;
        double cy = cos(eulerInRadian.z/2);
        double sy = sin(eulerInRadian.z/2);
        double cp = cos(eulerInRadian.y/2);
        double sp = sin(eulerInRadian.y/2);
        double cr = cos(eulerInRadian.x/2);
        double sr = sin(eulerInRadian.x/2);

        w = cr*cp*cy + sr*sp*sy;
        x = sr*cp*cy - cr*sp*sy;
        y = cr*sp*cy + sr*cp*sy;
        z = cr*cp*sy - sr*sp*cy;
    }

    Quaternion(double nw, double nx, double ny, double nz) : w(nw), x(nx), y(ny), z(nz) {}

    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }

    void normalize() {
        double len = sqrt(w * w + x * x + y * y + z * z);
        if (len != 0) {
            w /= len;
            x /= len;
            y /= len;
            z /= len;
        }
    }

    Vec3 rotate(Vec3 point, Vec3 center)
    {
        point = point - center;
        Quaternion p(0, point.x, point.y, point.z);
        Quaternion rotate = *this * p * conjugate();
        Vec3 res = Vec3(rotate.x, rotate.y, rotate.z) + center;
        return res;
    }
};
}

#endif /* !QUATERNION_HPP_ */
