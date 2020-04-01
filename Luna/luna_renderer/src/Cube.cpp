#include "Cube.hpp"
#include <math.h>

namespace luna 
{
	Cube::Cube(Vector3d transform) : 
		GameObject{transform}, 
		mMesh{ {
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(0.0f,0.0f)},
           Vertex{Vector3d(0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,0.0f)},
           Vertex{Vector3d(0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(-0.5f,  0.5f, -0.5f),
                  Vector2d(0.0f,1.0f)},
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(0.0f,0.0f)},

           Vertex{Vector3d(-0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,0.0f)},
           Vertex{Vector3d(0.5f, -0.5f,  0.5f),
                  Vector2d(1.0f,0.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(-0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,1.0f)},
           Vertex{Vector3d(-0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,0.0f)},

           Vertex{Vector3d(-0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,0.0f)},
           Vertex{Vector3d(-0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,0.0f)},
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(-0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,1.0f)},
           Vertex{Vector3d(-0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,0.0f)},

           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,0.0f)},
           Vertex{Vector3d(0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,0.0f)},
           Vertex{Vector3d(0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,1.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,0.0f)},

           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(0.0f,0.0f)},
           Vertex{Vector3d(0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,0.0f)},
           Vertex{Vector3d(0.5f, -0.5f,  0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(0.5f, -0.5f,  0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(-0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,1.0f)},
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(0.0f,0.0f)},

           Vertex{Vector3d(-0.5f,  0.5f, -0.5f),
                  Vector2d(0.0f,0.0f)},
           Vertex{Vector3d(0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,0.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(1.0f,1.0f)},
           Vertex{Vector3d(-0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,1.0f)},
           Vertex{Vector3d(-0.5f,  0.5f, -0.5f),
                  Vector2d(0.0f,0.0f)}},

            "/home/csevier/Source/Luna/Luna/luna_renderer/textures/luna.jpg"}
	{
	}

    void Cube::Update(const TimeManager& tm)
	{
        float ct = (float)tm.GetCurrentTime();
		Matrix4d model{};
		model = model * luna::Matrix4d::Translate(GetTransform() + luna::Vector3d{0.0f,0.0f,25.0f});
		mMesh.SetModel(model);
	}

	void Cube::Draw(Shader shader) {
		mMesh.Draw(shader);
	}
}

