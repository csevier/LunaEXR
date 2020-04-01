#include "GameObject.hpp"

namespace luna
{
    GameObject::GameObject(const Vector3d& position)
    {
        mTransform.Position = position;
        mTransform.Scale = {1,1,1};
        mTransform.Rotation = {0, 0, 0};
    }

    Transform& GameObject::GetTransform()
    {
        return mTransform;
    }

    void GameObject::Draw(Shader shader)
    {
        // no draw on base.
    }
}
