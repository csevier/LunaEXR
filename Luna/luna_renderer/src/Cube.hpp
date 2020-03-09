#ifndef CUBE_HPP
#define CUBE_HPP

#include "GameObject.hpp"
#include "../luna_math/vector3d.hpp"
#include "Mesh.hpp"
#include "Drawable.hpp"

namespace luna 
{
	class Cube : public GameObject
	{
	public:
		Cube(Vector3d transform);
		void Update(float deltaTime) override;
		void Draw(Shader shader) override;
	private:
		Mesh mMesh;
	};
}

#endif