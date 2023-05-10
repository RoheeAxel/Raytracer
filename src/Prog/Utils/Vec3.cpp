/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Vec3
*/

#include "Vec3.hpp"
#include <cmath>
#include <sstream>
#include <istream>
#include <iostream>
#include <algorithm>

namespace Raytracer
{
    Vec3::Vec3() : x(0), y(0), z(0) {}

    Vec3::Vec3(double scalar) : x(scalar), y(scalar), z(scalar) {}

    Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    Vec3::Vec3(const Vec3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    Vec3::Vec3(const std::string &str) {
        std::vector<std::string> vec;
        std::string tmp = str;
        tmp.erase(std::remove(tmp.begin(), tmp.end(), '{'), tmp.end());
        tmp.erase(std::remove(tmp.begin(), tmp.end(), '}'), tmp.end());
        std::stringstream ss(tmp);
        std::string item;
        while (std::getline(ss, item, ',')) {
            vec.push_back(item);
        }
        if (vec.size() != 3)
            throw Exception("Vec3: invalid string");
        x = std::stod(vec[0]);
        y = std::stod(vec[1]);
        z = std::stod(vec[2]);
    }

    Vec3& Vec3::operator=(const Raytracer::Vec3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vec3 Vec3::operator+(const Vec3 &other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vec3 Vec3::operator-(const Vec3 &other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vec3 Vec3::operator*(const Vec3 &other) const
    {
        return {x * other.x, y * other.y, z * other.z};
    }

    Vec3 Vec3::operator/(const Vec3 &other) const
    {
        return {x / other.x, y / other.y, z / other.z};
    }

    Vec3 Vec3::operator*(double scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    Vec3 Vec3::operator/(double scalar) const
    {
        return {x / scalar, y / scalar, z / scalar};
    }

    Vec3& Vec3::operator+=(const Vec3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3& Vec3::operator-=(const Vec3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }   

    Vec3& Vec3::operator*=(const Vec3 &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    Vec3& Vec3::operator/=(const Vec3 &other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    Vec3& Vec3::operator*=(double scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vec3& Vec3::operator/=(double scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    bool Vec3::operator==(const Vec3 &other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Vec3::operator!=(const Vec3 &other) const
    {
        return x != other.x || y != other.y || z != other.z;
    }

    double Vec3::Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vec3 &Vec3::abs()
    {
        x = std::abs(x);
        y = std::abs(y);
        z = std::abs(z);
        return *this;
    }

    Vec3& Vec3::Normalize()
    {
        double length = Length();
        x /= length;
        y /= length;
        z /= length;
        return *this;
    }

    Vec3 Vec3::Normalized() const
    {
        double length = Length();
        return {x / length, y / length, z / length};
    }

    double Vec3::Dot(const Vec3 &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    Vec3 Vec3::Cross(const Vec3 &other) const
    {
        return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
    }
    Vec3 Vec3::Max(const Vec3 &other) const
    {
        return {std::max(x, other.x), std::max(y, other.y), std::max(z, other.z)};
    }

    Vec3 Vec3::Clamp(const double min, const double max) const
    {
        return {std::clamp(x, min, max), std::clamp(y, min, max), std::clamp(z, min, max)};
    }

    Vec3 Vec3::random() {
        CustomRandom random;
        while (true) {
            Vec3 p = (Vec3(random.drand48(), random.drand48(), random.drand48()) * 2) - Vec3(1, 1, 1);
            if (p.Length() >= 1) continue;
            return p;
        }
    }

    double Vec3::operator[](int i) const
    {
        if (i == 0)
            return x;
        if (i == 1)
            return y;
        return z;
    }
    double &Vec3::operator[](int i)
    {
        if (i == 0)
            return x;
        if (i == 1)
            return y;
        return z;
    }

}