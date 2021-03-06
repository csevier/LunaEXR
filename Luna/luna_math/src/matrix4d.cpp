#include "matrix4d.hpp"

namespace luna 
{
	Matrix4d::Matrix4d()
	{
		mContents[0][0] = 1; mContents[0][1] = 0; mContents[0][2] = 0; mContents[0][3] = 0;
		mContents[1][0] = 0; mContents[1][1] = 1; mContents[1][2] = 0; mContents[1][3] = 0;
		mContents[2][0] = 0; mContents[2][1] = 0; mContents[2][2] = 1; mContents[2][3] = 0;
		mContents[3][0] = 0; mContents[3][1] = 0; mContents[3][2] = 0; mContents[3][3] = 1;
	}

    Matrix4d::Matrix4d(float r0c0, float r0c1, float r0c2, float r0c3,
                       float r1c0, float r1c1, float r1c2, float r1c3,
                       float r2c0, float r2c1, float r2c2, float r2c3,
                       float r3c0, float r3c1, float r3c2, float r3c3)
	{
        mContents[0][0] = r0c0; mContents[0][1] = r1c0; mContents[0][2] = r2c0; mContents[0][3] = r3c0;
        mContents[1][0] = r0c1; mContents[1][1] = r1c1; mContents[1][2] = r2c1; mContents[1][3] = r3c1;
        mContents[2][0] = r0c2; mContents[2][1] = r1c2; mContents[2][2] = r2c2; mContents[2][3] = r3c2;
        mContents[3][0] = r0c3; mContents[3][1] = r1c3; mContents[3][2] = r2c3; mContents[3][3] = r3c3;
	}

	bool Matrix4d::operator==(const Matrix4d& other) const
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

	float Matrix4d::operator()(int row, int column) const
	{
        return mContents[column][row];
	}

	Matrix4d Matrix4d::Transpose() const
	{
        float r0c0 = (*this)(0,0);
        float r1c0 = (*this)(1,0);
        float r2c0 = (*this)(2,0);
        float r3c0 = (*this)(3,0);
        float r0c1 = (*this)(0,1);
        float r1c1 = (*this)(1,1);
        float r2c1 = (*this)(2,1);
        float r3c1 = (*this)(3,1);
        float r0c2 = (*this)(0,2);
        float r1c2 = (*this)(1,2);
        float r2c2 = (*this)(2,2);
        float r3c2 = (*this)(3,2);
        float r0c3 = (*this)(0,3);
        float r1c3 = (*this)(1,3);
        float r2c3 = (*this)(2,3);
        float r3c3 = (*this)(3,3);

        return Matrix4d{ r0c0, r1c0, r2c0, r3c0,
                         r0c1, r1c1, r2c1, r3c1,
                         r0c2, r1c2, r2c2, r3c2,
                         r0c3, r1c3, r2c3, r3c3 };
	}

	bool Matrix4d::IsDiagonal() const
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

	bool Matrix4d::IsIdentity() const
	{
		return mContents[0][0] == 1 && mContents[1][1] == 1 && mContents[2][2] == 1 && mContents[3][3] == 1;
	}

	Matrix4d Matrix4d::operator*(int scaler) const
	{
        float r0c0 = (*this)(0,0) * scaler;
        float r1c0 = (*this)(1,0) * scaler;
        float r2c0 = (*this)(2,0) * scaler;
        float r3c0 = (*this)(3,0) * scaler;
        float r0c1 = (*this)(0,1) * scaler;
        float r1c1 = (*this)(1,1) * scaler;
        float r2c1 = (*this)(2,1) * scaler;
        float r3c1 = (*this)(3,1) * scaler;
        float r0c2 = (*this)(0,2) * scaler;
        float r1c2 = (*this)(1,2) * scaler;
        float r2c2 = (*this)(2,2) * scaler;
        float r3c2 = (*this)(3,2) * scaler;
        float r0c3 = (*this)(0,3) * scaler;
        float r1c3 = (*this)(1,3) * scaler;
        float r2c3 = (*this)(2,3) * scaler;
        float r3c3 = (*this)(3,3) * scaler;

        return Matrix4d{r0c0, r0c1, r0c2, r0c3,
                        r1c0, r1c1, r1c2, r1c3,
                        r2c0, r2c1, r2c2, r2c3,
                        r3c0, r3c1, r3c2, r3c3};
	}

	/*
	Matrix * Matrix

	  a00 a01 a02 a03       b00 b01 b02 b03     a00 * b00 + a01 * b10 + a02 * b20 + a03 * b30      a00 * b01 + a01 * b11 + a02 * b21 + a03 * b31      a00 * b02 + a01 * b12 + a02 * b22 + a03 * b32		a00 * b03 + a01 * b13 + a03 * b23 + a03 * b33	 =   m00, m01, m02, m03
	  a10 a11 a12 a13   *   b10 b11 b12 b13 =   a10 * b00 + a11 * b10 + a12 * b20 + a13 * b30      a10 * b01 + a11 * b11 + a12 * b21 + a13 * b31	  a10 * b02 + a11 * b12 + a12 * b22 + a13 * b32		a10 * b03 + a11 * b13 + a13 * b23 + a13 * b33		 m10, m11, m12, m12
	  a20 a21 a22 a23       b20 b21 b22 b23     a20 * b00 + a21 * b10 + a22 * b20 + a23 * b30      a20 * b01 + a21 * b11 + a22 * b21 + a23 * b31	  a20 * b02 + a21 * b12 + a22 * b22 + a23 * b32		a20 * b03 + a21 * b13 + a23 * b23 + a23 * b33		 m20, m21, m22, m23
	  a30 a31 a32 a33       b30 b31 b32 b33     a30 * b00 + a31 * b10 + a32 * b20 + a33 * b30	   a30 * b01 + a31 * b11 + a32 * b21 + a33 * b31	  a30 * b02 + a31 * b12 + a32 * b22 + a33 * b32		a30 * b03 + a31 * b13 + a33 * b23 + a33 * b33		 m30, m31, m32, m33
	*/
	Matrix4d Matrix4d::operator*(const Matrix4d& other) const
	{

        float r0c0 = (*this)(0, 0) * other(0, 0) + (*this)(0, 1) * other(1, 0) + (*this)(0, 2) * other(2, 0) + (*this)(0, 3) * other(3, 0);
        float r0c1 = (*this)(0, 0) * other(0, 1) + (*this)(0, 1) * other(1, 1) + (*this)(0, 2) * other(2, 1) + (*this)(0, 3) * other(3, 1);
        float r0c2 = (*this)(0, 0) * other(0, 2) + (*this)(0, 1) * other(1, 2) + (*this)(0, 2) * other(2, 2) + (*this)(0, 3) * other(3, 2);
        float r0c3 = (*this)(0, 0) * other(0, 3) + (*this)(0, 1) * other(1, 3) + (*this)(0, 2) * other(2, 3) + (*this)(0, 3) * other(3, 3);

        float r1c0 = (*this)(1, 0) * other(0, 0) + (*this)(1, 1) * other(1, 0) + (*this)(1, 2) * other(2, 0) + (*this)(1, 3) * other(3, 0);
        float r1c1 = (*this)(1, 0) * other(0, 1) + (*this)(1, 1) * other(1, 1) + (*this)(1, 2) * other(2, 1) + (*this)(1, 3) * other(3, 1);
        float r1c2 = (*this)(1, 0) * other(0, 2) + (*this)(1, 1) * other(1, 2) + (*this)(1, 2) * other(2, 2) + (*this)(1, 3) * other(3, 2);
        float r1c3 = (*this)(1, 0) * other(0, 3) + (*this)(1, 1) * other(1, 3) + (*this)(1, 2) * other(2, 3) + (*this)(1, 3) * other(3, 3);

        float r2c0 = (*this)(2, 0) * other(0, 0) + (*this)(2, 1) * other(1, 0) + (*this)(2, 2) * other(2, 0) + (*this)(2, 3) * other(3, 0);
        float r2c1 = (*this)(2, 0) * other(0, 1) + (*this)(2, 1) * other(1, 1) + (*this)(2, 2) * other(2, 1) + (*this)(2, 3) * other(3, 1);
        float r2c2 = (*this)(2, 0) * other(0, 2) + (*this)(2, 1) * other(1, 2) + (*this)(2, 2) * other(2, 2) + (*this)(2, 3) * other(3, 2);
        float r2c3 = (*this)(2, 0) * other(0, 3) + (*this)(2, 1) * other(1, 3) + (*this)(2, 2) * other(2, 3) + (*this)(2, 3) * other(3, 3);

        float r3c0 = (*this)(3, 0) * other(0, 0) + (*this)(3, 1) * other(1, 0) + (*this)(3, 2) * other(2, 0) + (*this)(3, 3) * other(3, 0);
        float r3c1 = (*this)(3, 0) * other(0, 1) + (*this)(3, 1) * other(1, 1) + (*this)(3, 2) * other(2, 1) + (*this)(3, 3) * other(3, 1);
        float r3c2 = (*this)(3, 0) * other(0, 2) + (*this)(3, 1) * other(1, 2) + (*this)(3, 2) * other(2, 2) + (*this)(3, 3) * other(3, 2);
        float r3c3 = (*this)(3, 0) * other(0, 3) + (*this)(3, 1) * other(1, 3) + (*this)(3, 2) * other(2, 3) + (*this)(3, 3) * other(3, 3);

        return Matrix4d{ r0c0, r0c1, r0c2, r0c3,
                         r1c0, r1c1, r1c2, r1c3,
                         r2c0, r2c1, r2c2, r2c3,
                         r3c0, r3c1, r3c2, r3c3 };
	}

	/*
	Vector * Matrix is each vector component times column component added.

					 m00 m01 m02 m03                       X                                          Y                                          Z								          W
	 [ x y z w ]  *  m10 m11 m12 m13  =  [(x * m00 + y * m10 + z * m20 + w * m30)   (x * m01 + y * m11 + z * m21 + w * m31)   (x * m02 + y * m12 + z * m22 + w * m32)   (x * m03 + y * m13 + z * m23 + w * m33)];
					 m20 m21 m22 m23
					 m30 m31 m32 m33
	*/
	Vector4d Matrix4d::operator*(const Vector4d& vector) const
	{
		float x = (*this)(0, 0) * vector.x() + (*this)(1, 0) * vector.y() + (*this)(2, 0) * vector.z() + (*this)(3, 0) * vector.w();
		float y = (*this)(0, 1) * vector.x() + (*this)(1, 1) * vector.y() + (*this)(2, 1) * vector.z() + (*this)(3, 1) * vector.w();
		float z = (*this)(0, 2) * vector.x() + (*this)(1, 2) * vector.y() + (*this)(2, 2) * vector.z() + (*this)(3, 2) * vector.w();
		float w = (*this)(0, 3) * vector.x() + (*this)(1, 3) * vector.y() + (*this)(2, 3) * vector.z() + (*this)(3, 3) * vector.w();
		return Vector4d{ x, y , z, w };
	}

	const float* Matrix4d::Data() const
	{
		return &mContents[0][0];
	}

	const Matrix4d Matrix4d::Translate(const Vector3d& translate)
	{
		return Matrix4d{ 1.0f, 0,  0, translate.x(),
						 0,  1.0f, 0, translate.y(),
						 0,  0, 1.0f, translate.z(),
						 0,  0,    0,          1.0f
		};
	}

	const Matrix4d Matrix4d::Scale(const Vector3d& scale)
	{
		return Matrix4d{ scale.x(), 0, 0, 0,
						 0, scale.y(), 0, 0,
						 0, 0, scale.z(), 0,
						 0, 0, 0, 1 };
	}

	const Matrix4d Matrix4d::RotateX(Angle angle)
	{
		return Matrix4d{ 1, 0, 0, 0,
						 0,  cosf(angle.Radians()), sinf(angle.Radians()), 0,
						 0, -sinf(angle.Radians()), cosf(angle.Radians()), 0,
						 0,  0, 0, 1 };
	}

	const Matrix4d Matrix4d::RotateY(Angle angle)
	{
		return Matrix4d{ cosf(angle.Radians()), 0, -sinf(angle.Radians()),     0,
						 0,                     1,      0,                     0,
						 sinf(angle.Radians()), 0,  cosf(angle.Radians()),     0,
						 0,						0,      0,                     1 };
	}

	const Matrix4d Matrix4d::RotateZ(Angle angle)
	{
		return Matrix4d{ cosf(angle.Radians()), -sinf(angle.Radians()), 0, 0,
						 sinf(angle.Radians()),  cosf(angle.Radians()), 0, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 1 };
	}
	const Matrix4d Matrix4d::Frustrum(float left,
		float right,
		float bottom,
		float top,
		float near,
		float far)
	{
		return Matrix4d{ ((2 * near) / (right - left)), 0, ((right + left) / (right - left)), 0,
						0, ((2 * near) / (top - bottom)), ((top + bottom) / (top - bottom)), 0,
						0, 0,((near + far) / (near - far)), ((2 * near * far) / (near - far)),
						0, 0,-1.0f, 0 };
	}

	const Matrix4d Matrix4d::Perspective(Angle fovy, float aspect, float near, float far)
	{
        float g = 1.0f / std::tan(0.5f * fovy.Degrees());
		float k = far / (far - near);
		float A = g / aspect;

        return Matrix4d{ A, 0, 0,    0,
                         0, g, 0,    0,
                         0, 0, k,    -near * k,
                         0, 0, 1.0f, 0 };
	}

	const Matrix4d Matrix4d::Ortho(float left, float right, float bottom, float top, float near, float far)
	{
		return Matrix4d{ (2.0f / (right - left)), 0, 0, 0,
						 0, (2.0f / (top - bottom)), 0, 0,
						 0, 0, (2.0f / (near - far)), 0.0f,
						 ((left + right) / (left - right)),((bottom + top) / (bottom - top)),((near + far) / (near - -far)), 1.0f };
	}

	const Matrix4d Matrix4d::LookAt(const Vector3d& eye, const Vector3d& center, const Vector3d& up)
	{
		const Vector3d forward = center - eye;
		const Vector3d f = forward.Normalize();
		const Vector3d s = f.CrossProduct(up).Normalize();
		const Vector3d u = s.CrossProduct(f);
		float eyeS = -s.DotProduct(eye);
		float eyeU = -u.DotProduct(eye);
		float eyeF = f.DotProduct(eye);
        const Matrix4d mat{ s.x(),   s.y(),     s.z(),  eyeS,
                            u.x(),   u.y(),     u.z(),  eyeU,
                            -f.x(),  -f.y(),   -f.z(),  eyeF,
                            0,        0,        0,       1  };
		return mat;

	}
}
