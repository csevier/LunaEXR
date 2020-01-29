#include "pch.h"
#include "../luna_math/matrix3d.hpp"
#include "../luna_math/vector3d.hpp"

TEST(TestMatrix3d, Ctor)
{
	luna::Matrix3d mat3{ 1,2,3,4,5,6,7,8,9 };
	EXPECT_EQ(mat3(0,0), 1);
	EXPECT_EQ(mat3(1,1), 5);
	EXPECT_EQ(mat3(2,2), 9);
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
    luna::Matrix3d mat3{ 1,2,3,4,5,6,7,8,9 };
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
	luna::Matrix3d diag{ 2,0,0,0,9,0,0,0,12 };
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
	luna::Matrix3d a{ 1,-5,3,0,-2,6,7,2,-4 };
	luna::Matrix3d b{ -8,6,1,7,0,-3,2,4,5 };
	luna::Matrix3d scaled = a * b;
	EXPECT_EQ(scaled(0, 0),-37);
	EXPECT_EQ(scaled(0, 1), 18);
	EXPECT_EQ(scaled(0, 2), 31);
	EXPECT_EQ(scaled(1, 0), -2);
	EXPECT_EQ(scaled(1, 1), 24);
	EXPECT_EQ(scaled(1, 2), 36);
	EXPECT_EQ(scaled(2, 0),-50);
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
	EXPECT_EQ(vec.x(), 514.700012f);
	EXPECT_EQ(vec.y(), 483.089996f);
	EXPECT_EQ(vec.z(), 557.290039f);

}