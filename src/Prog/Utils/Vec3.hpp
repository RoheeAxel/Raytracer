/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Vec3
*/

#ifndef VEC3_HPP_
#define VEC3_HPP_

namespace Raytracer
{
    class Vec3
    {
    public:
        Vec3();
        Vec3(double scalar);
        Vec3(double x, double y, double z);
        Vec3(const Vec3& other);
        ~Vec3() = default;

        Vec3& operator=(const Vec3& other);
        Vec3 operator+(const Vec3& other) const;
        Vec3 operator-(const Vec3& other) const;
        Vec3 operator*(const Vec3& other) const;
        Vec3 operator/(const Vec3& other) const;
        Vec3 operator*(double scalar) const;
        Vec3 operator/(double scalar) const;
        Vec3& operator+=(const Vec3& other);
        Vec3& operator-=(const Vec3& other);
        Vec3& operator*=(const Vec3& other);
        Vec3& operator/=(const Vec3& other);
        Vec3& operator*=(double scalar);
        Vec3& operator/=(double scalar);
        bool operator==(const Vec3& other) const;
        bool operator!=(const Vec3& other) const;

        double Length() const;
        Vec3 &abs();
        Vec3& Normalize();
        Vec3 Normalized() const;
        double Dot(const Vec3& other) const;
        Vec3 Cross(const Vec3& other) const;
        Vec3 Max(const Vec3& other) const;
        Vec3 Clamp(const double min, const double max) const;
        Vec3 random();

        double operator[](int i) const;
        double& operator[](int i);

        double x;
        double y;
        double z;
    };
}

#endif /* !VEC3_HPP_ */