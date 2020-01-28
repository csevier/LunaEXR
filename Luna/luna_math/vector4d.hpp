#ifndef VECTOR4D_H
#define VECTOR4D_H
#include "trig.hpp"
#include <cmath>

namespace luna
{
	namespace math
	{
		class Vector4d
		{
		public:
			Vector4d() = default;
			Vector4d(float x, float y, float z, float w);
			float x() const;
			float y() const;
			float z() const;
			float w() const;
			Vector4d operator *(float scalar) const;
			Vector4d operator /(float scalar) const;
			Vector4d operator +(const Vector4d& other) const;
			Vector4d operator -(const Vector4d& other) const;
			Vector4d operator -() const;
			Vector4d& operator *=(float s);
			Vector4d& operator +=(const Vector4d& other);
			Vector4d& operator -=(const Vector4d& other);
			bool operator ==(const Vector4d& other);
			float& operator [](int i);
			const float& operator [](int i) const;
			float Magnitude() const;
			Vector4d Normalize();
			float DotProduct(const Vector4d& other) const;
			float DistanceTo(const Vector4d& other) const;
			float AngleBetween(const Vector4d& other) const;
			bool SameDirection(const Vector4d& other) const;

		private:
			float mX;
			float mY;
			float mZ;
			float mW;
		};

		Vector4d::Vector4d(float x, float y, float z, float w) : mX{ x }, mY{ y }, mZ{ z }, mW{ w }
		{
		}

		inline float Vector4d::x() const 
		{
			return mX;
		}

		inline float Vector4d::y() const 
		{
			return mY;
		}

		inline float Vector4d::z() const 
		{
			return mZ;
		}

		inline float Vector4d::w() const 
		{
			return mW;
		}

		inline Vector4d Vector4d::operator *(float scalar) const
		{
			return Vector4d(mX * scalar, mY * scalar, mZ * scalar, mW * scalar);
		}

		inline Vector4d Vector4d::operator /(float scalar) const
		{
			float reciprocal = 1.0F / scalar;
			return (*this) * reciprocal;
		}

		inline Vector4d Vector4d::operator -() const
		{
			return Vector4d(-mX, -mY, -mZ, -mW);
		}

		inline Vector4d Vector4d::operator +(const Vector4d& other) const
		{
			return Vector4d(mX + other.mX, mY + other.mY, mZ + other.mZ, mW + other.mW);
		}

		inline Vector4d Vector4d::operator -(const Vector4d& other) const
		{
			return Vector4d(mX - other.mX, mY - other.mY, mZ - other.mZ, mW - other.mW);
		}

		inline Vector4d& Vector4d::operator *=(float scalar)
		{
			mX *= scalar;
			mY *= scalar;
			mZ *= scalar;
			mW *= scalar;
			return *this;
		}

		inline Vector4d& Vector4d::operator +=(const Vector4d& other)
		{
			mX += other.mX;
			mY += other.mY;
			mZ += other.mZ;
			mW += other.mW;
			return *this;
		}

		inline Vector4d& Vector4d::operator -=(const Vector4d& other)
		{
			mX -= other.mX;
			mY -= other.mY;
			mZ -= other.mZ;
			mW -= other.mW;
			return *this;
		}

		inline bool Vector4d::operator ==(const Vector4d& other)
		{
			return mX == other.mX &&
				mY == other.mY &&
				mZ == other.mZ &&
				mW == other.mW;
		}

		inline float& Vector4d::operator [](int i)
		{
			return ((&mX)[i]);
		}

		inline const float& Vector4d::operator [](int i) const
		{
			return ((&mX)[i]);
		}

		inline  float Vector4d::Magnitude() const
		{
			return std::sqrt(mX * mX + mY * mY + mZ * mZ + mW * mW);
		}

		inline Vector4d Vector4d::Normalize()
		{
			return (*this) / Magnitude();
		}

		inline float Vector4d::DotProduct(const Vector4d& other) const
		{
			return mX * other.mX + mY * other.mY + mZ * other.mZ + mW + other.mW;
		}

		inline float Vector4d::DistanceTo(const Vector4d& other) const
		{
			return (other - *this).Magnitude();
		}

		inline float Vector4d::AngleBetween(const Vector4d& other) const
		{
			return std::acos(DotProduct(other) / (Magnitude() * other.Magnitude()));
		}

		inline bool Vector4d::SameDirection(const Vector4d& other) const
		{
			return  DotProduct(other) > 0;
		}
	}
}
#endif


