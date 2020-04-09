#ifndef Vector3d_H
#define Vector3d_H
#include "angle.hpp"
#include <cmath>
#include <iostream>

namespace luna
{
	class Vector3d
	{
	public:
		Vector3d() = default;
		Vector3d(float x, float y, float z);
        Vector3d(const Vector3d& other);

        // coordinate
		float x() const;
		float y() const;
		float z() const;

        // color
        float r() const;
        float g() const;
        float b() const;

        // operators
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

        // methods
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

    std::istream& operator>>(std::istream& is, Vector3d& vec);
    std::ostream& operator<<(std::ostream& os, const Vector3d& vec);
}
#endif


