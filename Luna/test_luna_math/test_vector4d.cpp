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
	luna::math::Angle angle = vec.AngleBetween(vec2);
	EXPECT_EQ(angle.Radians(), 1.07658029f);
	EXPECT_EQ(angle.Degrees(), 61.6835060f);
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
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
	EXPECT_EQ(vec.z(), 6);
	EXPECT_EQ(vec.w(), 8);
}

TEST(TestVector4d, DivideVector)
{
	luna::math::Vector4d v{ 4,10,16, 10 };
	luna::math::Vector4d vec = v / 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 5);
	EXPECT_EQ(vec.z(), 8);
	EXPECT_EQ(vec.w(), 5);
}

TEST(TestVector4d, NegateVector)
{
	luna::math::Vector4d v{ 4,10,16, 2 };
	luna::math::Vector4d vec = -v;
	EXPECT_EQ(vec.x(), -4);
	EXPECT_EQ(vec.y(), -10);
	EXPECT_EQ(vec.z(), -16);
	EXPECT_EQ(vec.w(), -2);
}

TEST(TestVector4d, AddVector)
{
	luna::math::Vector4d v{ 4,10,16,3 };
	luna::math::Vector4d vec{ 1,2,3, 6 };
	luna::math::Vector4d add = v + vec;
	EXPECT_EQ(add.x(), 5);
	EXPECT_EQ(add.y(), 12);
	EXPECT_EQ(add.z(), 19);
	EXPECT_EQ(add.w(), 9);
}

TEST(TestVector4d, SubtractVector)
{
	luna::math::Vector4d v{ 4,10,16,5 };
	luna::math::Vector4d vec{ 1,2,3,2 };
	luna::math::Vector4d minus = v - vec;
	EXPECT_EQ(minus.x(), 3);
	EXPECT_EQ(minus.y(), 8);
	EXPECT_EQ(minus.z(), 13);
	EXPECT_EQ(minus.w(), 3);
}

TEST(TestVector4d, ScaleSelf)
{

	luna::math::Vector4d vec{ 1,2,3,4 };
	vec *= 3;
	EXPECT_EQ(vec.x(), 3);
	EXPECT_EQ(vec.y(), 6);
	EXPECT_EQ(vec.z(), 9);
	EXPECT_EQ(vec.w(), 12);
}

TEST(TestVector4d, AddSelf)
{

	luna::math::Vector4d vec{ 1,2,3,4 };
	vec += luna::math::Vector4d{ 1,2,3,4 };
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
	EXPECT_EQ(vec.z(), 6);
	EXPECT_EQ(vec.w(), 8);
}

TEST(TestVector4d, SubtractSelf)
{
	luna::math::Vector4d vec{ 1,2,3,4 };
	vec -= luna::math::Vector4d{ 1,2,3,4 };
	EXPECT_EQ(vec.x(), 0);
	EXPECT_EQ(vec.y(), 0);
	EXPECT_EQ(vec.z(), 0);
	EXPECT_EQ(vec.w(), 0);
}

TEST(TestVector4d, SubscripVector)
{
	luna::math::Vector4d vec{ 1,2,3,4 };

	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
	EXPECT_EQ(vec[2], 3);
	EXPECT_EQ(vec[3], 4);
}