#include "GameObject.hpp"

namespace luna
{
    GameObject::GameObject(Vector3d transform) : mTransform{transform} {}

    Vector3d GameObject::GetTransform() const
    {
        return mTransform;
    }

    void GameObject::Draw(Shader shader)
    {
        // no draw on base.
    }
}
