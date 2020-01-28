#include "pch.h"
#include "../luna_math/math.hpp"
#include "../luna_math/angle.hpp"

TEST(TestAngle, DegreeToRadian)
{
	luna::Angle angle = luna::AngleFromDegrees(360);
	EXPECT_EQ(angle.Radians(), 6.28318548f);
	EXPECT_EQ(angle.Degrees(), 360.0f);
}

TEST(TestAngle, RadianToDegree)
{
	luna::Angle angle = luna::AngleFromRadians(6.28318548f);
	luna::Angle angle1{ 6.28318548f };
	EXPECT_EQ(angle.Radians(), 6.28318548f);
	EXPECT_EQ(angle.Degrees(), 360.0f);
	EXPECT_EQ(angle1.Radians(), 6.28318548f);
	EXPECT_EQ(angle1.Degrees(), 360.0f);
}

TEST(TestAngle, AngleEquality)
{
	luna::Angle angle = luna::AngleFromRadians(6.28318548f);
	luna::Angle angleD = luna::AngleFromDegrees(360);
	luna::Angle angle1{ 6.28318548f };
	EXPECT_EQ(angle, angle1);
	EXPECT_EQ(angle, angleD);
}

TEST(TestAngle, AFewMoreTests)
{
	luna::Angle fullCircle = luna::AngleFromRadians(6.28318548f);
	luna::Angle halfcircle = luna::AngleFromDegrees(180.0f);
	luna::Angle thirty = luna::AngleFromDegrees(30.0f);
	luna::Angle twoSeventy = luna::AngleFromDegrees(270.0f);
	
	EXPECT_EQ(fullCircle.Radians(), luna::M_PI *2);
	EXPECT_EQ(fullCircle.Degrees(), 360.0f);

	EXPECT_EQ(halfcircle.Radians(), luna::M_PI);
	EXPECT_EQ(halfcircle.Degrees(), 180.0f);

	EXPECT_EQ(thirty.Radians(), 0.523598790f);
	EXPECT_EQ(thirty.Degrees(), 30.0f);

	EXPECT_EQ(twoSeventy.Radians(), 4.71238899f);
	EXPECT_EQ(twoSeventy.Degrees(), 270.0f);
}

