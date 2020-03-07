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
}
#endif


