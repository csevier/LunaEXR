#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Shader.hpp"
#include "vector3d.hpp"
#include "Drawable.hpp"
#include "TimeManger.hpp"

namespace luna 
{
    struct Transform
    {
        Vector3d Position;
        Vector3d Rotation;
        Vector3d Scale;
    };

	class GameObject: public Drawable
	{
        public:
            GameObject(const Vector3d& transform);
            Transform& GetTransform();
            virtual void Update(const TimeManager& tm) = 0;
            void Draw(Shader shader) override;

        private:
            Transform mTransform;
	};
}
#endif
