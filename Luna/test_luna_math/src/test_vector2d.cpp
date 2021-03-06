#include "math.hpp"
#include "vector2d.hpp"
#include "angle.hpp"

#include <gtest/gtest.h>


TEST(TestVector2d, Ctor)
{
	luna::Vector2d v{ 1,2 };
	EXPECT_EQ(v.x(), 1);
	EXPECT_EQ(v.y(), 2);
}

TEST(TestVector2d, ScaleVector)
{
	luna::Vector2d v{ 1,2 };
	luna::Vector2d vec = v * 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
}

TEST(TestVector2d, DivideVector)
{
	luna::Vector2d v{ 4,10};
	luna::Vector2d vec = v / 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 5);
}

TEST(TestVector2d, NegateVector)
{
	luna::Vector2d v{ 4,10 };
	luna::Vector2d vec = -v;
	EXPECT_EQ(vec.x(), -4);
	EXPECT_EQ(vec.y(), -10);
}

TEST(TestVector2d, AddVector)
{
	luna::Vector2d v{ 4,10 };
	luna::Vector2d vec{ 1,2 };
	luna::Vector2d add = v + vec;
	EXPECT_EQ(add.x(), 5);
	EXPECT_EQ(add.y(), 12);
}

TEST(TestVector2d, SubtractVector)
{
	luna::Vector2d v{ 4,10 };
	luna::Vector2d vec{ 1,2 };
	luna::Vector2d minus = v - vec;
	EXPECT_EQ(minus.x(), 3);
	EXPECT_EQ(minus.y(), 8);
}

TEST(TestVector2d, ScaleSelf)
{

	luna::Vector2d vec{ 1,2 };
	vec *= 3;
	EXPECT_EQ(vec.x(), 3);
	EXPECT_EQ(vec.y(), 6);
}

TEST(TestVector2d, AddSelf)
{

	luna::Vector2d vec{ 1,2};
	vec += luna::Vector2d{ 1,2 };
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
}

TEST(TestVector2d, SubtractSelf)
{
	luna::Vector2d vec{ 1,2 };
	vec -= luna::Vector2d{ 1,2 };
	EXPECT_EQ(vec.x(), 0);
	EXPECT_EQ(vec.y(), 0);
}

TEST(TestVector2d, SubscripVector)
{
	luna::Vector2d vec{ 1,2};

	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
}

TEST(TestVector2d, Magnitude)
{
	luna::Vector2d vec{ 1,2 };
	float mag = vec.Magnitude();
	EXPECT_EQ(mag, 2.23606801f);
}

TEST(TestVector2d, NormalizeVector)
{
	luna::Vector2d vec{ 2,5 };
	luna::Vector2d norm = vec.Normalize();
	float mag = norm.Magnitude();
	EXPECT_EQ(mag, 1);
}

TEST(TestVector2d, DotProduct)
{
	luna::Vector2d vec{ 2,2 };
	luna::Vector2d vec2{ 1,2 };
	float dot = vec.DotProduct(vec2);
	EXPECT_EQ(dot, 6);
}

TEST(TestVector2d, DistanceTo)
{
	luna::Vector2d vec{ 7,4 };
	luna::Vector2d vec2{ 17, 6 };
	float distance = vec.DistanceTo(vec2);
	float distanceOther = vec2.DistanceTo(vec);
	EXPECT_EQ(distance, 10.1980391f);
	EXPECT_EQ(distanceOther, 10.1980391f);
}

TEST(TestVector2d, AngleBetween)
{
	luna::Vector2d vec{ 2,1 };
	luna::Vector2d vec2{ 1,1 };
	luna::Angle angle = vec.AngleBetween(vec2);
	EXPECT_EQ(angle.Radians(), 0.321750671f);
	EXPECT_EQ(angle.Degrees(), 18.4349537f);
}

TEST(TestVector2d, IsPerependicular)
{
	luna::Vector2d vec{ 5, 0 };
	luna::Vector2d vec2{ 0,5 };
	bool isperp = vec.IsPerpendicular(vec2);
	EXPECT_TRUE(isperp);
}

TEST(TestVector2d, IsParallel)
{
	luna::Vector2d vec{ 0,5 };
	luna::Vector2d vec2{ 0,6 };
	bool para = vec.IsParallel(vec2);
	EXPECT_TRUE(para);
}

TEST(TestVector2d, VectorEquality)
{
	luna::Vector2d vec{ 10,4 };
	luna::Vector2d vec2{ 1,1 };
	luna::Vector2d vec3{ 1,1 };
	EXPECT_FALSE(vec == vec2);
	EXPECT_TRUE(vec2 == vec3);
}

TEST(TestVector2d, SameDirection)
{
	luna::Vector2d vec{ -1,-1 };
	luna::Vector2d vec2{ 1,12, };
	luna::Vector2d vec3{ 1,1 };
	bool samedir = vec2.SameDirection(vec);
	bool samedirt = vec2.SameDirection(vec3);
	EXPECT_FALSE(samedir);
	EXPECT_TRUE(samedirt);
}


//Tests checked against 3d graphics primer book, chapter 2 exercises
TEST(TestVector2d, NegateVectorBook)
{
	luna::Vector2d v{ 3,7 };
	luna::Vector2d vec = -v;
	EXPECT_EQ(vec.x(), -3);
	EXPECT_EQ(vec.y(), -7);
}

TEST(TestVector2d, VectorMagnitudeBook)
{
	luna::Vector2d v{ -12,5 };
	EXPECT_EQ(v.Magnitude(), 13);
}

TEST(TestVector2d, VectorDivisionBook)
{
	luna::Vector2d v{ 4,5 };
	luna::Vector2d div = v / 2;
	EXPECT_EQ(div.x(), 2);
	EXPECT_EQ(div.y(), 5.0f/2.0f);
}

TEST(TestVector2d, NormalizeVectorBook)
{
	luna::Vector2d v{ 12,5 };
	luna::Vector2d norm = v.Normalize();
	EXPECT_EQ(norm.x(), 0.923076987f);
	EXPECT_EQ(norm.y(), 0.384615391f);
}

TEST(TestVector2d, NormalizeVectorBook6b)
{
	luna::Vector2d v{ 0,743.632 };
	luna::Vector2d norm = v.Normalize();
	EXPECT_EQ(norm.x(), 0);
	EXPECT_EQ(norm.y(), 1);
}

TEST(TestVector2d, DistanceBook)
{
	luna::Vector2d v{ 10, 6 };
	luna::Vector2d z{-14,30 };
	float distance = v.DistanceTo(z);
	EXPECT_EQ(distance, 33.9411240f);
}

TEST(TestVector2d, DistanceBook8b)
{
	luna::Vector2d v{ 0,0 };
	luna::Vector2d z{ -12,5 };
	float distance = v.DistanceTo(z);
	EXPECT_EQ(distance, 13);
}
