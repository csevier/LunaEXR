#include "matrix2d.hpp"

namespace luna 
{
	Matrix2d::Matrix2d()
	{
		mContents[0][0] = 1; mContents[0][1] = 0;
		mContents[1][0] = 0; mContents[1][1] = 1;
	}

	Matrix2d::Matrix2d(float a00, float a01,
		float a10, float a11)
	{
		mContents[0][0] = a00; mContents[0][1] = a01;
		mContents[1][0] = a10; mContents[1][1] = a11;
	}

	Matrix2d::Matrix2d(float a00)
	{
		mContents[0][0] = a00; mContents[0][1] = 0;
		mContents[1][0] = 0;   mContents[1][1] = a00;
	}

	bool Matrix2d::operator==(const Matrix2d& other) const
	{
		for (int row = 0; row < 2; row++)
		{
			for (int column = 0; column < 2; column++) {
				if (mContents[row][column] != other.mContents[row][column])
				{
					return false;
				}
			}
		}
		return true;
	}

	float Matrix2d::operator()(int row, int column) const
	{
		return mContents[row][column];
	}

	Matrix2d Matrix2d::Transpose() const
	{
		return Matrix2d{ mContents[0][0], mContents[1][0],
						 mContents[0][1], mContents[1][1] };
	}

	bool Matrix2d::IsDiagonal() const
	{
		for (int row = 0; row < 2; row++)
		{
			for (int column = 0; column < 2; column++) {
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

	bool Matrix2d::IsIdentity() const
	{
		return mContents[0][0] == 1 && mContents[1][1] == 1;
	}

	Matrix2d Matrix2d::operator*(int scaler) const
	{
		return Matrix2d{ mContents[0][0] * scaler, mContents[0][1] * scaler,
						 mContents[1][0] * scaler, mContents[1][1] * scaler };
	}
	/*
	Matrix * Matrix

	  a00 a01  *  b00 b01   =  a00 * b00 + a01 * b10    a00 * b01 + a01 * b11    =  m00, m01
	  a10 a11     b10 b11      a10 * b00 + a11 * b10    a10 * b01 + a11 * b11       m10, m11
	*/
	Matrix2d Matrix2d::operator*(const Matrix2d& other) const
	{
		float m00 = (*this)(0, 0) * other(0, 0) + (*this)(0, 1) * other(1, 0); // a00 * b00 + a01 * b10
		float m01 = (*this)(0, 0) * other(0, 1) + (*this)(0, 1) * other(1, 1); // a00 * b01 + a01 * b11
		float m10 = (*this)(1, 0) * other(0, 0) + (*this)(1, 1) * other(1, 0); // a10 * b00 + a11 * b10
		float m11 = (*this)(1, 0) * other(0, 1) + (*this)(1, 1) * other(1, 1); // a10 * b01 + a11 * b11

		return Matrix2d{ m00, m01,
						 m10, m11 };
	}
	/*
	Vector * Matrix is each vector component times column component added.

				 m00 m01                X                       Y
	 [ x y ]  *  m10 m11   =  [(x * m00 + y * m10)   (x * m01 + y * m11)];
	*/
	Vector2d Matrix2d::operator*(const Vector2d& vector) const
	{
		float x = (*this)(0, 0) * vector.x() + (*this)(1, 0) * vector.y();
		float y = (*this)(0, 1) * vector.x() + (*this)(1, 1) * vector.y();
		return Vector2d{ x, y };
	}

	const Matrix2d Matrix2d::MakeRotate(Angle angle)
	{
		return Matrix2d{ cosf(angle.Radians()), sinf(angle.Radians()),
						 -sinf(angle.Radians()), cosf(angle.Radians()) };
	}

	const Matrix2d  Matrix2d::MakeShearX(float scalar)
	{
		return Matrix2d{ 1,      0,
						 scalar, 1 };
	}

	const Matrix2d Matrix2d::MakeShearY(float scalar)
	{
		return Matrix2d{ 1, scalar,
						 0, 1 };
	}
}