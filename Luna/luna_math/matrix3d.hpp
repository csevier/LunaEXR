#ifndef MATRIX3D_H
#define MATRIX3D_H

#include "vector3d.hpp"
#include <math.h>
namespace luna
{

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
		static const Matrix3d MakeRotateX(Angle angle);
		static const Matrix3d MakeRotateY(Angle angle);
		static const Matrix3d MakeRotateZ(Angle angle);
		static const Matrix3d MakeShearXY(float s, float t);
		static const Matrix3d MakeShearXZ(float s, float t);
		static const Matrix3d MakeShearYZ(float s, float t);

	private:
		float mContents[3][3];
	};

	inline Matrix3d::Matrix3d()
	{
		mContents[0][0] = 1; mContents[0][1] = 0; mContents[0][2] = 0;
		mContents[1][0] = 0; mContents[1][1] = 1; mContents[1][2] = 0;
		mContents[2][0] = 0; mContents[2][1] = 0; mContents[2][2] = 1;
	}

	inline Matrix3d::Matrix3d(float a00, float a01, float a02,
		float a10, float a11, float a12,
		float a20, float a21, float a22)
	{
		mContents[0][0] = a00; mContents[0][1] = a01; mContents[0][2] = a02;
		mContents[1][0] = a10; mContents[1][1] = a11; mContents[1][2] = a12;
		mContents[2][0] = a20; mContents[2][1] = a21; mContents[2][2] = a22;
	}

	inline Matrix3d::Matrix3d(float a00)
	{
		mContents[0][0] = a00; mContents[0][1] = 0;   mContents[0][2] = 0;
		mContents[1][0] = 0;   mContents[1][1] = a00; mContents[1][2] = 0;
		mContents[2][0] = 0;   mContents[2][1] = 0;   mContents[2][2] = a00;
	}

	inline bool Matrix3d::operator==(const Matrix3d& other) const
	{
		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++) {
				if (mContents[row][column] != other.mContents[row][column])
				{
					return false;
				}
			}
		}
		return true;
	}

	inline float Matrix3d::operator()(int row, int column) const
	{
		return mContents[row][column];
	}

	inline Matrix3d Matrix3d::Transpose() const
	{
		return Matrix3d{ mContents[0][0], mContents[1][0], mContents[2][0],
						 mContents[0][1], mContents[1][1], mContents[2][1],
						 mContents[0][2], mContents[1][2], mContents[2][2] };
	}

	inline bool Matrix3d::IsDiagonal() const
	{
		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++) {
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

	inline bool Matrix3d::IsIdentity() const
	{
		return mContents[0][0] == 1 && mContents[1][1] == 1 && mContents[2][2] == 1;
	}

	inline Matrix3d Matrix3d::operator*(int scaler) const
	{
		return Matrix3d{ mContents[0][0] * scaler, mContents[0][1] * scaler, mContents[0][2] * scaler,
						 mContents[1][0] * scaler, mContents[1][1] * scaler, mContents[1][2] * scaler,
						 mContents[2][0] * scaler, mContents[2][1] * scaler, mContents[2][2] * scaler };
	}
	/*
	Matrix * Matrix 

	  a00 a01 a02      b00 b01 b02     a00 * b00 + a01 * b10 + a02 * b20       a00 * b01 + a01 * b11 + a02 * b21      a00 * b02 + a01 * b12 + a02 * b22      =  m00, m01, m02,
	  a10 a11 a12  *   b10 b11 b12  =  a10 * b00 + a11 * b10 + a12 * b20       a10 * b01 + a11 * b11 + a12 * b21      a10 * b02 + a11 * b12 + a12 * b22			m10, m11, m12,
	  a20 a21 a22      b20 b21 b22     a20 * b00 + a21 * b10 + a22 * b20       a20 * b01 + a21 * b11 + a22 * b21      a20 * b02 + a21 * b12 + a22 * b22			m20, m21, m22
	*/
	inline Matrix3d Matrix3d::operator*(const Matrix3d& other) const
	{
		float m00 = (*this)(0,0) * other(0,0) + (*this)(0,1) * other(1,0) + (*this)(0,2) * other(2,0);
		float m01 = (*this)(0,0) * other(0,1) + (*this)(0,1) * other(1,1) + (*this)(0,2) * other(2,1);
		float m02 = (*this)(0,0) * other(0,2) + (*this)(0,1) * other(1,2) + (*this)(0,2) * other(2,2);
		float m10 = (*this)(1,0) * other(0,0) + (*this)(1,1) * other(1,0) + (*this)(1,2) * other(2,0);
		float m11 = (*this)(1,0) * other(0,1) + (*this)(1,1) * other(1,1) + (*this)(1,2) * other(2,1);
		float m12 = (*this)(1,0) * other(0,2) + (*this)(1,1) * other(1,2) + (*this)(1,2) * other(2,2);
		float m20 = (*this)(2,0) * other(0,0) + (*this)(2,1) * other(1,0) + (*this)(2,2) * other(2,0);
		float m21 = (*this)(2,0) * other(0,1) + (*this)(2,1) * other(1,1) + (*this)(2,2) * other(2,1);
		float m22 = (*this)(2,0) * other(0,2) + (*this)(2,1) * other(1,2) + (*this)(2,2) * other(2,2);

		return Matrix3d{ m00, m01, m02,
						 m10, m11, m12,
						 m20, m21, m22 };
	}

	/*
	Vector * Matrix is each vector component times column component added.

				   m00 m01 m02                 X                                Y                                  Z
	 [ x y z ]  *  m10 m11 m12  =  [(x * m00 + y * m10 + z * m20)   (x * m01 + y * m11 + z * m21)   (x * m02 + y * m12 + z * m22)];
				   m20 m21 m22
	*/
	inline Vector3d Matrix3d::operator*(const Vector3d& vector) const
	{
		float x = (*this)(0, 0) * vector.x() + (*this)(1, 0) * vector.y() + (*this)(2, 0) * vector.z();
		float y = (*this)(0, 1) * vector.x() + (*this)(1, 1) * vector.y() + (*this)(2, 1) * vector.z();
		float z = (*this)(0, 2) * vector.x() + (*this)(1, 2) * vector.y() + (*this)(2, 2) * vector.z();
		return Vector3d{ x, y , z };
	}

	const Matrix3d Matrix3d::MakeRotateX(Angle angle)
	{
		return Matrix3d{ 1, 0, 0,
						 0,  cosf(angle.Radians()), sinf(angle.Radians()),
						 0, -sinf(angle.Radians()), cosf(angle.Radians())};
	}

	const Matrix3d Matrix3d::MakeRotateY(Angle angle)
	{
		return Matrix3d{ cosf(angle.Radians()), 0, -sinf(angle.Radians()),
						 0,                     1,  0,
						 sinf(angle.Radians()), 0, cosf(angle.Radians()) };
	}

	const Matrix3d Matrix3d::MakeRotateZ(Angle angle)
	{
		return Matrix3d{ cosf(angle.Radians()),  sinf(angle.Radians()),  0,
						 -sinf(angle.Radians()), cosf(angle.Radians()) , 0,
						  0, 1, 1};
	}

	const Matrix3d Matrix3d::MakeShearXY(float s, float t)
	{
		return Matrix3d{ 1, 0, 0,
						 0, 1, 0,
						 s, t, 1 };
	}

	const Matrix3d Matrix3d::MakeShearXZ(float s, float t)
	{
		return Matrix3d{ 1, 0, 0,
						 s, 1, t,
						 0, 0, 1 };
	}

	const Matrix3d Matrix3d::MakeShearYZ(float s, float t) 
	{
		return Matrix3d{ 1, s, t,
						 0, 1, 0,
						 0, 0, 1 };
	}
}

#endif