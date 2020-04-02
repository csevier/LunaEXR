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
        shader.SetUniform("material.ambient", {1.0f, 0.5f, 0.31f});
        shader.SetUniform("material.diffuse", 0);
        shader.SetUniform("material.specular", {0.5f, 0.5f, 0.5f});
        shader.SetUniform("material.shininess", 32.0f);

        shader.SetUniform("light.ambient",  {0.2f, 0.2f, 0.2f});
        shader.SetUniform("light.diffuse",  {0.5f, 0.5f, 0.5f}); // darken diffuse light a bit
        shader.SetUniform("light.specular", {1.0f, 1.0f, 1.0f});
        shader.SetModel(GetModelMatrix());
        mMesh.Use();
        glDrawArrays(GL_TRIANGLES, 0, mMesh.GetVertices().size());
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

