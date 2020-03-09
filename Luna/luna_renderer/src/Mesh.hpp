#ifndef MESH_HPP
#define MESH_HPP
#include <vector>
#include <string>
#include "../../../luna_math/src/vector2d.hpp"
#include "../../../luna_math/src/vector3d.hpp"
#include "shader.hpp"
#include "GameObject.hpp"
#include "Drawable.hpp"
#include "../../../luna_math/src/matrix4d.hpp"


namespace luna 
{
	
    struct Vertex 
    {
        Vertex(Vector3d vec) {
            position = vec;
        }
        Vector3d position;
       // Vector2d texCoords;
    };

    struct Texture 
    {
        unsigned int id;
        std::string type;
    };

    class Mesh : public Drawable
    {
        public:
            Mesh(std::vector<Vertex> vertices);
            void Draw(Shader shader);
            void SetModel(Matrix4d model);

        private:
            unsigned int VAO, VBO, EBO;
            void setupMesh();
            std::vector<Vertex> vertices;
            Matrix4d mModel;
    };

	
}
#endif