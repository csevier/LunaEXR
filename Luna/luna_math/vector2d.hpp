#ifndef Vector2d_H
#define Vector2d_H
#include "angle.hpp"
#include <cmath>

namespace luna
{
	class Vector2d
	{
	public:
		Vector2d() = default;
		Vector2d(float x, float y);
		float x() const;
		float y() const;
		Vector2d operator *(float scalar) const;
		Vector2d operator /(float scalar) const;
		Vector2d operator +(const Vector2d& other) const;
		Vector2d operator -(const Vector2d& other) const;
		Vector2d operator -() const;
		Vector2d& operator *=(float s);
		Vector2d& operator +=(const Vector2d& other);
		Vector2d& operator -=(const Vector2d& other);
		bool operator ==(const Vector2d& other);
		float& operator [](int i);
		const float& operator [](int i) const;
		float Magnitude() const;
		Vector2d Normalize();
		float DotProduct(const Vector2d& other) const;
		float DistanceTo(const Vector2d& other) const;
		Angle AngleBetween(const Vector2d& other) const;
		bool IsPerpendicular(const Vector2d& other) const;
		bool IsParallel(const Vector2d& other) const;
		bool SameDirection(const Vector2d& other) const;

	private:
		float mX;
		float mY;
	};

	inline Vector2d::Vector2d(float x, float y) : mX{ x }, mY{ y }
	{
	}

	inline float Vector2d::x() const
	{
		return mX;
	}

	inline float Vector2d::y() const
	{
		return mY;
	}

	inline Vector2d Vector2d::operator *(float scalar) const
	{
		return Vector2d(mX * scalar, mY * scalar);
	}

	inline Vector2d Vector2d::operator /(float scalar) const
	{
		float reciprocal = 1.0F / scalar;
		return (*this) * reciprocal;
	}

	inline Vector2d Vector2d::operator -() const
	{
		return Vector2d(-mX, -mY);
	}

	inline Vector2d Vector2d::operator +(const Vector2d& other) const
	{
		return Vector2d(mX + other.mX, mY + other.mY);
	}

	inline Vector2d Vector2d::operator -(const Vector2d& other) const
	{
		return Vector2d(mX - other.mX, mY - other.mY);
	}

	inline Vector2d& Vector2d::operator *=(float scalar)
	{
		mX *= scalar;
		mY *= scalar;
		return *this;
	}

	inline Vector2d& Vector2d::operator +=(const Vector2d& other)
	{
		mX += other.mX;
		mY += other.mY;
		return *this;
	}

	inline Vector2d& Vector2d::operator -=(const Vector2d& other)
	{
		mX -= other.mX;
		mY -= other.mY;
		return *this;
	}

	inline bool Vector2d::operator ==(const Vector2d& other)
	{
		return mX == other.mX &&
			mY == other.mY;
	}

	inline float& Vector2d::operator [](int i)
	{
		return ((&mX)[i]);
	}

	inline const float& Vector2d::operator [](int i) const
	{
		return ((&mX)[i]);
	}

	inline float Vector2d::Magnitude() const
	{
		return std::sqrt(mX * mX + mY * mY);
	}

	inline Vector2d Vector2d::Normalize()
	{
		return (*this) / Magnitude();
	}

	inline float Vector2d::DotProduct(const Vector2d& other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	inline float Vector2d::DistanceTo(const Vector2d& other) const
	{
		return (other - *this).Magnitude();
	}

	inline Angle Vector2d::AngleBetween(const Vector2d& other) const
	{
		return Angle(std::acos(DotProduct(other) / (Magnitude() * other.Magnitude())));
	}

	inline bool Vector2d::IsPerpendicular(const Vector2d& other) const
	{
		return DotProduct(other) == 0;
	}

	inline bool Vector2d::IsParallel(const Vector2d& other) const
	{
		Angle angle =  AngleBetween(other);
		return angle.Degrees() == 180 || angle.Degrees() == 0;
	}

	inline bool Vector2d::SameDirection(const Vector2d& other) const
	{
		return  DotProduct(other) > 0;
	}
}
#endif


