#include "vector3d.hpp"

namespace luna 
{
	Vector3d::Vector3d(float x, float y, float z) : mX{ x }, mY{ y }, mZ{ z }
	{
	}

    Vector3d::Vector3d(const Vector3d& other) : mX{ other.x() }, mY{ other.y()}, mZ{ other.z() }
    {
    }

	float Vector3d::x() const
	{
		return mX;
	}

	float Vector3d::y() const
	{
		return mY;
	}

	float Vector3d::z() const
	{
		return mZ;
	}

    float Vector3d::r() const
    {
        return mX;
    }

    float Vector3d::g() const
    {
        return mY;
    }

    float Vector3d::b() const
    {
        return mZ;
    }

	Vector3d Vector3d::operator *(float scalar) const
	{
		return Vector3d(mX * scalar, mY * scalar, mZ * scalar);
	}

	Vector3d Vector3d::operator /(float scalar) const
	{
		float reciprocal = 1.0F / scalar;
		return (*this) * reciprocal;
	}

	Vector3d Vector3d::operator -() const
	{
		return Vector3d(-mX, -mY, -mZ);
	}

	Vector3d Vector3d::operator +(const Vector3d& other) const
	{
		return Vector3d(mX + other.mX, mY + other.mY, mZ + other.mZ);
	}

	Vector3d Vector3d::operator -(const Vector3d& other) const
	{
		return Vector3d(mX - other.mX, mY - other.mY, mZ - other.mZ);
	}

	Vector3d& Vector3d::operator *=(float scalar)
	{
		mX *= scalar;
		mY *= scalar;
		mZ *= scalar;
		return *this;
	}

	Vector3d& Vector3d::operator +=(const Vector3d& other)
	{
		mX += other.mX;
		mY += other.mY;
		mZ += other.mZ;
		return *this;
	}

	Vector3d& Vector3d::operator -=(const Vector3d& other)
	{
		mX -= other.mX;
		mY -= other.mY;
		mZ -= other.mZ;
		return *this;
	}

	bool Vector3d::operator ==(const Vector3d& other)
	{
		return mX == other.mX &&
			mY == other.mY &&
			mZ == other.mZ;
	}

	float& Vector3d::operator [](int i)
	{
		return ((&mX)[i]);
	}

	const float& Vector3d::operator [](int i) const
	{
		return ((&mX)[i]);
	}

	float Vector3d::Magnitude() const
	{
		return std::sqrt(mX * mX + mY * mY + mZ * mZ);
	}

	Vector3d Vector3d::Normalize() const
	{
		return (*this) / Magnitude();
	}

	float Vector3d::DotProduct(const Vector3d& other) const
	{
		return mX * other.mX + mY * other.mY + mZ * other.mZ;
	}

	Vector3d Vector3d::CrossProduct(const Vector3d& other) const
	{
		return Vector3d(mY * other.mZ - mZ * other.mY,
			mZ * other.mX - mX * other.mZ,
			mX * other.mY - mY * other.mX);
	}

	float Vector3d::DistanceTo(const Vector3d& other) const
	{
		return (other - *this).Magnitude();
	}

	Angle Vector3d::AngleBetween(const Vector3d& other) const
	{
		return Angle(std::acos(DotProduct(other) / (Magnitude() * other.Magnitude())));
	}

	bool Vector3d::IsPerpendicular(const Vector3d& other) const
	{
		return DotProduct(other) == 0;
	}

	bool Vector3d::IsParallel(const Vector3d& other) const
	{
		return CrossProduct(other) == Vector3d(0, 0, 0);
	}

	bool Vector3d::SameDirection(const Vector3d& other) const
	{
		return DotProduct(other) > 0;
	}

    // binary operators
    std::istream& operator>>(std::istream& is, Vector3d& vec)
    {
        is >> vec[0] >> vec[1] >> vec[2];
        return is;
    }

    std::ostream& operator<<(std::ostream& os,  const Vector3d& vec)
    {
        os <<  vec.x() << vec.y() << vec.z();
        return os;
    }
}
