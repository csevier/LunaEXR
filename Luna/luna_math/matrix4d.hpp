#ifndef MATRIX4D_H
#define MATRIX4D_H
#include "vector4d.hpp"
#include "vector3d.hpp"

namespace luna
{
	// Row Major Layout.
	/* Layout
		  Column 0 Column 1 Column 2
	row 0 [0][0]    [0][1]   [0][2]  [0][3]
	row 1 [1][0]    [1][1]   [1][2]  [1][3]
	row 2 [2][0]    [2][1]   [2][2]  [2][3]
	row 3 [3][0]    [3][1]   [3][2]  [3][3]
	*/
	class Matrix4d
	{
	public:
		Matrix4d();
		Matrix4d(float a00, float a01, float a02, float a03, 
			float a10, float a11, float a12, float a13,
			float a20, float a21, float a22, float a23,
			float a30, float a31, float a32, float a33);

		bool operator==(const Matrix4d& other) const;
		Matrix4d operator*(int scaler) const;
		Matrix4d operator*(const Matrix4d& other) const;
		Vector4d operator*(const Vector4d& vector) const;
		float operator()(int row, int column) const;
		Matrix4d Transpose() const;
		bool IsDiagonal() const;
		bool IsIdentity() const;
		// for passing to opengl
		const float* Data() const;
		static const Matrix4d Translate(const Vector3d& translate);
		static const Matrix4d Scale(const Vector3d& scale);
		static const Matrix4d RotateX(Angle angle);
		static const Matrix4d RotateY(Angle angle);
		static const Matrix4d RotateZ(Angle angle);
		static const Matrix4d Frustrum(float left,float right, float bottom, float top, float near, float far);
		static const Matrix4d Perspective(Angle fovy, float aspect, float near, float far);
		static const Matrix4d Ortho(float left, float right, float bottom, float top, float near, float far);
		static const Matrix4d LookAt(const Vector3d& eye, const Vector3d& center, const Vector3d& up);

	private:
		float mContents[4][4];
	};
}

#endif
