#ifndef VECTOR3D_H
#define VECTOR3D_H

namespace luna
{
	namespace math
	{
		struct Vector3d
		{
			Vector3d() = default;
			Vector3d(float x, float y, float z);
			Vector3d operator *(float scalar) const;
			Vector3d operator /(float scalar) const;
			Vector3d operator +(const Vector3d& other) const;
			Vector3d operator -(const Vector3d& other) const;
			Vector3d operator -() const;
			Vector3d& operator *=(float s);
			Vector3d& operator +=(const Vector3d& other);
			Vector3d& operator -=(const Vector3d& other);
			float& operator [](int i);
			const float& operator [](int i) const;
			float Magnitude() const;
			Vector3d Normalize();
			float DotProduct(const Vector3d& other) const;
			Vector3d CrossProduct(const Vector3d& other) const;
			float DistanceTo(const Vector3d& other) const;

		
			float mX;
			float mY;
			float mZ;
		};
	}
}
#endif


