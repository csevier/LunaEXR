#include "pch.h"
#include "../luna_math/math.hpp"
#include "../luna_math/angle.hpp"

TEST(TestAngle, DegreeToRadian)
{
	luna::math::Angle angle = luna::math::AngleFromDegrees(360);
	EXPECT_EQ(angle.Radians(), 6.28318548f);
	EXPECT_EQ(angle.Degrees(), 360.0f);
}

TEST(TestAngle, RadianToDegree)
{
	luna::math::Angle angle = luna::math::AngleFromRadians(6.28318548f);
	luna::math::Angle angle1{ 6.28318548f };
	EXPECT_EQ(angle.Radians(), 6.28318548f);
	EXPECT_EQ(angle.Degrees(), 360.0f);
	EXPECT_EQ(angle1.Radians(), 6.28318548f);
	EXPECT_EQ(angle1.Degrees(), 360.0f);
}

TEST(TestAngle, AngleEquality)
{
	luna::math::Angle angle = luna::math::AngleFromRadians(6.28318548f);
	luna::math::Angle angleD = luna::math::AngleFromDegrees(360);
	luna::math::Angle angle1{ 6.28318548f };
	EXPECT_EQ(angle, angle1);
	EXPECT_EQ(angle, angleD);
}

TEST(TestAngle, AFewMoreTests)
{
	luna::math::Angle fullCircle = luna::math::AngleFromRadians(6.28318548f);
	luna::math::Angle halfcircle = luna::math::AngleFromDegrees(180.0f);
	luna::math::Angle thirty = luna::math::AngleFromDegrees(30.0f);
	luna::math::Angle twoSeventy = luna::math::AngleFromDegrees(270.0f);
	
	EXPECT_EQ(fullCircle.Radians(), luna::math::M_PI *2);
	EXPECT_EQ(fullCircle.Degrees(), 360.0f);

	EXPECT_EQ(halfcircle.Radians(), luna::math::M_PI);
	EXPECT_EQ(halfcircle.Degrees(), 180.0f);

	EXPECT_EQ(thirty.Radians(), 0.523598790f);
	EXPECT_EQ(thirty.Degrees(), 30.0f);

	EXPECT_EQ(twoSeventy.Radians(), 4.71238899f);
	EXPECT_EQ(twoSeventy.Degrees(), 270.0f);
}

