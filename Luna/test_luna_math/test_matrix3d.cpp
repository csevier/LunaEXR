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
}