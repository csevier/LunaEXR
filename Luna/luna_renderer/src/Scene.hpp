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
            void AddObject(Drawable* object);
        private:
            std::vector<Drawable*> mObjects;
	};
}
#endif
