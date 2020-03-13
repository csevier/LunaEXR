#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Shader.hpp"
#include "vector3d.hpp"
#include "Drawable.hpp"

namespace luna 
{
	class GameObject: public Drawable
	{
        public:
            GameObject(Vector3d transform);
            Vector3d GetTransform() const;
            virtual void Update(float deltaTime) = 0;
            void Draw(Shader shader) override;

        private:
            Vector3d mTransform;
	};
}
#endif
