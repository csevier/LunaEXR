#include "matrix3d.hpp"

namespace luna 
{
	Matrix3d::Matrix3d()
	{
		mContents[0][0] = 1; mContents[0][1] = 0; mContents[0][2] = 0;
		mContents[1][0] = 0; mContents[1][1] = 1; mContents[1][2] = 0;
		mContents[2][0] = 0; mContents[2][1] = 0; mContents[2][2] = 1;
	}

    Matrix3d::Matrix3d(float r0c0, float r0c1, float r0c2,
                       float r1c0, float r1c1, float r1c2,
                       float r2c0, float r2c1, float r2c2)
	{
        mContents[0][0] = r0c0; mContents[0][1] = r1c0; mContents[0][2] = r2c0;
        mContents[1][0] = r0c1; mContents[1][1] = r1c1; mContents[1][2] = r2c1;
        mContents[2][0] = r0c2; mContents[2][1] = r1c2; mContents[2][2] = r2c2;
	}

    Matrix3d::Matrix3d(float diagonal)
	{
        mContents[0][0] = diagonal; mContents[0][1] = 0;        mContents[0][2] = 0;
        mContents[1][0] = 0;        mContents[1][1] = diagonal; mContents[1][2] = 0;
        mContents[2][0] = 0;        mContents[2][1] = 0;        mContents[2][2] = diagonal;
	}

	bool Matrix3d::operator==(const Matrix3d& other) const
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

	float Matrix3d::operator()(int row, int column) const
	{
        return mContents[column][row];
	}

	Matrix3d Matrix3d::Transpose() const
	{
        float r0c0 = (*this)(0,0);
        float r1c0 = (*this)(1,0);
        float r2c0 = (*this)(2,0);
        float r0c1 = (*this)(0,1);
        float r1c1 = (*this)(1,1);
        float r2c1 = (*this)(2,1);
        float r0c2 = (*this)(0,2);
        float r1c2 = (*this)(1,2);
        float r2c2 = (*this)(2,2);

        return Matrix3d{ r0c0, r1c0, r2c0,
                         r0c1, r1c1, r2c1,
                         r0c2, r1c2, r2c2};
	}

	bool Matrix3d::IsDiagonal() const
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

	bool Matrix3d::IsIdentity() const
	{
		return mContents[0][0] == 1 && mContents[1][1] == 1 && mContents[2][2] == 1;
	}

	Matrix3d Matrix3d::operator*(int scaler) const
	{
        float r0c0 = (*this)(0,0) * scaler;
        float r1c0 = (*this)(1,0) * scaler;
        float r2c0 = (*this)(2,0) * scaler;
        float r0c1 = (*this)(0,1) * scaler;
        float r1c1 = (*this)(1,1) * scaler;
        float r2c1 = (*this)(2,1) * scaler;
        float r0c2 = (*this)(0,2) * scaler;
        float r1c2 = (*this)(1,2) * scaler;
        float r2c2 = (*this)(2,2) * scaler;

        return Matrix3d{ r0c0, r0c1, r0c2,
                         r1c0, r1c1, r1c2,
                         r2c0, r2c1, r2c2 };
	}
	/*
	Matrix * Matrix

	  a00 a01 a02      b00 b01 b02     a00 * b00 + a01 * b10 + a02 * b20       a00 * b01 + a01 * b11 + a02 * b21      a00 * b02 + a01 * b12 + a02 * b22      =  m00, m01, m02,
	  a10 a11 a12  *   b10 b11 b12  =  a10 * b00 + a11 * b10 + a12 * b20       a10 * b01 + a11 * b11 + a12 * b21      a10 * b02 + a11 * b12 + a12 * b22			m10, m11, m12,
	  a20 a21 a22      b20 b21 b22     a20 * b00 + a21 * b10 + a22 * b20       a20 * b01 + a21 * b11 + a22 * b21      a20 * b02 + a21 * b12 + a22 * b22			m20, m21, m22
	*/
	Matrix3d Matrix3d::operator*(const Matrix3d& other) const
	{
        float r0c0 = (*this)(0, 0) * other(0, 0) + (*this)(0, 1) * other(1, 0) + (*this)(0, 2) * other(2, 0);
        float r0c1 = (*this)(0, 0) * other(0, 1) + (*this)(0, 1) * other(1, 1) + (*this)(0, 2) * other(2, 1);
        float r0c2 = (*this)(0, 0) * other(0, 2) + (*this)(0, 1) * other(1, 2) + (*this)(0, 2) * other(2, 2);
        float r1c0 = (*this)(1, 0) * other(0, 0) + (*this)(1, 1) * other(1, 0) + (*this)(1, 2) * other(2, 0);
        float r1c1 = (*this)(1, 0) * other(0, 1) + (*this)(1, 1) * other(1, 1) + (*this)(1, 2) * other(2, 1);
        float r1c2 = (*this)(1, 0) * other(0, 2) + (*this)(1, 1) * other(1, 2) + (*this)(1, 2) * other(2, 2);
        float r2c0 = (*this)(2, 0) * other(0, 0) + (*this)(2, 1) * other(1, 0) + (*this)(2, 2) * other(2, 0);
        float r2c1 = (*this)(2, 0) * other(0, 1) + (*this)(2, 1) * other(1, 1) + (*this)(2, 2) * other(2, 1);
        float r2c2 = (*this)(2, 0) * other(0, 2) + (*this)(2, 1) * other(1, 2) + (*this)(2, 2) * other(2, 2);

        return Matrix3d{ r0c0, r0c1, r0c2,
                         r1c0, r1c1, r1c2,
                         r2c0, r2c1, r2c2 };
	}

	/*
	Vector * Matrix is each vector component times column component added.

				   m00 m01 m02                 X                                Y                                  Z
	 [ x y z ]  *  m10 m11 m12  =  [(x * m00 + y * m10 + z * m20)   (x * m01 + y * m11 + z * m21)   (x * m02 + y * m12 + z * m22)];
				   m20 m21 m22
	*/
	Vector3d Matrix3d::operator*(const Vector3d& vector) const
	{
		float x = (*this)(0, 0) * vector.x() + (*this)(1, 0) * vector.y() + (*this)(2, 0) * vector.z();
		float y = (*this)(0, 1) * vector.x() + (*this)(1, 1) * vector.y() + (*this)(2, 1) * vector.z();
		float z = (*this)(0, 2) * vector.x() + (*this)(1, 2) * vector.y() + (*this)(2, 2) * vector.z();
		return Vector3d{ x, y , z };
	}

	const Matrix3d Matrix3d::Scale(const Vector3d& scale)
	{
		return Matrix3d{ scale.x(), 0, 0,
						 0, scale.y(), 0,
						 0, 0, scale.z() };
	}

	const Matrix3d Matrix3d::RotateX(Angle angle)
	{
		return Matrix3d{ 1, 0, 0,
						 0,  cosf(angle.Radians()), sinf(angle.Radians()),
						 0, -sinf(angle.Radians()), cosf(angle.Radians()) };
	}

	const Matrix3d Matrix3d::RotateY(Angle angle)
	{
		return Matrix3d{ cosf(angle.Radians()), 0, -sinf(angle.Radians()),
						 0,                     1,  0,
						 sinf(angle.Radians()), 0, cosf(angle.Radians()) };
	}

	const Matrix3d Matrix3d::RotateZ(Angle angle)
	{
		return Matrix3d{ cosf(angle.Radians()),  sinf(angle.Radians()),  0,
						 -sinf(angle.Radians()), cosf(angle.Radians()) , 0,
						  0, 1, 1 };
	}

	const Matrix3d Matrix3d::ShearXY(float s, float t)
	{
		return Matrix3d{ 1, 0, 0,
						 0, 1, 0,
						 s, t, 1 };
	}

	const Matrix3d Matrix3d::ShearXZ(float s, float t)
	{
		return Matrix3d{ 1, 0, 0,
						 s, 1, t,
						 0, 0, 1 };
	}

	const Matrix3d Matrix3d::ShearYZ(float s, float t)
	{
		return Matrix3d{ 1, s, t,
						 0, 1, 0,
						 0, 0, 1 };
	}
}
