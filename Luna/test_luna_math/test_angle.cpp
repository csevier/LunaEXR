#include "pch.h"
#include "../luna_math/trig.hpp"
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

