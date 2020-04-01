#include "Cube.hpp"
#include <math.h>

namespace luna 
{
    Cube::Cube(const Vector3d& transform) :
		GameObject{transform}, 
		mMesh{ {
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(0.0f,  0.0f, -1.0f)},
           Vertex{Vector3d(0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,0.0f),
                  Vector3d(0.0f,  0.0f, -1.0f)},
           Vertex{Vector3d(0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(0.0f,  0.0f, -1.0f)},
           Vertex{Vector3d(0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(0.0f,  0.0f, -1.0f)},
           Vertex{Vector3d(-0.5f,  0.5f, -0.5f),
                  Vector2d(0.0f,1.0f),
                  Vector3d(0.0f,  0.0f, -1.0f)},
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(0.0f,  0.0f, -1.0f)},

           Vertex{Vector3d(-0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(0.0f,  0.0f, 1.0f)},
           Vertex{Vector3d(0.5f, -0.5f,  0.5f),
                  Vector2d(1.0f,0.0f),
                  Vector3d(0.0f,  0.0f, 1.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(0.0f,  0.0f, 1.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(0.0f,  0.0f, 1.0f)},
           Vertex{Vector3d(-0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,1.0f),
                  Vector3d(0.0f,  0.0f, 1.0f)},
           Vertex{Vector3d(-0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(0.0f,  0.0f, 1.0f)},

           Vertex{Vector3d(-0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(-1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(-0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,0.0f),
                  Vector3d(-1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(-1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(-1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(-0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,1.0f),
                  Vector3d(-1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(-0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(-1.0f,  0.0f,  0.0f)},

           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,0.0f),
                  Vector3d(1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,1.0f),
                  Vector3d(1.0f,  0.0f,  0.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(1.0f,  0.0f,  0.0f)},

           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(0.0f, -1.0f,  0.0f)},
           Vertex{Vector3d(0.5f, -0.5f, -0.5f),
                  Vector2d(1.0f,0.0f),
                  Vector3d(0.0f, -1.0f,  0.0f)},
           Vertex{Vector3d(0.5f, -0.5f,  0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(0.0f, -1.0f,  0.0f)},
           Vertex{Vector3d(0.5f, -0.5f,  0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(0.0f, -1.0f,  0.0f)},
           Vertex{Vector3d(-0.5f, -0.5f,  0.5f),
                  Vector2d(0.0f,1.0f),
                  Vector3d(0.0f, -1.0f,  0.0f)},
           Vertex{Vector3d(-0.5f, -0.5f, -0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(0.0f, -1.0f,  0.0f)},

           Vertex{Vector3d(-0.5f,  0.5f, -0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(0.0f,  1.0f,  0.0f)},
           Vertex{Vector3d(0.5f,  0.5f, -0.5f),
                  Vector2d(1.0f,0.0f),
                  Vector3d(0.0f,  1.0f,  0.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(0.0f,  1.0f,  0.0f)},
           Vertex{Vector3d(0.5f,  0.5f,  0.5f),
                  Vector2d(1.0f,1.0f),
                  Vector3d(0.0f,  1.0f,  0.0f)},
           Vertex{Vector3d(-0.5f,  0.5f,  0.5f),
                  Vector2d(0.0f,1.0f),
                  Vector3d(0.0f,  1.0f,  0.0f)},
           Vertex{Vector3d(-0.5f,  0.5f, -0.5f),
                  Vector2d(0.0f,0.0f),
                  Vector3d(0.0f,  1.0f,  0.0f)}},

            "../../Luna/luna_renderer/textures/wood.jpg"}
	{
	}

    void Cube::Update(const TimeManager& tm)
	{
        //Matrix4d& mine = GetModelMatrix();
        Matrix4d model{};
        model = model * luna::Matrix4d::Translate(GetTransform().Position);
        model = model * luna::Matrix4d::RotateX(luna::Angle::AngleFromDegrees(GetTransform().Rotation.x() +35 *tm.GetCurrentTime()));
        model = model * luna::Matrix4d::RotateY(luna::Angle::AngleFromDegrees(GetTransform().Rotation.y()));
        model = model * luna::Matrix4d::RotateZ(luna::Angle::AngleFromDegrees(GetTransform().Rotation.z()));
        model = model * luna::Matrix4d::Scale(GetTransform().Scale);
//        for(GameObject* child : children)
//        {
//            //child->SetModelMatrix(model * child->GetModelMatrix());
//            child->Update(tm);
//           // const Matrix4d& childMat = child->GetModelMatrix();
//            //model = model * childMat;

        //}
        SetModelMatrix(model);
	}

    void Cube::Draw(Shader shader)
    {
        shader.Use();
        if(isLightSource)
        {
            shader.SetUniform("isLightSource", true);
            shader.SetUniform("lightPos", GetTransform().Position);
        }
        else
        {
            shader.SetUniform("isLightSource", false);
        }
        shader.SetUniform("objectColor", objectColor);
        shader.SetUniform("lightColor",  lightColor);
        shader.SetModel(GetModelMatrix());
        mMesh.Use();
        glDrawArrays(GL_TRIANGLES, 0, mMesh.GetVertices().size());
//        for(GameObject* child : children)
//        {
//            child->Draw(shader);
//        }
	}

    void Cube::SetColor(const Vector3d &color)
    {
        objectColor = color;
    }

    void Cube::SetLight(const Vector3d &light)
    {
        lightColor = light;
    }

    void  Cube::UseAsLamp(bool isLightSource)
    {
        this->isLightSource = isLightSource;
    }
}

