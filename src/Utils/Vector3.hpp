namespace Raytracer
{
    class Vector3
    {
    public:
        Vector3();
        Vector3(double x, double y, double z);
        Vector3(const Vector3& other);
        ~Vector3() = default;

        Vector3& operator=(const Vector3& other);
        Vector3 operator+(const Vector3& other);
        Vector3 operator-(const Vector3& other);
        Vector3 operator*(const Vector3& other);
        Vector3 operator/(const Vector3& other);
        Vector3 operator*(double scalar) const;
        Vector3 operator/(double scalar) const;
        Vector3& operator+=(const Vector3& other);
        Vector3& operator-=(const Vector3& other);
        Vector3& operator*=(const Vector3& other);
        Vector3& operator/=(const Vector3& other);
        Vector3& operator*=(double scalar);
        Vector3& operator/=(double scalar);
        bool operator==(const Vector3& other) const;
        bool operator!=(const Vector3& other) const;

        double Length() const;
        Vector3& Normalize();
        Vector3 Normalized() const;
        double Dot(const Vector3& other) const;
        Vector3 Cross(const Vector3& other) const;

        double x;
        double y;
        double z;
    };
}