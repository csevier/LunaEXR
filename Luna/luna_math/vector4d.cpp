#include "pch.h"
#include "vector4d.hpp"
#include "trig.hpp"
#include <cmath>

namespace luna
{
	namespace math
	{
		Vector4d::Vector4d(float x, float y, float z, float w) : mX{ x }, mY{ y }, mZ{ z }, mW {w}
		{
		}

		Vector4d Vector4d::operator *(float scalar) const
		{
			return Vector4d(mX * scalar, mY * scalar, mZ * scalar, mW * scalar);
		}

		Vector4d Vector4d::operator /(float scalar) const
		{
			float reciprocal = 1.0F / scalar;
			return (*this) * reciprocal;
		}

		Vector4d Vector4d::operator -() const
		{
			return Vector4d(-mX, -mY, -mZ, -mW);
		}

		Vector4d Vector4d::operator +(const Vector4d& other) const
		{
			return Vector4d(mX + other.mX, mY + other.mY, mZ + other.mZ, mW + other.mW);
		}

		Vector4d Vector4d::operator -(const Vector4d& other) const
		{
			return Vector4d(mX - other.mX, mY - other.mY, mZ - other.mZ, mW - other.mW);
		}

		Vector4d& Vector4d::operator *=(float scalar)
		{
			mX *= scalar;
			mY *= scalar;
			mZ *= scalar;
			mW *= scalar;
			return *this;
		}

		Vector4d& Vector4d::operator +=(const Vector4d& other)
		{
			mX += other.mX;
			mY += other.mY;
			mZ += other.mZ;
			mW += other.mW;
			return *this;
		}

		Vector4d& Vector4d::operator -=(const Vector4d& other)
		{
			mX -= other.mX;
			mY -= other.mY;
			mZ -= other.mZ;
			mW -= other.mW;
			return *this;
		}

		bool Vector4d::operator ==(const Vector4d& other)
		{
			return mX == other.mX &&
				mY == other.mY &&
				mZ == other.mZ &&
				mW == other.mW;
		}

		float& Vector4d::operator [](int i)
		{
			return ((&mX)[i]);
		}

		const float& Vector4d::operator [](int i) const
		{
			return ((&mX)[i]);
		}

		float Vector4d::Magnitude() const
		{
			return std::sqrt(mX * mX + mY * mY + mZ * mZ + mW * mW);
		}

		Vector4d Vector4d::Normalize()
		{
			return (*this) / Magnitude();
		}

		float Vector4d::DotProduct(const Vector4d& other) const
		{
			return mX * other.mX + mY * other.mY + mZ * other.mZ + mW + other.mW;
		}

		float Vector4d::DistanceTo(const Vector4d& other) const
		{
			return (other - *this).Magnitude();
		}

		float Vector4d::AngleBetween(const Vector4d& other) const
		{
			return std::acos(DotProduct(other) / (Magnitude() * other.Magnitude()));
		}

		bool Vector4d::SameDirection(const Vector4d& other) const
		{
			return DotProduct(other) >= 90;
		}
	}
}

