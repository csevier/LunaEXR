#include "pch.h"
#include "../luna_math/matrix3d.hpp"
#include "../luna_math/vector3d.hpp"
#include <iostream> 

TEST(TestMatrix3d, Ctor)
{
	luna::Matrix3d mat3{ 1,2,3,4,5,6,7,8,9 };
	EXPECT_EQ(mat3(0,0), 1);
	EXPECT_EQ(mat3(1,1), 5);
	EXPECT_EQ(mat3(2,2), 9);
}

TEST(TestMatrix3d, MakesDiag)
{
	luna::Matrix3d mat3{ 1 };
	EXPECT_TRUE(mat3.IsIdentity());
	EXPECT_TRUE(mat3.IsDiagonal());
	EXPECT_EQ(mat3(0, 0), 1);
	EXPECT_EQ(mat3(1, 1), 1);
	EXPECT_EQ(mat3(2, 2), 1);
}

TEST(TestMatrix3d, MatrixEquality)
{
	luna::Matrix3d mat3{ 1,2,3,4,5,6,7,8,9 };
	luna::Matrix3d mat4{ 1,2,3,4,5,6,7,8,9 };
	EXPECT_EQ(mat3, mat4);
}

TEST(TestMatrix3d, DefaultCtorIdentity)
{
	luna::Matrix3d mat3{ };
	EXPECT_EQ(mat3(0, 0), 1);
	EXPECT_EQ(mat3(0, 1), 0);
	EXPECT_EQ(mat3(0, 2), 0);
	EXPECT_EQ(mat3(1, 0), 0);
	EXPECT_EQ(mat3(1, 1), 1);
	EXPECT_EQ(mat3(1, 2), 0);
	EXPECT_EQ(mat3(2, 0), 0);
	EXPECT_EQ(mat3(2, 1), 0);
	EXPECT_EQ(mat3(2, 2), 1);
	EXPECT_TRUE(mat3.IsIdentity());
}

TEST(TestMatrix3d, Transpose)
{
    luna::Matrix3d mat3{ 1,2,3,
						4,5,6,
						7,8,9 };
    luna::Matrix3d ident{ };
	luna::Matrix3d mat3T = mat3.Transpose();
	luna::Matrix3d orig = mat3T.Transpose();
	EXPECT_EQ(mat3T(0, 0), 1);
	EXPECT_EQ(mat3T(0, 1), 4);
	EXPECT_EQ(mat3T(0, 2), 7);
	EXPECT_EQ(mat3T(1, 0), 2);
	EXPECT_EQ(mat3T(1, 1), 5);
	EXPECT_EQ(mat3T(1, 2), 8);
	EXPECT_EQ(mat3T(2, 0), 3);
	EXPECT_EQ(mat3T(2, 1), 6);
	EXPECT_EQ(mat3T(2, 2), 9);
	EXPECT_EQ(mat3, orig);
	EXPECT_EQ(ident, ident.Transpose());
}

TEST(TestMatrix3d, Diagonal)
{
	luna::Matrix3d mat3{ 1,2,3,4,5,6,7,8,9 };
	luna::Matrix3d ident{ };
	luna::Matrix3d diag{ 2,0,0,
					     0,9,0,
						 0,0,12 };
	EXPECT_TRUE(ident.IsDiagonal());
	EXPECT_TRUE(diag.IsDiagonal());
	EXPECT_FALSE(mat3.IsDiagonal());
}

TEST(TestMatrix3d, ScaleMatrix)
{
	luna::Matrix3d mat3{ 1,2,3,4,5,6,7,8,9 }; 
	luna::Matrix3d scaled = mat3 * 2;
	EXPECT_EQ(scaled(0, 0), 2);
	EXPECT_EQ(scaled(0, 1), 4);
	EXPECT_EQ(scaled(0, 2), 6);
	EXPECT_EQ(scaled(1, 0), 8);
	EXPECT_EQ(scaled(1, 1), 10);
	EXPECT_EQ(scaled(1, 2), 12);
	EXPECT_EQ(scaled(2, 0), 14);
	EXPECT_EQ(scaled(2, 1), 16);
	EXPECT_EQ(scaled(2, 2), 18);
}

TEST(TestMatrix3d, MatrixByMatrix)
{
	luna::Matrix3d a{ 1,2,3,4,5,6,7,8,9 };
	luna::Matrix3d b{ 1,2,3,4,5,6,7,8,9 };
	luna::Matrix3d scaled = a * b;
	EXPECT_EQ(scaled(0, 0),30);
	EXPECT_EQ(scaled(0, 1), 36);
	EXPECT_EQ(scaled(0, 2), 42);
	EXPECT_EQ(scaled(1, 0), 66);
	EXPECT_EQ(scaled(1, 1), 81);
	EXPECT_EQ(scaled(1, 2), 96);
	EXPECT_EQ(scaled(2, 0), 102);
	EXPECT_EQ(scaled(2, 1), 126);
	EXPECT_EQ(scaled(2, 2), 150);
}

TEST(TestMatrix3d, MatrixByMatrixAnother)
{
	luna::Matrix3d a{ 1,-5,3,0,-2,6,7,2,-4 };
	luna::Matrix3d b{ -8,6,1,7,0,-3,2,4,5 };
	luna::Matrix3d scaled = a * b;
	EXPECT_EQ(scaled(0, 0), -37);
	EXPECT_EQ(scaled(0, 1), 18);
	EXPECT_EQ(scaled(0, 2), 31);
	EXPECT_EQ(scaled(1, 0), -2);
	EXPECT_EQ(scaled(1, 1), 24);
	EXPECT_EQ(scaled(1, 2), 36);
	EXPECT_EQ(scaled(2, 0), -50);
	EXPECT_EQ(scaled(2, 1), 26);
	EXPECT_EQ(scaled(2, 2), -19);
}

TEST(TestMatrix3d, MatrixByVector)
{
	luna::Matrix3d a{ 18.5, 27.3, 14.7,
	                  21.8, 13.9, 16.5,
	                  17.7, 15.1, 31.2};
	luna::Vector3d b{ 12.1, 6.4, 7.9 };
	luna::Vector3d vec = a * b;
	EXPECT_EQ(vec.x(), 503.200012f);
	EXPECT_EQ(vec.y(), 538.579956f);
	EXPECT_EQ(vec.z(), 529.950012f);

}
TEST(TestMatrix3d, MatrixByVectorAnother)
{
	luna::Matrix3d a{ 2,-5, 1,
					  0, 3, 4,
					 -7, 1, 8 };

	luna::Vector3d b{ 3, -1, 2 };
	luna::Vector3d vec = a * b;
	EXPECT_EQ(vec.x(), -8.0f);
	EXPECT_EQ(vec.y(), -16.0f);
	EXPECT_EQ(vec.z(), 15.0f);

}
TEST(TestMatrix3d,  MatrixByBasisVector)
{
	luna::Matrix3d a{ 1,2,3,
		              4,5,6,
		              7,8,9};
	luna::Vector3d x{ 1, 0, 0};
	luna::Vector3d y{ 0, 1, 0};
	luna::Vector3d z{ 0, 0, 1};

	luna::Vector3d vec = a * x;
	EXPECT_EQ(vec.x(), 1.0f);
	EXPECT_EQ(vec.y(), 2.0f);
	EXPECT_EQ(vec.z(), 3.0f);

	luna::Vector3d vec1 = a * y;
	EXPECT_EQ(vec1.x(), 4.0f);
	EXPECT_EQ(vec1.y(), 5.0f);
	EXPECT_EQ(vec1.z(), 6.0f);

	luna::Vector3d vec2 = a * z;
	EXPECT_EQ(vec2.x(), 7.0f);
	EXPECT_EQ(vec2.y(), 8.0f);
	EXPECT_EQ(vec2.z(), 9.0f);

}

TEST(TestMatrix3d, Rotate3dX)
{
	luna::Matrix3d rotateDeg = luna::Matrix3d::MakeRotateX(luna::AngleFromDegrees(90));
	luna::Vector3d x{ 0, 0, 1 };
	luna::Vector3d xprime = rotateDeg * x;

	EXPECT_EQ(xprime.x(), x.x());
	EXPECT_EQ(xprime.y(), -1); 
	EXPECT_EQ(std::ceil(xprime.z()), 0); 
	printf("%.5f\n", xprime.z());

}

TEST(TestMatrix3d, Rotate3dXAnother)
{
	luna::Matrix3d rotateDeg = luna::Matrix3d::MakeRotateX(luna::AngleFromDegrees(360));
	luna::Vector3d x{ 0, 0, 1 };
	luna::Vector3d xprime = rotateDeg * x;
	EXPECT_EQ(xprime.x(), x.x());
	EXPECT_EQ(std::ceil(xprime.y()), 0);
	printf("%.5f\n", xprime.y());
	EXPECT_EQ(xprime.z(), 1);
}

TEST(TestMatrix3d, Rotate3dY)
{
	luna::Matrix3d rotateDeg = luna::Matrix3d::MakeRotateY(luna::AngleFromDegrees(90));
	luna::Vector3d x{ 0, 0, 1 };
	luna::Vector3d xprime = rotateDeg * x;

	EXPECT_EQ(xprime.x(), 1);
	EXPECT_EQ(xprime.y(), 0);
	EXPECT_EQ(std::ceil(xprime.z()), 0);
	printf("%.5f\n", xprime.z());

}

TEST(TestMatrix3d, Rotate3dYAnother)
{
	luna::Matrix3d rotateDeg = luna::Matrix3d::MakeRotateY(luna::AngleFromDegrees(360));
	luna::Vector3d x{ 0, 0, 1  };
	luna::Vector3d xprime = rotateDeg * x;
	EXPECT_EQ(std::floor(xprime.x()), 0);
	printf("%.5f\n", xprime.x());
	EXPECT_EQ(xprime.y(), 0);
	EXPECT_EQ(xprime.z(), 1);
}

TEST(TestMatrix3d, Rotate3dZ)
{
	luna::Matrix3d rotateDeg = luna::Matrix3d::MakeRotateZ(luna::AngleFromDegrees(90));
	luna::Vector3d x{ 1, 0, 0 };
	luna::Vector3d xprime = rotateDeg * x;

	EXPECT_EQ(std::ceil(xprime.x()), 0);
	printf("%.5f\n", xprime.x());
	EXPECT_EQ(xprime.y(), 1);
	EXPECT_EQ(xprime.z(), 0);

}

TEST(TestMatrix3d, Rotate3dZAnother)
{
	luna::Matrix3d rotateDeg = luna::Matrix3d::MakeRotateZ(luna::AngleFromDegrees(360));
	luna::Vector3d x{ 1, 0, 0  };
	luna::Vector3d xprime = rotateDeg * x;
	EXPECT_EQ(xprime.x(), 1);
	EXPECT_EQ(std::floor(xprime.y()), 0);
	printf("%.5f\n", xprime.y());
	EXPECT_EQ(xprime.z(), 0);
}

TEST(TestMatrix3d, Scale3d)
{
	luna::Matrix3d scale = luna::Matrix3d{ 2 };
	luna::Vector3d x{ 1, 2, 3 };
	luna::Vector3d xprime = scale * x;
	EXPECT_EQ(xprime.x(), 2);
	EXPECT_EQ(xprime.y(), 4);
	EXPECT_EQ(xprime.z(), 6);
}

TEST(TestMatrix2d, Shear3dxy)
{
	luna::Matrix3d scale = luna::Matrix3d::MakeShearXY(2,2);
	luna::Vector3d x{ 1, 1, 1 };
	luna::Vector3d xprime = scale * x;
	EXPECT_EQ(xprime.x(), 3);
	EXPECT_EQ(xprime.y(), 3);
	EXPECT_EQ(xprime.z(), 1);
}

TEST(TestMatrix2d, Shear3xz)
{
	luna::Matrix3d scale = luna::Matrix3d::MakeShearXZ(2, 2);
	luna::Vector3d x{ 1, 1, 1 };
	luna::Vector3d xprime = scale * x;
	EXPECT_EQ(xprime.x(), 3);
	EXPECT_EQ(xprime.y(), 1);
	EXPECT_EQ(xprime.z(), 3);
}

TEST(TestMatrix2d, Shear3yz)
{
	luna::Matrix3d scale = luna::Matrix3d::MakeShearYZ(2, 2);
	luna::Vector3d x{ 1, 1, 1 };
	luna::Vector3d xprime = scale * x;
	EXPECT_EQ(xprime.x(), 1);
	EXPECT_EQ(xprime.y(), 3);
	EXPECT_EQ(xprime.z(), 3);
}
