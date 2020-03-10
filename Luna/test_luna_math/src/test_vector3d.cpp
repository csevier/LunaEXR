#include "math.hpp"
#include "vector3d.hpp"
#include "angle.hpp"
#include <gtest/gtest.h>


TEST(TestVector3d, Ctor)
{
	luna::Vector3d v{ 1,2,3 };
	EXPECT_EQ(v.x(), 1);
	EXPECT_EQ(v.y(), 2);
	EXPECT_EQ(v.z(), 3);
}

TEST(TestVector3d, ScaleVector)
{
	luna::Vector3d v{ 1,2,3 };
	luna::Vector3d vec = v * 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
	EXPECT_EQ(vec.z(), 6);
}

TEST(TestVector3d, DivideVector)
{
	luna::Vector3d v{ 4,10,16 };
	luna::Vector3d vec = v / 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 5);
	EXPECT_EQ(vec.z(), 8);
}

TEST(TestVector3d, NegateVector)
{
	luna::Vector3d v{ 4,10,16 };
	luna::Vector3d vec = -v;
	EXPECT_EQ(vec.x(), -4);
	EXPECT_EQ(vec.y(), -10);
	EXPECT_EQ(vec.z(), -16);
}

TEST(TestVector3d, AddVector)
{
	luna::Vector3d v{ 4,10,16 };
	luna::Vector3d vec{ 1,2,3 };
	luna::Vector3d add = v + vec;
	EXPECT_EQ(add.x(), 5);
	EXPECT_EQ(add.y(), 12);
	EXPECT_EQ(add.z(), 19);
}

TEST(TestVector3d, SubtractVector)
{
	luna::Vector3d v{ 4,10,16 };
	luna::Vector3d vec{ 1,2,3 };
	luna::Vector3d minus = v - vec;
	EXPECT_EQ(minus.x(), 3);
	EXPECT_EQ(minus.y(), 8);
	EXPECT_EQ(minus.z(), 13);
}

TEST(TestVector3d, ScaleSelf)
{

	luna::Vector3d vec{ 1,2,3 };
	vec *= 3;
	EXPECT_EQ(vec.x(), 3);
	EXPECT_EQ(vec.y(), 6);
	EXPECT_EQ(vec.z(), 9);
}

TEST(TestVector3d, AddSelf)
{

	luna::Vector3d vec{ 1,2,3 };
	vec += luna::Vector3d{ 1,2,3 };
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
	EXPECT_EQ(vec.z(), 6);
}

TEST(TestVector3d, SubtractSelf)
{
	luna::Vector3d vec{ 1,2,3 };
	vec -= luna::Vector3d{ 1,2,3 };
	EXPECT_EQ(vec.x(), 0);
	EXPECT_EQ(vec.y(), 0);
	EXPECT_EQ(vec.z(), 0);
}

TEST(TestVector3d, SubscripVector)
{
	luna::Vector3d vec{ 1,2,3 };

	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
	EXPECT_EQ(vec[2], 3);
}

TEST(TestVector3d, Magnitude)
{
	luna::Vector3d vec{ 1,2,3 };
	float mag = vec.Magnitude();
	EXPECT_EQ(mag, 3.74165750f);
}

TEST(TestVector3d, NormalizeVector)
{
	luna::Vector3d vec{ 2,2,7 };
	luna::Vector3d norm = vec.Normalize();
	float mag = norm.Magnitude();
	EXPECT_EQ(mag, 1);
}

TEST(TestVector3d, DotProduct)
{
	luna::Vector3d vec{ 2,2,7 };
	luna::Vector3d vec2{ 1,2,3 };
	float dot = vec.DotProduct(vec2);
	EXPECT_EQ(dot, 27);
}

TEST(TestVector3d, CrossProduct)
{
	luna::Vector3d vec{ 2,3,4 };
	luna::Vector3d vec2{ 5,6,7 };
	luna::Vector3d cross = vec.CrossProduct(vec2);
	EXPECT_EQ(cross.x(), -3);
	EXPECT_EQ(cross.y(), 6);
	EXPECT_EQ(cross.z(), -3);
}

TEST(TestVector3d, DistanceTo)
{
	luna::Vector3d vec{ 7,4,3 };
	luna::Vector3d vec2{ 17, 6, 2 };
	float distance = vec.DistanceTo(vec2);
	float distanceOther = vec2.DistanceTo(vec);
	EXPECT_EQ(distance, 10.2469511f);
	EXPECT_EQ(distanceOther, 10.2469511f);
}

TEST(TestVector3d, AngleBetween)
{
	luna::Vector3d vec{ 2,1,-2 };
	luna::Vector3d vec2{ 1,1,1 };
	luna::Angle angle = vec.AngleBetween(vec2);
	EXPECT_EQ(angle.Radians(), 1.37713802f);
	EXPECT_EQ(angle.Degrees(), 78.9041901f);
}

TEST(TestVector3d, AngleBetween90)
{
	luna::Vector3d vec{ 10,4,-1 };
	luna::Vector3d vec2{ 1,1,14 };
	bool isperp = vec.IsPerpendicular(vec2);
	EXPECT_TRUE(isperp);
	luna::Angle angle = vec.AngleBetween(vec2);
	EXPECT_EQ(angle.Radians(), 1.57079637f);
	EXPECT_EQ(angle.Degrees(), 90.0000000f);
}

TEST(TestVector3d, AngleBetweenPara)
{
	luna::Vector3d vec{ 10,4,-1 };
	luna::Vector3d vec2{ 1,1,14 };
	bool ispara = vec.IsParallel(vec);
	EXPECT_TRUE(ispara);
	luna::Angle angle = vec.AngleBetween(vec);
	EXPECT_EQ(angle.Radians(), 0.000345266977f);
	EXPECT_EQ(angle.Degrees(), 0.0197823402f);
}

TEST(TestVector3d, IsPerependicular)
{
	luna::Vector3d vec{ 10,4,-1 };
	luna::Vector3d vec2{ 1,1,14 };
	bool isperp = vec.IsPerpendicular(vec2);
	EXPECT_TRUE(isperp);
}

TEST(TestVector3d, IsParallel)
{
	luna::Vector3d vec{ 10,4,-1 };
	luna::Vector3d vec2{ 1,1,14 };
	bool para = vec.IsParallel(vec2);
	bool ispara = vec.IsParallel(vec);
	EXPECT_FALSE(para);
	EXPECT_TRUE(ispara);
}

TEST(TestVector3d, VectorEquality)
{
	luna::Vector3d vec{ 10,4,-1 };
	luna::Vector3d vec2{ 1,1,14 };
	luna::Vector3d vec3{ 1,1,14 };
	EXPECT_FALSE(vec == vec2);
	EXPECT_TRUE(vec2 == vec3);
}

TEST(TestVector3d, SameDirection)
{
	luna::Vector3d vec{ -1,-1, -14 };
	luna::Vector3d vec2{ 1,12,14 };
	luna::Vector3d vec3{ 1,1,14 };
	bool samedir = vec2.SameDirection(vec);
	bool samedirt = vec2.SameDirection(vec3);
	EXPECT_FALSE(samedir);
	EXPECT_TRUE(samedirt);
}

//Tests checked against 3d graphics primer book, chapter 2 exercises
TEST(TestVector3d, VectorMagnitudeBook)
{
	luna::Vector3d v{ 8,-3, 0.5f };
	EXPECT_EQ(v.Magnitude(), 8.55862141f);
}

TEST(TestVector3d, ScaleVectorBook)
{
	luna::Vector3d v{ 4, -7, 0 };
	luna::Vector3d scaled = v * 3;
	EXPECT_EQ(scaled.x(), 12);
	EXPECT_EQ(scaled.y(), -21);
	EXPECT_EQ(scaled.z(), 0);
}


TEST(TestVector3d, NormalizeVectorBook)
{
	luna::Vector3d v{ 8,-3, 1.0f/2.0f };
	luna::Vector3d norm = v.Normalize();
	EXPECT_EQ(norm.x(), 0.934729993f);
	EXPECT_EQ(norm.y(), -0.350523740f);
	EXPECT_EQ(norm.z(), 0.0584206246f);
}

TEST(TestVector3d, NormalizeVectorBook6d)
{
	luna::Vector3d v{ -12 ,3, -4 };
	luna::Vector3d norm = v.Normalize();
	EXPECT_EQ(norm.x(), -0.923076987f);
	EXPECT_EQ(norm.y(), 0.230769247f);
	EXPECT_EQ(norm.z(), -0.307692319f);
}

TEST(TestVector3d, DistanceBook)
{
	luna::Vector3d v{ 3, 10, 7 };
	luna::Vector3d z{ 8, -7, 4 };
	float distance = v.DistanceTo(z);
	EXPECT_EQ(distance, 17.9722004f);
}

TEST(TestVector3d, DistanceBook8d)
{
	luna::Vector3d v{ -2, -4, 9};
	luna::Vector3d z{ 6, -7, 9.5f };
	float distance = v.DistanceTo(z);
	EXPECT_EQ(distance, 8.55862141f);
}
