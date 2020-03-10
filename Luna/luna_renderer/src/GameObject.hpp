#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "shader.hpp"
#include "vector3d.hpp"
#include "Drawable.hpp"

namespace luna 
{
	class GameObject: public Drawable
	{
	public:
		GameObject(Vector3d transform) : mTransform{transform} 
		{
		}

		Vector3d GetTransform() const
		{
			return mTransform;
		}
		virtual void Update(float deltaTime) = 0;
		void Draw(Shader shader) override {

		}
		
	private:
		Vector3d mTransform;
	};
}
#endif
