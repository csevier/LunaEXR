#include "pch.h"
#include "../luna_math/math.hpp"

#include "../luna_math/geometry.hpp"

TEST(TestGeometry, AreaOfCircle)
{
	float area = luna::math::AreaOfCircle(2);
	EXPECT_EQ(area, 12.5663710f);
}

TEST(TestGeometry, AreaOfRectangle)
{
	float area = luna::math::AreaOfRectangle(2, 3);
	EXPECT_EQ(area, 6);
}

TEST(TestGeometry, CircleCircumference)
{
	float area = luna::math::CircleCircumference(6);
	EXPECT_EQ(area, 37.6991119f);
}