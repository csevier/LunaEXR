#include "pch.h"
#include "../luna_math/math.hpp"
#include "../luna_math/vector3d.hpp"
#include "../luna_math/trig.hpp"


TEST(TestVector3d, Ctor)
{
	luna::math::Vector3d v{ 1,2,3 };
	EXPECT_EQ(v.x(), 1);
	EXPECT_EQ(v.y(), 2);
	EXPECT_EQ(v.z(), 3);
}

TEST(TestVector3d, ScaleVector)
{
	luna::math::Vector3d v{ 1,2,3 };
	luna::math::Vector3d vec = v * 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
	EXPECT_EQ(vec.z(), 6);
}

TEST(TestVector3d, DivideVector)
{
	luna::math::Vector3d v{ 4,10,16 };
	luna::math::Vector3d vec = v / 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 5);
	EXPECT_EQ(vec.z(), 8);
}

TEST(TestVector3d, NegateVector)
{
	luna::math::Vector3d v{ 4,10,16 };
	luna::math::Vector3d vec = -v;
	EXPECT_EQ(vec.x(), -4);
	EXPECT_EQ(vec.y(), -10);
	EXPECT_EQ(vec.z(), -16);
}

TEST(TestVector3d, AddVector)
{
	luna::math::Vector3d v{ 4,10,16 };
	luna::math::Vector3d vec{ 1,2,3 };
	luna::math::Vector3d add = v + vec;
	EXPECT_EQ(add.x(), 5);
	EXPECT_EQ(add.y(), 12);
	EXPECT_EQ(add.z(), 19);
}

TEST(TestVector3d, SubtractVector)
{
	luna::math::Vector3d v{ 4,10,16 };
	luna::math::Vector3d vec{ 1,2,3 };
	luna::math::Vector3d minus = v - vec;
	EXPECT_EQ(minus.x(), 3);
	EXPECT_EQ(minus.y(), 8);
	EXPECT_EQ(minus.z(), 13);
}

TEST(TestVector3d, ScaleSelf)
{

	luna::math::Vector3d vec{ 1,2,3 };
	vec *= 3;
	EXPECT_EQ(vec.x(), 3);
	EXPECT_EQ(vec.y(), 6);
	EXPECT_EQ(vec.z(), 9);
}

TEST(TestVector3d, AddSelf)
{

	luna::math::Vector3d vec{ 1,2,3 };
	vec += luna::math::Vector3d{ 1,2,3 };
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
	EXPECT_EQ(vec.z(), 6);
}

TEST(TestVector3d, SubtractSelf)
{
	luna::math::Vector3d vec{ 1,2,3 };
	vec -= luna::math::Vector3d{ 1,2,3 };
	EXPECT_EQ(vec.x(), 0);
	EXPECT_EQ(vec.y(), 0);
	EXPECT_EQ(vec.z(), 0);
}

TEST(TestVector3d, SubscripVector)
{
	luna::math::Vector3d vec{ 1,2,3 };

	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
	EXPECT_EQ(vec[2], 3);
}

TEST(TestVector3d, Magnitude)
{
	luna::math::Vector3d vec{ 1,2,3 };
	float mag = vec.Magnitude();
	EXPECT_EQ(mag, 3.74165750f);
}

TEST(TestVector3d, NormalizeVector)
{
	luna::math::Vector3d vec{ 2,2,7 };
	luna::math::Vector3d norm = vec.Normalize();
	float mag = norm.Magnitude();
	EXPECT_EQ(mag, 1);
}

TEST(TestVector3d, DotProduct)
{
	luna::math::Vector3d vec{ 2,2,7 };
	luna::math::Vector3d vec2{ 1,2,3 };
	float dot = vec.DotProduct(vec2);
	EXPECT_EQ(dot, 27);
}

TEST(TestVector3d, CrossProduct)
{
	luna::math::Vector3d vec{ 2,3,4 };
	luna::math::Vector3d vec2{ 5,6,7 };
	luna::math::Vector3d cross = vec.CrossProduct(vec2);
	EXPECT_EQ(cross.x(), -3);
	EXPECT_EQ(cross.y(), 6);
	EXPECT_EQ(cross.z(), -3);
}

TEST(TestVector3d, DistanceTo)
{
	luna::math::Vector3d vec{ 7,4,3 };
	luna::math::Vector3d vec2{ 17, 6, 2 };
	float distance = vec.DistanceTo(vec2);
	float distanceOther = vec2.DistanceTo(vec);
	EXPECT_EQ(distance, 10.2469511f);
	EXPECT_EQ(distanceOther, 10.2469511f);
}

TEST(TestVector3d, AngleBetween)
{
	luna::math::Vector3d vec{ 2,1,-2 };
	luna::math::Vector3d vec2{ 1,1,1 };
	float distance = vec.AngleBetween(vec2);
	EXPECT_EQ(distance, 1.37713802f);
	float degrees = luna::math::RadianToDegree(distance);
	EXPECT_EQ(degrees, 78.9041901f);
}

TEST(TestVector3d, IsPerependicular)
{
	luna::math::Vector3d vec{ 10,4,-1 };
	luna::math::Vector3d vec2{ 1,1,14 };
	bool isperp = vec.IsPerpendicular(vec2);
	EXPECT_TRUE(isperp);
}

TEST(TestVector3d, IsParallel)
{
	luna::math::Vector3d vec{ 10,4,-1 };
	luna::math::Vector3d vec2{ 1,1,14 };
	bool para = vec.IsParallel(vec2);
	bool ispara = vec.IsParallel(vec);
	EXPECT_FALSE(para);
	EXPECT_TRUE(ispara);
}

TEST(TestVector3d, VectorEquality)
{
	luna::math::Vector3d vec{ 10,4,-1 };
	luna::math::Vector3d vec2{ 1,1,14 };
	luna::math::Vector3d vec3{ 1,1,14 };
	EXPECT_FALSE(vec == vec2);
	EXPECT_TRUE(vec2 == vec3);
}

TEST(TestVector3d, SameDirection)
{
	luna::math::Vector3d vec{ -1,-1, -14 };
	luna::math::Vector3d vec2{ 1,12,14 };
	luna::math::Vector3d vec3{ 1,1,14 };
	bool samedir = vec2.SameDirection(vec);
	bool samedirt = vec2.SameDirection(vec3);
	EXPECT_FALSE(samedir);
	EXPECT_TRUE(samedirt);
}

