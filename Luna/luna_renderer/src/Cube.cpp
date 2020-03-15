#include "Cube.hpp"
#include <math.h>

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

    void Cube::Update(const TimeManager& tm)
	{
        float ct = (float)tm.GetCurrentTime();
		Matrix4d model{};
		model = model * luna::Matrix4d::Translate(GetTransform() + luna::Vector3d{0.0f,0.0f,25.0f});
        model = model * luna::Matrix4d::RotateY(luna::Angle::AngleFromDegrees(50.0f).Radians() *ct);
		mMesh.SetModel(model);
	}

	void Cube::Draw(Shader shader) {
		mMesh.Draw(shader);
	}
}

