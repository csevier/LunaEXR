#ifndef MATRIX3D_H
#define MATRIX3D_H

#include "vector3d.hpp"
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

		bool operator==(const Matrix3d& other) const;
		Matrix3d operator*(int scaler) const;
		Matrix3d operator*(const Matrix3d& other) const;
		Vector3d operator*(const Vector3d& vector) const;
		float operator()(int row, int column) const;
		Matrix3d Transpose() const;
		bool IsDiagonal() const;
		bool IsIdentity() const;

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

	inline Matrix3d Matrix3d::operator*(const Matrix3d& other) const
	{
		return Matrix3d{ (*this)(0,0) * other(0,0) + (*this)(0,1) * other(1,0) + (*this)(0,2) * other(2,0),
						 (*this)(0,0) * other(0,1) + (*this)(0,1) * other(1,1) + (*this)(0,2) * other(2,1),
						 (*this)(0,0) * other(0,2) + (*this)(0,1) * other(1,2) + (*this)(0,2) * other(2,2),
						 (*this)(1,0) * other(0,0) + (*this)(1,1) * other(1,0) + (*this)(1,2) * other(2,0),
						 (*this)(1,0) * other(0,1) + (*this)(1,1) * other(1,1) + (*this)(1,2) * other(2,1),
						 (*this)(1,0) * other(0,2) + (*this)(1,1) * other(1,2) + (*this)(1,2) * other(2,2),
						 (*this)(2,0) * other(0,0) + (*this)(2,1) * other(1,0) + (*this)(2,2) * other(2,0),
						 (*this)(2,0) * other(0,1) + (*this)(2,1) * other(1,1) + (*this)(2,2) * other(2,1),
						 (*this)(2,0) * other(0,2) + (*this)(2,1) * other(1,2) + (*this)(2,2) * other(2,2) };
	}
	
	inline Vector3d Matrix3d::operator*(const Vector3d& vector) const
	{
		return Vector3d{ (*this)(0, 0) * vector.x() + (*this)(0, 1) * vector.y() + (*this)(0, 2) * vector.z(),
						 (*this)(1, 0) * vector.x() + (*this)(1, 1) * vector.y() + (*this)(1, 2) * vector.z(),
						 (*this)(2, 0) * vector.x() + (*this)(2, 1) * vector.y() + (*this)(2, 2) * vector.z()};
	}
}

#endif