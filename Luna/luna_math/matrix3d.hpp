#ifndef MATRIX3D_H
#define MATRIX3D_H

#include "vector3d.hpp"
#include <math.h>
namespace luna
{
	// Row Major Layout.
	/* Layout
		  Column 0 Column 1 Column 2
	row 0 [0][0]    [0][1]   [0][2]
	row 1 [1][0]    [1][1]   [1][2]
	row 2 [2][0]    [2][1]   [2][2]
	*/
	class Matrix3d
	{
	public:
		Matrix3d();
		Matrix3d(float a00, float a01, float a02,
			float a10, float a11, float a12,
			float a20, float a21, float a22);
		// Makes diagonal
		Matrix3d(float a00);
		bool operator==(const Matrix3d& other) const;
		Matrix3d operator*(int scaler) const;
		Matrix3d operator*(const Matrix3d& other) const;
		Vector3d operator*(const Vector3d& vector) const;
		float operator()(int row, int column) const;
		Matrix3d Transpose() const;
		bool IsDiagonal() const;
		bool IsIdentity() const;
		static const Matrix3d Scale(const Vector3d& scale);
		static const Matrix3d RotateX(Angle angle);
		static const Matrix3d RotateY(Angle angle);
		static const Matrix3d RotateZ(Angle angle);
		static const Matrix3d ShearXY(float s, float t);
		static const Matrix3d ShearXZ(float s, float t);
		static const Matrix3d ShearYZ(float s, float t);

	private:
		float mContents[3][3];
	};
}

#endif