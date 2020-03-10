#include "vmath.h"
#include "matrix4d.hpp"
#include "vector4d.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <gtest/gtest.h>


TEST(TestMatrix4d, Ctor)
{
	luna::Matrix4d mat3{ 1,2,3,4,
						 5,6,7,8,
						 9,10,11,12,
						13,14,15,16 };
	EXPECT_EQ(mat3(0, 0), 1);
	EXPECT_EQ(mat3(1, 1), 6);
	EXPECT_EQ(mat3(2, 2), 11);
	EXPECT_EQ(mat3(3, 3), 16);
}

TEST(TestMatrix4d, MatrixEquality)
{
	luna::Matrix4d mat3{ 1,2,3,4,
						 5,6,7,8,
						 9,10,11,12,
						13,14,15,16 };

	luna::Matrix4d mat4{ 1,2,3,4,
						 5,6,7,8,
						 9,10,11,12,
						13,14,15,16 };
	
	EXPECT_EQ(mat3, mat4);
}

TEST(TestMatrix4d, DefaultCtorIdentity)
{
	luna::Matrix4d mat3{ };
	EXPECT_EQ(mat3(0, 0), 1);
	EXPECT_EQ(mat3(0, 1), 0);
	EXPECT_EQ(mat3(0, 2), 0);
	EXPECT_EQ(mat3(0, 3), 0);

	EXPECT_EQ(mat3(1, 0), 0);
	EXPECT_EQ(mat3(1, 1), 1);
	EXPECT_EQ(mat3(1, 2), 0);
	EXPECT_EQ(mat3(1, 3), 0);

	EXPECT_EQ(mat3(2, 0), 0);
	EXPECT_EQ(mat3(2, 1), 0);
	EXPECT_EQ(mat3(2, 2), 1);
	EXPECT_EQ(mat3(2, 3), 0);

	EXPECT_EQ(mat3(3, 0), 0);
	EXPECT_EQ(mat3(3, 1), 0);
	EXPECT_EQ(mat3(3, 2), 0);
	EXPECT_EQ(mat3(3, 3), 1);

	EXPECT_TRUE(mat3.IsIdentity());
}

TEST(TestMatrix4d, Transpose)
{
	luna::Matrix4d mat3{ 1, 2, 3, 4,
						 5, 6, 7, 8,
						 9, 10,11,12,
						 13,14,15,16 };

	luna::Matrix4d ident{ };

	luna::Matrix4d mat3T = mat3.Transpose();
	luna::Matrix4d orig = mat3T.Transpose();

	EXPECT_EQ(mat3T(0, 0), 1);
	EXPECT_EQ(mat3T(0, 1), 5);
	EXPECT_EQ(mat3T(0, 2), 9);
	EXPECT_EQ(mat3T(0, 3), 13);

	EXPECT_EQ(mat3T(1, 0), 2);
	EXPECT_EQ(mat3T(1, 1), 6);
	EXPECT_EQ(mat3T(1, 2), 10);
	EXPECT_EQ(mat3T(1, 3), 14);

	EXPECT_EQ(mat3T(2, 0), 3);
	EXPECT_EQ(mat3T(2, 1), 7);
	EXPECT_EQ(mat3T(2, 2), 11);
	EXPECT_EQ(mat3T(2, 3), 15);

	EXPECT_EQ(mat3T(3, 0), 4);
	EXPECT_EQ(mat3T(3, 1), 8);
	EXPECT_EQ(mat3T(3, 2), 12);
	EXPECT_EQ(mat3T(3, 3), 16);

	EXPECT_EQ(mat3, orig);
	EXPECT_EQ(ident, ident.Transpose());
}

TEST(TestMatrix4d, Diagonal)
{
	luna::Matrix4d mat3{ 1, 2, 3, 4,
						 5, 6, 7, 8,
						 9, 10,11,12,
						 13,14,15,16 };

	luna::Matrix4d ident{ };

	luna::Matrix4d diag{ 2,0,0, 0,
						 0,9,0, 0,
						 0,0,12, 0,
						 0,0,0, 15, };
	EXPECT_TRUE(ident.IsDiagonal());
	EXPECT_TRUE(diag.IsDiagonal());
	EXPECT_FALSE(mat3.IsDiagonal());
}

TEST(TestMatrix4d, ScaleMatrix)
{
	luna::Matrix4d mat3{ 1, 2, 3, 4,
						 5, 6, 7, 8,
						 9, 10,11,12,
						 13,14,15,16 };

	luna::Matrix4d scaled = mat3 * 2;
	EXPECT_EQ(scaled(0, 0), 2);
	EXPECT_EQ(scaled(0, 1), 4);
	EXPECT_EQ(scaled(0, 2), 6);
	EXPECT_EQ(scaled(0, 3), 8);

	EXPECT_EQ(scaled(1, 0), 10);
	EXPECT_EQ(scaled(1, 1), 12);
	EXPECT_EQ(scaled(1, 2), 14);
	EXPECT_EQ(scaled(1, 3), 16);

	EXPECT_EQ(scaled(2, 0), 18);
	EXPECT_EQ(scaled(2, 1), 20);
	EXPECT_EQ(scaled(2, 2), 22);
	EXPECT_EQ(scaled(2, 3), 24);

	EXPECT_EQ(scaled(3, 0), 26);
	EXPECT_EQ(scaled(3, 1), 28);
	EXPECT_EQ(scaled(3, 2), 30);
	EXPECT_EQ(scaled(3, 3), 32);
}

TEST(TestMatrix4d, MatrixByMatrix)
{
	luna::Matrix4d a{ 1, 2, 3, 4,
						 5, 6, 7, 8,
						 9, 10,11,12,
						 13,14,15,16 };
	luna::Matrix4d b{ 1, 2, 3, 4,
						 5, 6, 7, 8,
						 9, 10,11,12,
						 13,14,15,16 };

	luna::Matrix4d scaled = a * b;
	EXPECT_EQ(scaled(0, 0), 90);
	EXPECT_EQ(scaled(0, 1), 100);
	EXPECT_EQ(scaled(0, 2), 110);
	EXPECT_EQ(scaled(0, 3), 120);

	EXPECT_EQ(scaled(1, 0), 202);
	EXPECT_EQ(scaled(1, 1), 228);
	EXPECT_EQ(scaled(1, 2), 254);
	EXPECT_EQ(scaled(1, 3), 280);

	EXPECT_EQ(scaled(2, 0), 314);
	EXPECT_EQ(scaled(2, 1), 356);
	EXPECT_EQ(scaled(2, 2), 398);
	EXPECT_EQ(scaled(2, 3), 440);

	EXPECT_EQ(scaled(3, 0), 426);
	EXPECT_EQ(scaled(3, 1), 484);
	EXPECT_EQ(scaled(3, 2), 542);
	EXPECT_EQ(scaled(3, 3), 600);
}


TEST(TestMatrix4d, MatrixByVector)
{
	luna::Matrix4d a{ 1, 2, 3, 4,
					  5, 6, 7, 8,
					  9, 10,11,12,
					  13,14,15,16 };

	luna::Vector4d b{ 1,2,3,4 };
	luna::Vector4d vec = a * b;

	EXPECT_EQ(vec.x(), 90.0f);
	EXPECT_EQ(vec.y(), 100.0f);
	EXPECT_EQ(vec.z(), 110.0f);
	EXPECT_EQ(vec.w(), 120.0f);

}


TEST(TestMatrix4d, MatrixByBasisVector)
{
	luna::Matrix4d a{ 1, 2, 3, 4,
						 5, 6, 7, 8,
						 9, 10,11,12,
						 13,14,15,16 };

	luna::Vector4d x{ 1, 0, 0, 0 };
	luna::Vector4d y{ 0, 1, 0 , 0 };
	luna::Vector4d z{ 0, 0, 1, 0 };
	luna::Vector4d w{ 0, 0, 0, 1 };

	luna::Vector4d vec = a * x;
	EXPECT_EQ(vec.x(), 1.0f);
	EXPECT_EQ(vec.y(), 2.0f);
	EXPECT_EQ(vec.z(), 3.0f);
	EXPECT_EQ(vec.w(), 4.0f);

	luna::Vector4d vec1 = a * y;
	EXPECT_EQ(vec1.x(), 5.0f);
	EXPECT_EQ(vec1.y(), 6.0f);
	EXPECT_EQ(vec1.z(), 7.0f);
	EXPECT_EQ(vec1.w(), 8.0f);

	luna::Vector4d vec2 = a * z;
	EXPECT_EQ(vec2.x(), 9.0f);
	EXPECT_EQ(vec2.y(), 10.0f);
	EXPECT_EQ(vec2.z(), 11.0f);
	EXPECT_EQ(vec2.w(), 12.0f);

	luna::Vector4d vec3 = a * w;
	EXPECT_EQ(vec3.x(), 13.0f);
	EXPECT_EQ(vec3.y(), 14.0f);
	EXPECT_EQ(vec3.z(), 15.0f);
	EXPECT_EQ(vec3.w(), 16.0f);

}

TEST(TestMatrix4d, TranslateIsAccurate)
{
	auto trans = luna::Matrix4d::Translate({3,3,3,});
	auto columnMajor = trans.Transpose();
	auto vtrans = vmath::translate(3,3,3);
	EXPECT_EQ(vtrans[0][0], columnMajor(0,0));
	EXPECT_EQ(vtrans[0][1], columnMajor(0,1));
	EXPECT_EQ(vtrans[0][2], columnMajor(0,2));
	EXPECT_EQ(vtrans[0][3], columnMajor(0,3));

	EXPECT_EQ(vtrans[1][0], columnMajor(1, 0));
	EXPECT_EQ(vtrans[1][1], columnMajor(1, 1));
	EXPECT_EQ(vtrans[1][2], columnMajor(1, 2));
	EXPECT_EQ(vtrans[1][3], columnMajor(1, 3));

	EXPECT_EQ(vtrans[2][0], columnMajor(2, 0));
	EXPECT_EQ(vtrans[2][1], columnMajor(2, 1));
	EXPECT_EQ(vtrans[2][2], columnMajor(2, 2));
	EXPECT_EQ(vtrans[2][3], columnMajor(2, 3));

	EXPECT_EQ(vtrans[3][0], columnMajor(3, 0));
	EXPECT_EQ(vtrans[3][1], columnMajor(3, 1));
	EXPECT_EQ(vtrans[3][2], columnMajor(3, 2));
	EXPECT_EQ(vtrans[3][3], columnMajor(3, 3));
}

TEST(TestMatrix4d, TestLookAtStart)
{
	luna::Matrix4d lunaLookat{};
	luna::Vector3d cameraPos = luna::Vector3d(0.0f, 0.0f, -3.0f);
	luna::Vector3d cameraFront = luna::Vector3d(0.0f, 0.0f, -1.0f);
	luna::Vector3d cameraUp = luna::Vector3d(0.0f, 1.0f, 0.0f);
	lunaLookat = lunaLookat * luna::Matrix4d::LookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	glm::vec3 gCameraPos{ cameraPos.x(), cameraPos.y(), cameraPos.z() };
	glm::vec3 gCameraFront{ cameraFront.x(), cameraFront.y(), cameraFront.z() };
	glm::vec3 gCameraUp{ cameraUp.x(), cameraUp.y(), cameraUp.z() };
	auto glmLookat = glm::lookAt(gCameraPos, gCameraPos + gCameraFront, gCameraUp);
	EXPECT_EQ(glmLookat[0][0], lunaLookat(0, 0));
	EXPECT_EQ(glmLookat[0][1], lunaLookat(0, 1));
	EXPECT_EQ(glmLookat[0][2], lunaLookat(0, 2));
	EXPECT_EQ(glmLookat[0][3], lunaLookat(0, 3));

	EXPECT_EQ(glmLookat[1][0], lunaLookat(1, 0));
	EXPECT_EQ(glmLookat[1][1], lunaLookat(1, 1));
	EXPECT_EQ(glmLookat[1][2], lunaLookat(1, 2));
	EXPECT_EQ(glmLookat[1][3], lunaLookat(1, 3));

	EXPECT_EQ(glmLookat[2][0], lunaLookat(2, 0));
	EXPECT_EQ(glmLookat[2][1], lunaLookat(2, 1));
	EXPECT_EQ(glmLookat[2][2], lunaLookat(2, 2));
	EXPECT_EQ(glmLookat[2][3], lunaLookat(2, 3));

	EXPECT_EQ(glmLookat[3][0], lunaLookat(3, 0));
	EXPECT_EQ(glmLookat[3][1], lunaLookat(3, 1));
	EXPECT_EQ(glmLookat[3][2], lunaLookat(3, 2));
	EXPECT_EQ(glmLookat[3][3], lunaLookat(3, 3));
}

TEST(TestMatrix4d, TestLookAtAfterMove)
{
	luna::Matrix4d lunaLookat{};
	luna::Vector3d cameraPos = luna::Vector3d(0.0f, 0.0f, -3.0f);
	luna::Vector3d cameraFront = luna::Vector3d(0.705246329f, 0.00436331099f, -0.708948910f);
	luna::Vector3d cameraUp = luna::Vector3d(0.0f, 1.0f, 0.0f);
	lunaLookat = lunaLookat * luna::Matrix4d::LookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	glm::vec3 gCameraPos{ cameraPos.x(), cameraPos.y(), cameraPos.z() };
	glm::vec3 gCameraFront{ cameraFront.x(), cameraFront.y(), cameraFront.z() };
	glm::vec3 gCameraUp{ cameraUp.x(), cameraUp.y(), cameraUp.z() };
	auto glmLookat = glm::lookAt(gCameraPos, gCameraPos + gCameraFront, gCameraUp);
	EXPECT_EQ(glmLookat[0][0], lunaLookat(0, 0));
	EXPECT_EQ(glmLookat[0][1], lunaLookat(0, 1));
	EXPECT_EQ(glmLookat[0][2], lunaLookat(0, 2));
	EXPECT_EQ(glmLookat[0][3], lunaLookat(0, 3));

	EXPECT_EQ(glmLookat[1][0], lunaLookat(1, 0));
	EXPECT_EQ(glmLookat[1][1], lunaLookat(1, 1));
	EXPECT_EQ(glmLookat[1][2], lunaLookat(1, 2));
	EXPECT_EQ(glmLookat[1][3], lunaLookat(1, 3));

	EXPECT_EQ(glmLookat[2][0], lunaLookat(2, 0));
	EXPECT_EQ(glmLookat[2][1], lunaLookat(2, 1));
	EXPECT_EQ(glmLookat[2][2], lunaLookat(2, 2));
	EXPECT_EQ(glmLookat[2][3], lunaLookat(2, 3));

	EXPECT_EQ(glmLookat[3][0], lunaLookat(3, 0));
	EXPECT_EQ(glmLookat[3][1], lunaLookat(3, 1));
	EXPECT_EQ(glmLookat[3][2], lunaLookat(3, 2));
	EXPECT_EQ(glmLookat[3][3], lunaLookat(3, 3));
}
