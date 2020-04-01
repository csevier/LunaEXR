#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "GameObject.hpp"
#include "Shader.hpp"
#include "Drawable.hpp"

namespace luna 
{
	class Scene 
	{
        public:
            Scene() = default;
            void DrawScene(Shader shader) noexcept;
            void UpdateScene(const TimeManager& tm);
            void AddObject(GameObject* object);
        private:
            std::vector<GameObject*> mObjects;
	};
}
#endif
