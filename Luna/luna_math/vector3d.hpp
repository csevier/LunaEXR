#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "pch.h"
#include "vector3d.hpp"
#include <cmath>

namespace luna
{
	namespace math
	{
		class Vector3d
		{
		public:
			Vector3d() = default;
			Vector3d(float x, float y, float z);
			float x() const;
			float y() const;
			float z() const;
			Vector3d operator *(float scalar) const;
			Vector3d operator /(float scalar) const;
			Vector3d operator +(const Vector3d& other) const;
			Vector3d operator -(const Vector3d& other) const;
			Vector3d operator -() const;
			Vector3d& operator *=(float s);
			Vector3d& operator +=(const Vector3d& other);
			Vector3d& operator -=(const Vector3d& other);
			bool operator ==(const Vector3d& other);
			float& operator [](int i);
			const float& operator [](int i) const;
			float Magnitude() const;
			Vector3d Normalize();
			float DotProduct(const Vector3d& other) const;
			Vector3d CrossProduct(const Vector3d& other) const;
			float DistanceTo(const Vector3d& other) const;
			float AngleBetween(const Vector3d& other) const;
			bool IsPerpendicular(const Vector3d& other) const;
			bool IsParallel(const Vector3d& other) const;
			bool SameDirection(const Vector3d& other) const;

		private:
			float mX;
			float mY;
			float mZ;
		};

		inline Vector3d::Vector3d(float x, float y, float z) : mX{ x }, mY{ y }, mZ{ z }
		{
		}

		inline float Vector3d::x() const
		{
			return mX;
		}

		inline float Vector3d::y() const
		{
			return mY;
		}

		inline float Vector3d::z() const
		{
			return mZ;
		}

		inline Vector3d Vector3d::operator *(float scalar) const
		{
			return Vector3d(mX * scalar, mY * scalar, mZ * scalar);
		}

		inline Vector3d Vector3d::operator /(float scalar) const
		{
			float reciprocal = 1.0F / scalar;
			return (*this) * reciprocal;
		}

		inline Vector3d Vector3d::operator -() const
		{
			return Vector3d(-mX, -mY, -mZ);
		}

		inline Vector3d Vector3d::operator +(const Vector3d& other) const
		{
			return Vector3d(mX + other.mX, mY + other.mY, mZ + other.mZ);
		}

		inline Vector3d Vector3d::operator -(const Vector3d& other) const
		{
			return Vector3d(mX - other.mX, mY - other.mY, mZ - other.mZ);
		}

		inline Vector3d& Vector3d::operator *=(float scalar)
		{
			mX *= scalar;
			mY *= scalar;
			mZ *= scalar;
			return *this;
		}

		inline Vector3d& Vector3d::operator +=(const Vector3d& other)
		{
			mX += other.mX;
			mY += other.mY;
			mZ += other.mZ;
			return *this;
		}

		inline Vector3d& Vector3d::operator -=(const Vector3d& other)
		{
			mX -= other.mX;
			mY -= other.mY;
			mZ -= other.mZ;
			return *this;
		}

		inline bool Vector3d::operator ==(const Vector3d& other)
		{
			return mX == other.mX &&
				mY == other.mY &&
				mZ == other.mZ;
		}

		inline float& Vector3d::operator [](int i)
		{
			return ((&mX)[i]);
		}

		inline const float& Vector3d::operator [](int i) const
		{
			return ((&mX)[i]);
		}

		inline float Vector3d::Magnitude() const
		{
			return std::sqrt(mX * mX + mY * mY + mZ * mZ);
		}

		inline Vector3d Vector3d::Normalize()
		{
			return (*this) / Magnitude();
		}

		inline float Vector3d::DotProduct(const Vector3d& other) const
		{
			return mX * other.mX + mY * other.mY + mZ * other.mZ;
		}

		inline Vector3d Vector3d::CrossProduct(const Vector3d& other) const
		{
			return Vector3d(mY * other.mZ - mZ * other.mY,
				mZ * other.mX - mX * other.mZ,
				mX * other.mY - mY * other.mX);
		}

		inline float Vector3d::DistanceTo(const Vector3d& other) const
		{
			return (other - *this).Magnitude();
		}

		inline float Vector3d::AngleBetween(const Vector3d& other) const
		{
			return std::acos(DotProduct(other) / (Magnitude() * other.Magnitude()));
		}

		inline bool Vector3d::IsPerpendicular(const Vector3d& other) const
		{
			return DotProduct(other) == 0;
		}

		inline bool Vector3d::IsParallel(const Vector3d& other) const
		{
			return CrossProduct(other) == Vector3d(0, 0, 0);
		}

		inline bool Vector3d::SameDirection(const Vector3d& other) const
		{
			return DotProduct(other) > 0;
		}
	}
}
#endif


