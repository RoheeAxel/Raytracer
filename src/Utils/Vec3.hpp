namespace Raytracer
{
    class Vec3
    {
    public:
        Vec3();
        Vec3(double x, double y, double z);
        Vec3(const Vec3& other);
        ~Vec3() = default;

        Vec3& operator=(const Vec3& other);
        Vec3& operator+(const Vec3& other);
        Vec3& operator-(const Vec3& other);
        Vec3& operator*(const Vec3& other);
        Vec3& operator/(const Vec3& other);
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
        Vec3& Normalize();
        Vec3 Normalized() const;
        double Dot(const Vec3& other) const;
        Vec3 Cross(const Vec3& other) const;

        double x;
        double y;
        double z;
    };
}