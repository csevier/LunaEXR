#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "GameObject.hpp"
#include "shader.hpp"

namespace luna 
{
	class Scene 
	{
	public:
		Scene() = default;
		void DrawScene(Shader shader) noexcept 
		{
			for (Drawable* object : mObjects) {
				object->Draw(shader);
			}
		}
		void AddObject(Drawable* object) {
			mObjects.push_back(object);
		}
	private:
		std::vector<Drawable*> mObjects;
	};
}
#endif