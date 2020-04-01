#include "Mesh.hpp"
#include "vector3d.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "vector2d.hpp"

namespace luna
{
    

    Mesh::Mesh( std::vector<Vertex> vertices, std::string texturePath )
	{
		this->vertices = vertices;
        this->mTexturePath = texturePath;
        SetupMesh();
        SetupTexture();
	}

    void Mesh::Draw(Shader shader)
    {
        shader.Use();
        shader.SetModel(mModel);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    }

    void Mesh::SetupMesh()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

        // position attribute
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        // texture coord attribute
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoordinate));

        glBindVertexArray(0);
    }

    void Mesh::SetupTexture()
    {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        unsigned char *data = stbi_load(mTexturePath.c_str(), &width, &height, &nrChannels, 0);


        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            std::cout << glGetError() << std::endl; // returns 1280 (invalid enum)
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }

    void Mesh::SetModel(Matrix4d model) {
        mModel = model;
    }
}
