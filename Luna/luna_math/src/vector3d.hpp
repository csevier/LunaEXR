#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "angle.hpp"
#include <cmath>

namespace luna
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
		Vector3d Normalize() const;
		float DotProduct(const Vector3d& other) const;
		Vector3d CrossProduct(const Vector3d& other) const;
		float DistanceTo(const Vector3d& other) const;
		Angle AngleBetween(const Vector3d& other) const;
		bool IsPerpendicular(const Vector3d& other) const;
		bool IsParallel(const Vector3d& other) const;
		bool SameDirection(const Vector3d& other) const;

	private:
		float mX;
		float mY;
		float mZ;
	};
}
#endif


