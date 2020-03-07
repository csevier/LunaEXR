#include "../luna_math/matrix2d.hpp"
#include "../luna_math/vector2d.hpp"
#include <gtest/gtest.h>

TEST(TestMatrix2d, Ctor)
{
	luna::Matrix2d mat2{ 1,2,3,4};
	EXPECT_EQ(mat2(0, 0), 1);
	EXPECT_EQ(mat2(1, 1), 4);
}

TEST(TestMatrix2d, MakesDiag)
{
	luna::Matrix2d mat2{ 1,};
	EXPECT_TRUE(mat2.IsIdentity());
	EXPECT_TRUE(mat2.IsDiagonal());
	EXPECT_EQ(mat2(0, 0), 1);
	EXPECT_EQ(mat2(1, 1), 1);
}

TEST(TestMatrix2d, MatrixEquality)
{
	luna::Matrix2d mat2{ 1,2,3,4 };
	luna::Matrix2d mat4{ 1,2,3,4 };
	EXPECT_EQ(mat2, mat4);
}

TEST(TestMatrix2d, DefaultCtorIdentity)
{
	luna::Matrix2d mat2{ };
	EXPECT_EQ(mat2(0, 0), 1);
	EXPECT_EQ(mat2(0, 1), 0);
	EXPECT_EQ(mat2(1, 0), 0);
	EXPECT_EQ(mat2(1, 1), 1);
	EXPECT_TRUE(mat2.IsIdentity());
}

TEST(TestMatrix2d, Transpose)
{
	luna::Matrix2d mat2{ 1,2,3,4 };
	luna::Matrix2d ident{ };
	luna::Matrix2d mat2T = mat2.Transpose();
	luna::Matrix2d orig = mat2T.Transpose();
	EXPECT_EQ(mat2T(0, 0), 1);
	EXPECT_EQ(mat2T(0, 1), 3);
	EXPECT_EQ(mat2T(1, 0), 2);
	EXPECT_EQ(mat2T(1, 1), 4);
	EXPECT_EQ(mat2, orig);
	EXPECT_EQ(ident, ident.Transpose());
}

TEST(TestMatrix2d, Diagonal)
{
	luna::Matrix2d mat2{ 1,2,3,4};
	luna::Matrix2d ident{ };
	luna::Matrix2d diag{ 2, 0,
						 0, 9};
	EXPECT_TRUE(ident.IsDiagonal());
	EXPECT_TRUE(diag.IsDiagonal());
	EXPECT_FALSE(mat2.IsDiagonal());
}

TEST(TestMatrix2d, ScaleMatrix)
{
	luna::Matrix2d mat2{ 1,2,3,4};
	luna::Matrix2d scaled = mat2 * 2;
	EXPECT_EQ(scaled(0, 0), 2);
	EXPECT_EQ(scaled(0, 1), 4);
	EXPECT_EQ(scaled(1, 0), 6);
	EXPECT_EQ(scaled(1, 1), 8);
}

TEST(TestMatrix2d, MatrixByMatrix)
{
	luna::Matrix2d a{ 1,-5,3,0};
	luna::Matrix2d b{ -8,6,1,7};
	luna::Matrix2d scaled = a * b;
	EXPECT_EQ(scaled(0, 0), -13);
	EXPECT_EQ(scaled(0, 1), -29);
	EXPECT_EQ(scaled(1, 0), -24);
	EXPECT_EQ(scaled(1, 1),  18);
}

TEST(TestMatrix2d, MatrixByVector)
{
	luna::Matrix2d a{ 18.5f, 27.3f,
					  21.8f, 13.9f };
	luna::Vector2d b{ 12.1f, 6.4f};
	luna::Vector2d vec = a * b;
	EXPECT_EQ(vec.x(), 363.369995f);
	EXPECT_EQ(vec.y(), 419.289978f);

}
TEST(TestMatrix2d, MatrixByVectorAnother)
{
	luna::Matrix2d a{ 2,-5,
					  0, 3};

	luna::Vector2d b{ 3, -1};
	luna::Vector2d vec = a * b;
	EXPECT_EQ(vec.x(), 6.0f);
	EXPECT_EQ(vec.y(), -18.0f);

}
TEST(TestMatrix2d, MatrixByBasisVector)
{
	luna::Matrix2d a{ 1,2,
					  4,5 };
	luna::Vector2d x{ 1, 0 };
	luna::Vector2d y{ 0, 1 };

	luna::Vector2d vec = a * x;
	EXPECT_EQ(vec.x(), 1.0f);
	EXPECT_EQ(vec.y(), 2.0f);

	luna::Vector2d vec1 = a * y;
	EXPECT_EQ(vec1.x(), 4.0f);
	EXPECT_EQ(vec1.y(), 5.0f);
}

TEST(TestMatrix2d, Rotate2d)
{
	luna::Matrix2d rotateDeg = luna::Matrix2d::MakeRotate(luna::Angle::AngleFromDegrees(180));
	luna::Vector2d x{ 1, 0 };
	luna::Vector2d xprime = rotateDeg *x;
	EXPECT_EQ(xprime.x(),  -x.x());
	EXPECT_EQ(std::ceil(xprime.y()),  0); // its SUPER close to 0
	printf("%.5f\n", xprime.y());
}

TEST(TestMatrix2d, Rotate2dAnother)
{
	luna::Matrix2d rotateDeg = luna::Matrix2d::MakeRotate(luna::Angle::AngleFromDegrees(360));
	luna::Vector2d x{ 1, 0 };
	luna::Vector2d xprime = rotateDeg * x;
	EXPECT_EQ(xprime.x(), x.x());
	EXPECT_EQ(std::floor(xprime.y()), 0);
	printf("%.5f\n", xprime.y());
}

TEST(TestMatrix2d, Scale2d)
{
	luna::Matrix2d scale = luna::Matrix2d{ 2 };
	luna::Vector2d x{ 1, 2 };
	luna::Vector2d xprime = scale * x;
	EXPECT_EQ(xprime.x(), 2);
	EXPECT_EQ(xprime.y(), 4);
}

TEST(TestMatrix2d, Shear2dx)
{
	luna::Matrix2d scale = luna::Matrix2d::MakeShearX(2);
	luna::Vector2d x{ 2, 1 };
	luna::Vector2d xprime = scale * x;
	EXPECT_EQ(xprime.x(), 4);
	EXPECT_EQ(xprime.y(), 1);
}

TEST(TestMatrix2d, Shear2dy)
{
	luna::Matrix2d scale = luna::Matrix2d::MakeShearY(2);
	luna::Vector2d x{ 1, 2 };
	luna::Vector2d xprime = scale * x;
	EXPECT_EQ(xprime.x(), 1);
	EXPECT_EQ(xprime.y(), 4);
}


