/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Vector3
*/

#include "Vector3.hpp"
#include <cmath>

namespace Raytracer
{
    Vector3::Vector3() : x(0), y(0), z(0)
    {
    }

    Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z)
    {
    }

    Vector3& Vector3::operator=(const Raytracer::Vector3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3 Vector3::operator+(const Vector3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3 Vector3::operator-(const Vector3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3 Vector3::operator*(const Vector3 &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    Vector3 Vector3::operator/(const Vector3 &other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    Vector3 Vector3::operator*(double scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 Vector3::operator/(double scalar) const
    {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    Vector3& Vector3::operator+=(const Vector3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3& Vector3::operator-=(const Vector3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }   

    Vector3& Vector3::operator*=(const Vector3 &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    Vector3& Vector3::operator/=(const Vector3 &other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    Vector3& Vector3::operator*=(double scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3& Vector3::operator/=(double scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    bool Vector3::operator==(const Vector3 &other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Vector3::operator!=(const Vector3 &other) const
    {
        return x != other.x || y != other.y || z != other.z;
    }

    double Vector3::Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vector3& Vector3::Normalize()
    {
        double length = Length();
        x /= length;
        y /= length;
        z /= length;
        return *this;
    }

    Vector3 Vector3::Normalized() const
    {
        double length = Length();
        return Vector3(x / length, y / length, z / length);
    }

    double Vector3::Dot(const Vector3 &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3 Vector3::Cross(const Vector3 &other) const
    {
        return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
}