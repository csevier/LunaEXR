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

    void GameObject::Draw()
    {
        // no draw on base.
    }

    void GameObject::AddChild(GameObject *child)
    {
        children.push_back(child);
    }

    const Matrix4d& GameObject::GetModelMatrix() const
    {
        return mModel;
    }

    void GameObject::SetModelMatrix(const Matrix4d &matrix)
    {
        mModel = matrix;
    }
}
