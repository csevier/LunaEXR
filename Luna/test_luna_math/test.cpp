#include "pch.h"
#include "../luna_math/math.hpp"

TEST(TestTrig, DegreeToRadian)
{
	double radian = luna::math::trig::DegreeToRadian(360);
	EXPECT_EQ(radian, 2 * luna::math::M_PI);
}

TEST(TestTrig, RadianToDegree)
{
	double degree = luna::math::trig::RadianToDegree(2 * luna::math::M_PI);
	EXPECT_EQ(degree, 360);
}

TEST(TestTrig, ArcLengthRadians)
{
	double arcLength = luna::math::trig::ArcLengthRadians(2, luna::math::M_PI);
	EXPECT_EQ(arcLength, 2 * luna::math::M_PI);
	double arcLength2 = luna::math::trig::ArcLengthRadians(7 * luna::math::M_PI / 4, 20);
	EXPECT_EQ(arcLength2, 109.95574287564276);
	double arcLength3 = luna::math::trig::ArcLengthRadians(3, luna::math::trig::DegreeToRadian(180));
	EXPECT_EQ(arcLength3, 3 * luna::math::M_PI);
}

TEST(TestTrig, ArcLengthDegrees)
{
	double arcLength = luna::math::trig::ArcLengthDegrees(3, 75);
	EXPECT_EQ(arcLength, 3.9269908169872414);
}

TEST(TestGeometry, AreaOfCircle)
{
	double area = luna::math::geometry::AreaOfCircle(2);
	EXPECT_EQ(area, 12.566370614359172);
}

TEST(TestGeometry, AreaOfRectangle)
{
	double area = luna::math::geometry::AreaOfRectangle(2,3);
	EXPECT_EQ(area, 6);
}

TEST(TestGeometry, CircleCircumference)
{
	double area = luna::math::geometry::CircleCircumference(6);
	EXPECT_EQ(area, 37.699111843077517);
}