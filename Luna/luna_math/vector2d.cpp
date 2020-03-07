#include "vector2d.hpp"

namespace luna 
{
	Vector2d::Vector2d(float x, float y) : mX{ x }, mY{ y }
	{
	}

	float Vector2d::x() const
	{
		return mX;
	}

	float Vector2d::y() const
	{
		return mY;
	}

	Vector2d Vector2d::operator *(float scalar) const
	{
		return Vector2d(mX * scalar, mY * scalar);
	}

	Vector2d Vector2d::operator /(float scalar) const
	{
		float reciprocal = 1.0F / scalar;
		return (*this) * reciprocal;
	}

	Vector2d Vector2d::operator -() const
	{
		return Vector2d(-mX, -mY);
	}

	Vector2d Vector2d::operator +(const Vector2d& other) const
	{
		return Vector2d(mX + other.mX, mY + other.mY);
	}

	Vector2d Vector2d::operator -(const Vector2d& other) const
	{
		return Vector2d(mX - other.mX, mY - other.mY);
	}

	Vector2d& Vector2d::operator *=(float scalar)
	{
		mX *= scalar;
		mY *= scalar;
		return *this;
	}

	Vector2d& Vector2d::operator +=(const Vector2d& other)
	{
		mX += other.mX;
		mY += other.mY;
		return *this;
	}

	Vector2d& Vector2d::operator -=(const Vector2d& other)
	{
		mX -= other.mX;
		mY -= other.mY;
		return *this;
	}

	bool Vector2d::operator ==(const Vector2d& other)
	{
		return mX == other.mX &&
			mY == other.mY;
	}

	float& Vector2d::operator [](int i)
	{
		return ((&mX)[i]);
	}

	const float& Vector2d::operator [](int i) const
	{
		return ((&mX)[i]);
	}

	float Vector2d::Magnitude() const
	{
		return std::sqrt(mX * mX + mY * mY);
	}

	Vector2d Vector2d::Normalize()
	{
		return (*this) / Magnitude();
	}

	float Vector2d::DotProduct(const Vector2d& other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	float Vector2d::DistanceTo(const Vector2d& other) const
	{
		return (other - *this).Magnitude();
	}

	Angle Vector2d::AngleBetween(const Vector2d& other) const
	{
		return Angle(std::acos(DotProduct(other) / (Magnitude() * other.Magnitude())));
	}

	bool Vector2d::IsPerpendicular(const Vector2d& other) const
	{
		return DotProduct(other) == 0;
	}

	bool Vector2d::IsParallel(const Vector2d& other) const
	{
		Angle angle = AngleBetween(other);
		return angle.Degrees() == 180 || angle.Degrees() == 0;
	}

	bool Vector2d::SameDirection(const Vector2d& other) const
	{
		return  DotProduct(other) > 0;
	}
}