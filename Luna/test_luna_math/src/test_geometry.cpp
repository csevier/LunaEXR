#include "../../../luna_math/src/geometry.hpp"
#include "../../../luna_math/src/math.hpp"
#include <gtest/gtest.h>

TEST(TestGeometry, AreaOfCircle)
{
	float area = luna::AreaOfCircle(2);
	EXPECT_EQ(area, 12.5663710f);
}

TEST(TestGeometry, AreaOfRectangle)
{
	float area = luna::AreaOfRectangle(2, 3);
	EXPECT_EQ(area, 6);
}

TEST(TestGeometry, CircleCircumference)
{
	float area = luna::CircleCircumference(6);
	EXPECT_EQ(area, 37.6991119f);
}