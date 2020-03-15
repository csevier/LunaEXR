#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Shader.hpp"
#include "vector3d.hpp"
#include "Drawable.hpp"
#include "TimeManger.hpp"

namespace luna 
{
	class GameObject: public Drawable
	{
        public:
            GameObject(Vector3d transform);
            Vector3d GetTransform() const;
            virtual void Update(const TimeManager& tm) = 0;
            void Draw(Shader shader) override;

        private:
            Vector3d mTransform;
	};
}
#endif
