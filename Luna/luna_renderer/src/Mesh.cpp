#include "Mesh.hpp"
#include "../../../luna_math/src/vector3d.hpp"
namespace luna
{
    

	Mesh::Mesh( std::vector<Vertex> vertices)
	{
		this->vertices = vertices;
		setupMesh();
	}

    void Mesh::Draw(Shader shader)
    {
        shader.Use();
        shader.SetModel(model);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));
    }

    void Mesh::setupMesh()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        glBindVertexArray(0);
    }

    void Mesh::SetModel(Matrix4d model) {
        model = model;
    }
}
