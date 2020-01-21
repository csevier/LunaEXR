#include "pch.h"
#include "../luna_math/math.hpp"
#include "../luna_math/trig.hpp"
#include "../luna_math/geometry.hpp"
#include "../luna_math/vector3d.hpp"

TEST(TestTrig, DegreeToRadian)
{
	float radian = luna::math::DegreeToRadian(360);
	EXPECT_EQ(radian, 6.28318548f);
}

TEST(TestTrig, RadianToDegree)
{
	float degree = luna::math::RadianToDegree(6.28319f);
	EXPECT_EQ(degree, 360.000244f);
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

TEST(TestTrig, SecantIsCorrect)
{
	float val = luna::math::Sec(5);
	EXPECT_EQ(val, 3.52531981f);
}

TEST(TestTrig, CosecantIsCorrect)
{
	float val = luna::math::Csc(3);
	EXPECT_EQ(val, 7.08616781f);
}

TEST(TestTrig, CotangetIsCorrect)
{
	float val = luna::math::Cot(1);
	EXPECT_EQ(val, 0.642092586f);
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

TEST(TestVector3d, Ctor)
{
	luna::math::Vector3d v{ 1,2,3 };
	EXPECT_EQ(v.mX, 1);
	EXPECT_EQ(v.mY, 2);
	EXPECT_EQ(v.mZ, 3);
}

TEST(TestVector3d, ScaleVector)
{
	luna::math::Vector3d v{ 1,2,3 };
	luna::math::Vector3d vec = v * 2;
	EXPECT_EQ(vec.mX, 2);
	EXPECT_EQ(vec.mY, 4);
	EXPECT_EQ(vec.mZ, 6);
}

TEST(TestVector3d, DivideVector)
{
	luna::math::Vector3d v{ 4,10,16 };
	luna::math::Vector3d vec = v / 2;
	EXPECT_EQ(vec.mX, 2);
	EXPECT_EQ(vec.mY, 5);
	EXPECT_EQ(vec.mZ, 8);
}

TEST(TestVector3d, NegateVector)
{
	luna::math::Vector3d v{ 4,10,16 };
	luna::math::Vector3d vec = -v;
	EXPECT_EQ(vec.mX, -4);
	EXPECT_EQ(vec.mY, -10);
	EXPECT_EQ(vec.mZ, -16);
}

TEST(TestVector3d, AddVector)
{
	luna::math::Vector3d v{ 4,10,16 };
	luna::math::Vector3d vec{1,2,3};
	luna::math::Vector3d add = v + vec;
	EXPECT_EQ(add.mX,5);
	EXPECT_EQ(add.mY, 12);
	EXPECT_EQ(add.mZ, 19);
}

TEST(TestVector3d, SubtractVector)
{
	luna::math::Vector3d v{ 4,10,16 };
	luna::math::Vector3d vec{ 1,2,3 };
	luna::math::Vector3d minus = v - vec;
	EXPECT_EQ(minus.mX, 3);
	EXPECT_EQ(minus.mY, 8);
	EXPECT_EQ(minus.mZ, 13);
}

TEST(TestVector3d, ScaleSelf)
{
	
	luna::math::Vector3d vec{ 1,2,3 };
	vec *= 3;
	EXPECT_EQ(vec.mX, 3);
	EXPECT_EQ(vec.mY, 6);
	EXPECT_EQ(vec.mZ, 9);
}

TEST(TestVector3d, AddSelf)
{

	luna::math::Vector3d vec{ 1,2,3 };
	vec += luna::math::Vector3d{ 1,2,3 };
	EXPECT_EQ(vec.mX, 2);
	EXPECT_EQ(vec.mY, 4);
	EXPECT_EQ(vec.mZ, 6);
}

TEST(TestVector3d, SubtractSelf)
{
	luna::math::Vector3d vec{ 1,2,3 };
	vec -= luna::math::Vector3d{ 1,2,3 };
	EXPECT_EQ(vec.mX, 0);
	EXPECT_EQ(vec.mY, 0);
	EXPECT_EQ(vec.mZ, 0);
}

TEST(TestVector3d, SubscripVector)
{
	luna::math::Vector3d vec{ 1,2,3 };
	
	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
	EXPECT_EQ(vec[2], 3);
}

TEST(TestVector3d, Magnitude)
{
	luna::math::Vector3d vec{ 1,2,3 };
	float mag = vec.Magnitude();
	EXPECT_EQ(mag, 3.74165750f);
}

TEST(TestVector3d, NormalizeVector)
{
	luna::math::Vector3d vec{ 2,2,7 };
	luna::math::Vector3d norm =vec.Normalize();
	float mag = norm.Magnitude();
	EXPECT_EQ(mag,1);
}

TEST(TestVector3d, DotProduct)
{
	luna::math::Vector3d vec{ 2,2,7 };
	luna::math::Vector3d vec2{ 1,2,3 };
	float dot = vec.DotProduct(vec2);
	EXPECT_EQ(dot, 27);
}

TEST(TestVector3d, CrossProduct)
{
	luna::math::Vector3d vec{2,3,4 };
	luna::math::Vector3d vec2{ 5,6,7 };
	luna::math::Vector3d cross = vec.CrossProduct(vec2);
	EXPECT_EQ(cross.mX, -3);
	EXPECT_EQ(cross.mY, 6);
	EXPECT_EQ(cross.mZ, -3);
}
