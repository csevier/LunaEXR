#include "../../../luna_math/src/math.hpp"
#include "../../../luna_math/src/vector4d.hpp"
#include "../../../luna_math/src/angle.hpp"
#include <gtest/gtest.h>

TEST(TestVector4d, SameDirection)
{
	luna::Vector4d vec{ -1,-1, -14,1 };
	luna::Vector4d vec2{ 1,12,14,1 };
	luna::Vector4d vec3{ 1,1,14,1 };
	bool samedir = vec2.SameDirection(vec);
	bool samedirt = vec2.SameDirection(vec3);
	EXPECT_FALSE(samedir);
	EXPECT_TRUE(samedirt);
}

TEST(TestVector4d, VectorEquality)
{
	luna::Vector4d vec{ 10,4,-1,3 };
	luna::Vector4d vec2{ 1,1,14,3 };
	luna::Vector4d vec3{ 1,1,14,3 };
	EXPECT_FALSE(vec == vec2);
	EXPECT_TRUE(vec2 == vec3);
}

TEST(TestVector4d, DistanceTo)
{
	luna::Vector4d vec{ 7,4,3,1 };
	luna::Vector4d vec2{ 17, 6, 2,1 };
	float distance = vec.DistanceTo(vec2);
	float distanceOther = vec2.DistanceTo(vec);
	EXPECT_EQ(distance, 10.2469511f);
	EXPECT_EQ(distanceOther, 10.2469511f);
}

TEST(TestVector4d, AngleBetween)
{
	luna::Vector4d vec{ 2,1,-2,1 };
	luna::Vector4d vec2{ 1,1,1,1 }; 
	luna::Angle angle = vec.AngleBetween(vec2);
	EXPECT_EQ(angle.Radians(), 1.07658029f);
	EXPECT_EQ(angle.Degrees(), 61.6835060f);
}

TEST(TestVector4d, NormalizeVector)
{
	luna::Vector4d vec{ 2,2,7,3 };
	luna::Vector4d norm = vec.Normalize();
	float mag = norm.Magnitude();
	EXPECT_EQ(mag, 1);
}

TEST(TestVector4d, DotProduct)
{
	luna::Vector4d vec{ 2,2,7,1 };
	luna::Vector4d vec2{ 1,2,3,1 };
	float dot = vec.DotProduct(vec2);
	EXPECT_EQ(dot, 29);
}

TEST(TestVector4d, ScaleVector)
{
	luna::Vector4d v{ 1,2,3,4 };
	luna::Vector4d vec = v * 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
	EXPECT_EQ(vec.z(), 6);
	EXPECT_EQ(vec.w(), 8);
}

TEST(TestVector4d, DivideVector)
{
	luna::Vector4d v{ 4,10,16, 10 };
	luna::Vector4d vec = v / 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 5);
	EXPECT_EQ(vec.z(), 8);
	EXPECT_EQ(vec.w(), 5);
}

TEST(TestVector4d, NegateVector)
{
	luna::Vector4d v{ 4,10,16, 2 };
	luna::Vector4d vec = -v;
	EXPECT_EQ(vec.x(), -4);
	EXPECT_EQ(vec.y(), -10);
	EXPECT_EQ(vec.z(), -16);
	EXPECT_EQ(vec.w(), -2);
}

TEST(TestVector4d, AddVector)
{
	luna::Vector4d v{ 4,10,16,3 };
	luna::Vector4d vec{ 1,2,3, 6 };
	luna::Vector4d add = v + vec;
	EXPECT_EQ(add.x(), 5);
	EXPECT_EQ(add.y(), 12);
	EXPECT_EQ(add.z(), 19);
	EXPECT_EQ(add.w(), 9);
}

TEST(TestVector4d, SubtractVector)
{
	luna::Vector4d v{ 4,10,16,5 };
	luna::Vector4d vec{ 1,2,3,2 };
	luna::Vector4d minus = v - vec;
	EXPECT_EQ(minus.x(), 3);
	EXPECT_EQ(minus.y(), 8);
	EXPECT_EQ(minus.z(), 13);
	EXPECT_EQ(minus.w(), 3);
}

TEST(TestVector4d, ScaleSelf)
{

	luna::Vector4d vec{ 1,2,3,4 };
	vec *= 3;
	EXPECT_EQ(vec.x(), 3);
	EXPECT_EQ(vec.y(), 6);
	EXPECT_EQ(vec.z(), 9);
	EXPECT_EQ(vec.w(), 12);
}

TEST(TestVector4d, AddSelf)
{

	luna::Vector4d vec{ 1,2,3,4 };
	vec += luna::Vector4d{ 1,2,3,4 };
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
	EXPECT_EQ(vec.z(), 6);
	EXPECT_EQ(vec.w(), 8);
}

TEST(TestVector4d, SubtractSelf)
{
	luna::Vector4d vec{ 1,2,3,4 };
	vec -= luna::Vector4d{ 1,2,3,4 };
	EXPECT_EQ(vec.x(), 0);
	EXPECT_EQ(vec.y(), 0);
	EXPECT_EQ(vec.z(), 0);
	EXPECT_EQ(vec.w(), 0);
}

TEST(TestVector4d, SubscripVector)
{
	luna::Vector4d vec{ 1,2,3,4 };

	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
	EXPECT_EQ(vec[2], 3);
	EXPECT_EQ(vec[3], 4);
}

//Test from 3d primer book exercises.
TEST(TestVector4d, NormalizeVectorBook)
{
	luna::Vector4d v{ 1,1,1,1 };
	luna::Vector4d norm = v.Normalize();
	EXPECT_EQ(norm.x(), 0.5f);
	EXPECT_EQ(norm.y(), 0.5f);
	EXPECT_EQ(norm.z(), 0.5f);
	EXPECT_EQ(norm.w(), 0.5f);
}

TEST(TestVector4d,DistanceBook)
{
	luna::Vector4d v{ 4, -4, -4, 4 };
	luna::Vector4d z{ -6, 6,6,-6 };
	float distance = v.DistanceTo(z);
	EXPECT_EQ(distance,20);
}