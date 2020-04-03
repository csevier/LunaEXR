#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Shader.hpp"
#include "vector3d.hpp"
#include "Drawable.hpp"
#include "TimeManger.hpp"
#include <vector>

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
            void Draw() override;
            void AddChild(GameObject* child);
            const Matrix4d& GetModelMatrix() const;
            void SetModelMatrix(const Matrix4d& matrix);

        private:
            Transform mTransform;
            Matrix4d mModel;

        protected:

            std::vector<GameObject*> children;
	};
}
#endif
