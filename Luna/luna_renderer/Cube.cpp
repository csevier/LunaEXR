#include "Cube.hpp"

namespace luna 
{
	Cube::Cube(Vector3d transform) : 
		GameObject{transform}, 
		mMesh{ {
		   Vector3d(-0.5f, -0.5f, -0.5f),
			Vector3d(0.5f, -0.5f, -0.5f),
			Vector3d(0.5f,  0.5f, -0.5f),
			Vector3d(0.5f,  0.5f, -0.5f),
		   Vector3d(-0.5f,  0.5f, -0.5f),
		   Vector3d(-0.5f, -0.5f, -0.5f),

		   Vector3d(-0.5f, -0.5f,  0.5f),
		   Vector3d(0.5f, -0.5f,  0.5f),
		   Vector3d(0.5f,  0.5f,  0.5f),
		   Vector3d(0.5f,  0.5f,  0.5f),
		   Vector3d(-0.5f,  0.5f,  0.5f),
		   Vector3d(-0.5f, -0.5f,  0.5f),

		   Vector3d(-0.5f,  0.5f,  0.5f),
		   Vector3d(-0.5f,  0.5f, -0.5f),
		   Vector3d(-0.5f, -0.5f, -0.5f),
		   Vector3d(-0.5f, -0.5f, -0.5f),
		   Vector3d(-0.5f, -0.5f,  0.5f),
		   Vector3d(-0.5f,  0.5f,  0.5f),

			Vector3d(0.5f,  0.5f,  0.5f),
			Vector3d(0.5f,  0.5f, -0.5f),
		   Vector3d(0.5f, -0.5f, -0.5f),
			Vector3d(0.5f, -0.5f, -0.5f),
		   Vector3d(0.5f, -0.5f,  0.5f),
			Vector3d(0.5f,  0.5f,  0.5f),

		   Vector3d(-0.5f, -0.5f, -0.5f),
		   Vector3d(0.5f, -0.5f, -0.5f),
			Vector3d(0.5f, -0.5f,  0.5f),
		   Vector3d(0.5f, -0.5f,  0.5f),
		   Vector3d(-0.5f, -0.5f,  0.5f),
		   Vector3d(-0.5f, -0.5f, -0.5f),

		   Vector3d(-0.5f,  0.5f, -0.5f),
			Vector3d(0.5f,  0.5f, -0.5f),
			Vector3d(0.5f,  0.5f,  0.5f),
		   Vector3d(0.5f,  0.5f,  0.5f),
		   Vector3d(-0.5f,  0.5f,  0.5f),
		   Vector3d(-0.5f,  0.5f, -0.5f)} }
	{
	}

	void Cube::Update(float deltaTime)
	{
		Matrix4d model{};
		model = model * luna::Matrix4d::Translate(GetTransform());
		model = model * luna::Matrix4d::RotateY(luna::Angle::AngleFromDegrees(50.0f).Radians() * (float)deltaTime);
		mMesh.SetModel(model);
	}

	void Cube::Draw(Shader shader) {
		mMesh.Draw(shader);
	}
}

