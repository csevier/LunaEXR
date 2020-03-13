#include "Scene.hpp"

namespace luna
{
    void Scene::DrawScene(Shader shader) noexcept
    {
        for (Drawable* object : mObjects)
        {
            object->Draw(shader);
        }
    }

    void Scene::AddObject(Drawable* object)
    {
        mObjects.push_back(object);
    }
}
