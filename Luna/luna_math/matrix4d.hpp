#ifndef MATRIX4D_H
#define MATRIX4D_H
#include "vector4d.hpp"

namespace luna
{
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

	private:
		float mContents[4][4];
	};

	inline Matrix4d::Matrix4d()
	{
		mContents[0][0] = 1; mContents[0][1] = 0; mContents[0][2] = 0; mContents[0][3] = 0;
		mContents[1][0] = 0; mContents[1][1] = 1; mContents[1][2] = 0; mContents[1][3] = 0;
		mContents[2][0] = 0; mContents[2][1] = 0; mContents[2][2] = 1; mContents[2][3] = 0;
		mContents[3][0] = 0; mContents[3][1] = 0; mContents[3][2] = 0; mContents[3][3] = 1;
	}

	inline Matrix4d::Matrix4d(float a00, float a01, float a02, float a03,
		float a10, float a11, float a12, float a13,
		float a20, float a21, float a22, float a23,
		float a30, float a31, float a32, float a33)
	{
		mContents[0][0] = a00; mContents[0][1] = a01; mContents[0][2] = a02; mContents[0][3] = a03;
		mContents[1][0] = a10; mContents[1][1] = a11; mContents[1][2] = a12; mContents[1][3] = a13;
		mContents[2][0] = a20; mContents[2][1] = a21; mContents[2][2] = a22; mContents[2][3] = a23;
		mContents[3][0] = a30; mContents[3][1] = a31; mContents[3][2] = a32; mContents[3][3] = a33;
	}

	inline bool Matrix4d::operator==(const Matrix4d& other) const
	{
		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++) {
				if (mContents[row][column] != other.mContents[row][column])
				{
					return false;
				}
			}
		}
		return true;
	}

	inline float Matrix4d::operator()(int row, int column) const
	{
		return mContents[row][column];
	}

	inline Matrix4d Matrix4d::Transpose() const
	{
		return Matrix4d{ mContents[0][0], mContents[1][0], mContents[2][0], mContents[3][0],
						 mContents[0][1], mContents[1][1], mContents[2][1], mContents[3][1],
						 mContents[0][2], mContents[1][2], mContents[2][2], mContents[3][2],
						 mContents[0][3], mContents[1][3], mContents[2][3], mContents[3][3] };
	}

	inline bool Matrix4d::IsDiagonal() const
	{
		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++) {
				if (row == column) // The diagonal
				{
					continue;
				}
				if (mContents[row][column] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	inline bool Matrix4d::IsIdentity() const
	{
		return mContents[0][0] == 1 && mContents[1][1] == 1 && mContents[2][2] == 1 && mContents[3][3] == 1;
	}

	inline Matrix4d Matrix4d::operator*(int scaler) const
	{
		return Matrix4d{ mContents[0][0] * scaler, mContents[0][1] * scaler, mContents[0][2] * scaler, mContents[0][3] * scaler,
						 mContents[1][0] * scaler, mContents[1][1] * scaler, mContents[1][2] * scaler, mContents[1][3] * scaler,
						 mContents[2][0] * scaler, mContents[2][1] * scaler, mContents[2][2] * scaler, mContents[2][3] * scaler,
						 mContents[3][0] * scaler, mContents[3][1] * scaler, mContents[3][2] * scaler, mContents[3][3] * scaler };
	}
	/*
	Matrix * Matrix

	  a00 a01 a02 a03       b00 b01 b02 b03     a00 * b00 + a01 * b10 + a02 * b20 + a03 * b30      a00 * b01 + a01 * b11 + a02 * b21 + a03 * b31      a00 * b02 + a01 * b12 + a02 * b22 + a03 * b32		a00 * b03 + a01 * b13 + a03 * b23 + a03 * b33	 =   m00, m01, m02, m03
	  a10 a11 a12 a13   *   b10 b11 b12 b13 =   a10 * b00 + a11 * b10 + a12 * b20 + a13 * b30      a10 * b01 + a11 * b11 + a12 * b21 + a13 * b31	  a10 * b02 + a11 * b12 + a12 * b22 + a13 * b32		a10 * b03 + a11 * b13 + a13 * b23 + a13 * b33		 m10, m11, m12, m12
	  a20 a21 a22 a23       b20 b21 b22 b23     a20 * b00 + a21 * b10 + a22 * b20 + a23 * b30      a20 * b01 + a21 * b11 + a22 * b21 + a23 * b31	  a20 * b02 + a21 * b12 + a22 * b22 + a23 * b32		a20 * b03 + a21 * b13 + a23 * b23 + a23 * b33		 m20, m21, m22, m23
	  a30 a31 a32 a33       b30 b31 b32 b33     a30 * b00 + a31 * b10 + a32 * b20 + a33 * b30	   a30 * b01 + a31 * b11 + a32 * b21 + a33 * b31	  a30 * b02 + a31 * b12 + a32 * b22 + a33 * b32		a30 * b03 + a31 * b13 + a33 * b23 + a33 * b33		 m30, m31, m32, m33
	*/
	inline Matrix4d Matrix4d::operator*(const Matrix4d& other) const
	{
		float m00 = (*this)(0, 0) * other(0, 0) + (*this)(0, 1) * other(1, 0) + (*this)(0, 2) * other(2, 0) + (*this)(0, 3) * other(3, 0);
		float m01 = (*this)(0, 0) * other(0, 1) + (*this)(0, 1) * other(1, 1) + (*this)(0, 2) * other(2, 1) + (*this)(0, 3) * other(3, 1);
		float m02 = (*this)(0, 0) * other(0, 2) + (*this)(0, 1) * other(1, 2) + (*this)(0, 2) * other(2, 2) + (*this)(0, 3) * other(3, 2);
		float m03 = (*this)(0, 0) * other(0, 3) + (*this)(0, 1) * other(1, 3) + (*this)(0, 2) * other(2, 3) + (*this)(0, 3) * other(3, 3);

		float m10 = (*this)(1, 0) * other(0, 0) + (*this)(1, 1) * other(1, 0) + (*this)(1, 2) * other(2, 0) + (*this)(1, 3) * other(3, 0);
		float m11 = (*this)(1, 0) * other(0, 1) + (*this)(1, 1) * other(1, 1) + (*this)(1, 2) * other(2, 1) + (*this)(1, 3) * other(3, 1);
		float m12 = (*this)(1, 0) * other(0, 2) + (*this)(1, 1) * other(1, 2) + (*this)(1, 2) * other(2, 2) + (*this)(1, 3) * other(3, 2);
		float m13 = (*this)(1, 0) * other(0, 3) + (*this)(1, 1) * other(1, 3) + (*this)(1, 2) * other(2, 3) + (*this)(1, 3) * other(3, 3);

		float m20 = (*this)(2, 0) * other(0, 0) + (*this)(2, 1) * other(1, 0) + (*this)(2, 2) * other(2, 0) + (*this)(2, 3) * other(3, 0);
		float m21 = (*this)(2, 0) * other(0, 1) + (*this)(2, 1) * other(1, 1) + (*this)(2, 2) * other(2, 1) + (*this)(2, 3) * other(3, 1);
		float m22 = (*this)(2, 0) * other(0, 2) + (*this)(2, 1) * other(1, 2) + (*this)(2, 2) * other(2, 2) + (*this)(2, 3) * other(3, 2);
		float m23 = (*this)(2, 0) * other(0, 3) + (*this)(2, 1) * other(1, 3) + (*this)(2, 2) * other(2, 3) + (*this)(2, 3) * other(3, 3);

		float m30 = (*this)(3, 0) * other(0, 0) + (*this)(3, 1) * other(1, 0) + (*this)(3, 2) * other(2, 0) + (*this)(3, 3) * other(3, 0);
		float m31 = (*this)(3, 0) * other(0, 1) + (*this)(3, 1) * other(1, 1) + (*this)(3, 2) * other(2, 1) + (*this)(3, 3) * other(3, 1);
		float m32 = (*this)(3, 0) * other(0, 2) + (*this)(3, 1) * other(1, 2) + (*this)(3, 2) * other(2, 2) + (*this)(3, 3) * other(3, 2);
		float m33 = (*this)(3, 0) * other(0, 3) + (*this)(3, 1) * other(1, 3) + (*this)(3, 2) * other(2, 3) + (*this)(3, 3) * other(3, 3);

		return Matrix4d{ m00, m01, m02, m03,
						 m10, m11, m12, m13,
						 m20, m21, m22, m23,
						 m30, m31, m32, m33 };
	}

	/*
	Vector * Matrix is each vector component times column component added.

			         m00 m01 m02 m03                       X                                          Y                                          Z								          W
	 [ x y z w ]  *  m10 m11 m12 m13  =  [(x * m00 + y * m10 + z * m20 + w * m30)   (x * m01 + y * m11 + z * m21 + w * m31)   (x * m02 + y * m12 + z * m22 + w * m32)   (x * m03 + y * m13 + z * m23 + w * m33)];
					 m20 m21 m22 m23
					 m30 m31 m32 m33
	*/
	inline Vector4d Matrix4d::operator*(const Vector4d& vector) const
	{
		float x = (*this)(0, 0) * vector.x() + (*this)(1, 0) * vector.y() + (*this)(2, 0) * vector.z() + (*this)(3, 0) * vector.w();
		float y = (*this)(0, 1) * vector.x() + (*this)(1, 1) * vector.y() + (*this)(2, 1) * vector.z() + (*this)(3, 1) * vector.w();
		float z = (*this)(0, 2) * vector.x() + (*this)(1, 2) * vector.y() + (*this)(2, 2) * vector.z() + (*this)(3, 2) * vector.w();
		float w = (*this)(0, 3) * vector.x() + (*this)(1, 3) * vector.y() + (*this)(2, 3) * vector.z() + (*this)(3, 3) * vector.w();
		return Vector4d{ x, y , z, w };
	}
}

#endif
