#include "pch.h"

#include "../luna_math/trig.hpp"
#include "../luna_math/vector4d.hpp"
#include "../luna_math/math.hpp"

TEST(TestVector4d, SameDirection)
{
	luna::math::Vector4d vec{ -1,-1, -14,1 };
	luna::math::Vector4d vec2{ 1,12,14,1 };
	luna::math::Vector4d vec3{ 1,1,14,1 };
	bool samedir = vec2.SameDirection(vec);
	bool samedirt = vec2.SameDirection(vec3);
	EXPECT_FALSE(samedir);
	EXPECT_TRUE(samedirt);
}

TEST(TestVector4d, VectorEquality)
{
	luna::math::Vector4d vec{ 10,4,-1,3 };
	luna::math::Vector4d vec2{ 1,1,14,3 };
	luna::math::Vector4d vec3{ 1,1,14,3 };
	EXPECT_FALSE(vec == vec2);
	EXPECT_TRUE(vec2 == vec3);
}

TEST(TestVector4d, DistanceTo)
{
	luna::math::Vector4d vec{ 7,4,3,1 };
	luna::math::Vector4d vec2{ 17, 6, 2,1 };
	float distance = vec.DistanceTo(vec2);
	float distanceOther = vec2.DistanceTo(vec);
	EXPECT_EQ(distance, 10.2469511f);
	EXPECT_EQ(distanceOther, 10.2469511f);
}

TEST(TestVector4d, AngleBetween)
{
	luna::math::Vector4d vec{ 2,1,-2,1 };
	luna::math::Vector4d vec2{ 1,1,1,1 };
	float angle = vec.AngleBetween(vec2);
	EXPECT_EQ(angle, 1.07658029f);
	float degrees = luna::math::RadianToDegree(angle);
	EXPECT_EQ(degrees, 61.6835060f);
}

TEST(TestVector4d, NormalizeVector)
{
	luna::math::Vector4d vec{ 2,2,7,3 };
	luna::math::Vector4d norm = vec.Normalize();
	float mag = norm.Magnitude();
	EXPECT_EQ(mag, 1);
}

TEST(TestVector4d, DotProduct)
{
	luna::math::Vector4d vec{ 2,2,7,1 };
	luna::math::Vector4d vec2{ 1,2,3,1 };
	float dot = vec.DotProduct(vec2);
	EXPECT_EQ(dot, 29);
}

TEST(TestVector4d, ScaleVector)
{
	luna::math::Vector4d v{ 1,2,3,4 };
	luna::math::Vector4d vec = v * 2;
	EXPECT_EQ(vec.mX, 2);
	EXPECT_EQ(vec.mY, 4);
	EXPECT_EQ(vec.mZ, 6);
	EXPECT_EQ(vec.mW, 8);
}

TEST(TestVector4d, DivideVector)
{
	luna::math::Vector4d v{ 4,10,16, 10 };
	luna::math::Vector4d vec = v / 2;
	EXPECT_EQ(vec.mX, 2);
	EXPECT_EQ(vec.mY, 5);
	EXPECT_EQ(vec.mZ, 8);
	EXPECT_EQ(vec.mW, 5);
}

TEST(TestVector4d, NegateVector)
{
	luna::math::Vector4d v{ 4,10,16, 2 };
	luna::math::Vector4d vec = -v;
	EXPECT_EQ(vec.mX, -4);
	EXPECT_EQ(vec.mY, -10);
	EXPECT_EQ(vec.mZ, -16);
	EXPECT_EQ(vec.mW, -2);
}

TEST(TestVector4d, AddVector)
{
	luna::math::Vector4d v{ 4,10,16,3 };
	luna::math::Vector4d vec{ 1,2,3, 6 };
	luna::math::Vector4d add = v + vec;
	EXPECT_EQ(add.mX, 5);
	EXPECT_EQ(add.mY, 12);
	EXPECT_EQ(add.mZ, 19);
	EXPECT_EQ(add.mW, 9);
}

TEST(TestVector4d, SubtractVector)
{
	luna::math::Vector4d v{ 4,10,16,5 };
	luna::math::Vector4d vec{ 1,2,3,2 };
	luna::math::Vector4d minus = v - vec;
	EXPECT_EQ(minus.mX, 3);
	EXPECT_EQ(minus.mY, 8);
	EXPECT_EQ(minus.mZ, 13);
	EXPECT_EQ(minus.mW, 3);
}

TEST(TestVector4d, ScaleSelf)
{

	luna::math::Vector4d vec{ 1,2,3,4 };
	vec *= 3;
	EXPECT_EQ(vec.mX, 3);
	EXPECT_EQ(vec.mY, 6);
	EXPECT_EQ(vec.mZ, 9);
	EXPECT_EQ(vec.mW, 12);
}

TEST(TestVector4d, AddSelf)
{

	luna::math::Vector4d vec{ 1,2,3,4 };
	vec += luna::math::Vector4d{ 1,2,3,4 };
	EXPECT_EQ(vec.mX, 2);
	EXPECT_EQ(vec.mY, 4);
	EXPECT_EQ(vec.mZ, 6);
	EXPECT_EQ(vec.mW, 8);
}

TEST(TestVector4d, SubtractSelf)
{
	luna::math::Vector4d vec{ 1,2,3,4 };
	vec -= luna::math::Vector4d{ 1,2,3,4 };
	EXPECT_EQ(vec.mX, 0);
	EXPECT_EQ(vec.mY, 0);
	EXPECT_EQ(vec.mZ, 0);
	EXPECT_EQ(vec.mW, 0);
}

TEST(TestVector4d, SubscripVector)
{
	luna::math::Vector4d vec{ 1,2,3,4 };

	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
	EXPECT_EQ(vec[2], 3);
	EXPECT_EQ(vec[3], 4);
}