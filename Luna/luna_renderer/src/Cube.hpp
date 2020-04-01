#ifndef CUBE_HPP
#define CUBE_HPP

#include "GameObject.hpp"
#include "vector3d.hpp"
#include "Mesh.hpp"
#include "Drawable.hpp"
#include "TimeManger.hpp"

namespace luna 
{
	class Cube : public GameObject
	{
	public:
        Cube(const Vector3d& transform);
        void Update(const TimeManager& tm) override;
		void Draw(Shader shader) override;

	private:
		Mesh mMesh;
	};
}

#endif
