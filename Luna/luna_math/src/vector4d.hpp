#ifndef VECTOR4D_H
#define VECTOR4D_H
#include "angle.hpp"
#include <cmath>

namespace luna
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
		Angle AngleBetween(const Vector4d& other) const;
		bool SameDirection(const Vector4d& other) const;

	private:
		float mX;
		float mY;
		float mZ;
		float mW;
	};
}
#endif


