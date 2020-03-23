#ifndef MATRIX2D_H
#define MATRIX2D_H

#include "vector2d.hpp"
namespace luna
{
	// Row Major Layout.
	/* Layout
		  Column 0  Column 1 
    row 0 [0][0]    [1][0]
    row 1 [0][1]    [1][1]

	*/
	class Matrix2d
	{
	public:
		Matrix2d();
        Matrix2d(float r0c0, float r0c1,
                 float r1c0, float r1c1);
		// Makes diagonal
        Matrix2d(float diagonal);

		bool operator==(const Matrix2d& other) const;
		Matrix2d operator*(int scaler) const;
		Matrix2d operator*(const Matrix2d& other) const;
		Vector2d operator*(const Vector2d& vector) const;
		float operator()(int row, int column) const;
		Matrix2d Transpose() const;
		bool IsDiagonal() const;
		bool IsIdentity() const;
		static const Matrix2d MakeRotate(Angle angle);
		static const Matrix2d MakeShearX(float scaler);
		static const Matrix2d MakeShearY(float scaler);

	private:
		float mContents[2][2];
	};
}

#endif
