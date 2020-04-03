#include "Scene.hpp"

namespace luna
{
    void Scene::DrawScene() noexcept
    {
        for (Drawable* object : mObjects)
        {
            object->Draw();
        }
    }

    void Scene::UpdateScene(const TimeManager &tm)
    {
        for (GameObject* object : mObjects)
        {
            object->Update(tm);
        }
    }

    void Scene::AddObject(GameObject* object)
    {
        mObjects.push_back(object);
    }
}
