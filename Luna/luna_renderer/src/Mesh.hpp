#ifndef MESH_HPP
#define MESH_HPP
#include <vector>
#include <string>
#include "vector2d.hpp"
#include "vector3d.hpp"
#include "Shader.hpp"
#include "GameObject.hpp"
#include "matrix4d.hpp"


namespace luna 
{
	
    struct Vertex 
    {
        Vertex(Vector3d pos, Vector2d texCoordinate, Vector3d normalVector) {
            position = pos;
            textureCoordinate = texCoordinate;
            surfaceNormal = normalVector;
        }

        Vector3d position;
        Vector2d textureCoordinate;
        Vector3d surfaceNormal;
    };

    class Mesh
    {
        public:
            Mesh(std::vector<Vertex> vertices, std::string texturePath);
            void Use();
            const std::vector<Vertex>& GetVertices() const;

        private:
            unsigned int VAO, VBO, EBO, texture;
            void SetupMesh();
            void SetupTexture();
            std::vector<Vertex> vertices;
            std::string mTexturePath;
    };

	
}
#endif
