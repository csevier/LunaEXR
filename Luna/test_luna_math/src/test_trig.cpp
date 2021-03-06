#include "geometry.hpp"
#include "math.hpp"
#include "angle.hpp"

#include <gtest/gtest.h>

TEST(TestTrig, DegreeToRadian)
{
	float radian = luna::Angle::DegreeToRadian(360);
	EXPECT_EQ(radian, 6.28318548f);
}

TEST(TestTrig, RadianToDegree)
{
	float degree = luna::Angle::RadianToDegree(6.28319f);
	EXPECT_EQ(degree, 360.000244f);
}

TEST(TestTrig, ArcLengthRadians)
{
	float arcLength = luna::ArcLengthRadians(2, luna::Angle{ luna::cPI });
	EXPECT_EQ(arcLength, 2 * luna::cPI);
	float arcLength2 = luna::ArcLengthRadians(7 * luna::cPI / 4, 20);
	EXPECT_EQ(arcLength2, 109.955750f);
	float arcLength3 = luna::ArcLengthRadians(3, luna::Angle::AngleFromDegrees(180));
	EXPECT_EQ(arcLength3, 3 * luna::cPI);
}

TEST(TestTrig, ArcLengthDegrees)
{
	float arcLength = luna::ArcLengthDegrees(3, luna::Angle::AngleFromDegrees(75));
	EXPECT_EQ(arcLength, 3.92699075f);
}

TEST(TestTrig, SecantIsCorrect)
{
	float val = luna::Sec(luna::Angle{ 5 });
	EXPECT_EQ(val, 3.52531981f);
}

TEST(TestTrig, CosecantIsCorrect)
{
	float val = luna::Csc(luna::Angle{ 3 });
	EXPECT_EQ(val, 7.08616781f);
}

TEST(TestTrig, CotangetIsCorrect)
{
	float val = luna::Cot(luna::Angle{ 1 });
	EXPECT_EQ(val, 0.642092586f);
}
