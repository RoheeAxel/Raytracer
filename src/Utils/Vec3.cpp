/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Vec3
*/

#include "Vec3.hpp"
#include <cmath>

namespace Raytracer
{
    Vec3::Vec3() : x(0), y(0), z(0)
    {
    }

    Vec3::Vec3(double scalar) : x(scalar), y(scalar), z(scalar)
    {
    }

    Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z)
    {
    }

    Vec3::Vec3(const Vec3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    Vec3& Vec3::operator=(const Raytracer::Vec3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vec3 Vec3::operator+(const Vec3 &other)
    {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 Vec3::operator-(const Vec3 &other)
    {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 Vec3::operator*(const Vec3 &other)
    {
        return Vec3(x * other.x, y * other.y, z * other.z);
    }

    Vec3 Vec3::operator/(const Vec3 &other)
    {
        return Vec3(x / other.x, y / other.y, z / other.z);
    }

    Vec3 Vec3::operator*(double scalar) const
    {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 Vec3::operator/(double scalar) const
    {
        return Vec3(x / scalar, y / scalar, z / scalar);
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
        return Vec3(x / length, y / length, z / length);
    }

    double Vec3::Dot(const Vec3 &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    Vec3 Vec3::Cross(const Vec3 &other) const
    {
        return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
}