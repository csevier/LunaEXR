#include "pch.h"
#include "../luna_math/matrix3d.hpp"

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