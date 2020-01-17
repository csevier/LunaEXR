#include "pch.h"
#include "../luna_math/math.hpp"
#include "../luna_math/trig.hpp"
#include "../luna_math/geometry.hpp"

TEST(TestTrig, DegreeToRadian)
{
	float radian = luna::math::DegreeToRadian(360);
	EXPECT_EQ(radian, 2 * luna::math::M_PI);
}

TEST(TestTrig, RadianToDegree)
{
	float degree = luna::math::RadianToDegree(2 * luna::math::M_PI);
	EXPECT_EQ(degree, 360);
}

TEST(TestTrig, ArcLengthRadians)
{
	float arcLength = luna::math::ArcLengthRadians(2, luna::math::M_PI);
	EXPECT_EQ(arcLength, 2 * luna::math::M_PI);
	float arcLength2 = luna::math::ArcLengthRadians(7 * luna::math::M_PI / 4, 20);
	EXPECT_EQ(arcLength2, 109.955750f);
	float arcLength3 = luna::math::ArcLengthRadians(3, luna::math::DegreeToRadian(180));
	EXPECT_EQ(arcLength3, 3 * luna::math::M_PI);
}

TEST(TestTrig, ArcLengthDegrees)
{
	float arcLength = luna::math::ArcLengthDegrees(3, 75);
	EXPECT_EQ(arcLength, 3.92699075f);
}

TEST(TestGeometry, AreaOfCircle)
{
	float area = luna::math::AreaOfCircle(2);
	EXPECT_EQ(area, 12.5663710f);
}

TEST(TestGeometry, AreaOfRectangle)
{
	float area = luna::math::AreaOfRectangle(2,3);
	EXPECT_EQ(area, 6);
}

TEST(TestGeometry, CircleCircumference)
{
	float area = luna::math::CircleCircumference(6);
	EXPECT_EQ(area, 37.6991119f);
}