#ifndef MESH_HPP
#define MESH_HPP
#include <vector>
#include <string>
#include "vector2d.hpp"
#include "vector3d.hpp"
#include "Shader.hpp"
#include "GameObject.hpp"
#include "Drawable.hpp"
#include "matrix4d.hpp"


namespace luna 
{
	
    struct Vertex 
    {
        Vertex(Vector3d pos, Vector2d texCoordinate) {
            position = pos;
            textureCoordinate = texCoordinate;
        }
        Vector3d position;
        Vector2d textureCoordinate;
    };

    class Mesh : public Drawable
    {
        public:
            Mesh(std::vector<Vertex> vertices, std::string texturePath);
            void Draw(Shader shader);
            void SetModel(Matrix4d model);

        private:
            unsigned int VAO, VBO, EBO, texture;
            void SetupMesh();
            void SetupTexture();
            std::vector<Vertex> vertices;
            Matrix4d mModel;
            std::string mTexturePath;
    };

	
}
#endif
