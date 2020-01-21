#include "pch.h"
#include "vector3d.hpp"
#include <cmath>

namespace luna
{
	namespace math
	{
		Vector3d::Vector3d(float x, float y, float z): mX{x}, mY{y}, mZ{z}
		{
		}

		Vector3d Vector3d::operator *(float scalar) const
		{
			return Vector3d(mX * scalar, mY * scalar, mZ * scalar);
		}

		Vector3d Vector3d::operator /(float scalar) const
		{
			scalar = 1.0F / scalar;
			return (*this) * scalar;
		}

		Vector3d Vector3d::operator -() const
		{
			return Vector3d(-mX , -mY, -mZ);
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

		Vector3d Vector3d::Normalize()
		{
			return (*this) / this->Magnitude();
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
	}
}

