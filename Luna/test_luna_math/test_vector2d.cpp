#include "pch.h"
#include "../luna_math/math.hpp"
#include "../luna_math/vector2d.hpp"
#include "../luna_math/trig.hpp"


TEST(TestVector2d, Ctor)
{
	luna::math::Vector2d v{ 1,2 };
	EXPECT_EQ(v.x(), 1);
	EXPECT_EQ(v.y(), 2);
}

TEST(TestVector2d, ScaleVector)
{
	luna::math::Vector2d v{ 1,2 };
	luna::math::Vector2d vec = v * 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
}

TEST(TestVector2d, DivideVector)
{
	luna::math::Vector2d v{ 4,10};
	luna::math::Vector2d vec = v / 2;
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 5);
}

TEST(TestVector2d, NegateVector)
{
	luna::math::Vector2d v{ 4,10 };
	luna::math::Vector2d vec = -v;
	EXPECT_EQ(vec.x(), -4);
	EXPECT_EQ(vec.y(), -10);
}

TEST(TestVector2d, AddVector)
{
	luna::math::Vector2d v{ 4,10 };
	luna::math::Vector2d vec{ 1,2 };
	luna::math::Vector2d add = v + vec;
	EXPECT_EQ(add.x(), 5);
	EXPECT_EQ(add.y(), 12);
}

TEST(TestVector2d, SubtractVector)
{
	luna::math::Vector2d v{ 4,10 };
	luna::math::Vector2d vec{ 1,2 };
	luna::math::Vector2d minus = v - vec;
	EXPECT_EQ(minus.x(), 3);
	EXPECT_EQ(minus.y(), 8);
}

TEST(TestVector2d, ScaleSelf)
{

	luna::math::Vector2d vec{ 1,2 };
	vec *= 3;
	EXPECT_EQ(vec.x(), 3);
	EXPECT_EQ(vec.y(), 6);
}

TEST(TestVector2d, AddSelf)
{

	luna::math::Vector2d vec{ 1,2};
	vec += luna::math::Vector2d{ 1,2 };
	EXPECT_EQ(vec.x(), 2);
	EXPECT_EQ(vec.y(), 4);
}

TEST(TestVector2d, SubtractSelf)
{
	luna::math::Vector2d vec{ 1,2 };
	vec -= luna::math::Vector2d{ 1,2 };
	EXPECT_EQ(vec.x(), 0);
	EXPECT_EQ(vec.y(), 0);
}

TEST(TestVector2d, SubscripVector)
{
	luna::math::Vector2d vec{ 1,2};

	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
}

TEST(TestVector2d, Magnitude)
{
	luna::math::Vector2d vec{ 1,2 };
	float mag = vec.Magnitude();
	EXPECT_EQ(mag, 2.23606801f);
}

TEST(TestVector2d, NormalizeVector)
{
	luna::math::Vector2d vec{ 2,5 };
	luna::math::Vector2d norm = vec.Normalize();
	float mag = norm.Magnitude();
	EXPECT_EQ(mag, 1);
}

TEST(TestVector2d, DotProduct)
{
	luna::math::Vector2d vec{ 2,2 };
	luna::math::Vector2d vec2{ 1,2 };
	float dot = vec.DotProduct(vec2);
	EXPECT_EQ(dot, 6);
}

TEST(TestVector2d, DistanceTo)
{
	luna::math::Vector2d vec{ 7,4 };
	luna::math::Vector2d vec2{ 17, 6 };
	float distance = vec.DistanceTo(vec2);
	float distanceOther = vec2.DistanceTo(vec);
	EXPECT_EQ(distance, 10.1980391f);
	EXPECT_EQ(distanceOther, 10.1980391f);
}

TEST(TestVector2d, AngleBetween)
{
	luna::math::Vector2d vec{ 2,1 };
	luna::math::Vector2d vec2{ 1,1 };
	float angle = vec.AngleBetween(vec2);
	EXPECT_EQ(angle, 0.321750671f);
	float degrees = luna::math::RadianToDegree(angle);
	EXPECT_EQ(degrees, 18.4349537f);
}

TEST(TestVector2d, IsPerependicular)
{
	luna::math::Vector2d vec{ 5, 0 };
	luna::math::Vector2d vec2{ 0,5 };
	bool isperp = vec.IsPerpendicular(vec2);
	EXPECT_TRUE(isperp);
}

TEST(TestVector2d, IsParallel)
{
	luna::math::Vector2d vec{ 0,5 };
	luna::math::Vector2d vec2{ 0,6 };
	bool para = vec.IsParallel(vec2);
	EXPECT_TRUE(para);
}

TEST(TestVector2d, VectorEquality)
{
	luna::math::Vector2d vec{ 10,4 };
	luna::math::Vector2d vec2{ 1,1 };
	luna::math::Vector2d vec3{ 1,1 };
	EXPECT_FALSE(vec == vec2);
	EXPECT_TRUE(vec2 == vec3);
}

TEST(TestVector2d, SameDirection)
{
	luna::math::Vector2d vec{ -1,-1 };
	luna::math::Vector2d vec2{ 1,12, };
	luna::math::Vector2d vec3{ 1,1 };
	bool samedir = vec2.SameDirection(vec);
	bool samedirt = vec2.SameDirection(vec3);
	EXPECT_FALSE(samedir);
	EXPECT_TRUE(samedirt);
}

